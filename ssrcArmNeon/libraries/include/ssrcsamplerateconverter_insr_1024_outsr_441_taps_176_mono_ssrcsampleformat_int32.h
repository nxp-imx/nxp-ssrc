/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef  SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32_h
#include "ssrcSampleRateConverter.h"
class SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32 :
    public SsrcSampleRateConverterTemplate<
    class SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32,/* input iSample rate */
    1024,/* input iSample rate */
    441,/* output iSample rate */
    176, /* num taps per oSample */
    8,/* number of taps and samples red per read cycle */
    232,/*max iSamples needed per run*/
    24,/* number of iSamples out per run */
    false,/* stereo */
    -1024>/* tap load instruction initial offset */
{
public:
bool process();
SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32();
};
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_176_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo);
#endif 
