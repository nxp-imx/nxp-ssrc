/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcNeonTest_h
#define ssrcNeonTest_h
#include "ssrcConverterAccess.h"
#include "wavHeader.h"
#include <vector>
#include <cstdlib>
#include <sstream>

/*
    a sample class for SSRC sample rate conveter
*/
class ConverterExample
{
public:
    WaveFileIO inputFile;      // wave input file object
    WaveFileIO outputFile;     // wave output file object
    SsrcConfig config;         // configuration container
    SsrcSampleRateConverterList converterList;        // converter list object
    SsrcSampleRateConverterInfo converterContainer;   // converter container filled by converter list
    static const char *qualityList[3];
#ifndef USE_ARM_INLINE
    NeonInsC neonIns;   // this object only used when simulating neon instruction in non-arm CPU
#endif
    /*
        convert input file to output sample rate and write it to output wav file
    */
    bool convertFile(string &inputFileName, string &outputFileName, unsigned outputSamplingRate, string quality);
    /*
        process function
    */
    bool processFile();

};

#endif

