/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrc_quantized_interpolation_filter.h"
unsigned getNumberOfFilters() { return 234;}
QuantizedFitlerEntry quantizedFitlerList[234] = 
{
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         0,
         147,
         160,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         1,
         147,
         160,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_160_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         2,
         147,
         160,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         3,
         3,
         4,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         4,
         3,
         4,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_4_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         5,
         3,
         4,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         6,
         320,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         7,
         320,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         8,
         320,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         9,
         441,
         640,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         10,
         441,
         640,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_640_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         11,
         441,
         640,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         12,
         2,
         3,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         13,
         2,
         3,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_3_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         14,
         2,
         3,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         15,
         80,
         147,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         16,
         80,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_147_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         17,
         80,
         147,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         18,
         1,
         2,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         19,
         1,
         2,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_2_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         20,
         1,
         2,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         21,
         147,
         320,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         22,
         147,
         320,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_320_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         23,
         147,
         320,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         24,
         3,
         8,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         25,
         3,
         8,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_8_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         26,
         3,
         8,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         27,
         160,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         28,
         160,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         29,
         160,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         30,
         441,
         1280,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         31,
         441,
         1280,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1280_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         32,
         441,
         1280,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         33,
         1,
         3,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         34,
         1,
         3,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_3_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         35,
         1,
         3,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         36,
         40,
         147,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         37,
         40,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_147_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         38,
         40,
         147,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         39,
         1,
         4,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         40,
         1,
         4,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_4_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         41,
         1,
         4,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         42,
         147,
         640,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         43,
         147,
         640,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_640_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         44,
         147,
         640,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         45,
         3,
         16,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         46,
         3,
         16,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_16_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         47,
         3,
         16,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         48,
         80,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         49,
         80,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_80_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         50,
         80,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         51,
         441,
         2560,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         52,
         441,
         2560,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_2560_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         53,
         441,
         2560,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         54,
         1,
         6,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         55,
         1,
         6,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_6_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         56,
         1,
         6,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         57,
         20,
         147,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         58,
         20,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_147_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         59,
         20,
         147,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         60,
         1,
         8,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         61,
         1,
         8,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_8_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         62,
         1,
         8,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         63,
         147,
         1280,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         64,
         147,
         1280,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_1280_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         65,
         147,
         1280,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         66,
         3,
         32,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         67,
         3,
         32,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_32_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         68,
         3,
         32,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         69,
         40,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         70,
         40,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_40_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         71,
         40,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         72,
         441,
         5120,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         73,
         441,
         5120,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_5120_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         74,
         441,
         5120,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         75,
         1,
         12,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         76,
         1,
         12,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_12_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         77,
         1,
         12,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         78,
         10,
         147,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         79,
         10,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_147_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         80,
         10,
         147,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         81,
         1,
         16,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         82,
         1,
         16,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_16_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         83,
         1,
         16,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         84,
         147,
         2560,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         85,
         147,
         2560,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_2560_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         86,
         147,
         2560,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         87,
         3,
         64,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         88,
         3,
         64,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_64_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         89,
         3,
         64,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         90,
         20,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         91,
         20,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_20_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         92,
         20,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         93,
         441,
         1024,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         94,
         441,
         1024,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_1024_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         95,
         441,
         1024,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         96,
         1,
         24,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         97,
         1,
         24,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_24_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         98,
         1,
         24,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         99,
         5,
         147,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         100,
         5,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5_outsr_147_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         101,
         5,
         147,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         102,
         1,
         32,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         103,
         1,
         32,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_32_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         104,
         1,
         32,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         105,
         147,
         5120,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         106,
         147,
         5120,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5120_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         107,
         147,
         5120,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         108,
         10,
         441,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         109,
         10,
         441,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_10_outsr_441_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         110,
         10,
         441,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         111,
         1,
         48,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         112,
         1,
         48,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_48_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         113,
         1,
         48,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         114,
         1,
         96,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         115,
         1,
         96,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_88_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_88_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1_outsr_96_taps_88_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         116,
         1,
         96,
         88,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_120_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_120_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_120_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         117,
         160,
         147,
         120,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_104_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_104_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_104_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         118,
         160,
         147,
         104,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_96_int32.so",
         "ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_96_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_160_outsr_147_taps_96_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         119,
         160,
         147,
         96,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_152_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_152_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_152_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         120,
         4,
         3,
         152,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_128_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_128_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_128_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         121,
         4,
         3,
         128,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_112_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_112_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_3_taps_112_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         122,
         4,
         3,
         112,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_152_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_152_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_152_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         123,
         441,
         320,
         152,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_128_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_128_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_128_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         124,
         441,
         320,
         128,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_120_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_120_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_320_taps_120_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         125,
         441,
         320,
         120,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_160_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_160_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_160_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         126,
         640,
         441,
         160,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_136_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_136_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_136_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         127,
         640,
         441,
         136,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_128_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_128_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_441_taps_128_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         128,
         640,
         441,
         128,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_168_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_168_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_168_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         129,
         3,
         2,
         168,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_144_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_144_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_144_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         130,
         3,
         2,
         144,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_128_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_128_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_2_taps_128_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         131,
         3,
         2,
         128,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_208_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_208_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_208_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         132,
         147,
         80,
         208,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_176_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_176_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_176_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         133,
         147,
         80,
         176,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_160_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_160_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_80_taps_160_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         134,
         147,
         80,
         160,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_224_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_224_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_224_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         135,
         2,
         1,
         224,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_192_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_192_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_192_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         136,
         2,
         1,
         192,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_176_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_176_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2_outsr_1_taps_176_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         137,
         2,
         1,
         176,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_248_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_248_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_248_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         138,
         320,
         147,
         248,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_208_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_208_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_208_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         139,
         320,
         147,
         208,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_192_int32.so",
         "ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_192_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_320_outsr_147_taps_192_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         140,
         320,
         147,
         192,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_288_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_288_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_288_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         141,
         8,
         3,
         288,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_248_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_248_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_248_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         142,
         8,
         3,
         248,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_224_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_224_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_3_taps_224_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         143,
         8,
         3,
         224,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_304_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_304_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_304_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         144,
         441,
         160,
         304,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_256_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_256_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_256_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         145,
         441,
         160,
         256,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_232_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_232_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_160_taps_232_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         146,
         441,
         160,
         232,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_320_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_320_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_320_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         147,
         1280,
         441,
         320,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_272_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_272_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_272_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         148,
         1280,
         441,
         272,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_248_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_248_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_441_taps_248_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         149,
         1280,
         441,
         248,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_328_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_328_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_328_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         150,
         3,
         1,
         328,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_280_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_280_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_280_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         151,
         3,
         1,
         280,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_256_int32.so",
         "ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_256_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_3_outsr_1_taps_256_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         152,
         3,
         1,
         256,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_400_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_400_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_400_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         153,
         147,
         40,
         400,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_344_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_344_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_344_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         154,
         147,
         40,
         344,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_312_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_312_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_40_taps_312_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         155,
         147,
         40,
         312,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_440_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_440_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_440_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         156,
         4,
         1,
         440,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_376_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_376_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_376_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         157,
         4,
         1,
         376,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_336_int32.so",
         "ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_336_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_4_outsr_1_taps_336_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         158,
         4,
         1,
         336,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_480_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_480_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_480_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         159,
         640,
         147,
         480,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_408_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_408_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_408_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         160,
         640,
         147,
         408,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_368_int32.so",
         "ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_368_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_640_outsr_147_taps_368_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         161,
         640,
         147,
         368,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_584_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_584_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_584_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         162,
         16,
         3,
         584,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_496_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_496_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_496_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         163,
         16,
         3,
         496,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_456_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_456_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_3_taps_456_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         164,
         16,
         3,
         456,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_608_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_608_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_608_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         165,
         441,
         80,
         608,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_512_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_512_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_512_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         166,
         441,
         80,
         512,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_464_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_464_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_80_taps_464_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         167,
         441,
         80,
         464,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_640_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_640_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_640_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         168,
         2560,
         441,
         640,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_544_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_544_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_544_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         169,
         2560,
         441,
         544,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_496_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_496_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_441_taps_496_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         170,
         2560,
         441,
         496,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_664_int32.so",
         "ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_664_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_664_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         171,
         6,
         1,
         664,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_560_int32.so",
         "ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_560_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_560_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         172,
         6,
         1,
         560,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_512_int32.so",
         "ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_512_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_6_outsr_1_taps_512_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         173,
         6,
         1,
         512,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_808_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_808_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_808_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         174,
         147,
         20,
         808,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_688_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_688_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_688_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         175,
         147,
         20,
         688,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_624_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_624_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_20_taps_624_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         176,
         147,
         20,
         624,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_624_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_624_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_624_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         177,
         8,
         1,
         624,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_528_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_528_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_528_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         178,
         8,
         1,
         528,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_480_int32.so",
         "ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_480_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_8_outsr_1_taps_480_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         179,
         8,
         1,
         480,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_936_int32.so",
         "ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_936_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_936_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         180,
         12,
         1,
         936,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_800_int32.so",
         "ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_800_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_800_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         181,
         12,
         1,
         800,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_728_int32.so",
         "ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_728_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_12_outsr_1_taps_728_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         182,
         12,
         1,
         728,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_864_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_864_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_864_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         183,
         441,
         40,
         864,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_728_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_728_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_728_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         184,
         441,
         40,
         728,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_664_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_664_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_40_taps_664_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         185,
         441,
         40,
         664,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_680_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_680_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_680_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         186,
         1280,
         147,
         680,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_576_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_576_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_576_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         187,
         1280,
         147,
         576,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_528_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_528_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1280_outsr_147_taps_528_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         188,
         1280,
         147,
         528,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_832_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_832_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_832_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         189,
         32,
         3,
         832,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_704_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_704_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_704_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         190,
         32,
         3,
         704,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_640_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_640_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_3_taps_640_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         191,
         32,
         3,
         640,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_904_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_904_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_904_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         192,
         5120,
         441,
         904,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_768_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_768_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_768_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         193,
         5120,
         441,
         768,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_704_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_704_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_441_taps_704_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         194,
         5120,
         441,
         704,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_1152_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_1152_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_1152_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         195,
         147,
         10,
         1152,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_976_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_976_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_976_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         196,
         147,
         10,
         976,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_888_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_888_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_10_taps_888_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         197,
         147,
         10,
         888,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1256_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1256_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1256_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         198,
         16,
         1,
         1256,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1064_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1064_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_1064_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         199,
         16,
         1,
         1064,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_968_int32.so",
         "ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_968_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_16_outsr_1_taps_968_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         200,
         16,
         1,
         968,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1360_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1360_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1360_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         201,
         2560,
         147,
         1360,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1152_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1152_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1152_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         202,
         2560,
         147,
         1152,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1048_int32.so",
         "ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1048_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_2560_outsr_147_taps_1048_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         203,
         2560,
         147,
         1048,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1672_int32.so",
         "ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1672_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1672_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         204,
         64,
         3,
         1672,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1416_int32.so",
         "ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1416_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1416_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         205,
         64,
         3,
         1416,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1288_int32.so",
         "ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1288_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_64_outsr_3_taps_1288_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         206,
         64,
         3,
         1288,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1728_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1728_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1728_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         207,
         441,
         20,
         1728,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1464_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1464_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1464_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         208,
         441,
         20,
         1464,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1336_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1336_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_20_taps_1336_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         209,
         441,
         20,
         1336,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_176_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_176_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_176_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         210,
         1024,
         441,
         176,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_152_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_152_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_152_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         211,
         1024,
         441,
         152,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_136_int32.so",
         "ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_136_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_1024_outsr_441_taps_136_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         212,
         1024,
         441,
         136,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1880_int32.so",
         "ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1880_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1880_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         213,
         24,
         1,
         1880,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1592_int32.so",
         "ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1592_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1592_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         214,
         24,
         1,
         1592,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1448_int32.so",
         "ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1448_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_24_outsr_1_taps_1448_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         215,
         24,
         1,
         1448,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_2304_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_2304_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_2304_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         216,
         147,
         5,
         2304,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1952_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1952_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1952_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         217,
         147,
         5,
         1952,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1776_int32.so",
         "ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1776_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_147_outsr_5_taps_1776_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         218,
         147,
         5,
         1776,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2504_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2504_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2504_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         219,
         32,
         1,
         2504,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2128_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2128_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_2128_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         220,
         32,
         1,
         2128,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_1936_int32.so",
         "ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_1936_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_32_outsr_1_taps_1936_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         221,
         32,
         1,
         1936,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2728_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2728_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2728_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         222,
         5120,
         147,
         2728,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2312_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2312_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2312_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         223,
         5120,
         147,
         2312,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2104_int32.so",
         "ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2104_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_5120_outsr_147_taps_2104_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         224,
         5120,
         147,
         2104,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_3456_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_3456_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_3456_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         225,
         441,
         10,
         3456,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2928_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2928_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2928_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         226,
         441,
         10,
         2928,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2672_int32.so",
         "ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2672_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_441_outsr_10_taps_2672_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         227,
         441,
         10,
         2672,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3760_int32.so",
         "ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3760_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3760_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         228,
         48,
         1,
         3760,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3192_int32.so",
         "ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3192_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_3192_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         229,
         48,
         1,
         3192,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_2904_int32.so",
         "ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_2904_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_48_outsr_1_taps_2904_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         230,
         48,
         1,
         2904,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_7520_int32.so",
         "ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_7520_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_7520_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         231,
         96,
         1,
         7520,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_6384_int32.so",
         "ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_6384_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_6384_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         232,
         96,
         1,
         6384,
         SsrcSampleFormat_int32
    },
    {
         nullptr,
         nullptr,
         "libssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_5816_int32.so",
         "ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_5816_int32",
#ifdef DLL_COMPILE_MODE    // if compiling fo DLL, set this pointer to null
         nullptr,
#else    // if compiling fo DLL, set this pointer to null
         ssrc_quantized_interpolation_filter_insr_96_outsr_1_taps_5816_int32[0],
#endif    // if compiling fo DLL, set this pointer to null
         233,
         96,
         1,
         5816,
         SsrcSampleFormat_int32
    }, 
};
