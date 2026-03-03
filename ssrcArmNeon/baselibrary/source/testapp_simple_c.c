/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
/********************************************************************************
* example of up sampling a wave input file using SSRC 
*
*******************************************************************************/
#include "ssrcCInterface.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "wavHeader.h"

/********************************************************************************
* sample SSRC conversion list 
*
*********************************************************************************/
/*
    the function we need in the list
*/
uint32_t * get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_88_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);
uint32_t * get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_96_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);
uint32_t * get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_112_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);

uint32_t * get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_88_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);
uint32_t * get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_96_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);
uint32_t * get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_112_float32();
struct SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_stereo_SsrcSampleFormat_float32(struct SsrcSampleRateConverterDefinition *returnedInfo);

struct WaveFileIO;
struct WavfileHeader;

bool constructAnInstanceOfConverter( struct SsrcSampleConverterInstance *instanceOfConverter);
void destructAnInstanceOfConverter(struct SsrcSampleConverterInstance *instanceOfConverter);
struct WaveFileIO *openInputWaveFile(char *fileName);
struct WaveFileIO *openOutputWaveFile(char *fileName,struct WaveFileInfo *inputFile);
void closeWaveFile(struct WaveFileIO *file);
int readInputWaveFile(struct WaveFileIO *inputFile,int32_t *inputBuffer,size_t inputTransferSize);
int writeOutputWaveFile(struct WaveFileIO *outputFile,int32_t *outputBuffer,size_t outputTransferSize);
void getInfo(struct WaveFileIO *inputFile, struct WaveFileInfo *info);
void clearInstanceOfConverterStruct(struct SsrcSampleConverterInstance *instanceOfConverter);
bool getSampleRateRatio(unsigned inputSampleRate, unsigned outputSampleRate, struct SSRCSamplingRatesRatio *output);

/*
    pre defined queue transfer units size
*/
unsigned getInputOutputTransferTransferUnitSize();
/*
    an example of list of conversions
*/
#define NumberOfSupportedConversions 6
struct SsrcSampleConverterListEntry ssrcSampleConverterList[NumberOfSupportedConversions] =
{
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_high,
        1,
        2,
        true,
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_112_float32
    },
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_medium,
        1,
        2,
        true,
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_96_float32
    },
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_low,
        1,
        2,
        true,
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_88_float32
    },
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_high,
        147,
        160,
        true,
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_112_float32
    },
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_medium,
        147,
        160,
        true,
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_96_float32
    },
    {
        SsrcSampleFormat_float32,
        SsrcResampleConversionQuality_low,
        147,
        160,
        true,
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_stereo_SsrcSampleFormat_float32,
        get_ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_88_float32
    }
};

/*
    example of up sampling a wave input file using SSRC 
*/
int main_testapp(int argc,char **argv)
{
    /*
        more input is from input file
    */
    bool haveMoreInput = true;

    char *inputFileName,*outputFileName;
    struct WaveFileIO *inputFile,*outputFile;
    unsigned outputSampleRate;
    struct SsrcSampleConverterInstance converterInstance;
    int inputTransferSize,outputTransferSize;
    struct SSRCSamplingRatesRatio srRatio;
    struct WaveFileInfo inputfileInfo;
    int index;
    bool input_to_float=false, output_to_int=false;

    int32_t *inputBuffer,*outputBuffer;
    /*
        clear the structure
    */
    clearInstanceOfConverterStruct(&converterInstance);
    /*
        need input file, output file and output sample rate
    */
    if (argc < 4)
    {
        printf("Not Enough parameter, Usage:\n");
        printf("%s<input file>  <output file> <output sampling rate>\n", argv[0] );
       return 0;
    }

    /*
        for simplicity this sample program using string containers for names
    */
    inputFileName = argv[1];
    outputFileName = argv[2];
    /*
        output sample rate from text to integer
    */
    outputSampleRate = atoi(argv[3]);
    /*
        converter definition
    */
    /*
        open input file
    */
    inputFile = openInputWaveFile(inputFileName);
    if (inputFile == nullptr)
    {
        printf("ERROR: can not open input file \n");
        return 1;
    }
    getInfo(inputFile, &inputfileInfo);

    if (!getSampleRateRatio(inputfileInfo.SampleRate, outputSampleRate, &srRatio))
    {
        printf("Can not find sample ratio in %d out %d\n", inputfileInfo.SampleRate, outputSampleRate);
        return 0;

    }
    if (inputfileInfo.AudioFormat != WAVE_FORMAT_IEEE_FLOAT)
    {
        input_to_float = output_to_int = true;
    }
    for (index = 0; index < NumberOfSupportedConversions; index++)
    {
        if (
            srRatio.inputSampleRate == ssrcSampleConverterList[index].sampleRateRatioInput &&
            srRatio.outputSampleRate == ssrcSampleConverterList[index].sampleRateRatioOutput &&
            ((inputfileInfo.NumChannels == 2 && ssrcSampleConverterList[index].stereo) ||
            (inputfileInfo.NumChannels == 1 && !ssrcSampleConverterList[index].stereo)))
        {
            break;
        }
    }
    if (index == NumberOfSupportedConversions)
    {
        printf("sample ratio not supported in %d out %d\n", inputfileInfo.SampleRate, outputSampleRate);
        return 0;
    }
    converterInstance.converterDef = &ssrcSampleConverterList[index];

    /*
        open output file
    */
    inputfileInfo.SampleRate = outputSampleRate;
    outputFile = openOutputWaveFile(outputFileName, &inputfileInfo);
    if (outputFile == nullptr)
    {
        printf("ERROR: can not open output file \n");
        return 1;
    }

    /*
        these are used by converter to cosntruct input/output queue
    */
    converterInstance.inputTrasferSizeInTransferUnits = 1;
    converterInstance.outputTrasferSizeInTransferUnits = 1;


    inputTransferSize = getInputOutputTransferTransferUnitSize() * converterInstance.inputTrasferSizeInTransferUnits;
    outputTransferSize = getInputOutputTransferTransferUnitSize() * converterInstance.outputTrasferSizeInTransferUnits;


    inputBuffer = (int32_t *)malloc(inputTransferSize * sizeof(int32_t));
    if (inputBuffer == nullptr)
    {
        return false;
    }
    outputBuffer = (int32_t *)malloc(outputTransferSize * sizeof(int32_t));
    if (outputBuffer == nullptr)
    {
        free(inputBuffer);
        return false;
    }
    /*
        construct a converter
    */

    if (!constructAnInstanceOfConverter(&converterInstance))
    {
        int index;
        for(index =0;index < converterInstance.logCount;index++)
        {
            printf("%s\n",converterInstance.log[index]);
        }
        printf("construction failed\n");
        destructAnInstanceOfConverter(&converterInstance);
        free(inputBuffer);
        free(outputBuffer);
        return 1;
    }
    resetConverter(&converterInstance);


    /*
        processs input file loop
    */
    do
    {
        /*
            while there is not enough input samples to generate output
        */
        while (!ssrchaveEnoughSamplesToProcess(converterInstance.converterPointer))
        {


            /*
                read samples from input file
            */
            if ((haveMoreInput = (readInputWaveFile(inputFile,inputBuffer, inputTransferSize) == inputTransferSize)))
            {
                bool inputBufferFull =
                    input_to_float ?
                    !ssrcput(converterInstance.converterPointer,inputBuffer) :
                    !ssrcput_IntToFloat(converterInstance.converterPointer, inputBuffer);
                /*
                    Something has gone wrong
                    the is not enough samples in the queue to process, but we can not put more samples 
                */
                if (inputBufferFull)
                {
                    return 0;
                }
            }
            /*
                out of input
            */
            else
            {
                break;
            }
        }
        /*
            generate as much ouput as we have enough input samples
            and output samples that are generated
        */
        while (ssrcprocess(converterInstance.converterPointer))
        {
            while (
                output_to_int ?
                ssrcget(converterInstance.converterPointer, outputBuffer) :
                ssrcget_FloatToInt(converterInstance.converterPointer, outputBuffer))
            {
                writeOutputWaveFile(outputFile,outputBuffer, outputTransferSize);
            }
        }
        /*
            no more input and not enough enough samples to generate output, exit
        */
    } while (haveMoreInput);

    int inSamp = inputFulness(converterInstance.converterPointer);
    int outSamp = outputFulness(converterInstance.converterPointer);


    closeWaveFile(inputFile);
    closeWaveFile(outputFile);
    destructAnInstanceOfConverter(&converterInstance);
    free(inputBuffer);
    free(outputBuffer);

    return 0;

}



