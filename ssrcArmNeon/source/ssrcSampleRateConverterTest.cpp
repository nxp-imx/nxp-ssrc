/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef USE_ARM_INLINE

#include "ssrcSampleRateConverterTest.h"
NeonExec neonExec;
NeonInsCBase *NeonExec::f;
extern "C" void getInfo(WaveFileIO *inputFile, struct WaveFileInfo *info);

bool ConverterTest::convertFile(string &inputFileName, string &outputFileName, unsigned outputSamplingRate)
{
    const char *error = inputFile.openRead(inputFileName);
    if (error != nullptr)
    {
        cerr << error << " for file input file:" << inputFileName << endl;
        return false;
    }
    if (inputFile.BitsPerSample != 32)
    {
        cerr << "Error:only 32 bits sample bit depth is supported, inputfile:" << inputFileName << " has bit depth of:" << inputFile.BitsPerSample << endl;
        return false;
    }
    if (inputFile.NumChannels > 2)
    {
        cerr << "Error:only mono or stereo supported, inputfile:" << inputFileName << " has :" << inputFile.NumChannels << endl;
        return false;
    }
    WaveFileInfo  outHeader ;
    getInfo(&inputFile, &outHeader);
    outHeader.SampleRate = outputSamplingRate;
    error = outputFile.openWrite(outputFileName, &outHeader);
    if (error != nullptr)
    {
        cerr << error << " for output file:" << outputFileName << endl;
        return false;
    }

    config.inputSampleRate = inputFile.SampleRate;
    config.outputSampleRate = outputSamplingRate;
    config.stereo = inputFile.NumChannels == 2;
    config.requestedInterpolationNumberOfTaps = 0;
    // using 112 tap interpolator
    config.sampleRateConversionQuality = SsrcResampleConversionQuality_high;
    // input chunck size of 128 (only multiple of 128 allowed)
    config.inputTrasferSizeInTransferUnits = 1;
    // output chunck size of 128 (only multiple of 128 allowed)
    config.outputTrasferSizeInTransferUnits = 1;
    SampleFormat sampleFormat = inputFile.getSampleFormat();
    if (sampleFormat == SampleFormat_LE_PCM_32_bits)
    {
        config.requestedSampleFormat = SsrcSampleFormat_int32;
    }
    else if (sampleFormat == SampleFormat_LE_FLOAT_32_bits)
    {
        config.requestedSampleFormat = SsrcSampleFormat_float32;
    }
    else
    {
        cerr << "unsupported input sample format" << endl;
        return false;
    }
    if (!converterList.getConverter(config, converterContainer))
    {
        for (int index = 0; index < converterContainer.log.index; index++)
        {
            cerr << converterContainer.log.list[index] << endl;
        }

        return false;
    }

    if (sampleFormat == SampleFormat_LE_PCM_32_bits)
    {
        return processFile<int32_t, int64_t>();
    }
    else if (sampleFormat == SampleFormat_LE_FLOAT_32_bits)
    {
        return processFile<float, float>();
    }
    else
    {
        cerr << "only 32 bits integer and 32 bits float sample formats are supported" << endl;
        return false;
    }
    return true;
}
template <class _SAMPLE_TYPE_, class _ACC_TYPE_>
bool ConverterTest::processFile()
{
    size_t inputBufferSize = config.inputTrasferSizeInTransferUnits*converterContainer.inputOutputTransferTransferUnitSize;
    size_t outputBufferSize = config.outputTrasferSizeInTransferUnits*converterContainer.inputOutputTransferTransferUnitSize;
    vector<_SAMPLE_TYPE_> inputBuffer(inputBufferSize);
    vector<_SAMPLE_TYPE_> outputBuffer(outputBufferSize);
    inputBuffer.assign(inputBuffer.capacity(), 0);
    outputBuffer.assign(outputBuffer.capacity(), 0);
    if (inputBuffer.size() != inputBufferSize || outputBuffer.size() != outputBufferSize)
    {
        return false;
    }
    bool needMoreInput = true;
    bool haveMoreInput = false;
    NeonInsC *neonIns;
    bool traceEnable = false;
    bool traceFile = false;
    bool exitAfterTrace = false;

    if (traceEnable)
        if(traceFile)
            neonIns = new NeonInsCTraceFile< _SAMPLE_TYPE_, _ACC_TYPE_>;
        else
            neonIns = new NeonInsCTrace< _SAMPLE_TYPE_, _ACC_TYPE_>(converterContainer);
    else
        neonIns = new NeonInsC;
    neonIns->configure(converterContainer);
    NeonExec::setNeonIns(neonIns);
    unsigned outputGroupCount = 0;
    unsigned outputGroupTrace = 10;
    SsrcSampleRateConverterInterface &converter = *converterContainer.converterPointer;
    neonIns->fillFilterWithSequence(converter);

    do
    {
        if (haveMoreInput)
        {
            needMoreInput = converter.put(inputBuffer.data());
            haveMoreInput = !needMoreInput;
        }
        if (converter.process())
        {
            if (traceEnable)
            {
                neonIns->verify();
                if (outputGroupCount == outputGroupTrace)
                {
                    if (exitAfterTrace)
                    {
                        return true;
                    }
                }
                neonIns->resetTrace();
                outputGroupCount++;
            }
        }
        if (converter.get(outputBuffer.data()))
        {
            outputFile.write(outputBuffer);
        }
        if (needMoreInput)
        {
            haveMoreInput = (inputFile.read(inputBuffer) == inputBufferSize);
            needMoreInput = !haveMoreInput;
        }
    } while (haveMoreInput || converter.haveEnoughSamplesToProcess() || converter.haveEnoughOutputSamples());
    return true;
}

#endif
