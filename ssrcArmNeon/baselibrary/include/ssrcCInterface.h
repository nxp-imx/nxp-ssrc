/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcCInterface_h
#define ssrcCInterface_h
#include <stdbool.h>
#include <inttypes.h>
/*
    FORWARD defitions to allow usage of pointers
*/
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __cplusplus
#define nullptr NULL
#endif
/********************************************************************************
*  maximum number of error returned from SSRC
*
*******************************************************************************/
#define SsrcMaxLog  10

struct SsrcSampleRateConverterInterface;
struct SsrcSampleRateConverterDefinition;
struct QuantizedFitlerEntry;

/********************************************************************************
*  wavefile information
*
*******************************************************************************/
struct WaveFileInfo
{
    uint16_t AudioFormat;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t ByteRate;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    uint32_t DataBlockSize;
};
/********************************************************************************
*  sample ratio numeritor and denominator
*
*******************************************************************************/
struct SSRCSamplingRatesRatio
{
    unsigned inputSampleRate;        // input sample rate 
    unsigned outputSampleRate;       // output sample rate
};

/********************************************************************************
*  Three quality level of sample rate conversion generated
*   low has lowest THD+N and lowest number of fitler taps
*   high has highest THD+N and highest number of fitler taps
*******************************************************************************/
typedef enum SsrcResampleConversionQuality
{
    SsrcResampleConversionQuality_low,
    SsrcResampleConversionQuality_medium,
    SsrcResampleConversionQuality_high,
    SsrcResampleConversionQuality_not_set
} SsrcResampleConversionQuality;

/********************************************************************************
*  two sample formats are supported
*  int32 (int32_t) and float32 (float)
*******************************************************************************/
typedef enum SsrcSampleFormat
{
    SsrcSampleFormat_int32,
    SsrcSampleFormat_float32
} SsrcSampleFormat;
/********************************************************************************
*  SSRC sampling rate to ratio conversion container
*
*******************************************************************************/
struct SsrcSapleRateToRatio
{
    unsigned inputSampleRate;             // input sampling rate
    unsigned outputSampleRate;            // output sampling rate
    unsigned sampleRateRatioInput;        // input/output sample rate conversion ratio, input  
    unsigned sampleRateRatioOutput;       // input/output sample rate conversion ratio, output
};
/********************************************************************************
*  SSRC configuration
*
*******************************************************************************/
struct SsrcConfig
{
    unsigned inputSampleRate;                     // input sampling rate
    unsigned outputSampleRate;                    // output sampling rate
    unsigned inputTrasferSizeInTransferUnits;              // ssrc input transfer chunk size , must be multiple of 128
    unsigned outputTrasferSizeInTransferUnits;             // ssrc output transfer chunk size , must be multiple of 128
    unsigned requestedInterpolationNumberOfTaps;  // interpolation number of taps if set to 0, uses quality setting
    SsrcResampleConversionQuality  sampleRateConversionQuality; // quality setting if set to not_set, uses requestedInterpolationNumberOfTaps
    bool stereo;                                  // stereo == true mono == false  
    SsrcSampleFormat requestedSampleFormat;       // input/ouput sample format (int32 or float 32) 
};

/********************************************************************************
* Sample rate converter instance definition
*
*******************************************************************************/
struct SsrcSampleRateConverterDefinition
{
    void *libHandle;                      // lib handle for DLL generated mode
    void *symbolPointerInLib;             // lib symbol for DLL generated mode            
    const char *libSoFileName;            // lib so file name for DLL generated mode   
    const char *libSymbolToGet;           // lib symbol for DLL generated mode  
    struct SsrcSampleRateConverterInterface *(*constructor)(struct SsrcSampleRateConverterDefinition *); // construction 
    unsigned sampleRateConverterNo;       // index in internal sample rate converter table 
    unsigned sampleRateRatioInput;        // input/output sample rate conversion ratio, input  
    unsigned sampleRateRatioOutput;       // input/output sample rate conversion ratio, output
    unsigned numberOftapsPerPhase;        // interpolator number of taps 
    unsigned numberOfTapsRedPerReadCycle; // number of taps red per process cycle
    unsigned numberOfSamplesUsedPerRunPerChan; // number input samples used per per process cycle per channel
    unsigned totalNumberOfSamplesUsedPerRun; //  total number input samples used per per process cycle
    unsigned numOutputSamplesPerChanPerRun; // number of output samples genenerated per process cycle per channel
    unsigned totalNumOutputSamplesPerRun;   // number of output samples genenerated per process cycle
    unsigned numberOfChannels;            // number of channels 1 or 2
    SsrcSampleFormat sampleFormat;        // sample format 32 bits int or 32 bits float
    unsigned inputOutputTransferTransferUnitSize; // input/output queue sample transfer unit size in samples
}; 
/*!******************************************************************************************
**
** quantized filter entry in interpolation filter list
**
*******************************************************************************************/
struct QuantizedFitlerEntry
{
    void *libHandle;                 // object file lib handle function pointer
    void *symbolPointerInLib;        // symbol pointer in lib  
    const char *libSoFileName;       // dynamic lirary name
    const char *libSymbolToGet;      // dynamic lib symbol to get 
    uint32_t *filter;                // interpolation filter array
    unsigned filterNumber;           // index in filter list
    unsigned sampleRateRatioInput;   // input/output sample rate conversion ratio, input
    unsigned sampleRateRatioOutput;  // input/output sample rate conversion ratio, outpu
    unsigned numberOftapsPerPhase;   // interpolation filter number of taps 
    SsrcSampleFormat sampleFormat;   //  sample format 32 bits int or 32 bits float
};
/*!******************************************************************************************
**
** ssrc resampler list entry
**
*******************************************************************************************/

struct SsrcSampleConverterListEntry
{
    SsrcSampleFormat sampleFormat;   //  sample format 32 bits int or 32 bits float
    SsrcResampleConversionQuality  sampleRateConversionQuality; // quality setting if set to not_set, uses requestedInterpolationNumberOfTaps
    unsigned sampleRateRatioInput;        // input/output sample rate conversion ratio, input  
    unsigned sampleRateRatioOutput;       // input/output sample rate conversion ratio, output
    bool stereo;                          // true: stereo (two channel input/output) false:mono (single channel input/output)
    struct SsrcSampleRateConverterInterface *(*constructor)(struct SsrcSampleRateConverterDefinition *);
    uint32_t * (*get_filter)();
};
/*!******************************************************************************************
**
** ssrc converter instance
**
*******************************************************************************************/
struct SsrcSampleConverterInstance
{
    struct SsrcSampleConverterListEntry *converterDef;             // converter defintion 
    struct SsrcSampleRateConverterInterface *converterPointer;     // constructed converter object 
    int inputTrasferSizeInTransferUnits;                    // input fifo transfer size in transfer units
    int outputTrasferSizeInTransferUnits;                   // output fifo transfer size in transfer units
    int logCount;                                           // number of valid log strings in log
    const char *log[SsrcMaxLog];                            // log of error returned
};
/********************************************************************************
*  generate one set of output samples
*  DOES NOT CHECK FOR NULL  instanceOfConverter
*  return :
*           false : converter not ready to process samples
*           true : converter process samples and generated output samples
*******************************************************************************/
bool ssrcprocess(struct SsrcSampleRateConverterInterface *instanceOfConverter);
/********************************************************************************
* get a chunck size data from converter output queue
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to output chunck size buffer to transfer output data to
*  return :
*           false : not enough samples in output queue
*           true  : buffer 'data' has chunck size output samples
*******************************************************************************/
bool ssrcget(struct SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data);
/********************************************************************************
* get a chunck size data from converter output queue
* and convert output from float to int
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to output chunck size buffer to transfer output data to
*  return :
*           false : not enough samples in output queue
*           true  : buffer 'data' has chunck size output samples
*******************************************************************************/
bool ssrcget_FloatToInt(struct SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data);
/********************************************************************************
* put a chunck size data into converter input queue
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to input chunck size buffer to transfer output data from
*  return :
*           false : input queue doesn't have enough empty space to transfer data
*           true  : data from 'data' buffer was transferd to input queue
*******************************************************************************/
bool ssrcput(struct SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data);
/********************************************************************************
* put a chunck size data into converter input queue
* convert input from int to float before
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to input chunck size buffer to transfer output data from
*  return :
*           false : input queue doesn't have enough empty space to transfer data
*           true  : data from 'data' buffer was transferd to input queue
*******************************************************************************/
bool ssrcput_IntToFloat(struct SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data);
/********************************************************************************
* is ther enough samples input queue to generate a set of output samples
*  DOES NOT CHECK FOR NULL  instanceOfConverter
*    return:
*            false : if not egough samples
*            true  : if if there is enough samples
*******************************************************************************/
bool ssrchaveEnoughSamplesToProcess(struct SsrcSampleRateConverterInterface *instanceOfConverter);
/********************************************************************************
* is there at least a output chunck size output samples in output queue
*     return:
*             false : if not an least output chunck size output samples in output queue
*             true  : if there is at lest a chunk size number of output samples available
*******************************************************************************/
bool ssrchaveEnoughOutputSamples(struct SsrcSampleRateConverterInterface *instanceOfConverter);

/********************************************************************************
* construct an instance of sample rate converter based on parameters
* in SsrcSampleConverterInstance
* input :
*        SsrcSampleConverterInstance
*        SsrcSampleConverterInstance->converterDef: pointing to converter definition
*        instanceOfConverter->converterDef->constructor : pointer constructor pointer for sample rate converter
*        instanceOfConverter->converterDef->get_filter  : pointer to get sample rate converter filter
* output :
*        SsrcSampleConverterInstance->converterPointer: pointing to converter
*
*******************************************************************************/
bool constructAnInstanceOfConverter(struct SsrcSampleConverterInstance *instanceOfConverter);
/********************************************************************************
*  get sample rate index
*
*******************************************************************************/
int getSampleRateIndex(unsigned sampleRate);
/********************************************************************************
*  get sample rate ratio
*
*******************************************************************************/
bool getSampleRateRatio(unsigned inputSampleRate, unsigned outputSampleRate, struct SSRCSamplingRatesRatio *output);
/********************************************************************************
* destruct given instance of sample rate converter in SsrcSampleConverterInstance
*
* input :
*        SsrcSampleConverterInstance
*        SsrcSampleConverterInstance->converterPointer: pointing to converter
*
*******************************************************************************/
void destructAnInstanceOfConverter(struct SsrcSampleConverterInstance *instanceOfConverter);
/********************************************************************************
* reset converter to initial state
*
* input :
*        SsrcSampleConverterInstance
*        SsrcSampleConverterInstance->converterPointer: pointing to converter
*
*******************************************************************************/
void resetConverter(struct SsrcSampleConverterInstance *instanceOfConverter);

/********************************************************************************
* clear the structure (after memory allocation)
*
* input :
*        SsrcSampleConverterInstance
*
*******************************************************************************/
void clearInstanceOfConverterStruct(struct SsrcSampleConverterInstance *instanceOfConverter);


/********************************************************************************
* get input queue fulness
*
* output :
*        number of samples currently in input queue
*
*******************************************************************************/
int inputFulness(struct SsrcSampleRateConverterInterface  *converterPointer);
/********************************************************************************
* get output queue fulness
*
* output :
*        number of samples currently in output queue
*
*******************************************************************************/
int outputFulness(struct SsrcSampleRateConverterInterface  *converterPointer);



void addToLog(struct SsrcSampleConverterInstance *instanceOfConverter, const char *message);
void addToLogList(struct SsrcSampleConverterInstance *instanceOfConverter, const char **messages, int count);

#ifdef __cplusplus
}
#endif
#endif // ssrcCInterface_h
