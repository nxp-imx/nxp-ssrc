/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcConverterAccess.h"
#include "ssrcSampleRateConverter.h"
/********************************************************************************
*
*
*******************************************************************************/
bool LoadSharedObjectLib::openDL(QuantizedFitlerEntry &fitlerDef, SsrcLog &log)
{
    if (usingDLL)
    {
        if (!loadSharedLib(fitlerDef, log))
        {
            return false;
        }
        fitlerDef.filter = (uint32_t *)fitlerDef.symbolPointerInLib;
    }
    return true;
}
/********************************************************************************
*
*
*******************************************************************************/
bool LoadSharedObjectLib::openDL(SsrcSampleRateConverterDefinition &interpDef, SsrcLog &log)
{
    if (usingDLL)
    {
        if (!loadSharedLib(interpDef, log))
        {
            return false;
        }
        interpDef.constructor = (SsrcSampleRateConverterInterface *(*)(SsrcSampleRateConverterDefinition *))interpDef.symbolPointerInLib;
    }
    return true;

}
/********************************************************************************
*
*
*******************************************************************************/
bool LoadSharedObjectLib::closeDL(QuantizedFitlerEntry &fitlerDef)
{
    if (usingDLL)
    {
        unloadSharedLib(fitlerDef);
    }
    return true;
}
/********************************************************************************
*
*
*******************************************************************************/
bool LoadSharedObjectLib::closeDL(SsrcSampleRateConverterDefinition &interpDef)
{
    if (usingDLL)
    {
        unloadSharedLib(interpDef);
    }
    return true;
}
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
const QuantizedFitlerEntry *
InterpolationFilterList::
getInterpolationFilter(SsrcSampleRateConverterInfo &resamplerInfo)
{
    unsigned numberOfFilter = getNumberOfFilters();
    for (unsigned index = 0; index < numberOfFilter; index++)
    {
        QuantizedFitlerEntry &filter = quantizedFitlerList[index];

        if (
            filter.sampleRateRatioInput == resamplerInfo.sampleRateRatioInput &&
            filter.sampleRateRatioOutput == resamplerInfo.sampleRateRatioOutput &&
            filter.numberOftapsPerPhase == resamplerInfo.numberOftapsPerPhase &&
            filter.sampleFormat == resamplerInfo.sampleFormat
            )
        {
            if (LoadSharedObjectLib::openDL(filter, resamplerInfo.log) == false)
            {
                return nullptr;
            }
            return resamplerInfo.interpolationFilter = &filter;
        }

    }
    return nullptr;
}
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
const QuantizedFitlerEntry *
InterpolationFilterList::
getInterpolationFilter(int index)
{
	unsigned numberOfFilter = getNumberOfFilters();
	if (index < numberOfFilter)
	{
		QuantizedFitlerEntry &filter = quantizedFitlerList[index];
		return &filter;
	}
	return nullptr;
}
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
void 
InterpolationFilterList::
destruct()
{
    unsigned numberOfFilter = getNumberOfFilters();
    for (unsigned index = 0; index < numberOfFilter; index++)
    {
        QuantizedFitlerEntry &filter = quantizedFitlerList[index];

        if (
            filter.libHandle != nullptr
            )
        {
            LoadSharedObjectLib::closeDL(filter);
        }

    }
}






/********************************************************************************
* init
*
*******************************************************************************/
SsrcSampleRateConverterList::
SsrcSampleRateConverterList()
{
}
/********************************************************************************
* cleanup
*
*******************************************************************************/
SsrcSampleRateConverterList::
~SsrcSampleRateConverterList()
{
    destruct();
}
/********************************************************************************
*  delete all loaded DLL, if in dll mode
*
*******************************************************************************/
void SsrcSampleRateConverterList::
destruct()
{
    if (usingDLL)
    {
        unsigned listSize = getNumberOfConverters();
        for (unsigned index = 0; index < listSize; index++)
        {
            SsrcSampleRateConverterDefinition &definition = sampleRateConverterList[index];
            if (definition.libHandle != nullptr)
            {
                LoadSharedObjectLib::closeDL(definition);
                definition.libHandle = nullptr;
                definition.constructor = nullptr;
            }
        }
        InterpolationFilterList::destruct();
    }
}
/********************************************************************************
*  get a converter by index
*
*******************************************************************************/
SsrcSampleRateConverterDefinition * SsrcSampleRateConverterList::
getConverter(int index)
{
	int numberOfconverters = getNumberOfConverters();
	if (index < numberOfconverters)
	{
		return &sampleRateConverterList[index];
	}
	return nullptr;
}

/********************************************************************************
*  get a converter according to the info given
*  return false if cant find a converter withthe given spec
*******************************************************************************/
bool SsrcSampleRateConverterList::
getConverter(SsrcConfig &config, SsrcSampleRateConverterInfo &resamplerInfo)
{
    // convert input/output sample rate ratio to ratio
    // if the ratio doesnt not exist, exit
    SSRCSamplingRatesRatio ratio;
    static_cast<SsrcConfig &>(resamplerInfo) = config;
    if (!getSampleRateRatio(config.inputSampleRate, config.outputSampleRate, ratio))
    {
        resamplerInfo.log.add("ERROR: sampling rates and/or sampling rate ratio not supported ");
        return false;
    }
    // search sample converter table for the given converter
    // and make a list of all the converters that match 
    unsigned listSize = getNumberOfConverters();
    SsrcSampleRateConverterDefinition *definitionList[SsrcResampleConversionQuality_not_set] = { nullptr,nullptr,nullptr };
    int qualityCount = 0;
    for (unsigned index = 0; index < listSize && qualityCount < SsrcResampleConversionQuality_not_set; index++)
    {
        SsrcSampleRateConverterDefinition &definition = sampleRateConverterList[index];
        if (
            definition.sampleRateRatioInput == ratio.inputSampleRate &&
            definition.sampleRateRatioOutput == ratio.outputSampleRate &&
            definition.numberOfChannels == (config.stereo + 1) &&
            (definition.numberOftapsPerPhase == config.requestedInterpolationNumberOfTaps || config.requestedInterpolationNumberOfTaps == 0) &&
            definition.sampleFormat == config.requestedSampleFormat
            )
        {
            definitionList[qualityCount] = &definition;
            qualityCount++;

        }
    }
    // if 
    if (qualityCount != 0)
    {
        for (unsigned end = qualityCount - 1; end > 0; end--)
        {
            for (unsigned index = 0; index < end; index++)
            {
                if (definitionList[index]->numberOftapsPerPhase > definitionList[index + 1]->numberOftapsPerPhase)
                {
                    SsrcSampleRateConverterDefinition *swap = definitionList[index + 1];
                    definitionList[index + 1] = definitionList[index];
                    definitionList[index] = swap;
                }
            }
        }
        int qualityIndex = 0;
        if (config.sampleRateConversionQuality < qualityCount)
        {
            qualityIndex = config.sampleRateConversionQuality;
        }
        SsrcSampleRateConverterDefinition &definition = *definitionList[qualityIndex];
        if (!LoadSharedObjectLib::openDL(definition, resamplerInfo.log))
        {
            return false;
        }

        if (definition.constructor == nullptr)
        {
            resamplerInfo.log.add("ERROR: sample rate conversion constructor is nullptr ");
            return false;
        }
        SsrcSampleRateConverterDefinition converterDefintion = definition;
        resamplerInfo.converterPointer = definition.constructor(&converterDefintion);
        static_cast <SsrcSampleRateConverterDefinition &>(resamplerInfo) = converterDefintion;

        if (resamplerInfo.converterPointer == nullptr)
        {
            resamplerInfo.log.add("ERROR: sampling rate conversion not supported ");
            return false;
        }

        InterpolationFilterList::getInterpolationFilter(resamplerInfo);

        if (resamplerInfo.interpolationFilter == nullptr)
        {
            resamplerInfo.log.add("ERROR: sampling rate conversion not supported ");
            return false;
        }
        if (!resamplerInfo.converterPointer->configure(resamplerInfo))
        {
            delete resamplerInfo.converterPointer;
            resamplerInfo.log.add("ERROR: sampling rate conversion configuration error");
            return false;
        }
        return true;
    }
    resamplerInfo.log.add("ERROR: sampling rate conversion not supported ");
    return false;
}
/********************************************************************************
*  get sample rate index
*
*******************************************************************************/
bool SsrcSampleRateConverterList::
getSampleRateIndex(unsigned sampleRate, unsigned &index)
{
    for (index = 0; index < NumberOfSampleRatesSupported; index++)
    {
        if (samplingRateList[index] == sampleRate)
        {
            return true;
        }
    }
    index = 0;
    return false;
}
/********************************************************************************
*  get sample rate ratio
*
*******************************************************************************/
bool SsrcSampleRateConverterList::
getSampleRateRatio(unsigned inputSampleRate, unsigned outputSampleRate, SSRCSamplingRatesRatio &output)
{
    unsigned inputSRIndex = 0;
    if (!getSampleRateIndex(inputSampleRate, inputSRIndex))
    {
        return false;
    }
    unsigned outputSRIndex = 0;
    if (!getSampleRateIndex(outputSampleRate, outputSRIndex))
    {
        return false;
    }
    output = samplingRatesRatio[inputSRIndex][outputSRIndex];
    return true;
}



/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
const SSRCSamplingRatesRatio SsrcSampleRateConverterList::samplingRatesRatio[NumberOfSampleRatesSupported][NumberOfSampleRatesSupported] =
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
    /* 768000 */  {{   96,    1},{10240,  147},{   64,    1},{   48,    1},{ 5120,  147},{   32,    1},{   24,    1},{ 2560,  147},{   16,    1},{   12,    1},{ 1280,  147},{    8,    1},{    6,    1},{  640,  147},{    4,    1},{    3,    1},{  320,  147},{    2,    1},{    1,    1}}
};
/*!******************************************************************************************
 **
 **
 **
 *******************************************************************************************/
const unsigned SsrcSampleRateConverterList::samplingRateList[NumberOfSampleRatesSupported] =
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


