/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef  SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32_h
#include "ssrcSampleRateConverter.h"
class SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32 :
    public SsrcSampleRateConverterTemplate<
    class SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32,/* input iSample rate */
    48,/* input iSample rate */
    1,/* output iSample rate */
    3760, /* num taps per oSample */
    8,/* number of taps and samples red per read cycle */
    4912,/*max iSamples needed per run*/
    24,/* number of iSamples out per run */
    false,/* stereo */
    0>/* tap load instruction initial offset */
{
public:
bool process();
SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32();
};
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_48_outsr_1_taps_3760_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo);
#endif 
