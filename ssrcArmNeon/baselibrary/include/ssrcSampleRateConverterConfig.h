/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcSampleRateConverterConfig_h
#define ssrcSampleRateConverterConfig_h
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>
#include "ssrcCInterface.h"
/********************************************************************************
* This is not used
*
*******************************************************************************/
enum TARGETS
{
    TARGET_ARM,
    TARGET_C_LINUX,
    TARGET_C_MS
};

/********************************************************************************
*  Compiled for DLL mode or static library
*
*******************************************************************************/
#ifdef DLL_COMPILE_MODE
static bool usingDLL = true;
#else
static bool usingDLL = false;
#endif

/********************************************************************************
*
*
*******************************************************************************/
static const int NumberOfSampleRatesSupported = 19;
/********************************************************************************
* A constant string list to return list of errors when configuration fails
*
*******************************************************************************/
struct SsrcLog
{
    int index;
    static const int maxListSize = 128;
    const char *list[maxListSize];
    /********************************************************************************
   *   clear the object
   *
   *******************************************************************************/
    SsrcLog()
    {
        index = 0;
        for (int pos = 0; pos < maxListSize; pos++)
        {
            list[pos] = nullptr;
        }
    }
    /********************************************************************************
    * add a string to the list of messages
    *
    *******************************************************************************/
    void add(const char* in)
    {
        if (index < maxListSize)
        {
            list[index] = in;
            index++;
        }
    }

};
/********************************************************************************
*  ssrc filter information
*
*******************************************************************************/
struct SsrcFilterInfo
{
    unsigned numberOfZeroExtension;     // zero extesion required by interpolation process
    unsigned totalNumberOfTaps;         // interpolation filter number of taps + zero extension
    unsigned numberOfTaps;              // interpolation filter number of taps
    unsigned numberOfPhases;            // number of phases

    int32_t *filterTaps;                // filter taps array  
    int32_t*filterTapsWithZero;         // fiter taps array with zero extension
    QuantizedFitlerEntry * interpolationFilter; // filter definition
};
/********************************************************************************
* sample rate converter process information
*
*******************************************************************************/
struct SsrcSampleRateConverterInfo:
    public SsrcConfig,
    public SsrcSampleRateConverterDefinition
{
    SsrcLog log;
    SsrcSampleRateConverterInterface *converterPointer; // converter objct pointer
    const QuantizedFitlerEntry * interpolationFilter;   // filter object pointer
    /********************************************************************************
    * constructor, clear object
    *
    *******************************************************************************/
    SsrcSampleRateConverterInfo()
    {
        clear();
        converterPointer = nullptr;
        interpolationFilter = nullptr;
    }
    /********************************************************************************
    * clear object
    *
    *******************************************************************************/
    void clear()
    {
        sampleRateConverterNo = 0;
        sampleRateRatioInput = 0;
        sampleRateRatioOutput = 0;
        numberOftapsPerPhase = 0;
        numberOfTapsRedPerReadCycle = 0;
        numberOfSamplesUsedPerRunPerChan = 0;
        totalNumberOfSamplesUsedPerRun = 0;
        totalNumOutputSamplesPerRun = 0;
        stereo = false;
        numOutputSamplesPerChanPerRun = 0;
        numberOfChannels = 0;
    }
    /********************************************************************************
    * get the converter
    *
    *******************************************************************************/
    bool getConverterObject(SsrcSampleRateConverterInterface * (&output))
    {
        output = converterPointer;
        return converterPointer != nullptr;
    }
    /********************************************************************************
    * equal operator
    *
    *******************************************************************************/
    void operator = (SsrcSampleRateConverterInfo & _in)
    {
        SsrcSampleRateConverterDefinition &out = static_cast<SsrcSampleRateConverterDefinition &>( *this);
        SsrcSampleRateConverterDefinition &in = static_cast<SsrcSampleRateConverterDefinition &> ( _in);
        out = in;

    }

};
/********************************************************************************
*  sample rate converter interface class
*
*******************************************************************************/
struct SsrcSampleRateConverterInterface :
    public SsrcSampleRateConverterInfo
{
public:
    /********************************************************************************
    * destructor delete all allocated memory
    *
    *******************************************************************************/
    virtual ~SsrcSampleRateConverterInterface()
    {
    }
    void * operator new(size_t size)
    {
        void * p = malloc(size);

        return p;
    }
    void operator delete(void * p)
    {
        free(p);
    }


    /********************************************************************************
    *  generate on set of output 
    *  return :
    *           false : converter not ready to process samples
    *           true : converter process samples and generated output samples
    *******************************************************************************/
    virtual bool process()
    {
        return false;
    }
    /********************************************************************************
    * get a chunck size data from converter output queue
    *  input:
    *          data = pointer to output chunck size buffer to transfer output data to
    *  return :
    *           false : not enough samples in output queue 
    *           true  : buffer 'data' has chunck size output samples
    *******************************************************************************/
    virtual bool get(int32_t *data)
    {
        return false;
    }
    /********************************************************************************
    * get a chunck size data from converter output queue
    *  input:
    *          data = pointer to output chunck size buffer to transfer output data to
    *  return :
    *           false : not enough samples in output queue
    *           true  : buffer 'data' has chunck size output samples
    *******************************************************************************/
    virtual bool get_FloatToInt(int32_t *data)
    {
        return false;
    }
    /********************************************************************************
    * put a chunck size data into converter input queue
    *  input:
    *          data = pointer to input chunck size buffer to transfer output data from
    *  return :
    *           false : input queue doesn't have enough empty space to transfer data
    *           true  : data from 'data' buffer was transferd to input queue
    *******************************************************************************/
    virtual bool put(int32_t *data)
    {
        return false;
    }
    /********************************************************************************
    * put a chunck size data into converter input queue
    *  input:
    *          data = pointer to input chunck size buffer to transfer output data from
    *  return :
    *           false : input queue doesn't have enough empty space to transfer data
    *           true  : data from 'data' buffer was transferd to input queue
    *******************************************************************************/
    virtual bool put_IntToFloat(int32_t *data)
    {
        return false;
    }
    /********************************************************************************
    * get a chunck size data from converter output queue
    *  input:
    *          data = pointer to output chunck size buffer to transfer output data to
    *  return :
    *           false : not enough samples in output queue
    *           true  : buffer 'data' has chunck size output samples
    *******************************************************************************/
    virtual bool get(float *data)
    {
        return false;
    }
    /********************************************************************************
    * get a chunck size data from converter output queue
    *  input:
    *          data = pointer to output chunck size buffer to transfer output data to
    *  return :
    *           false : not enough samples in output queue
    *           true  : buffer 'data' has chunck size output samples
    *******************************************************************************/
    virtual bool get_FloatToInt(float *data)
    {
        return false;
    }
    /********************************************************************************
    * put a chunck size data into converter input queue
    *  input:
    *          data = pointer to input chunck size buffer to transfer output data from
    *  return :
    *           false : input queue doesn't have enough empty space to transfer data
    *           true  : data from 'data' buffer was transferd to input queue
    *******************************************************************************/
    virtual bool put(float *data)
    {
        return false;
    }
    /********************************************************************************
    * put a chunck size data into converter input queue
    *  input:
    *          data = pointer to input chunck size buffer to transfer output data from
    *  return :
    *           false : input queue doesn't have enough empty space to transfer data
    *           true  : data from 'data' buffer was transferd to input queue
    *******************************************************************************/
    virtual bool put_IntToFloat(float *data)
    {
        return false;
    }
    /********************************************************************************
    * is ther enough samples input queue to generate a set of output samples
    *    return:
    *            false : if not egough samples
    *            true  : if if there is enough samples
    *******************************************************************************/
    virtual bool haveEnoughSamplesToProcess()
    {
        return false;
    }
    /********************************************************************************
    * is there at least a output chunck size output samples in output queue
    *     return:
    *             false : if not an least output chunck size output samples in output queue
    *             true  : if there is at lest a chunk size number of output samples available
    *******************************************************************************/
    virtual bool haveEnoughOutputSamples()
    {
        return false;
    }
    /********************************************************************************
    *     get sample converter info
    *       input:
    *           ssrcInfo : reference to buffer to put the information
    *       output:
    *           ssrcInfo : filled with converter information
    *******************************************************************************/
    virtual bool getInfo(SsrcSampleRateConverterInfo &ssrcInfo)
    {
        return false;
    };
    /********************************************************************************
    * configure sample rate converter 
    *    input:
    *           config : configuration setting for sample rate conversion
    *    output:
    *          false : if configuration failed
    *          true : if configuration was sucessful
    *******************************************************************************/
    virtual bool configure(SsrcSampleRateConverterInfo &config)
    {
        return false;
    }
    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual bool getFilterInfo(SsrcFilterInfo &ret)
    {
        return false;
    }
    /********************************************************************************
    *  reset the converter to initial state by restting input/output queue
    *    input:
    *           phase : phase number to reset to
    *
     *******************************************************************************/
    virtual void reset(unsigned phase)
    {
        return ;
    }
    /********************************************************************************
    * get input queue fulness
    *
    * output :
    *        number of samples currently in input queue
    *
    *******************************************************************************/
    virtual int inputFulness()
    {
        return 0;
    }
    /********************************************************************************
    * get output queue fulness
    *
    * output :
    *        number of samples currently in output queue
    *
    *******************************************************************************/
    virtual int outputFulness()
    {
        return 0;
    }

};

extern SSRCSamplingRatesRatio samplingRatesRatio[NumberOfSampleRatesSupported][NumberOfSampleRatesSupported];
extern unsigned samplingRateList[NumberOfSampleRatesSupported];


#endif
