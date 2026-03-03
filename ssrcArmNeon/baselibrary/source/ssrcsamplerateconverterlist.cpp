/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcSampleRateConverter.h"
#include "ssrcsamplerateconverterlist.h"
unsigned SsrcSampleRateConverterList::getNumberOfConverters()
{
    return sampleRateConverterListSize;
}
SsrcSampleRateConverterDefinition SsrcSampleRateConverterList::sampleRateConverterList[sampleRateConverterListSize] = 
{
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        468, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        469, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        470, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        471, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        472, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_160_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_160_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        473, // sampleRateConverterNo
        147, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        474, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        475, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        476, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        477, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        478, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_4_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_4_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        479, // sampleRateConverterNo
        3, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        480, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        481, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        482, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        483, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        484, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        485, // sampleRateConverterNo
        320, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        486, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        487, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        488, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        489, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        490, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_640_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_640_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        491, // sampleRateConverterNo
        441, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        492, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        493, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        494, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        495, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        496, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_3_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        497, // sampleRateConverterNo
        2, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        498, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        499, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        500, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        501, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        502, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_147_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_147_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        503, // sampleRateConverterNo
        80, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        504, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        505, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        506, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        507, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        508, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_2_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_2_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        509, // sampleRateConverterNo
        1, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        510, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        511, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        512, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        513, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        514, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_320_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_320_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        515, // sampleRateConverterNo
        147, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        516, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        517, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        518, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        519, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        520, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_8_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_8_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        521, // sampleRateConverterNo
        3, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        522, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        523, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        524, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        525, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        526, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        527, // sampleRateConverterNo
        160, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        528, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        529, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        530, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        531, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        532, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1280_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1280_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        533, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        534, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        535, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        536, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        537, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        538, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_3_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_3_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        539, // sampleRateConverterNo
        1, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        540, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        541, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        542, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        543, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        544, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_147_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_147_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        545, // sampleRateConverterNo
        40, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        546, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        547, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        548, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        549, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        550, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_4_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_4_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        551, // sampleRateConverterNo
        1, // sampleRateRatioInput
        4, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        552, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        553, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        554, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        555, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        556, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_640_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_640_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        557, // sampleRateConverterNo
        147, // sampleRateRatioInput
        640, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        558, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        559, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        560, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        561, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        562, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_16_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_16_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        563, // sampleRateConverterNo
        3, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        564, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        565, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        566, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        567, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        568, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_80_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_80_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        569, // sampleRateConverterNo
        80, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        570, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        571, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        572, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        573, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        574, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_2560_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_2560_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        575, // sampleRateConverterNo
        441, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        576, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        577, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        578, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        579, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        580, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_6_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_6_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        581, // sampleRateConverterNo
        1, // sampleRateRatioInput
        6, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        582, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        583, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        584, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        585, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        586, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_147_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_147_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        587, // sampleRateConverterNo
        20, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        588, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        589, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        590, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        591, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        592, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_8_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_8_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        593, // sampleRateConverterNo
        1, // sampleRateRatioInput
        8, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        594, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        595, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        596, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        597, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        598, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_1280_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_1280_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        599, // sampleRateConverterNo
        147, // sampleRateRatioInput
        1280, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        600, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        601, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        602, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        603, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        604, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_32_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_32_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        605, // sampleRateConverterNo
        3, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        606, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        607, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        608, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        609, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        610, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_40_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_40_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        611, // sampleRateConverterNo
        40, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        612, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        613, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        614, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        615, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        616, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_5120_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_5120_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        617, // sampleRateConverterNo
        441, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        618, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        619, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        620, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        621, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        622, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_12_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_12_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        623, // sampleRateConverterNo
        1, // sampleRateRatioInput
        12, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        624, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        625, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        626, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        627, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        628, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_147_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_147_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        629, // sampleRateConverterNo
        10, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        630, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        631, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        632, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        633, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        634, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_16_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_16_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        635, // sampleRateConverterNo
        1, // sampleRateRatioInput
        16, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        636, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        637, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        638, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        639, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        640, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_2560_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_2560_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        641, // sampleRateConverterNo
        147, // sampleRateRatioInput
        2560, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        642, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        643, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        644, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        645, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        646, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_64_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_64_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        647, // sampleRateConverterNo
        3, // sampleRateRatioInput
        64, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        648, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        649, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        650, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        651, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        652, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_20_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_20_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        653, // sampleRateConverterNo
        20, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        654, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        655, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        656, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        657, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        658, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_1024_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_1024_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        659, // sampleRateConverterNo
        441, // sampleRateRatioInput
        1024, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        660, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        661, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        662, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        663, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        664, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_24_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_24_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        665, // sampleRateConverterNo
        1, // sampleRateRatioInput
        24, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        666, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        667, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        668, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        669, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        670, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5_outsr_147_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5_outsr_147_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        671, // sampleRateConverterNo
        5, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        672, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        673, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        674, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        675, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        676, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_32_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_32_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        677, // sampleRateConverterNo
        1, // sampleRateRatioInput
        32, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        678, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        679, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        680, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        681, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        682, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5120_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5120_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        683, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5120, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        684, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        685, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        686, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        687, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        688, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_10_outsr_441_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_10_outsr_441_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        689, // sampleRateConverterNo
        10, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        690, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        691, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        692, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        693, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        694, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_48_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_48_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        695, // sampleRateConverterNo
        1, // sampleRateRatioInput
        48, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        696, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        697, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        698, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        699, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_88_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_88_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_88_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        700, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1_outsr_96_taps_88_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_88_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1_outsr_96_taps_88_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        701, // sampleRateConverterNo
        1, // sampleRateRatioInput
        96, // sampleRateRatioOutput
        88, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_120_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_120_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_120_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        702, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        120, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_120_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_120_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_120_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        703, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        120, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_104_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_104_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_104_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        704, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        104, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_104_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_104_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_104_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        705, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        104, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_96_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_96_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_96_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        706, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_160_outsr_147_taps_96_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_96_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_160_outsr_147_taps_96_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        707, // sampleRateConverterNo
        160, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        96, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_152_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_152_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_152_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        708, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_152_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_152_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_152_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        709, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_128_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_128_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_128_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        710, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_128_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_128_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_128_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        711, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_112_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_112_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_112_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        712, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_3_taps_112_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_112_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_3_taps_112_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        713, // sampleRateConverterNo
        4, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        112, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_152_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_152_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_152_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        714, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_152_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_152_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_152_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        715, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_128_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_128_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_128_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        716, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_128_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_128_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_128_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        717, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_120_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_120_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_120_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        718, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        120, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_320_taps_120_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_120_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_320_taps_120_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        719, // sampleRateConverterNo
        441, // sampleRateRatioInput
        320, // sampleRateRatioOutput
        120, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_160_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_160_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_160_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        720, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        160, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_160_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_160_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_160_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        721, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        160, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_136_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_136_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_136_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        722, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        136, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_136_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_136_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_136_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        723, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        136, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_128_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_128_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_128_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        724, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_441_taps_128_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_128_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_441_taps_128_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        725, // sampleRateConverterNo
        640, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_168_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_168_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_168_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        726, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        168, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_168_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_168_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_168_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        727, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        168, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_144_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        728, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        144, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_144_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_144_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_144_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        729, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        144, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_128_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_128_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_128_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        730, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_2_taps_128_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_128_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_128_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        731, // sampleRateConverterNo
        3, // sampleRateRatioInput
        2, // sampleRateRatioOutput
        128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_208_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_208_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_208_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        732, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        208, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_208_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_208_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_208_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        733, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        208, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_176_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_176_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_176_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        734, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_176_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_176_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_176_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        735, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_160_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_160_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_160_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        736, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        160, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_80_taps_160_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_160_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_80_taps_160_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        737, // sampleRateConverterNo
        147, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        160, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_224_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_224_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_224_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        738, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        224, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_224_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_224_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_224_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        739, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        224, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_192_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_192_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_192_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        740, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_192_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_192_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_192_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        741, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_176_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_176_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_176_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        742, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2_outsr_1_taps_176_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_176_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2_outsr_1_taps_176_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        743, // sampleRateConverterNo
        2, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_248_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_248_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_248_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        744, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_248_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_248_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_248_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        745, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_208_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_208_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_208_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        746, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        208, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_208_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_208_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_208_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        747, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        208, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_192_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_192_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_192_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        748, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_320_outsr_147_taps_192_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_192_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_320_outsr_147_taps_192_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        749, // sampleRateConverterNo
        320, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_288_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_288_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_288_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        750, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        288, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_288_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_288_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_288_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        751, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        288, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_248_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_248_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_248_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        752, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_248_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_248_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_248_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        753, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_224_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_224_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_224_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        754, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        224, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_3_taps_224_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_224_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_3_taps_224_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        755, // sampleRateConverterNo
        8, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        224, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_304_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_304_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_304_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        756, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        304, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_304_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_304_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_304_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        757, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        304, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_256_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_256_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_256_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        758, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_256_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_256_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_256_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        759, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_232_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_232_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_232_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        760, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        232, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_160_taps_232_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_232_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_160_taps_232_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        761, // sampleRateConverterNo
        441, // sampleRateRatioInput
        160, // sampleRateRatioOutput
        232, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_320_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_320_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_320_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        762, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        320, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_320_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_320_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_320_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        763, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        320, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_272_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_272_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_272_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        764, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        272, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_272_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_272_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_272_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        765, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        272, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_248_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_248_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_248_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        766, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_441_taps_248_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_248_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_441_taps_248_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        767, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        248, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_328_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_328_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_328_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        768, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        328, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_328_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        769, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        328, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_280_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_280_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_280_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        770, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        280, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_280_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_280_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_280_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        771, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        280, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_256_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_256_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_256_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        772, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_3_outsr_1_taps_256_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_256_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_256_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        773, // sampleRateConverterNo
        3, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_400_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_400_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_400_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        774, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        400, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_400_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_400_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_400_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        775, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        400, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_344_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_344_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_344_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        776, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        344, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_344_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_344_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_344_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        777, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        344, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_312_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_312_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_312_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        778, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        312, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_40_taps_312_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_312_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_40_taps_312_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        779, // sampleRateConverterNo
        147, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        312, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_440_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_440_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_440_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        780, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        440, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_440_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_440_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_440_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        781, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        440, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_376_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_376_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_376_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        782, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        376, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_376_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_376_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_376_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        783, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        376, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_336_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        784, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        336, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_4_outsr_1_taps_336_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_336_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_336_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        785, // sampleRateConverterNo
        4, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        336, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_480_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_480_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_480_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        786, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        480, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_480_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_480_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_480_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        787, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        480, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_408_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_408_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_408_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        788, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        408, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_408_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_408_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_408_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        789, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        408, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_368_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_368_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_368_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        790, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        368, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_640_outsr_147_taps_368_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_368_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_640_outsr_147_taps_368_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        791, // sampleRateConverterNo
        640, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        368, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_584_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_584_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_584_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        792, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        584, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_584_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_584_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_584_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        793, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        584, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_496_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_496_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_496_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        794, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        496, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_496_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_496_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_496_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        795, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        496, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_456_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_456_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_456_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        796, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        456, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_3_taps_456_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_456_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_3_taps_456_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        797, // sampleRateConverterNo
        16, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        456, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_608_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_608_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_608_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        798, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        608, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_608_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_608_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_608_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        799, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        608, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_512_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_512_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_512_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        800, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        512, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_512_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_512_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_512_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        801, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        512, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_464_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_464_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_464_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        802, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        464, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_80_taps_464_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_464_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_80_taps_464_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        803, // sampleRateConverterNo
        441, // sampleRateRatioInput
        80, // sampleRateRatioOutput
        464, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_640_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_640_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_640_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        804, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        640, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_640_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_640_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_640_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        805, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        640, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_544_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_544_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_544_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        806, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        544, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_544_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_544_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_544_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        807, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        544, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_496_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_496_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_496_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        808, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        496, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_441_taps_496_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_496_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_441_taps_496_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        809, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        496, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_664_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_664_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_664_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        810, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        664, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_664_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_664_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_664_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        811, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        664, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_560_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_560_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_560_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        812, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        560, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_560_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_560_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_560_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        813, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        560, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_512_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_512_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_512_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        814, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        512, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_6_outsr_1_taps_512_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_512_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_6_outsr_1_taps_512_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        815, // sampleRateConverterNo
        6, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        512, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_808_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_808_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_808_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        816, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        808, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_808_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_808_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_808_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        817, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        808, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_688_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_688_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_688_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        818, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        688, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_688_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_688_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_688_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        819, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        688, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_624_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_624_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_624_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        820, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        624, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_20_taps_624_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_624_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_20_taps_624_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        821, // sampleRateConverterNo
        147, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        624, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_624_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_624_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_624_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        822, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        624, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_624_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_624_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_624_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        823, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        624, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_528_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_528_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_528_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        824, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        528, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_528_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_528_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_528_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        825, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        528, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_480_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_480_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_480_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        826, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        480, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_8_outsr_1_taps_480_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_480_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_8_outsr_1_taps_480_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        827, // sampleRateConverterNo
        8, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        480, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_936_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_936_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_936_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        828, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        936, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_936_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_936_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_936_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        829, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        936, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_800_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_800_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_800_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        830, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        800, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_800_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_800_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_800_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        831, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        800, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_728_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_728_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_728_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        832, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_12_outsr_1_taps_728_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_728_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_12_outsr_1_taps_728_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        833, // sampleRateConverterNo
        12, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_864_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_864_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_864_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        834, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        864, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_864_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_864_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_864_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        835, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        864, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_728_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_728_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_728_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        836, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_728_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_728_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_728_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        837, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_664_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_664_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_664_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        838, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        664, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_40_taps_664_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_664_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_40_taps_664_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        839, // sampleRateConverterNo
        441, // sampleRateRatioInput
        40, // sampleRateRatioOutput
        664, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_680_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        840, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        680, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_680_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        841, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        680, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_576_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_576_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_576_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        842, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        576, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_576_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_576_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_576_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        843, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        576, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_528_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_528_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_528_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        844, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        528, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1280_outsr_147_taps_528_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_528_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_528_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        845, // sampleRateConverterNo
        1280, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        528, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_832_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_832_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_832_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        846, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        832, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_832_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_832_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_832_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        847, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        832, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_704_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_704_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_704_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        848, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        704, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_704_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_704_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_704_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        849, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        704, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_640_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_640_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_640_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        850, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        640, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_3_taps_640_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_640_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_3_taps_640_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        851, // sampleRateConverterNo
        32, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        640, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_904_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_904_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_904_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        852, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        904, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_904_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_904_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_904_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        853, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        904, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_768_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_768_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_768_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        854, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        768, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_768_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_768_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_768_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        855, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        768, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_704_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_704_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_704_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        856, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        704, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_441_taps_704_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_704_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_441_taps_704_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        857, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        704, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_1152_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_1152_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_1152_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        858, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        1152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_1152_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_1152_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_1152_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        859, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        1152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_976_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_976_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_976_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        860, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        976, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_976_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_976_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_976_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        861, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        976, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_888_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_888_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_888_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        862, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        888, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_10_taps_888_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_888_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_10_taps_888_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        863, // sampleRateConverterNo
        147, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        888, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_1256_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1256_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1256_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        864, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_1256_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1256_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1256_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        865, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1256, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_1064_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1064_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1064_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        866, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1064, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_1064_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1064_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_1064_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        867, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1064, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_968_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_968_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_968_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        868, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        968, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_16_outsr_1_taps_968_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_968_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_16_outsr_1_taps_968_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        869, // sampleRateConverterNo
        16, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        968, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1360_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1360_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1360_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        870, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1360, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1360_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1360_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1360_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        871, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1360, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1152_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1152_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1152_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        872, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1152_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1152_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1152_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        873, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1048_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1048_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1048_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        874, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1048, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_2560_outsr_147_taps_1048_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1048_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_2560_outsr_147_taps_1048_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        875, // sampleRateConverterNo
        2560, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        1048, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1672_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1672_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1672_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        876, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1672, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1672_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1672_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1672_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        877, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1672, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1416_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1416_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1416_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        878, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1416, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1416_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1416_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1416_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        879, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1416, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1288_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1288_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1288_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        880, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1288, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_64_outsr_3_taps_1288_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1288_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_64_outsr_3_taps_1288_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        881, // sampleRateConverterNo
        64, // sampleRateRatioInput
        3, // sampleRateRatioOutput
        1288, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1728_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1728_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1728_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        882, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1728_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1728_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1728_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        883, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1464_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1464_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1464_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        884, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1464, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1464_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1464_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1464_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        885, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1464, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1336_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1336_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1336_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        886, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1336, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_20_taps_1336_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1336_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_20_taps_1336_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        887, // sampleRateConverterNo
        441, // sampleRateRatioInput
        20, // sampleRateRatioOutput
        1336, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_176_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        888, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_176_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        889, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        176, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_152_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_152_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_152_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        890, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_152_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_152_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_152_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        891, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        152, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_136_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        892, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        136, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_1024_outsr_441_taps_136_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        893, // sampleRateConverterNo
        1024, // sampleRateRatioInput
        441, // sampleRateRatioOutput
        136, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1880_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1880_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1880_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        894, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1880, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1880_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1880_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1880_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        895, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1880, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1592_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1592_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1592_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        896, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1592, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1592_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1592_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1592_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        897, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1592, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1448_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1448_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1448_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        898, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1448, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_24_outsr_1_taps_1448_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1448_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_24_outsr_1_taps_1448_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        899, // sampleRateConverterNo
        24, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1448, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_2304_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_2304_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_2304_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        900, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        2304, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_2304_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_2304_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_2304_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        901, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        2304, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_1952_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1952_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1952_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        902, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        1952, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_1952_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1952_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1952_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        903, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        1952, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_1776_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1776_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1776_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        904, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        1776, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_147_outsr_5_taps_1776_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1776_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_147_outsr_5_taps_1776_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        905, // sampleRateConverterNo
        147, // sampleRateRatioInput
        5, // sampleRateRatioOutput
        1776, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_2504_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2504_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2504_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        906, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2504, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_2504_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2504_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2504_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        907, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2504, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_2128_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2128_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2128_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        908, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_2128_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2128_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_2128_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        909, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2128, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_1936_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_1936_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_1936_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        910, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1936, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_32_outsr_1_taps_1936_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_1936_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_32_outsr_1_taps_1936_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        911, // sampleRateConverterNo
        32, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        1936, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2728_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2728_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2728_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        912, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2728_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2728_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2728_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        913, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2728, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2312_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2312_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2312_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        914, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2312, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2312_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2312_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2312_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        915, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2312, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2104_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2104_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2104_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        916, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2104, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_5120_outsr_147_taps_2104_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2104_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_5120_outsr_147_taps_2104_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        917, // sampleRateConverterNo
        5120, // sampleRateRatioInput
        147, // sampleRateRatioOutput
        2104, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_3456_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_3456_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_3456_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        918, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        3456, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_3456_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_3456_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_3456_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        919, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        3456, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_2928_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2928_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2928_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        920, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        2928, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_2928_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2928_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2928_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        921, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        2928, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_2672_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2672_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2672_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        922, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        2672, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_441_outsr_10_taps_2672_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2672_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_441_outsr_10_taps_2672_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        923, // sampleRateConverterNo
        441, // sampleRateRatioInput
        10, // sampleRateRatioOutput
        2672, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_3760_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        924, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        3760, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_3760_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        925, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        3760, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_3192_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3192_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3192_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        926, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        3192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_3192_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3192_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3192_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        927, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        3192, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_2904_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_2904_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_2904_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        928, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2904, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_48_outsr_1_taps_2904_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_2904_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_2904_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        929, // sampleRateConverterNo
        48, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        2904, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_7520_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_7520_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_7520_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        930, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        7520, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_7520_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_7520_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_7520_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        931, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        7520, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_6384_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_6384_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_6384_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        932, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        6384, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_6384_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_6384_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_6384_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        933, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        6384, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_5816_stereo_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_5816_stereo_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_5816_stereo_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        934, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        5816, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        12, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        2, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    },
    {
         nullptr,
         nullptr,
        "./libssrcsamplerateconverter_insr_96_outsr_1_taps_5816_mono_ssrcsampleformat_int32.so", // shared object lib file name
        "construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_5816_mono_SsrcSampleFormat_int32",// constructorFunctionName
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null 
         nullptr,
#else                      // if compiling fo DLL, set this pointer to null 
        construct_SsrcSampleRateConverter_insr_96_outsr_1_taps_5816_mono_SsrcSampleFormat_int32, // constructor function pointer
#endif                      // if compiling fo DLL, set this pointer to null 
        935, // sampleRateConverterNo
        96, // sampleRateRatioInput
        1, // sampleRateRatioOutput
        5816, // numberOftapsPerPhase
        8, // numberOfTapsRedPerReadCycle
        0, // numberOfSamplesUsedPerRunPerChan
        0, // totalNumberOfSamplesUsedPerRun
        24, // numOutputSamplesPerChanPerRun
        24, // totalNumOutputSamplesPerRun
        1, // numberOfChannels
        SsrcSampleFormat_int32 // sampleFormat
    }
};
