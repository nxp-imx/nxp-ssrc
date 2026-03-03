/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcSampleRateConverterTest_h
#define ssrcSampleRateConverterTest_h
#ifndef USE_ARM_INLINE

#include "ssrcConverterAccess.h"
#include "ssrcNeonAssemblerDefInC.h"
#include "ssrcNeonAssemberDef.h"
#include "wavHeader.h"
#include "ssrcSampleRateConverter.h"
#include <vector>
class ConverterTest
{
public:
    WaveFileIO inputFile;
    WaveFileIO outputFile;
    SsrcConfig config;
    SsrcSampleRateConverterList converterList;
    SsrcSampleRateConverterInfo converterContainer;
    bool convertFile(string &inputFileName, string &outputFileName, unsigned outputSamplingRate);
    template <class _SAMPLE_TYPE_, class _ACC_TYPE_>  bool processFile();

};
#endif
#endif
