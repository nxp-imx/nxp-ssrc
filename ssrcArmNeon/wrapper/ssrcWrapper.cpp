/********************************************************************************
* Copyright 2025 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcNeonTest.h"
#include "ssrcWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

struct SsrcConverterInstance {
    struct SsrcConfig config;                                // configuration container
    struct SsrcSampleRateConverterList converterList;        // converter list object
    struct SsrcSampleRateConverterInfo converterContainer;   // converter container filled by converter list
    SsrcSampleRateConverterInterface *converter;
    int32_t *residue_buffer;
    size_t residue_size;
};

struct SsrcConverterInstance* ssrc_wrapper_create(void)
{
    return new struct SsrcConverterInstance;
}

void ssrc_wrapper_destroy(struct SsrcConverterInstance *instance)
{
    free(instance->residue_buffer);
    delete instance;
}

int ssrc_wrapper_config(struct SsrcConverterInstance **instance_p, int sampleFormat, int channels, int input_rate, int output_rate, int quality)
{
    int ret = -1;

    struct SsrcConverterInstance *instance = *instance_p;
    if (sampleFormat == SampleFormat_LE_PCM_32_bits)
    {
        instance->config.requestedSampleFormat = SsrcSampleFormat_int32;
    }
    else if (sampleFormat == SampleFormat_LE_FLOAT_32_bits)
    {
        instance->config.requestedSampleFormat = SsrcSampleFormat_float32;
    }
    else
    {
        cerr << "SSRC: only 32 bits integer and 32 bits float sample formats are supported" << endl;
        return ret;
    }

    /*
        SSRC only accept stereo or mono
    */
    if (channels > 2)
    {
        cerr << "SSRC: Error:only mono or stereo supported, channels are : " << channels << endl;
        return ret;
    }

    /*
        configure SSRC
    */
    instance->config.inputSampleRate = input_rate;
    instance->config.outputSampleRate = output_rate;
    // stereo or mono
    instance->config.stereo = channels == 2;
    // using 112 tap interpolator
    instance->config.requestedInterpolationNumberOfTaps = 0;
    // using 112 tap interpolator

    instance->config.sampleRateConversionQuality = (SsrcResampleConversionQuality)quality;

    // input chunck size of 128 (only multiple of 128 allowed)
    instance->config.inputTrasferSizeInTransferUnits = 1;
    // output chunck size of 128 (only multiple of 128 allowed)
    instance->config.outputTrasferSizeInTransferUnits = 1 ;

    /*
        get the converter according to configuration
        return false if can't find converter according to the configuration
    */
    if (!instance->converterList.getConverter(instance->config, instance->converterContainer))
    {

        return ret;
    }

    int transferSize = instance->config.inputTrasferSizeInTransferUnits *
                       instance->converterContainer.inputOutputTransferTransferUnitSize;
    instance->residue_buffer = (int32_t *)malloc(transferSize * sizeof(int32_t));
    instance->residue_size = 0;

    /*
        get the converter pointer from
    */
    if (!instance->converterContainer.getConverterObject(instance->converter))
    {
        // this should not happen
        cerr << "internal error" << endl;
        return ret;
    }
    instance->converter->reset(0);

    return 0;
}

int ssrc_wrapper_process(struct SsrcConverterInstance *instance, size_t in_chunk, size_t *out_chunk, int32_t *in_p, int32_t *out_p)
{
    int ret = -1;
    int in_frames;
    *out_chunk = 0;
    /*
        easy buffer allocator with destructor
        using int32_t for both int32_t samples and float sample
        since only the bit depth matters for the buffers
    */
    int transferSize = instance->config.inputTrasferSizeInTransferUnits *
                       instance->converterContainer.inputOutputTransferTransferUnitSize;
    vector<int32_t> inputBuffer(transferSize);
    vector<int32_t> outputBuffer(transferSize);
    inputBuffer.assign(transferSize, 0);
    outputBuffer.assign(transferSize, 0);
    /*
        if memory allocation error return false
    */
    if (inputBuffer.size() != transferSize || outputBuffer.size() != transferSize)
    {
        cerr << "memory allocation error" << endl;
        return ret;
    }

    in_chunk /= sizeof(int32_t);

    while (in_chunk >= transferSize) {
        while (!instance->converter->haveEnoughSamplesToProcess()) {
            /* process residue */
            if (instance->residue_size) {
                memcpy(inputBuffer.data(), instance->residue_buffer, instance->residue_size * sizeof(int32_t));
                int left_size = transferSize - instance->residue_size;
                memcpy(inputBuffer.data() + instance->residue_size, in_p, left_size * sizeof(int32_t));
                in_p += left_size;
                in_chunk -= left_size;
                instance->residue_size = 0;
            } else {
                memcpy(inputBuffer.data(), in_p, transferSize * sizeof(int32_t));
                in_p += transferSize;
                in_chunk -= transferSize;
            }

            bool inputBufferFull = !instance->converter->put(inputBuffer.data());
            /*
                Something has gone wrong
                the is not enough samples in the queue to process, but we can not put more samples
            */
            if (inputBufferFull)
            {
                // this should not happen
                cerr << "internal error" << endl;
                return ret;
            }
            if (in_chunk < transferSize)
                break;

        }

        while (instance->converter->process()) {
            while(instance->converter->get(outputBuffer.data())) {
                memcpy(out_p, outputBuffer.data(), transferSize * sizeof(int32_t));
                out_p += transferSize;
                *out_chunk += transferSize * sizeof(int32_t);
            }
        }

    }

    /* residue buffer */
    if (in_chunk > 0) {
        memcpy(instance->residue_buffer, in_p, in_chunk * sizeof(int32_t));
        instance->residue_size = in_chunk;
    }

    return 0;
}

#ifdef __cplusplus
}
#endif
