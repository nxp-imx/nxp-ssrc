/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcsamplerateconverter_insr_2_outsr_3_taps_96_mono_ssrcsampleformat_int32.h"
/********************************************************************************
*  iSample rate converter input iSample rate 2 output iSample rate 3 mono
*
*******************************************************************************/
/********************************************************************************
*  
*
*******************************************************************************/
SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32::SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32()
{
}
/********************************************************************************
*  iSample processing
*
*******************************************************************************/
bool SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32::process()
{
    if (!inputOutputQueueReadyForRun()) return false;
    register int64x2_t oSample00Accum ArmRegister("v0"); // oSample0 chan0 oSample accumulators
    register int64x2_t oSample01Accum ArmRegister("v1"); // oSample1 chan0 oSample accumulators
    register int64x2_t oSample02Accum ArmRegister("v2"); // oSample2 chan0 oSample accumulators
    register int64x2_t oSample03Accum ArmRegister("v3"); // oSample3 chan0 oSample accumulators
    register int64x2_t oSample04Accum ArmRegister("v4"); // oSample4 chan0 oSample accumulators
    register int64x2_t oSample05Accum ArmRegister("v5"); // oSample5 chan0 oSample accumulators
    register int64x2_t oSample06Accum ArmRegister("v6"); // oSample6 chan0 oSample accumulators
    register int64x2_t oSample07Accum ArmRegister("v7"); // oSample7 chan0 oSample accumulators
    register int64x2_t oSample08Accum ArmRegister("v8"); // oSample8 chan0 oSample accumulators
    register int64x2_t oSample09Accum ArmRegister("v9"); // oSample9 chan0 oSample accumulators
    register int64x2_t oSample10Accum ArmRegister("v10"); // oSample10 chan0 oSample accumulators
    register int64x2_t oSample11Accum ArmRegister("v11"); // oSample11 chan0 oSample accumulators
    register int64x2_t oSample12Accum ArmRegister("v12"); // oSample12 chan0 oSample accumulators
    register int64x2_t oSample13Accum ArmRegister("v13"); // oSample13 chan0 oSample accumulators
    register int64x2_t oSample14Accum ArmRegister("v14"); // oSample14 chan0 oSample accumulators
    register int64x2_t oSample15Accum ArmRegister("v15"); // oSample15 chan0 oSample accumulators
    register int64x2_t oSample16Accum ArmRegister("v16"); // oSample16 chan0 oSample accumulators
    register int64x2_t oSample17Accum ArmRegister("v17"); // oSample17 chan0 oSample accumulators
    register int64x2_t oSample18Accum ArmRegister("v18"); // oSample18 chan0 oSample accumulators
    register int64x2_t oSample19Accum ArmRegister("v19"); // oSample19 chan0 oSample accumulators
    register int64x2_t oSample20Accum ArmRegister("v20"); // oSample20 chan0 oSample accumulators
    register int64x2_t oSample21Accum ArmRegister("v21"); // oSample21 chan0 oSample accumulators
    register int64x2_t oSample22Accum ArmRegister("v22"); // oSample22 chan0 oSample accumulators
    register int64x2_t oSample23Accum ArmRegister("v23"); // oSample23 chan0 oSample accumulators
    register int32x4_t tapSet_G0_M0 ArmRegister("v24"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G0_M1 ArmRegister("v25"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G1_M0 ArmRegister("v26"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G1_M1 ArmRegister("v27"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G0_M0 ArmRegister("v28"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G0_M1 ArmRegister("v29"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G1_M0 ArmRegister("v30"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G1_M1 ArmRegister("v31"); // OSamples filter tapSet ping pong registers
    register int32_t *oSample00FitlerP ArmRegister("x0"); // oSample0 taps pointer
    register int32_t *oSample01FitlerP ArmRegister("x1"); // oSample1 taps pointer
    register int32_t *oSample02FitlerP ArmRegister("x2"); // oSample2 taps pointer
    register int32_t *oSample03FitlerP ArmRegister("x3"); // oSample3 taps pointer
    register int32_t *oSample04FitlerP ArmRegister("x4"); // oSample4 taps pointer
    register int32_t *oSample05FitlerP ArmRegister("x5"); // oSample5 taps pointer
    register int32_t *oSample06FitlerP ArmRegister("x6"); // oSample6 taps pointer
    register int32_t *oSample07FitlerP ArmRegister("x7"); // oSample7 taps pointer
    register int32_t *oSample08FitlerP ArmRegister("x8"); // oSample8 taps pointer
    register int32_t *oSample09FitlerP ArmRegister("x9"); // oSample9 taps pointer
    register int32_t *oSample10FitlerP ArmRegister("x10"); // oSample10 taps pointer
    register int32_t *oSample11FitlerP ArmRegister("x11"); // oSample11 taps pointer
    register int32_t *oSample12FitlerP ArmRegister("x12"); // oSample12 taps pointer
    register int32_t *oSample13FitlerP ArmRegister("x13"); // oSample13 taps pointer
    register int32_t *oSample14FitlerP ArmRegister("x14"); // oSample14 taps pointer
    register int32_t *oSample15FitlerP ArmRegister("x15"); // oSample15 taps pointer
    register int32_t *oSample16FitlerP ArmRegister("x16"); // oSample16 taps pointer
    register int32_t *oSample17FitlerP ArmRegister("x17"); // oSample17 taps pointer
    register int32_t *oSample18FitlerP ArmRegister("x18"); // oSample18 taps pointer
    register int32_t *oSample19FitlerP ArmRegister("x19"); // oSample19 taps pointer
    register int32_t *oSample20FitlerP ArmRegister("x20"); // oSample20 taps pointer
    register int32_t *oSample21FitlerP ArmRegister("x21"); // oSample21 taps pointer
    register int32_t *oSample22FitlerP ArmRegister("x22"); // oSample22 taps pointer
    register int32_t *oSample23FitlerP ArmRegister("x23"); // oSample23 taps pointer
    register int32_t *inputISampleQueueP ArmRegister("x24"); // input iSample queue pointer
    register int32_t *inputISampleQueuePMask ArmRegister("x25"); // input iSample queue pointer wrap mask
    register int32_t *outputSampleQueueP ArmRegister("x26"); // output iSample queue pointer
    register int32_t *outputSampleQueuePMask ArmRegister("x27"); // output iSample queue pointer wrap mask
    /********************************************************************************
    *  initilaize oSample pointer
    *
    *******************************************************************************/
    unsigned offsetP = 0; //initialize input iSample offset
    unsigned divident = 0;       //intermidiate variable
    unsigned remainder = 0;      //intermidiate variable
    filter.phase(currentPhase,oSample00FitlerP,offsetP); // oSample pointer 0
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample01FitlerP,offsetP); // oSample pointer 1
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample02FitlerP,offsetP); // oSample pointer 2
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample03FitlerP,offsetP); // oSample pointer 3
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample04FitlerP,offsetP); // oSample pointer 4
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample05FitlerP,offsetP); // oSample pointer 5
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample06FitlerP,offsetP); // oSample pointer 6
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample07FitlerP,offsetP); // oSample pointer 7
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample08FitlerP,offsetP); // oSample pointer 8
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample09FitlerP,offsetP); // oSample pointer 9
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample10FitlerP,offsetP); // oSample pointer 10
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample11FitlerP,offsetP); // oSample pointer 11
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample12FitlerP,offsetP); // oSample pointer 12
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample13FitlerP,offsetP); // oSample pointer 13
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample14FitlerP,offsetP); // oSample pointer 14
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample15FitlerP,offsetP); // oSample pointer 15
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample16FitlerP,offsetP); // oSample pointer 16
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample17FitlerP,offsetP); // oSample pointer 17
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample18FitlerP,offsetP); // oSample pointer 18
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample19FitlerP,offsetP); // oSample pointer 19
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample20FitlerP,offsetP); // oSample pointer 20
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample21FitlerP,offsetP); // oSample pointer 21
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample22FitlerP,offsetP); // oSample pointer 22
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phase(currentPhase,oSample23FitlerP,offsetP); // oSample pointer 23
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    inputQueue.getCurrentGetPos(inputISampleQueueP);
    outputQueue.getCurrentPutPos(outputSampleQueueP);
    inputQueue.getQueuePointerMask(inputISampleQueuePMask);
    outputQueue.getQueuePointerMask(outputSampleQueuePMask);
    inputQueue.updateGetPos(offsetP*numberOfChannels);
    outputQueue.updatePutPos(totalNumOutputSamplesPerRun);
    asm_block_start() 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,0/*R0 iSampleSet*/,1/*R1 iSampleSet*/) //  chan0,0 iSampleSet0,1
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,2/*R0 iSampleSet*/,3/*R1 iSampleSet*/) //  chan0,0 iSampleSet2,3
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -1024,0/*oSample*/,0/*tapset*/)  //  oSample0 tapSet0,1 iSampleSet0,1
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -1024,1/*oSample*/,0/*tapset*/)  //  oSample1 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample00Accum,0/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -1024,2/*oSample*/,0/*tapset*/)  //  oSample2 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample01Accum,1/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -1024,3/*oSample*/,0/*tapset*/)  //  oSample3 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample02Accum,2/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample2 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample2 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -1024,4/*oSample*/,0/*tapset*/)  //  oSample4 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample03Accum,3/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample3 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -1024,5/*oSample*/,0/*tapset*/)  //  oSample5 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample04Accum,4/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample4 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample4 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample4 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -1008,6/*oSample*/,1/*tapset*/)  //  oSample6 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample05Accum,5/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample5 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample5 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample5 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -1008,7/*oSample*/,1/*tapset*/)  //  oSample7 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample06Accum,6/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample6 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample6 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -1008,8/*oSample*/,1/*tapset*/)  //  oSample8 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample07Accum,7/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample7 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample7 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample7 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample7 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -1008,9/*oSample*/,1/*tapset*/)  //  oSample9 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample08Accum,8/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample8 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample8 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample8 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample8 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -1008,10/*oSample*/,1/*tapset*/)  //  oSample10 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample09Accum,9/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample9 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample9 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample9 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -1008,11/*oSample*/,1/*tapset*/)  //  oSample11 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample10Accum,10/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample10 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample10 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample10 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -992,0/*oSample*/,2/*tapset*/)  //  oSample0 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample11Accum,11/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample11 tapSet1 Ch0  ISampleSet1 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,4/*R0 iSampleSet*/,5/*R1 iSampleSet*/) //  chan0,0 iSampleSet4,5
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample11 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample11 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -992,1/*oSample*/,2/*tapset*/)  //  oSample1 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -992,2/*oSample*/,2/*tapset*/)  //  oSample2 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -992,3/*oSample*/,2/*tapset*/)  //  oSample3 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -992,4/*oSample*/,2/*tapset*/)  //  oSample4 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -992,5/*oSample*/,2/*tapset*/)  //  oSample5 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -992,12/*oSample*/,2/*tapset*/)  //  oSample12 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -992,13/*oSample*/,2/*tapset*/)  //  oSample13 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample12Accum,12/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample12 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample12 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample12 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample12 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -992,14/*oSample*/,2/*tapset*/)  //  oSample14 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample13Accum,13/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample13 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample13 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample13 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample13 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -992,15/*oSample*/,2/*tapset*/)  //  oSample15 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample14Accum,14/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample14 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample14 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample14 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample14 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -992,16/*oSample*/,2/*tapset*/)  //  oSample16 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample15Accum,15/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample15 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample15 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample15 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -992,17/*oSample*/,2/*tapset*/)  //  oSample17 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample16Accum,16/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample16 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample16 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample16 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -976,6/*oSample*/,3/*tapset*/)  //  oSample6 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample17Accum,17/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample17 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample17 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample17 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -976,7/*oSample*/,3/*tapset*/)  //  oSample7 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -976,8/*oSample*/,3/*tapset*/)  //  oSample8 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -976,9/*oSample*/,3/*tapset*/)  //  oSample9 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -976,10/*oSample*/,3/*tapset*/)  //  oSample10 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -976,11/*oSample*/,3/*tapset*/)  //  oSample11 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample10 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample10 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -976,18/*oSample*/,3/*tapset*/)  //  oSample18 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample11 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample11 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -976,19/*oSample*/,3/*tapset*/)  //  oSample19 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample18Accum,18/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample18 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample18 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample18 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample18 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -976,20/*oSample*/,3/*tapset*/)  //  oSample20 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample19Accum,19/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample19 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample19 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample19 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample19 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -976,21/*oSample*/,3/*tapset*/)  //  oSample21 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample20Accum,20/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample20 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample20 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample20 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample20 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -976,22/*oSample*/,3/*tapset*/)  //  oSample22 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample21Accum,21/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample21 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample21 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample21 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -976,23/*oSample*/,3/*tapset*/)  //  oSample23 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample22Accum,22/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample22 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample22 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample22 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -960,0/*oSample*/,4/*tapset*/)  //  oSample0 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample23Accum,23/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample23 tapSet3 Ch0  ISampleSet3 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,6/*R0 iSampleSet*/,7/*R1 iSampleSet*/) //  chan0,0 iSampleSet6,7
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample23 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample23 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -960,1/*oSample*/,4/*tapset*/)  //  oSample1 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -960,2/*oSample*/,4/*tapset*/)  //  oSample2 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -960,3/*oSample*/,4/*tapset*/)  //  oSample3 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -960,4/*oSample*/,4/*tapset*/)  //  oSample4 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -960,5/*oSample*/,4/*tapset*/)  //  oSample5 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -960,12/*oSample*/,4/*tapset*/)  //  oSample12 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -960,13/*oSample*/,4/*tapset*/)  //  oSample13 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample12 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample12 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample12 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample12 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -960,14/*oSample*/,4/*tapset*/)  //  oSample14 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample13 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample13 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample13 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample13 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -960,15/*oSample*/,4/*tapset*/)  //  oSample15 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample14 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample14 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample14 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample14 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -960,16/*oSample*/,4/*tapset*/)  //  oSample16 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample15 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample15 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample15 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample15 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -960,17/*oSample*/,4/*tapset*/)  //  oSample17 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample16 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample16 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample16 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample16 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -944,6/*oSample*/,5/*tapset*/)  //  oSample6 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample17 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample17 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample17 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample17 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -944,7/*oSample*/,5/*tapset*/)  //  oSample7 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -944,8/*oSample*/,5/*tapset*/)  //  oSample8 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -944,9/*oSample*/,5/*tapset*/)  //  oSample9 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -944,10/*oSample*/,5/*tapset*/)  //  oSample10 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -944,11/*oSample*/,5/*tapset*/)  //  oSample11 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -944,18/*oSample*/,5/*tapset*/)  //  oSample18 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -944,19/*oSample*/,5/*tapset*/)  //  oSample19 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample18 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample18 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample18 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample18 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -944,20/*oSample*/,5/*tapset*/)  //  oSample20 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample19 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample19 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample19 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample19 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -944,21/*oSample*/,5/*tapset*/)  //  oSample21 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample20 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample20 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample20 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample20 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -944,22/*oSample*/,5/*tapset*/)  //  oSample22 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample21 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample21 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample21 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample21 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -944,23/*oSample*/,5/*tapset*/)  //  oSample23 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample22 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample22 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample22 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample22 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -928,0/*oSample*/,6/*tapset*/)  //  oSample0 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample23 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample23 tapSet5 Ch0  ISampleSet5 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,8/*R0 iSampleSet*/,9/*R1 iSampleSet*/) //  chan0,0 iSampleSet8,9
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample23 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample23 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -928,1/*oSample*/,6/*tapset*/)  //  oSample1 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -928,2/*oSample*/,6/*tapset*/)  //  oSample2 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -928,3/*oSample*/,6/*tapset*/)  //  oSample3 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -928,4/*oSample*/,6/*tapset*/)  //  oSample4 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -928,5/*oSample*/,6/*tapset*/)  //  oSample5 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -928,12/*oSample*/,6/*tapset*/)  //  oSample12 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -928,13/*oSample*/,6/*tapset*/)  //  oSample13 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample12 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample12 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample12 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample12 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -928,14/*oSample*/,6/*tapset*/)  //  oSample14 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample13 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample13 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample13 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample13 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -928,15/*oSample*/,6/*tapset*/)  //  oSample15 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample14 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample14 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample14 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample14 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -928,16/*oSample*/,6/*tapset*/)  //  oSample16 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample15 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample15 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample15 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample15 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -928,17/*oSample*/,6/*tapset*/)  //  oSample17 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample16 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample16 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample16 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample16 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -912,6/*oSample*/,7/*tapset*/)  //  oSample6 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample17 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample17 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample17 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample17 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -912,7/*oSample*/,7/*tapset*/)  //  oSample7 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -912,8/*oSample*/,7/*tapset*/)  //  oSample8 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -912,9/*oSample*/,7/*tapset*/)  //  oSample9 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -912,10/*oSample*/,7/*tapset*/)  //  oSample10 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -912,11/*oSample*/,7/*tapset*/)  //  oSample11 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -912,18/*oSample*/,7/*tapset*/)  //  oSample18 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -912,19/*oSample*/,7/*tapset*/)  //  oSample19 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample18 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample18 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample18 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample18 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -912,20/*oSample*/,7/*tapset*/)  //  oSample20 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample19 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample19 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample19 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample19 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -912,21/*oSample*/,7/*tapset*/)  //  oSample21 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample20 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample20 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample20 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample20 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -912,22/*oSample*/,7/*tapset*/)  //  oSample22 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample21 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample21 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample21 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample21 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -912,23/*oSample*/,7/*tapset*/)  //  oSample23 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample22 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample22 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample22 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample22 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -896,0/*oSample*/,8/*tapset*/)  //  oSample0 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample23 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample23 tapSet7 Ch0  ISampleSet7 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,10/*R0 iSampleSet*/,11/*R1 iSampleSet*/) //  chan0,0 iSampleSet10,11
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample23 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample23 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -896,1/*oSample*/,8/*tapset*/)  //  oSample1 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -896,2/*oSample*/,8/*tapset*/)  //  oSample2 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -896,3/*oSample*/,8/*tapset*/)  //  oSample3 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -896,4/*oSample*/,8/*tapset*/)  //  oSample4 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -896,5/*oSample*/,8/*tapset*/)  //  oSample5 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -896,12/*oSample*/,8/*tapset*/)  //  oSample12 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -896,13/*oSample*/,8/*tapset*/)  //  oSample13 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample12 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample12 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -896,14/*oSample*/,8/*tapset*/)  //  oSample14 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample13 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample13 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample13 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample13 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -896,15/*oSample*/,8/*tapset*/)  //  oSample15 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample14 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample14 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample14 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample14 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -896,16/*oSample*/,8/*tapset*/)  //  oSample16 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample15 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample15 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample15 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample15 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -896,17/*oSample*/,8/*tapset*/)  //  oSample17 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample16 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample16 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample16 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample16 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -880,6/*oSample*/,9/*tapset*/)  //  oSample6 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample17 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample17 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample17 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample17 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -880,7/*oSample*/,9/*tapset*/)  //  oSample7 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -880,8/*oSample*/,9/*tapset*/)  //  oSample8 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -880,9/*oSample*/,9/*tapset*/)  //  oSample9 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -880,10/*oSample*/,9/*tapset*/)  //  oSample10 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -880,11/*oSample*/,9/*tapset*/)  //  oSample11 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -880,18/*oSample*/,9/*tapset*/)  //  oSample18 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -880,19/*oSample*/,9/*tapset*/)  //  oSample19 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample18 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample18 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample18 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample18 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -880,20/*oSample*/,9/*tapset*/)  //  oSample20 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample19 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample19 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample19 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample19 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -880,21/*oSample*/,9/*tapset*/)  //  oSample21 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample20 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample20 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample20 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample20 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -880,22/*oSample*/,9/*tapset*/)  //  oSample22 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample21 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample21 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample21 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample21 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -880,23/*oSample*/,9/*tapset*/)  //  oSample23 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample22 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample22 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample22 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample22 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -864,0/*oSample*/,10/*tapset*/)  //  oSample0 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample23 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample23 tapSet9 Ch0  ISampleSet9 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,12/*R0 iSampleSet*/,13/*R1 iSampleSet*/) //  chan0,0 iSampleSet12,13
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample23 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample23 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -864,1/*oSample*/,10/*tapset*/)  //  oSample1 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -864,2/*oSample*/,10/*tapset*/)  //  oSample2 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -864,3/*oSample*/,10/*tapset*/)  //  oSample3 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -864,4/*oSample*/,10/*tapset*/)  //  oSample4 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -864,5/*oSample*/,10/*tapset*/)  //  oSample5 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -864,12/*oSample*/,10/*tapset*/)  //  oSample12 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -864,13/*oSample*/,10/*tapset*/)  //  oSample13 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -864,14/*oSample*/,10/*tapset*/)  //  oSample14 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -864,15/*oSample*/,10/*tapset*/)  //  oSample15 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample14 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample14 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -864,16/*oSample*/,10/*tapset*/)  //  oSample16 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample15 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample15 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -864,17/*oSample*/,10/*tapset*/)  //  oSample17 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample16 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample16 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample16 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample16 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -848,6/*oSample*/,11/*tapset*/)  //  oSample6 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample17 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample17 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample17 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample17 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -848,7/*oSample*/,11/*tapset*/)  //  oSample7 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -848,8/*oSample*/,11/*tapset*/)  //  oSample8 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -848,9/*oSample*/,11/*tapset*/)  //  oSample9 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -848,10/*oSample*/,11/*tapset*/)  //  oSample10 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -848,11/*oSample*/,11/*tapset*/)  //  oSample11 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -848,18/*oSample*/,11/*tapset*/)  //  oSample18 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -848,19/*oSample*/,11/*tapset*/)  //  oSample19 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample18 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample18 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample18 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample18 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -848,20/*oSample*/,11/*tapset*/)  //  oSample20 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample19 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample19 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample19 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample19 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -848,21/*oSample*/,11/*tapset*/)  //  oSample21 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample20 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample20 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample20 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample20 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -848,22/*oSample*/,11/*tapset*/)  //  oSample22 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample21 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample21 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample21 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample21 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -848,23/*oSample*/,11/*tapset*/)  //  oSample23 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample22 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample22 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample22 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample22 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -832,0/*oSample*/,12/*tapset*/)  //  oSample0 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample23 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample23 tapSet11 Ch0  ISampleSet11 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,14/*R0 iSampleSet*/,15/*R1 iSampleSet*/) //  chan0,0 iSampleSet14,15
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample23 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample23 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -832,1/*oSample*/,12/*tapset*/)  //  oSample1 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -832,2/*oSample*/,12/*tapset*/)  //  oSample2 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -832,3/*oSample*/,12/*tapset*/)  //  oSample3 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -832,4/*oSample*/,12/*tapset*/)  //  oSample4 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -832,5/*oSample*/,12/*tapset*/)  //  oSample5 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -832,12/*oSample*/,12/*tapset*/)  //  oSample12 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -832,13/*oSample*/,12/*tapset*/)  //  oSample13 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -832,14/*oSample*/,12/*tapset*/)  //  oSample14 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -832,15/*oSample*/,12/*tapset*/)  //  oSample15 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -832,16/*oSample*/,12/*tapset*/)  //  oSample16 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -832,17/*oSample*/,12/*tapset*/)  //  oSample17 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -816,6/*oSample*/,13/*tapset*/)  //  oSample6 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample17 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample17 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -816,7/*oSample*/,13/*tapset*/)  //  oSample7 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -816,8/*oSample*/,13/*tapset*/)  //  oSample8 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -816,9/*oSample*/,13/*tapset*/)  //  oSample9 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -816,10/*oSample*/,13/*tapset*/)  //  oSample10 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -816,11/*oSample*/,13/*tapset*/)  //  oSample11 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -816,18/*oSample*/,13/*tapset*/)  //  oSample18 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -816,19/*oSample*/,13/*tapset*/)  //  oSample19 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample18 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample18 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -816,20/*oSample*/,13/*tapset*/)  //  oSample20 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample19 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample19 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -816,21/*oSample*/,13/*tapset*/)  //  oSample21 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample20 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample20 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample20 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample20 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -816,22/*oSample*/,13/*tapset*/)  //  oSample22 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample21 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample21 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample21 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample21 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -816,23/*oSample*/,13/*tapset*/)  //  oSample23 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample22 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample22 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample22 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample22 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -800,0/*oSample*/,14/*tapset*/)  //  oSample0 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample23 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample23 tapSet13 Ch0  ISampleSet13 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,16/*R0 iSampleSet*/,17/*R1 iSampleSet*/) //  chan0,0 iSampleSet16,17
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample23 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample23 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -800,1/*oSample*/,14/*tapset*/)  //  oSample1 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -800,2/*oSample*/,14/*tapset*/)  //  oSample2 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -800,3/*oSample*/,14/*tapset*/)  //  oSample3 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -800,4/*oSample*/,14/*tapset*/)  //  oSample4 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -800,5/*oSample*/,14/*tapset*/)  //  oSample5 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -800,12/*oSample*/,14/*tapset*/)  //  oSample12 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -800,13/*oSample*/,14/*tapset*/)  //  oSample13 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -800,14/*oSample*/,14/*tapset*/)  //  oSample14 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -800,15/*oSample*/,14/*tapset*/)  //  oSample15 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -800,16/*oSample*/,14/*tapset*/)  //  oSample16 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -800,17/*oSample*/,14/*tapset*/)  //  oSample17 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -784,6/*oSample*/,15/*tapset*/)  //  oSample6 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -784,7/*oSample*/,15/*tapset*/)  //  oSample7 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -784,8/*oSample*/,15/*tapset*/)  //  oSample8 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -784,9/*oSample*/,15/*tapset*/)  //  oSample9 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -784,10/*oSample*/,15/*tapset*/)  //  oSample10 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -784,11/*oSample*/,15/*tapset*/)  //  oSample11 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -784,18/*oSample*/,15/*tapset*/)  //  oSample18 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -784,19/*oSample*/,15/*tapset*/)  //  oSample19 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -784,20/*oSample*/,15/*tapset*/)  //  oSample20 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -784,21/*oSample*/,15/*tapset*/)  //  oSample21 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -784,22/*oSample*/,15/*tapset*/)  //  oSample22 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample21 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample21 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -784,23/*oSample*/,15/*tapset*/)  //  oSample23 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample22 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample22 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample22 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample22 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -768,0/*oSample*/,16/*tapset*/)  //  oSample0 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample23 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample23 tapSet15 Ch0  ISampleSet15 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,18/*R0 iSampleSet*/,19/*R1 iSampleSet*/) //  chan0,0 iSampleSet18,19
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample23 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample23 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -768,1/*oSample*/,16/*tapset*/)  //  oSample1 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -768,2/*oSample*/,16/*tapset*/)  //  oSample2 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -768,3/*oSample*/,16/*tapset*/)  //  oSample3 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -768,4/*oSample*/,16/*tapset*/)  //  oSample4 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -768,5/*oSample*/,16/*tapset*/)  //  oSample5 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -768,12/*oSample*/,16/*tapset*/)  //  oSample12 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -768,13/*oSample*/,16/*tapset*/)  //  oSample13 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -768,14/*oSample*/,16/*tapset*/)  //  oSample14 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -768,15/*oSample*/,16/*tapset*/)  //  oSample15 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -768,16/*oSample*/,16/*tapset*/)  //  oSample16 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -768,17/*oSample*/,16/*tapset*/)  //  oSample17 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -752,6/*oSample*/,17/*tapset*/)  //  oSample6 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -752,7/*oSample*/,17/*tapset*/)  //  oSample7 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -752,8/*oSample*/,17/*tapset*/)  //  oSample8 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -752,9/*oSample*/,17/*tapset*/)  //  oSample9 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -752,10/*oSample*/,17/*tapset*/)  //  oSample10 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -752,11/*oSample*/,17/*tapset*/)  //  oSample11 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -752,18/*oSample*/,17/*tapset*/)  //  oSample18 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -752,19/*oSample*/,17/*tapset*/)  //  oSample19 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -752,20/*oSample*/,17/*tapset*/)  //  oSample20 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -752,21/*oSample*/,17/*tapset*/)  //  oSample21 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -752,22/*oSample*/,17/*tapset*/)  //  oSample22 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -752,23/*oSample*/,17/*tapset*/)  //  oSample23 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -736,0/*oSample*/,18/*tapset*/)  //  oSample0 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,20/*R0 iSampleSet*/,21/*R1 iSampleSet*/) //  chan0,0 iSampleSet20,21
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -736,1/*oSample*/,18/*tapset*/)  //  oSample1 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -736,2/*oSample*/,18/*tapset*/)  //  oSample2 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -736,3/*oSample*/,18/*tapset*/)  //  oSample3 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -736,4/*oSample*/,18/*tapset*/)  //  oSample4 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -736,5/*oSample*/,18/*tapset*/)  //  oSample5 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -736,12/*oSample*/,18/*tapset*/)  //  oSample12 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -736,13/*oSample*/,18/*tapset*/)  //  oSample13 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -736,14/*oSample*/,18/*tapset*/)  //  oSample14 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -736,15/*oSample*/,18/*tapset*/)  //  oSample15 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -736,16/*oSample*/,18/*tapset*/)  //  oSample16 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -736,17/*oSample*/,18/*tapset*/)  //  oSample17 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -720,6/*oSample*/,19/*tapset*/)  //  oSample6 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -720,7/*oSample*/,19/*tapset*/)  //  oSample7 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -720,8/*oSample*/,19/*tapset*/)  //  oSample8 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -720,9/*oSample*/,19/*tapset*/)  //  oSample9 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -720,10/*oSample*/,19/*tapset*/)  //  oSample10 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -720,11/*oSample*/,19/*tapset*/)  //  oSample11 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -720,18/*oSample*/,19/*tapset*/)  //  oSample18 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -720,19/*oSample*/,19/*tapset*/)  //  oSample19 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -720,20/*oSample*/,19/*tapset*/)  //  oSample20 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -720,21/*oSample*/,19/*tapset*/)  //  oSample21 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -720,22/*oSample*/,19/*tapset*/)  //  oSample22 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -720,23/*oSample*/,19/*tapset*/)  //  oSample23 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -704,0/*oSample*/,20/*tapset*/)  //  oSample0 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,22/*R0 iSampleSet*/,23/*R1 iSampleSet*/) //  chan0,0 iSampleSet22,23
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -704,1/*oSample*/,20/*tapset*/)  //  oSample1 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -704,2/*oSample*/,20/*tapset*/)  //  oSample2 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -704,3/*oSample*/,20/*tapset*/)  //  oSample3 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -704,4/*oSample*/,20/*tapset*/)  //  oSample4 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -704,5/*oSample*/,20/*tapset*/)  //  oSample5 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -704,12/*oSample*/,20/*tapset*/)  //  oSample12 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -704,13/*oSample*/,20/*tapset*/)  //  oSample13 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -704,14/*oSample*/,20/*tapset*/)  //  oSample14 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -704,15/*oSample*/,20/*tapset*/)  //  oSample15 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -704,16/*oSample*/,20/*tapset*/)  //  oSample16 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -704,17/*oSample*/,20/*tapset*/)  //  oSample17 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -688,6/*oSample*/,21/*tapset*/)  //  oSample6 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -688,7/*oSample*/,21/*tapset*/)  //  oSample7 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -688,8/*oSample*/,21/*tapset*/)  //  oSample8 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -688,9/*oSample*/,21/*tapset*/)  //  oSample9 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -688,10/*oSample*/,21/*tapset*/)  //  oSample10 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -688,11/*oSample*/,21/*tapset*/)  //  oSample11 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -688,18/*oSample*/,21/*tapset*/)  //  oSample18 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -688,19/*oSample*/,21/*tapset*/)  //  oSample19 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -688,20/*oSample*/,21/*tapset*/)  //  oSample20 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -688,21/*oSample*/,21/*tapset*/)  //  oSample21 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -688,22/*oSample*/,21/*tapset*/)  //  oSample22 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -688,23/*oSample*/,21/*tapset*/)  //  oSample23 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -672,0/*oSample*/,22/*tapset*/)  //  oSample0 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,24/*R0 iSampleSet*/,25/*R1 iSampleSet*/) //  chan0,0 iSampleSet24,25
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -672,1/*oSample*/,22/*tapset*/)  //  oSample1 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -672,2/*oSample*/,22/*tapset*/)  //  oSample2 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -672,3/*oSample*/,22/*tapset*/)  //  oSample3 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -672,4/*oSample*/,22/*tapset*/)  //  oSample4 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -672,5/*oSample*/,22/*tapset*/)  //  oSample5 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -672,12/*oSample*/,22/*tapset*/)  //  oSample12 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -672,13/*oSample*/,22/*tapset*/)  //  oSample13 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -672,14/*oSample*/,22/*tapset*/)  //  oSample14 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M0,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M1,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -672,15/*oSample*/,22/*tapset*/)  //  oSample15 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -672,16/*oSample*/,22/*tapset*/)  //  oSample16 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -672,17/*oSample*/,22/*tapset*/)  //  oSample17 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -656,6/*oSample*/,23/*tapset*/)  //  oSample6 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -656,7/*oSample*/,23/*tapset*/)  //  oSample7 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -656,8/*oSample*/,23/*tapset*/)  //  oSample8 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -656,9/*oSample*/,23/*tapset*/)  //  oSample9 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -656,10/*oSample*/,23/*tapset*/)  //  oSample10 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -656,11/*oSample*/,23/*tapset*/)  //  oSample11 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -656,18/*oSample*/,23/*tapset*/)  //  oSample18 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -656,19/*oSample*/,23/*tapset*/)  //  oSample19 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -656,20/*oSample*/,23/*tapset*/)  //  oSample20 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -656,21/*oSample*/,23/*tapset*/)  //  oSample21 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -656,22/*oSample*/,23/*tapset*/)  //  oSample22 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -656,23/*oSample*/,23/*tapset*/)  //  oSample23 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -640,1/*oSample*/,24/*tapset*/)  //  oSample1 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,26/*R0 iSampleSet*/,27/*R1 iSampleSet*/) //  chan0,0 iSampleSet26,27
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -640,2/*oSample*/,24/*tapset*/)  //  oSample2 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -640,3/*oSample*/,24/*tapset*/)  //  oSample3 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -640,4/*oSample*/,24/*tapset*/)  //  oSample4 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -640,5/*oSample*/,24/*tapset*/)  //  oSample5 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -640,12/*oSample*/,24/*tapset*/)  //  oSample12 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -640,13/*oSample*/,24/*tapset*/)  //  oSample13 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -640,14/*oSample*/,24/*tapset*/)  //  oSample14 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M0,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M0,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M1,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M1,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -640,15/*oSample*/,24/*tapset*/)  //  oSample15 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -640,16/*oSample*/,24/*tapset*/)  //  oSample16 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -640,17/*oSample*/,24/*tapset*/)  //  oSample17 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -624,7/*oSample*/,25/*tapset*/)  //  oSample7 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -624,8/*oSample*/,25/*tapset*/)  //  oSample8 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -624,9/*oSample*/,25/*tapset*/)  //  oSample9 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M0,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -624,10/*oSample*/,25/*tapset*/)  //  oSample10 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -624,11/*oSample*/,25/*tapset*/)  //  oSample11 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -624,18/*oSample*/,25/*tapset*/)  //  oSample18 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M0,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -624,19/*oSample*/,25/*tapset*/)  //  oSample19 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -624,20/*oSample*/,25/*tapset*/)  //  oSample20 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -624,21/*oSample*/,25/*tapset*/)  //  oSample21 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -624,22/*oSample*/,25/*tapset*/)  //  oSample22 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -624,23/*oSample*/,25/*tapset*/)  //  oSample23 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M1,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -608,13/*oSample*/,26/*tapset*/)  //  oSample13 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -608,14/*oSample*/,26/*tapset*/)  //  oSample14 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M0,13/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample13 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -608,15/*oSample*/,26/*tapset*/)  //  oSample15 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample14 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -608,16/*oSample*/,26/*tapset*/)  //  oSample16 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample15 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -608,17/*oSample*/,26/*tapset*/)  //  oSample17 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -592,19/*oSample*/,27/*tapset*/)  //  oSample19 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -592,20/*oSample*/,27/*tapset*/)  //  oSample20 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample19 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -592,21/*oSample*/,27/*tapset*/)  //  oSample21 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample20 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -592,22/*oSample*/,27/*tapset*/)  //  oSample22 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample21 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -592,23/*oSample*/,27/*tapset*/)  //  oSample23 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M0,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        add_two_halfs_of_accumulator(oSample00Accum,0/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample00Accum,0/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample00Accum,0/*offset in R*/,0/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample01Accum,1/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample01Accum,1/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample01Accum,1/*offset in R*/,1/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample02Accum,2/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample02Accum,2/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample02Accum,2/*offset in R*/,2/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample03Accum,3/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample03Accum,3/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample03Accum,3/*offset in R*/,3/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample04Accum,4/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample04Accum,4/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample04Accum,0/*offset in R*/,4/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample05Accum,5/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample05Accum,5/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample05Accum,1/*offset in R*/,5/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample06Accum,6/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample06Accum,6/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample06Accum,2/*offset in R*/,6/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample07Accum,7/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample07Accum,7/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample07Accum,3/*offset in R*/,7/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G0_M0,iSampleSet_G0_M1,outputSampleQueueP,0)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        add_two_halfs_of_accumulator(oSample08Accum,8/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample08Accum,8/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M0,oSample08Accum,0/*offset in R*/,8/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample09Accum,9/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample09Accum,9/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M0,oSample09Accum,1/*offset in R*/,9/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample10Accum,10/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample10Accum,10/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M0,oSample10Accum,2/*offset in R*/,10/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample11Accum,11/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample11Accum,11/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M0,oSample11Accum,3/*offset in R*/,11/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample12Accum,12/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample12Accum,12/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M1,oSample12Accum,0/*offset in R*/,12/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample13Accum,13/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample13Accum,13/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M1,oSample13Accum,1/*offset in R*/,13/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample14Accum,14/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample14Accum,14/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M1,oSample14Accum,2/*offset in R*/,14/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample15Accum,15/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample15Accum,15/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_M1,oSample15Accum,3/*offset in R*/,15/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G1_M0,iSampleSet_G1_M1,outputSampleQueueP,32)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        add_two_halfs_of_accumulator(oSample16Accum,16/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample16Accum,16/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample16Accum,0/*offset in R*/,16/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample17Accum,17/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample17Accum,17/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample17Accum,1/*offset in R*/,17/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample18Accum,18/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample18Accum,18/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample18Accum,2/*offset in R*/,18/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample19Accum,19/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample19Accum,19/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M0,oSample19Accum,3/*offset in R*/,19/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample20Accum,20/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample20Accum,20/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample20Accum,0/*offset in R*/,20/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample21Accum,21/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample21Accum,21/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample21Accum,1/*offset in R*/,21/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample22Accum,22/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample22Accum,22/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample22Accum,2/*offset in R*/,22/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample23Accum,23/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample23Accum,23/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_M1,oSample23Accum,3/*offset in R*/,23/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G0_M0,iSampleSet_G0_M1,outputSampleQueueP,64)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        put_char(:)
        asm_vector_usage_output(oSample00Accum)put_char(,)
        asm_vector_usage_output(oSample01Accum)put_char(,)
        asm_vector_usage_output(oSample02Accum)put_char(,)
        asm_vector_usage_output(oSample03Accum)put_char(,)
        asm_vector_usage_output(oSample04Accum)put_char(,)
        asm_vector_usage_output(oSample05Accum)put_char(,)
        asm_vector_usage_output(oSample06Accum)put_char(,)
        asm_vector_usage_output(oSample07Accum)put_char(,)
        asm_vector_usage_output(oSample08Accum)put_char(,)
        asm_vector_usage_output(oSample09Accum)put_char(,)
        asm_vector_usage_output(oSample10Accum)put_char(,)
        asm_vector_usage_output(oSample11Accum)put_char(,)
        asm_vector_usage_output(oSample12Accum)put_char(,)
        asm_vector_usage_output(oSample13Accum)put_char(,)
        asm_vector_usage_output(oSample14Accum)put_char(,)
        asm_vector_usage_output(oSample15Accum)put_char(,)
        asm_vector_usage_output(oSample16Accum)put_char(,)
        asm_vector_usage_output(oSample17Accum)put_char(,)
        asm_vector_usage_output(oSample18Accum)put_char(,)
        asm_vector_usage_output(oSample19Accum)put_char(,)
        asm_vector_usage_output(oSample20Accum)put_char(,)
        asm_vector_usage_output(oSample21Accum)put_char(,)
        asm_vector_usage_output(oSample22Accum)put_char(,)
        asm_vector_usage_output(oSample23Accum)put_char(,)
        asm_vector_usage_output(tapSet_G0_M0)put_char(,)
        asm_vector_usage_output(tapSet_G0_M1)put_char(,)
        asm_vector_usage_output(tapSet_G1_M0)put_char(,)
        asm_vector_usage_output(tapSet_G1_M1)put_char(,)
        asm_vector_usage_output(iSampleSet_G0_M0)put_char(,)
        asm_vector_usage_output(iSampleSet_G0_M1)put_char(,)
        asm_vector_usage_output(iSampleSet_G1_M0)put_char(,)
        asm_vector_usage_output(iSampleSet_G1_M1)put_char(,)
        asm_register_usage_output(oSample00FitlerP)put_char(,)
        asm_register_usage_output(oSample01FitlerP)put_char(,)
        asm_register_usage_output(oSample02FitlerP)put_char(,)
        asm_register_usage_output(oSample03FitlerP)put_char(,)
        asm_register_usage_output(oSample04FitlerP)put_char(,)
        asm_register_usage_output(oSample05FitlerP)put_char(,)
        asm_register_usage_output(oSample06FitlerP)put_char(,)
        asm_register_usage_output(oSample07FitlerP)put_char(,)
        asm_register_usage_output(oSample08FitlerP)put_char(,)
        asm_register_usage_output(oSample09FitlerP)put_char(,)
        asm_register_usage_output(oSample10FitlerP)put_char(,)
        asm_register_usage_output(oSample11FitlerP)put_char(,)
        asm_register_usage_output(oSample12FitlerP)put_char(,)
        asm_register_usage_output(oSample13FitlerP)put_char(,)
        asm_register_usage_output(oSample14FitlerP)put_char(,)
        asm_register_usage_output(oSample15FitlerP)put_char(,)
        asm_register_usage_output(oSample16FitlerP)put_char(,)
        asm_register_usage_output(oSample17FitlerP)put_char(,)
        asm_register_usage_output(oSample18FitlerP)put_char(,)
        asm_register_usage_output(oSample19FitlerP)put_char(,)
        asm_register_usage_output(oSample20FitlerP)put_char(,)
        asm_register_usage_output(oSample21FitlerP)put_char(,)
        asm_register_usage_output(oSample22FitlerP)put_char(,)
        asm_register_usage_output(oSample23FitlerP)put_char(,)
        asm_register_usage_output(inputISampleQueueP)put_char(,)
        asm_register_usage_output(inputISampleQueuePMask)put_char(,)
        asm_register_usage_output(outputSampleQueueP)put_char(,)
        asm_register_usage_output(outputSampleQueuePMask)
        put_char(:)
        put_char(:) STRING_INST(memory)
    asm_block_end();
    return true;
}
/********************************************************************************
*  construct sample rate converter object
*
*******************************************************************************/
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo)
{
     return SsrcSampleRateConverter_insr_2_outsr_3_taps_96_mono_SsrcSampleFormat_int32::construct(*returnedInfo);
}
