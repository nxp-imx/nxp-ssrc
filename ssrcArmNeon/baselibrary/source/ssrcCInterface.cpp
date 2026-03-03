/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcSampleRateConverterConfig.h"
#include "ssrcsamplerateconverterlist_const.h"
#include <malloc.h>
/********************************************************************************
*  get sample rate index
*
*******************************************************************************/
extern "C" 
int getSampleRateIndex(unsigned sampleRate)
{
    int index;
    for (index = 0; index < NumberOfSampleRatesSupported; index++)
    {
        if (samplingRateList[index] == sampleRate)
        {
            return index;
        }
    }
    return -1;
}
/********************************************************************************
*  get sample rate ratio
*
*******************************************************************************/
extern "C"
bool getSampleRateRatio(unsigned inputSampleRate, unsigned outputSampleRate, SSRCSamplingRatesRatio *output)
{
    unsigned inputSRIndex = 0;
    if ((inputSRIndex = getSampleRateIndex(inputSampleRate)) == -1)
    {
        return false;
    }
    unsigned outputSRIndex = 0;
    if ((outputSRIndex = getSampleRateIndex(outputSampleRate)) == -1)
    {
        return false;
    }
    *output = samplingRatesRatio[inputSRIndex][outputSRIndex];
    return true;
}

/********************************************************************************
*  generate one set of output samples
*  DOES NOT CHECK FOR NULL  instanceOfConverter
*  return :
*           false : converter not ready to process samples
*           true : converter process samples and generated output samples
*******************************************************************************/
extern "C" bool ssrcprocess(SsrcSampleRateConverterInterface *instanceOfConverter)
{
    return instanceOfConverter->process();
}
/********************************************************************************
* get a chunck size data from converter output queue
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to output chunck size buffer to transfer output data to
*  return :
*           false : not enough samples in output queue
*           true  : buffer 'data' has chunck size output samples
*******************************************************************************/
extern "C" bool ssrcget(SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data)
{
    return instanceOfConverter->get(data);
}
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
extern "C" bool ssrcget_FloatToInt(SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data)
{
    return instanceOfConverter->get_FloatToInt(data);
}
/********************************************************************************
* put a chunck size data into converter input queue
*  DOES NOT CHECK FOR NULL  instanceOfConverter or data
*  input:
*          data = pointer to input chunck size buffer to transfer output data from
*  return :
*           false : input queue doesn't have enough empty space to transfer data
*           true  : data from 'data' buffer was transferd to input queue
*******************************************************************************/
extern "C" bool ssrcput(SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data)
{
    return instanceOfConverter->put(data);
}
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
extern "C" bool ssrcput_IntToFloat(SsrcSampleRateConverterInterface *instanceOfConverter, int32_t *data)
{
    return instanceOfConverter->put_IntToFloat(data);
}
/********************************************************************************
* is ther enough samples input queue to generate a set of output samples
*  DOES NOT CHECK FOR NULL  instanceOfConverter
*    return:
*            false : if not egough samples
*            true  : if if there is enough samples
*******************************************************************************/
extern "C" bool ssrchaveEnoughSamplesToProcess(SsrcSampleRateConverterInterface *instanceOfConverter)
{
    return instanceOfConverter->haveEnoughSamplesToProcess();
}
/********************************************************************************
* is there at least a output chunck size output samples in output queue
*     return:
*             false : if not an least output chunck size output samples in output queue
*             true  : if there is at lest a chunk size number of output samples available
*******************************************************************************/
extern "C" bool ssrchaveEnoughOutputSamples(SsrcSampleRateConverterInterface *instanceOfConverter)
{
    return instanceOfConverter->haveEnoughOutputSamples();
}
/********************************************************************************
*******************************************************************************/

extern "C" void addToLog(SsrcSampleConverterInstance *instanceOfConverter,const char *message)
{
    if ( instanceOfConverter->logCount < SsrcMaxLog)
    {
        instanceOfConverter->log[ instanceOfConverter->logCount] =  message;
        instanceOfConverter->logCount++;
    }
}
/********************************************************************************
*******************************************************************************/
extern "C" void addToLogList(SsrcSampleConverterInstance *instanceOfConverter,const char **messages,int count)
{
    for ( int index=0;index < count && instanceOfConverter->logCount < SsrcMaxLog;index++)
    {
        instanceOfConverter->log[ instanceOfConverter->logCount] =  messages[index];
        instanceOfConverter->logCount++;
    }
}
#ifdef USE_ARM_INLINE

/********************************************************************************
*******************************************************************************/
extern "C" int posix_memalign(void **memptr, size_t alignment, size_t size)
{
   *memptr = memalign(alignment,size);
   return *memptr != nullptr ? 0 : 1;
}
/********************************************************************************
*******************************************************************************/
extern "C" void *aligned_alloc( size_t alignment, size_t size)
{
   return memalign(alignment,size);
}
#endif
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
extern "C" bool constructAnInstanceOfConverter( SsrcSampleConverterInstance *instanceOfConverter)
{
    /*
        clear log
    */
    instanceOfConverter->logCount = 0;
    instanceOfConverter->converterPointer = nullptr;
    for(int index=0;index < SsrcMaxLog;index++)
    {
        instanceOfConverter->log[index] = nullptr;
    }
    /*
        check for null pointers in structures 
    */
    if (instanceOfConverter->converterDef == nullptr )
    {
        addToLog(instanceOfConverter, "ERROR: instanceOfConverter->converterDef is nullptr");
        return false;
    }

    if ( instanceOfConverter->converterDef->constructor == nullptr )
    {
        addToLog(instanceOfConverter, "ERROR:instanceOfConverter->converterDef->constructor == nullptr is nullptr");
        return false;
    }
    if (instanceOfConverter->converterDef->get_filter == nullptr)
    {
        addToLog(instanceOfConverter, "ERROR:instanceOfConverter->converterDef->get_filter == nullptr is nullptr");
        return false;
    }


   SsrcSampleRateConverterInfo converterInfo;   // converter container filled by converter list

   converterInfo.stereo = instanceOfConverter->converterDef->stereo;
    /*
        construct the converter
    */
    converterInfo.converterPointer = instanceOfConverter->converterDef->constructor(&converterInfo);
    /*
        did something went wrong
    */
    if (converterInfo.converterPointer == nullptr)
    {
        addToLogList(instanceOfConverter, converterInfo.log.list, converterInfo.log.index);
        addToLog(instanceOfConverter, "ERROR:construction failed");
        return false;
    }
    instanceOfConverter->converterPointer = converterInfo.converterPointer;

    /*
        fill filter information since the constructor is looking to make sure its parameters match
    */
    QuantizedFitlerEntry fitlerInfo;
    /*
     these three parameters are used in dll and not used here
    */
    fitlerInfo.libHandle = nullptr;                       // object file lib handle function pointer
    fitlerInfo.symbolPointerInLib = nullptr;              // symbol pointer in lib  
    fitlerInfo.libSoFileName = nullptr;                   // dynamic lirary name
    fitlerInfo.libSymbolToGet = nullptr;                  // dynamic lib symbol to get 
    /*
        get the fitler 
    */
    fitlerInfo.filter = instanceOfConverter->converterDef->get_filter();                // interpolation filter array
    /* 
        not used
    */
    fitlerInfo.filterNumber = 0;                          // index in filter list
    /*
        these need to be set based on the constructed converter
        the filter and converter have error checking, if these parameters dont match the filter and converter
    */
    fitlerInfo.sampleRateRatioInput = converterInfo.sampleRateRatioInput;   // input/output sample rate conversion ratio, input
    fitlerInfo.sampleRateRatioOutput = converterInfo.sampleRateRatioOutput;  // input/output sample rate conversion ratio, outpu
    fitlerInfo.numberOftapsPerPhase = converterInfo.numberOftapsPerPhase;   // interpolation filter number of taps 
    fitlerInfo.sampleFormat = converterInfo.sampleFormat;   //  sample format 32 bits int or 32 bits float

    /*
        these are used by converter to cosntruct input/output queue
    */
    converterInfo.inputTrasferSizeInTransferUnits = instanceOfConverter->inputTrasferSizeInTransferUnits;
    converterInfo.outputTrasferSizeInTransferUnits =  instanceOfConverter->outputTrasferSizeInTransferUnits;
    /*
        set the filter info in converter 
    */
    converterInfo.interpolationFilter = &fitlerInfo;
    /*
        configure the converter 
        returns false when it fails
    */
    if (!converterInfo.converterPointer->configure(converterInfo))
    {
        addToLogList(instanceOfConverter, converterInfo.log.list, converterInfo.log.index);
        addToLog(instanceOfConverter, "ERROR:configuration failed");
        return false;
    }
    return true;
}
/********************************************************************************
* destruct given instance of sample rate converter in SsrcSampleConverterInstance
* 
* input :
*        SsrcSampleConverterInstance
*        SsrcSampleConverterInstance->converterPointer: pointing to converter
*        
*******************************************************************************/
extern "C" void destructAnInstanceOfConverter( SsrcSampleConverterInstance *instanceOfConverter)
{
    if (instanceOfConverter != nullptr && instanceOfConverter->converterPointer != nullptr)
    {
        delete (instanceOfConverter->converterPointer);
    }
}

/********************************************************************************
* reset converter to initial state
*
* input :
*        SsrcSampleConverterInstance
*        SsrcSampleConverterInstance->converterPointer: pointing to converter
*
*******************************************************************************/
extern "C" void resetConverter(SsrcSampleConverterInstance *instanceOfConverter)
{
    if (instanceOfConverter != nullptr && instanceOfConverter->converterPointer != nullptr)
    {
        instanceOfConverter->converterPointer->reset(0);
    }
}

/********************************************************************************
* clear the structure (after memory allocation)
* input :
*        SsrcSampleConverterInstance
*        
*******************************************************************************/
extern "C" void clearInstanceOfConverterStruct( SsrcSampleConverterInstance *instanceOfConverter)
{
    memset((void *)instanceOfConverter,0,sizeof(SsrcSampleConverterInstance));
}

/********************************************************************************
* get input queue fulness
*
* output :
*        number of samples currently in input queue
*
*******************************************************************************/
extern "C" int inputFulness(SsrcSampleRateConverterInterface  *converterPointer)
{
    return converterPointer->inputFulness();
}
/********************************************************************************
* get output queue fulness
*
* output :
*        number of samples currently in output queue
*
*******************************************************************************/
extern "C" int outputFulness(SsrcSampleRateConverterInterface *converterPointer)
{
    return converterPointer->outputFulness();
}
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
SSRCSamplingRatesRatio samplingRatesRatio[NumberOfSampleRatesSupported][NumberOfSampleRatesSupported] =
{
    /* 8000  */  /* 11025   */ /* 12000   */ /* 16000   */ /* 22050   */ /* 24000   */ /* 32000   */ /* 44100   */ /* 48000   */ /* 64000   */ /* 88200   */ /* 96000   */ /* 128000  */ /* 176400  */ /* 192000  */ /* 256000  */ /* 352800  */ /* 384000  */  /* 768000  */
    /* 8000   */  {{    1,    1},{  320,  441},{    2,    3},{    1,    2},{  160,  441},{    1,    3},{    1,    4},{   80,  441},{    1,    6},{    1,    8},{   40,  441},{    1,   12},{    1,   16},{   20,  441},{    1,   24},{    1,   32},{   10,  441},{    1,   48},{    1,   96}},
    /* 11025  */  {{  441,  320},{    1,    1},{  147,  160},{  441,  640},{    1,    2},{  147,  320},{  441, 1280},{    1,    4},{  147,  640},{  441, 2560},{    1,    8},{  147, 1280},{  441, 5120},{    1,   16},{  147, 2560},{  441,10240},{    1,   32},{  147, 5120},{  147,10240}},
    /* 12000  */  {{    3,    2},{  160,  147},{    1,    1},{    3,    4},{   80,  147},{    1,    2},{    3,    8},{   40,  147},{    1,    4},{    3,   16},{   20,  147},{    1,    8},{    3,   32},{   10,  147},{    1,   16},{    3,   64},{    5,  147},{    1,   32},{    1,   64}},
    /* 16000  */  {{    2,    1},{  640,  441},{    4,    3},{    1,    1},{  320,  441},{    2,    3},{    1,    2},{  160,  441},{    1,    3},{    1,    4},{   80,  441},{    1,    6},{    1,    8},{   40,  441},{    1,   12},{    1,   16},{   20,  441},{    1,   24},{    1,   48}},
    /* 22050  */  {{  441,  160},{    2,    1},{  147,   80},{  441,  320},{    1,    1},{  147,  160},{  441,  640},{    1,    2},{  147,  320},{  441, 1280},{    1,    4},{  147,  640},{  441, 2560},{    1,    8},{  147, 1280},{  441, 5120},{    1,   16},{  147, 2560},{  147, 5120}},
    /* 24000  */  {{    3,    1},{  320,  147},{    2,    1},{    3,    2},{  160,  147},{    1,    1},{    3,    4},{   80,  147},{    1,    2},{    3,    8},{   40,  147},{    1,    4},{    3,   16},{   20,  147},{    1,    8},{    3,   32},{   10,  147},{    1,   16},{    1,   32}},
    /* 32000  */  {{    4,    1},{ 1280,  441},{    8,    3},{    2,    1},{  640,  441},{    4,    3},{    1,    1},{  320,  441},{    2,    3},{    1,    2},{  160,  441},{    1,    3},{    1,    4},{   80,  441},{    1,    6},{    1,    8},{   40,  441},{    1,   12},{    1,   24}},
    /* 44100  */  {{  441,   80},{    4,    1},{  147,   40},{  441,  160},{    2,    1},{  147,   80},{  441,  320},{    1,    1},{  147,  160},{  441,  640},{    1,    2},{  147,  320},{  441, 1280},{    1,    4},{  147,  640},{  441, 2560},{    1,    8},{  147, 1280},{  147, 2560}},
    /* 48000  */  {{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  320,  147},{    2,    1},{    3,    2},{  160,  147},{    1,    1},{    3,    4},{   80,  147},{    1,    2},{    3,    8},{   40,  147},{    1,    4},{    3,   16},{   20,  147},{    1,    8},{    1,   16}},
    /* 64000  */  {{    8,    1},{ 2560,  441},{   16,    3},{    4,    1},{ 1280,  441},{    8,    3},{    2,    1},{  640,  441},{    4,    3},{    1,    1},{  320,  441},{    2,    3},{    1,    2},{  160,  441},{    1,    3},{    1,    4},{   80,  441},{    1,    6},{    1,   12}},
    /* 88200  */  {{  441,   40},{    8,    1},{  147,   20},{  441,   80},{    4,    1},{  147,   40},{  441,  160},{    2,    1},{  147,   80},{  441,  320},{    1,    1},{  147,  160},{  441,  640},{    1,    2},{  147,  320},{  441, 1280},{    1,    4},{  147,  640},{  147, 1280}},
    /* 96000  */  {{   12,    1},{ 1280,  147},{    8,    1},{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  320,  147},{    2,    1},{    3,    2},{  160,  147},{    1,    1},{    3,    4},{   80,  147},{    1,    2},{    3,    8},{   40,  147},{    1,    4},{    1,    8}},
    /* 128000 */  {{   16,    1},{ 5120,  441},{   32,    3},{    8,    1},{ 2560,  441},{   16,    3},{    4,    1},{ 1280,  441},{    8,    3},{    2,    1},{  640,  441},{    4,    3},{    1,    1},{  320,  441},{    2,    3},{    1,    2},{  160,  441},{    1,    3},{    1,    6}},
    /* 176400 */  {{  441,   20},{   16,    1},{  147,   10},{  441,   40},{    8,    1},{  147,   20},{  441,   80},{    4,    1},{  147,   40},{  441,  160},{    2,    1},{  147,   80},{  441,  320},{    1,    1},{  147,  160},{  441,  640},{    1,    2},{  147,  320},{  147,  640}},
    /* 192000 */  {{   24,    1},{ 2560,  147},{   16,    1},{   12,    1},{ 1280,  147},{    8,    1},{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  320,  147},{    2,    1},{    3,    2},{  160,  147},{    1,    1},{    3,    4},{   80,  147},{    1,    2},{    1,    4}},
    /* 256000 */  {{   32,    1},{10240,  441},{   64,    3},{   16,    1},{ 5120,  441},{   32,    3},{    8,    1},{ 2560,  441},{   16,    3},{    4,    1},{ 1280,  441},{    8,    3},{    2,    1},{  640,  441},{    4,    3},{    1,    1},{  320,  441},{    2,    3},{    1,    3}},
    /* 352800 */  {{  441,   10},{   32,    1},{  147,    5},{  441,   20},{   16,    1},{  147,   10},{  441,   40},{    8,    1},{  147,   20},{  441,   80},{    4,    1},{  147,   40},{  441,  160},{    2,    1},{  147,   80},{  441,  320},{    1,    1},{  147,  160},{  147,  320}},
    /* 384000 */  {{   48,    1},{ 5120,  147},{   32,    1},{   24,    1},{ 2560,  147},{   16,    1},{   12,    1},{ 1280,  147},{    8,    1},{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  320,  147},{    2,    1},{    3,    2},{  160,  147},{    1,    1},{    1,    2}},
    /* 768000 */  {{   96,    1},{10240,  147},{   64,    1},{   48,    1},{ 5120,  147},{   32,    1},{   24,    1},{ 2560,  147},{   16,    1},{   12,    1},{ 1280,  147},{    8,    1},{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  160,  147},{    2,    1},{    1,    1}}
};
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
unsigned samplingRateList[NumberOfSampleRatesSupported] =
{
    8000,
    11025,
    12000,
    16000,
    22050,
    24000,
    32000,
    44100,
    48000,
    64000,
    88200,
    96000,
    128000,
    176400,
    192000,
    256000,
    352800,
    384000,
    768000
};
