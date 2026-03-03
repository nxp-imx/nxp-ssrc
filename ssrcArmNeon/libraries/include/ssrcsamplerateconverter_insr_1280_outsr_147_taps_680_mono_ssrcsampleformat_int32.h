/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef  SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32_h
#include "ssrcSampleRateConverter.h"
class SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32 :
    public SsrcSampleRateConverterTemplate<
    class SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32,/* input iSample rate */
    1280,/* input iSample rate */
    147,/* output iSample rate */
    680, /* num taps per oSample */
    8,/* number of taps and samples red per read cycle */
    889,/*max iSamples needed per run*/
    24,/* number of iSamples out per run */
    false,/* stereo */
    0>/* tap load instruction initial offset */
{
public:
bool process();
SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32();
};
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1280_outsr_147_taps_680_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo);
#endif 
