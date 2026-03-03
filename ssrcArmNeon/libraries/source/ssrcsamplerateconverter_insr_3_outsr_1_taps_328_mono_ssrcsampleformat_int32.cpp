/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcsamplerateconverter_insr_3_outsr_1_taps_328_mono_ssrcsampleformat_int32.h"
/********************************************************************************
*  iSample rate converter input iSample rate 3 output iSample rate 1 mono
*
*******************************************************************************/
/********************************************************************************
*  
*
*******************************************************************************/
SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32::SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32()
{
}
/********************************************************************************
*  iSample processing
*
*******************************************************************************/
bool SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32::process()
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
    filter.phaseZero(oSample00FitlerP,offsetP); // oSample pointer 0
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample01FitlerP,offsetP); // oSample pointer 1
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample02FitlerP,offsetP); // oSample pointer 2
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample03FitlerP,offsetP); // oSample pointer 3
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample04FitlerP,offsetP); // oSample pointer 4
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample05FitlerP,offsetP); // oSample pointer 5
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample06FitlerP,offsetP); // oSample pointer 6
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample07FitlerP,offsetP); // oSample pointer 7
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample08FitlerP,offsetP); // oSample pointer 8
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample09FitlerP,offsetP); // oSample pointer 9
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample10FitlerP,offsetP); // oSample pointer 10
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample11FitlerP,offsetP); // oSample pointer 11
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample12FitlerP,offsetP); // oSample pointer 12
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample13FitlerP,offsetP); // oSample pointer 13
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample14FitlerP,offsetP); // oSample pointer 14
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample15FitlerP,offsetP); // oSample pointer 15
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample16FitlerP,offsetP); // oSample pointer 16
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample17FitlerP,offsetP); // oSample pointer 17
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample18FitlerP,offsetP); // oSample pointer 18
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample19FitlerP,offsetP); // oSample pointer 19
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample20FitlerP,offsetP); // oSample pointer 20
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample21FitlerP,offsetP); // oSample pointer 21
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample22FitlerP,offsetP); // oSample pointer 22
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    filter.phaseZero(oSample23FitlerP,offsetP); // oSample pointer 23
    currentPhase = currentPhase + sampleRateRatioInput; // move to next oSample of filter
    divident = currentPhase/sampleRateRatioOutput;    // divident and remainder of number of oSamples
    remainder = currentPhase%sampleRateRatioOutput;    // divident and remainder of number of oSamples
    offsetP += divident;   // increment input iSample offset
    currentPhase = remainder; // mod of number of oSamples
    offsetP = 3 * 24;   // increment input iSample offset
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
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -1008,2/*oSample*/,1/*tapset*/)  //  oSample2 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample01Accum,1/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -992,0/*oSample*/,2/*tapset*/)  //  oSample0 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample02Accum,2/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,4/*R0 iSampleSet*/,5/*R1 iSampleSet*/) //  chan0,0 iSampleSet4,5
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -992,1/*oSample*/,2/*tapset*/)  //  oSample1 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -992,3/*oSample*/,2/*tapset*/)  //  oSample3 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -976,2/*oSample*/,3/*tapset*/)  //  oSample2 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample03Accum,3/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -976,4/*oSample*/,3/*tapset*/)  //  oSample4 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -976,5/*oSample*/,3/*tapset*/)  //  oSample5 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample04Accum,4/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -960,0/*oSample*/,4/*tapset*/)  //  oSample0 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample05Accum,5/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,6/*R0 iSampleSet*/,7/*R1 iSampleSet*/) //  chan0,0 iSampleSet6,7
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -960,1/*oSample*/,4/*tapset*/)  //  oSample1 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -960,3/*oSample*/,4/*tapset*/)  //  oSample3 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -960,6/*oSample*/,4/*tapset*/)  //  oSample6 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -944,2/*oSample*/,5/*tapset*/)  //  oSample2 tapSet5,6 iSampleSet5,6
        clear_accumulator(oSample06Accum,6/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -944,4/*oSample*/,5/*tapset*/)  //  oSample4 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -944,5/*oSample*/,5/*tapset*/)  //  oSample5 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -944,7/*oSample*/,5/*tapset*/)  //  oSample7 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -928,0/*oSample*/,6/*tapset*/)  //  oSample0 tapSet6,7 iSampleSet6,7
        clear_accumulator(oSample07Accum,7/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,8/*R0 iSampleSet*/,9/*R1 iSampleSet*/) //  chan0,0 iSampleSet8,9
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -928,1/*oSample*/,6/*tapset*/)  //  oSample1 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -928,3/*oSample*/,6/*tapset*/)  //  oSample3 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -928,6/*oSample*/,6/*tapset*/)  //  oSample6 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -928,8/*oSample*/,6/*tapset*/)  //  oSample8 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -928,9/*oSample*/,6/*tapset*/)  //  oSample9 tapSet6,7 iSampleSet6,7
        clear_accumulator(oSample08Accum,8/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -912,2/*oSample*/,7/*tapset*/)  //  oSample2 tapSet7,8 iSampleSet7,8
        clear_accumulator(oSample09Accum,9/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -912,4/*oSample*/,7/*tapset*/)  //  oSample4 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -912,5/*oSample*/,7/*tapset*/)  //  oSample5 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -912,7/*oSample*/,7/*tapset*/)  //  oSample7 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -912,10/*oSample*/,7/*tapset*/)  //  oSample10 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -896,0/*oSample*/,8/*tapset*/)  //  oSample0 tapSet8,9 iSampleSet8,9
        clear_accumulator(oSample10Accum,10/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,10/*R0 iSampleSet*/,11/*R1 iSampleSet*/) //  chan0,0 iSampleSet10,11
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -896,1/*oSample*/,8/*tapset*/)  //  oSample1 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -896,3/*oSample*/,8/*tapset*/)  //  oSample3 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -896,6/*oSample*/,8/*tapset*/)  //  oSample6 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -896,8/*oSample*/,8/*tapset*/)  //  oSample8 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -896,9/*oSample*/,8/*tapset*/)  //  oSample9 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -896,11/*oSample*/,8/*tapset*/)  //  oSample11 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -880,2/*oSample*/,9/*tapset*/)  //  oSample2 tapSet9,10 iSampleSet9,10
        clear_accumulator(oSample11Accum,11/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -880,4/*oSample*/,9/*tapset*/)  //  oSample4 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -880,5/*oSample*/,9/*tapset*/)  //  oSample5 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -880,7/*oSample*/,9/*tapset*/)  //  oSample7 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -880,10/*oSample*/,9/*tapset*/)  //  oSample10 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -880,12/*oSample*/,9/*tapset*/)  //  oSample12 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -880,13/*oSample*/,9/*tapset*/)  //  oSample13 tapSet9,10 iSampleSet9,10
        clear_accumulator(oSample12Accum,12/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -864,0/*oSample*/,10/*tapset*/)  //  oSample0 tapSet10,11 iSampleSet10,11
        clear_accumulator(oSample13Accum,13/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample13 tapSet9 Ch0  ISampleSet9 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,12/*R0 iSampleSet*/,13/*R1 iSampleSet*/) //  chan0,0 iSampleSet12,13
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -864,1/*oSample*/,10/*tapset*/)  //  oSample1 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -864,3/*oSample*/,10/*tapset*/)  //  oSample3 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -864,6/*oSample*/,10/*tapset*/)  //  oSample6 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -864,8/*oSample*/,10/*tapset*/)  //  oSample8 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -864,9/*oSample*/,10/*tapset*/)  //  oSample9 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -864,11/*oSample*/,10/*tapset*/)  //  oSample11 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -864,14/*oSample*/,10/*tapset*/)  //  oSample14 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -848,2/*oSample*/,11/*tapset*/)  //  oSample2 tapSet11,12 iSampleSet11,12
        clear_accumulator(oSample14Accum,14/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample14 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -848,4/*oSample*/,11/*tapset*/)  //  oSample4 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -848,5/*oSample*/,11/*tapset*/)  //  oSample5 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -848,7/*oSample*/,11/*tapset*/)  //  oSample7 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -848,10/*oSample*/,11/*tapset*/)  //  oSample10 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -848,12/*oSample*/,11/*tapset*/)  //  oSample12 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -848,13/*oSample*/,11/*tapset*/)  //  oSample13 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -848,15/*oSample*/,11/*tapset*/)  //  oSample15 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -832,0/*oSample*/,12/*tapset*/)  //  oSample0 tapSet12,13 iSampleSet12,13
        clear_accumulator(oSample15Accum,15/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,14/*R0 iSampleSet*/,15/*R1 iSampleSet*/) //  chan0,0 iSampleSet14,15
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -832,1/*oSample*/,12/*tapset*/)  //  oSample1 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -832,3/*oSample*/,12/*tapset*/)  //  oSample3 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -832,6/*oSample*/,12/*tapset*/)  //  oSample6 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -832,8/*oSample*/,12/*tapset*/)  //  oSample8 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -832,9/*oSample*/,12/*tapset*/)  //  oSample9 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -832,11/*oSample*/,12/*tapset*/)  //  oSample11 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -832,14/*oSample*/,12/*tapset*/)  //  oSample14 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -832,16/*oSample*/,12/*tapset*/)  //  oSample16 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -832,17/*oSample*/,12/*tapset*/)  //  oSample17 tapSet12,13 iSampleSet12,13
        clear_accumulator(oSample16Accum,16/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -816,2/*oSample*/,13/*tapset*/)  //  oSample2 tapSet13,14 iSampleSet13,14
        clear_accumulator(oSample17Accum,17/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample17 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -816,4/*oSample*/,13/*tapset*/)  //  oSample4 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -816,5/*oSample*/,13/*tapset*/)  //  oSample5 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -816,7/*oSample*/,13/*tapset*/)  //  oSample7 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -816,10/*oSample*/,13/*tapset*/)  //  oSample10 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -816,12/*oSample*/,13/*tapset*/)  //  oSample12 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -816,13/*oSample*/,13/*tapset*/)  //  oSample13 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -816,15/*oSample*/,13/*tapset*/)  //  oSample15 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -816,18/*oSample*/,13/*tapset*/)  //  oSample18 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -800,0/*oSample*/,14/*tapset*/)  //  oSample0 tapSet14,15 iSampleSet14,15
        clear_accumulator(oSample18Accum,18/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample18 tapSet13 Ch0  ISampleSet13 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,16/*R0 iSampleSet*/,17/*R1 iSampleSet*/) //  chan0,0 iSampleSet16,17
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -800,1/*oSample*/,14/*tapset*/)  //  oSample1 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -800,3/*oSample*/,14/*tapset*/)  //  oSample3 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -800,6/*oSample*/,14/*tapset*/)  //  oSample6 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -800,8/*oSample*/,14/*tapset*/)  //  oSample8 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -800,9/*oSample*/,14/*tapset*/)  //  oSample9 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -800,11/*oSample*/,14/*tapset*/)  //  oSample11 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -800,14/*oSample*/,14/*tapset*/)  //  oSample14 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -800,16/*oSample*/,14/*tapset*/)  //  oSample16 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -800,17/*oSample*/,14/*tapset*/)  //  oSample17 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -800,19/*oSample*/,14/*tapset*/)  //  oSample19 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -784,2/*oSample*/,15/*tapset*/)  //  oSample2 tapSet15,16 iSampleSet15,16
        clear_accumulator(oSample19Accum,19/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -784,4/*oSample*/,15/*tapset*/)  //  oSample4 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -784,5/*oSample*/,15/*tapset*/)  //  oSample5 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -784,7/*oSample*/,15/*tapset*/)  //  oSample7 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -784,10/*oSample*/,15/*tapset*/)  //  oSample10 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -784,12/*oSample*/,15/*tapset*/)  //  oSample12 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -784,13/*oSample*/,15/*tapset*/)  //  oSample13 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -784,15/*oSample*/,15/*tapset*/)  //  oSample15 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -784,18/*oSample*/,15/*tapset*/)  //  oSample18 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -784,20/*oSample*/,15/*tapset*/)  //  oSample20 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -784,21/*oSample*/,15/*tapset*/)  //  oSample21 tapSet15,16 iSampleSet15,16
        clear_accumulator(oSample20Accum,20/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -768,0/*oSample*/,16/*tapset*/)  //  oSample0 tapSet16,17 iSampleSet16,17
        clear_accumulator(oSample21Accum,21/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample21 tapSet15 Ch0  ISampleSet15 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,18/*R0 iSampleSet*/,19/*R1 iSampleSet*/) //  chan0,0 iSampleSet18,19
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -768,1/*oSample*/,16/*tapset*/)  //  oSample1 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -768,3/*oSample*/,16/*tapset*/)  //  oSample3 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -768,6/*oSample*/,16/*tapset*/)  //  oSample6 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -768,8/*oSample*/,16/*tapset*/)  //  oSample8 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -768,9/*oSample*/,16/*tapset*/)  //  oSample9 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -768,11/*oSample*/,16/*tapset*/)  //  oSample11 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -768,14/*oSample*/,16/*tapset*/)  //  oSample14 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -768,16/*oSample*/,16/*tapset*/)  //  oSample16 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -768,17/*oSample*/,16/*tapset*/)  //  oSample17 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -768,19/*oSample*/,16/*tapset*/)  //  oSample19 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -768,22/*oSample*/,16/*tapset*/)  //  oSample22 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -752,2/*oSample*/,17/*tapset*/)  //  oSample2 tapSet17,18 iSampleSet17,18
        clear_accumulator(oSample22Accum,22/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample22 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -752,4/*oSample*/,17/*tapset*/)  //  oSample4 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -752,5/*oSample*/,17/*tapset*/)  //  oSample5 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -752,7/*oSample*/,17/*tapset*/)  //  oSample7 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -752,10/*oSample*/,17/*tapset*/)  //  oSample10 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -752,12/*oSample*/,17/*tapset*/)  //  oSample12 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -752,13/*oSample*/,17/*tapset*/)  //  oSample13 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -752,15/*oSample*/,17/*tapset*/)  //  oSample15 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -752,18/*oSample*/,17/*tapset*/)  //  oSample18 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -752,20/*oSample*/,17/*tapset*/)  //  oSample20 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -752,21/*oSample*/,17/*tapset*/)  //  oSample21 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -752,23/*oSample*/,17/*tapset*/)  //  oSample23 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -736,0/*oSample*/,18/*tapset*/)  //  oSample0 tapSet18,19 iSampleSet18,19
        clear_accumulator(oSample23Accum,23/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,20/*R0 iSampleSet*/,21/*R1 iSampleSet*/) //  chan0,0 iSampleSet20,21
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -736,1/*oSample*/,18/*tapset*/)  //  oSample1 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -736,3/*oSample*/,18/*tapset*/)  //  oSample3 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -736,6/*oSample*/,18/*tapset*/)  //  oSample6 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -736,8/*oSample*/,18/*tapset*/)  //  oSample8 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -736,9/*oSample*/,18/*tapset*/)  //  oSample9 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -736,11/*oSample*/,18/*tapset*/)  //  oSample11 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -736,14/*oSample*/,18/*tapset*/)  //  oSample14 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -736,16/*oSample*/,18/*tapset*/)  //  oSample16 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -736,17/*oSample*/,18/*tapset*/)  //  oSample17 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -736,19/*oSample*/,18/*tapset*/)  //  oSample19 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -736,22/*oSample*/,18/*tapset*/)  //  oSample22 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -720,2/*oSample*/,19/*tapset*/)  //  oSample2 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -720,4/*oSample*/,19/*tapset*/)  //  oSample4 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -720,5/*oSample*/,19/*tapset*/)  //  oSample5 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -720,7/*oSample*/,19/*tapset*/)  //  oSample7 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -720,10/*oSample*/,19/*tapset*/)  //  oSample10 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -720,12/*oSample*/,19/*tapset*/)  //  oSample12 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -720,13/*oSample*/,19/*tapset*/)  //  oSample13 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -720,15/*oSample*/,19/*tapset*/)  //  oSample15 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -720,18/*oSample*/,19/*tapset*/)  //  oSample18 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -720,20/*oSample*/,19/*tapset*/)  //  oSample20 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -720,21/*oSample*/,19/*tapset*/)  //  oSample21 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -720,23/*oSample*/,19/*tapset*/)  //  oSample23 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -704,0/*oSample*/,20/*tapset*/)  //  oSample0 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,22/*R0 iSampleSet*/,23/*R1 iSampleSet*/) //  chan0,0 iSampleSet22,23
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -704,1/*oSample*/,20/*tapset*/)  //  oSample1 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -704,3/*oSample*/,20/*tapset*/)  //  oSample3 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -704,6/*oSample*/,20/*tapset*/)  //  oSample6 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -704,8/*oSample*/,20/*tapset*/)  //  oSample8 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -704,9/*oSample*/,20/*tapset*/)  //  oSample9 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -704,11/*oSample*/,20/*tapset*/)  //  oSample11 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -704,14/*oSample*/,20/*tapset*/)  //  oSample14 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -704,16/*oSample*/,20/*tapset*/)  //  oSample16 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -704,17/*oSample*/,20/*tapset*/)  //  oSample17 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -704,19/*oSample*/,20/*tapset*/)  //  oSample19 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -704,22/*oSample*/,20/*tapset*/)  //  oSample22 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -688,2/*oSample*/,21/*tapset*/)  //  oSample2 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -688,4/*oSample*/,21/*tapset*/)  //  oSample4 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -688,5/*oSample*/,21/*tapset*/)  //  oSample5 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -688,7/*oSample*/,21/*tapset*/)  //  oSample7 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -688,10/*oSample*/,21/*tapset*/)  //  oSample10 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -688,12/*oSample*/,21/*tapset*/)  //  oSample12 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -688,13/*oSample*/,21/*tapset*/)  //  oSample13 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -688,15/*oSample*/,21/*tapset*/)  //  oSample15 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -688,18/*oSample*/,21/*tapset*/)  //  oSample18 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -688,20/*oSample*/,21/*tapset*/)  //  oSample20 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -688,21/*oSample*/,21/*tapset*/)  //  oSample21 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -688,23/*oSample*/,21/*tapset*/)  //  oSample23 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -672,0/*oSample*/,22/*tapset*/)  //  oSample0 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,24/*R0 iSampleSet*/,25/*R1 iSampleSet*/) //  chan0,0 iSampleSet24,25
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -672,1/*oSample*/,22/*tapset*/)  //  oSample1 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -672,3/*oSample*/,22/*tapset*/)  //  oSample3 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -672,6/*oSample*/,22/*tapset*/)  //  oSample6 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -672,8/*oSample*/,22/*tapset*/)  //  oSample8 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -672,9/*oSample*/,22/*tapset*/)  //  oSample9 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -672,11/*oSample*/,22/*tapset*/)  //  oSample11 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -672,14/*oSample*/,22/*tapset*/)  //  oSample14 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -672,16/*oSample*/,22/*tapset*/)  //  oSample16 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -672,17/*oSample*/,22/*tapset*/)  //  oSample17 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -672,19/*oSample*/,22/*tapset*/)  //  oSample19 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -672,22/*oSample*/,22/*tapset*/)  //  oSample22 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -656,2/*oSample*/,23/*tapset*/)  //  oSample2 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -656,4/*oSample*/,23/*tapset*/)  //  oSample4 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -656,5/*oSample*/,23/*tapset*/)  //  oSample5 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -656,7/*oSample*/,23/*tapset*/)  //  oSample7 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -656,10/*oSample*/,23/*tapset*/)  //  oSample10 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -656,12/*oSample*/,23/*tapset*/)  //  oSample12 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -656,13/*oSample*/,23/*tapset*/)  //  oSample13 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -656,15/*oSample*/,23/*tapset*/)  //  oSample15 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -656,18/*oSample*/,23/*tapset*/)  //  oSample18 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -656,20/*oSample*/,23/*tapset*/)  //  oSample20 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -656,21/*oSample*/,23/*tapset*/)  //  oSample21 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -656,23/*oSample*/,23/*tapset*/)  //  oSample23 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -640,0/*oSample*/,24/*tapset*/)  //  oSample0 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,26/*R0 iSampleSet*/,27/*R1 iSampleSet*/) //  chan0,0 iSampleSet26,27
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -640,1/*oSample*/,24/*tapset*/)  //  oSample1 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -640,3/*oSample*/,24/*tapset*/)  //  oSample3 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -640,6/*oSample*/,24/*tapset*/)  //  oSample6 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -640,8/*oSample*/,24/*tapset*/)  //  oSample8 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -640,9/*oSample*/,24/*tapset*/)  //  oSample9 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -640,11/*oSample*/,24/*tapset*/)  //  oSample11 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -640,14/*oSample*/,24/*tapset*/)  //  oSample14 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -640,16/*oSample*/,24/*tapset*/)  //  oSample16 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -640,17/*oSample*/,24/*tapset*/)  //  oSample17 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -640,19/*oSample*/,24/*tapset*/)  //  oSample19 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -640,22/*oSample*/,24/*tapset*/)  //  oSample22 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -624,2/*oSample*/,25/*tapset*/)  //  oSample2 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -624,4/*oSample*/,25/*tapset*/)  //  oSample4 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -624,5/*oSample*/,25/*tapset*/)  //  oSample5 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -624,7/*oSample*/,25/*tapset*/)  //  oSample7 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -624,10/*oSample*/,25/*tapset*/)  //  oSample10 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -624,12/*oSample*/,25/*tapset*/)  //  oSample12 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -624,13/*oSample*/,25/*tapset*/)  //  oSample13 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample12 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample12 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -624,15/*oSample*/,25/*tapset*/)  //  oSample15 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample13 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample13 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -624,18/*oSample*/,25/*tapset*/)  //  oSample18 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample15 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample15 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -624,20/*oSample*/,25/*tapset*/)  //  oSample20 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -624,21/*oSample*/,25/*tapset*/)  //  oSample21 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -624,23/*oSample*/,25/*tapset*/)  //  oSample23 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -608,0/*oSample*/,26/*tapset*/)  //  oSample0 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,28/*R0 iSampleSet*/,29/*R1 iSampleSet*/) //  chan0,0 iSampleSet28,29
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -608,1/*oSample*/,26/*tapset*/)  //  oSample1 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -608,3/*oSample*/,26/*tapset*/)  //  oSample3 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -608,6/*oSample*/,26/*tapset*/)  //  oSample6 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -608,8/*oSample*/,26/*tapset*/)  //  oSample8 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -608,9/*oSample*/,26/*tapset*/)  //  oSample9 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -608,11/*oSample*/,26/*tapset*/)  //  oSample11 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -608,14/*oSample*/,26/*tapset*/)  //  oSample14 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -608,16/*oSample*/,26/*tapset*/)  //  oSample16 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample14 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample14 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample14 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample14 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -608,17/*oSample*/,26/*tapset*/)  //  oSample17 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample16 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample16 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -608,19/*oSample*/,26/*tapset*/)  //  oSample19 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample17 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample17 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -608,22/*oSample*/,26/*tapset*/)  //  oSample22 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample19 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample19 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -592,2/*oSample*/,27/*tapset*/)  //  oSample2 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -592,4/*oSample*/,27/*tapset*/)  //  oSample4 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -592,5/*oSample*/,27/*tapset*/)  //  oSample5 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -592,7/*oSample*/,27/*tapset*/)  //  oSample7 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -592,10/*oSample*/,27/*tapset*/)  //  oSample10 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -592,12/*oSample*/,27/*tapset*/)  //  oSample12 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -592,13/*oSample*/,27/*tapset*/)  //  oSample13 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample12 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample12 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample12 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample12 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -592,15/*oSample*/,27/*tapset*/)  //  oSample15 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample13 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample13 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample13 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample13 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -592,18/*oSample*/,27/*tapset*/)  //  oSample18 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample15 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample15 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample15 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample15 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -592,20/*oSample*/,27/*tapset*/)  //  oSample20 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample18 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample18 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample18 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample18 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -592,21/*oSample*/,27/*tapset*/)  //  oSample21 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample20 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample20 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample20 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample20 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -592,23/*oSample*/,27/*tapset*/)  //  oSample23 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample21 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample21 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample21 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample21 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -576,0/*oSample*/,28/*tapset*/)  //  oSample0 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,30/*R0 iSampleSet*/,31/*R1 iSampleSet*/) //  chan0,0 iSampleSet30,31
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample23 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample23 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -576,1/*oSample*/,28/*tapset*/)  //  oSample1 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -576,3/*oSample*/,28/*tapset*/)  //  oSample3 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -576,6/*oSample*/,28/*tapset*/)  //  oSample6 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -576,8/*oSample*/,28/*tapset*/)  //  oSample8 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -576,9/*oSample*/,28/*tapset*/)  //  oSample9 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -576,11/*oSample*/,28/*tapset*/)  //  oSample11 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -576,14/*oSample*/,28/*tapset*/)  //  oSample14 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -576,16/*oSample*/,28/*tapset*/)  //  oSample16 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample14 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample14 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample14 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample14 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -576,17/*oSample*/,28/*tapset*/)  //  oSample17 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample16 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample16 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample16 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample16 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -576,19/*oSample*/,28/*tapset*/)  //  oSample19 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample17 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample17 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample17 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample17 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -576,22/*oSample*/,28/*tapset*/)  //  oSample22 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample19 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample19 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample19 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample19 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -560,2/*oSample*/,29/*tapset*/)  //  oSample2 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample22 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample22 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample22 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample22 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -560,4/*oSample*/,29/*tapset*/)  //  oSample4 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -560,5/*oSample*/,29/*tapset*/)  //  oSample5 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -560,7/*oSample*/,29/*tapset*/)  //  oSample7 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -560,10/*oSample*/,29/*tapset*/)  //  oSample10 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -560,12/*oSample*/,29/*tapset*/)  //  oSample12 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -560,13/*oSample*/,29/*tapset*/)  //  oSample13 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample12 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample12 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample12 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample12 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -560,15/*oSample*/,29/*tapset*/)  //  oSample15 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample13 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample13 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample13 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample13 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -560,18/*oSample*/,29/*tapset*/)  //  oSample18 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample15 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample15 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample15 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample15 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -560,20/*oSample*/,29/*tapset*/)  //  oSample20 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample18 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample18 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample18 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample18 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -560,21/*oSample*/,29/*tapset*/)  //  oSample21 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample20 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample20 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample20 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample20 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -560,23/*oSample*/,29/*tapset*/)  //  oSample23 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample21 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample21 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample21 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample21 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -544,0/*oSample*/,30/*tapset*/)  //  oSample0 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample23 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample23 tapSet29 Ch0  ISampleSet29 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,32/*R0 iSampleSet*/,33/*R1 iSampleSet*/) //  chan0,0 iSampleSet32,33
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample23 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample23 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -544,1/*oSample*/,30/*tapset*/)  //  oSample1 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -544,3/*oSample*/,30/*tapset*/)  //  oSample3 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -544,6/*oSample*/,30/*tapset*/)  //  oSample6 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -544,8/*oSample*/,30/*tapset*/)  //  oSample8 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -544,9/*oSample*/,30/*tapset*/)  //  oSample9 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -544,11/*oSample*/,30/*tapset*/)  //  oSample11 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -544,14/*oSample*/,30/*tapset*/)  //  oSample14 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -544,16/*oSample*/,30/*tapset*/)  //  oSample16 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample14 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample14 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample14 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample14 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -544,17/*oSample*/,30/*tapset*/)  //  oSample17 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample16 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample16 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample16 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample16 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -544,19/*oSample*/,30/*tapset*/)  //  oSample19 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample17 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample17 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample17 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample17 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -544,22/*oSample*/,30/*tapset*/)  //  oSample22 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample19 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample19 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample19 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample19 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -528,2/*oSample*/,31/*tapset*/)  //  oSample2 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample22 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample22 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample22 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample22 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -528,4/*oSample*/,31/*tapset*/)  //  oSample4 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -528,5/*oSample*/,31/*tapset*/)  //  oSample5 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -528,7/*oSample*/,31/*tapset*/)  //  oSample7 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -528,10/*oSample*/,31/*tapset*/)  //  oSample10 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -528,12/*oSample*/,31/*tapset*/)  //  oSample12 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -528,13/*oSample*/,31/*tapset*/)  //  oSample13 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample12 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample12 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample12 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample12 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -528,15/*oSample*/,31/*tapset*/)  //  oSample15 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample13 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample13 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample13 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample13 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -528,18/*oSample*/,31/*tapset*/)  //  oSample18 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample15 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample15 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample15 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample15 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -528,20/*oSample*/,31/*tapset*/)  //  oSample20 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample18 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample18 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample18 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample18 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -528,21/*oSample*/,31/*tapset*/)  //  oSample21 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample20 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample20 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample20 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample20 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -528,23/*oSample*/,31/*tapset*/)  //  oSample23 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample21 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample21 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample21 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample21 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -512,0/*oSample*/,32/*tapset*/)  //  oSample0 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample23 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample23 tapSet31 Ch0  ISampleSet31 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,34/*R0 iSampleSet*/,35/*R1 iSampleSet*/) //  chan0,0 iSampleSet34,35
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample23 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample23 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -512,1/*oSample*/,32/*tapset*/)  //  oSample1 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -512,3/*oSample*/,32/*tapset*/)  //  oSample3 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -512,6/*oSample*/,32/*tapset*/)  //  oSample6 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -512,8/*oSample*/,32/*tapset*/)  //  oSample8 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -512,9/*oSample*/,32/*tapset*/)  //  oSample9 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -512,11/*oSample*/,32/*tapset*/)  //  oSample11 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -512,14/*oSample*/,32/*tapset*/)  //  oSample14 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -512,16/*oSample*/,32/*tapset*/)  //  oSample16 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample14 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample14 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample14 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample14 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -512,17/*oSample*/,32/*tapset*/)  //  oSample17 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample16 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample16 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample16 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample16 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -512,19/*oSample*/,32/*tapset*/)  //  oSample19 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample17 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample17 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample17 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample17 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -512,22/*oSample*/,32/*tapset*/)  //  oSample22 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample19 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample19 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample19 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample19 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -496,2/*oSample*/,33/*tapset*/)  //  oSample2 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample22 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample22 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample22 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample22 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -496,4/*oSample*/,33/*tapset*/)  //  oSample4 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -496,5/*oSample*/,33/*tapset*/)  //  oSample5 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -496,7/*oSample*/,33/*tapset*/)  //  oSample7 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -496,10/*oSample*/,33/*tapset*/)  //  oSample10 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -496,12/*oSample*/,33/*tapset*/)  //  oSample12 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -496,13/*oSample*/,33/*tapset*/)  //  oSample13 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample12 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample12 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample12 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample12 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -496,15/*oSample*/,33/*tapset*/)  //  oSample15 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample13 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample13 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample13 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample13 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -496,18/*oSample*/,33/*tapset*/)  //  oSample18 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample15 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample15 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample15 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample15 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -496,20/*oSample*/,33/*tapset*/)  //  oSample20 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample18 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample18 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample18 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample18 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -496,21/*oSample*/,33/*tapset*/)  //  oSample21 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample20 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample20 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample20 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample20 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -496,23/*oSample*/,33/*tapset*/)  //  oSample23 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample21 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample21 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample21 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample21 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -480,0/*oSample*/,34/*tapset*/)  //  oSample0 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample23 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample23 tapSet33 Ch0  ISampleSet33 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,36/*R0 iSampleSet*/,37/*R1 iSampleSet*/) //  chan0,0 iSampleSet36,37
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample23 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample23 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -480,1/*oSample*/,34/*tapset*/)  //  oSample1 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -480,3/*oSample*/,34/*tapset*/)  //  oSample3 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -480,6/*oSample*/,34/*tapset*/)  //  oSample6 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -480,8/*oSample*/,34/*tapset*/)  //  oSample8 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -480,9/*oSample*/,34/*tapset*/)  //  oSample9 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -480,11/*oSample*/,34/*tapset*/)  //  oSample11 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -480,14/*oSample*/,34/*tapset*/)  //  oSample14 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -480,16/*oSample*/,34/*tapset*/)  //  oSample16 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample14 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample14 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample14 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample14 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -480,17/*oSample*/,34/*tapset*/)  //  oSample17 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample16 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample16 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample16 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample16 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -480,19/*oSample*/,34/*tapset*/)  //  oSample19 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample17 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample17 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample17 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample17 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -480,22/*oSample*/,34/*tapset*/)  //  oSample22 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample19 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample19 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample19 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample19 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -464,2/*oSample*/,35/*tapset*/)  //  oSample2 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample22 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample22 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample22 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample22 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -464,4/*oSample*/,35/*tapset*/)  //  oSample4 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -464,5/*oSample*/,35/*tapset*/)  //  oSample5 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -464,7/*oSample*/,35/*tapset*/)  //  oSample7 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -464,10/*oSample*/,35/*tapset*/)  //  oSample10 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -464,12/*oSample*/,35/*tapset*/)  //  oSample12 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -464,13/*oSample*/,35/*tapset*/)  //  oSample13 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample12 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample12 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample12 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample12 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -464,15/*oSample*/,35/*tapset*/)  //  oSample15 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample13 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample13 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample13 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample13 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -464,18/*oSample*/,35/*tapset*/)  //  oSample18 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample15 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample15 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample15 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample15 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -464,20/*oSample*/,35/*tapset*/)  //  oSample20 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample18 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample18 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample18 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample18 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -464,21/*oSample*/,35/*tapset*/)  //  oSample21 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample20 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample20 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample20 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample20 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -464,23/*oSample*/,35/*tapset*/)  //  oSample23 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample21 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample21 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample21 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample21 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -448,0/*oSample*/,36/*tapset*/)  //  oSample0 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample23 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample23 tapSet35 Ch0  ISampleSet35 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,38/*R0 iSampleSet*/,39/*R1 iSampleSet*/) //  chan0,0 iSampleSet38,39
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample23 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample23 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -448,1/*oSample*/,36/*tapset*/)  //  oSample1 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -448,3/*oSample*/,36/*tapset*/)  //  oSample3 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -448,6/*oSample*/,36/*tapset*/)  //  oSample6 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -448,8/*oSample*/,36/*tapset*/)  //  oSample8 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -448,9/*oSample*/,36/*tapset*/)  //  oSample9 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -448,11/*oSample*/,36/*tapset*/)  //  oSample11 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -448,14/*oSample*/,36/*tapset*/)  //  oSample14 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -448,16/*oSample*/,36/*tapset*/)  //  oSample16 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample14 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample14 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample14 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample14 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -448,17/*oSample*/,36/*tapset*/)  //  oSample17 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample16 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample16 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample16 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample16 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -448,19/*oSample*/,36/*tapset*/)  //  oSample19 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample17 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample17 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample17 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample17 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -448,22/*oSample*/,36/*tapset*/)  //  oSample22 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample19 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample19 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample19 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample19 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -432,2/*oSample*/,37/*tapset*/)  //  oSample2 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample22 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample22 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample22 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample22 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -432,4/*oSample*/,37/*tapset*/)  //  oSample4 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -432,5/*oSample*/,37/*tapset*/)  //  oSample5 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -432,7/*oSample*/,37/*tapset*/)  //  oSample7 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -432,10/*oSample*/,37/*tapset*/)  //  oSample10 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -432,12/*oSample*/,37/*tapset*/)  //  oSample12 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -432,13/*oSample*/,37/*tapset*/)  //  oSample13 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample12 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample12 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample12 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample12 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -432,15/*oSample*/,37/*tapset*/)  //  oSample15 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample13 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample13 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample13 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample13 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -432,18/*oSample*/,37/*tapset*/)  //  oSample18 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample15 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample15 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample15 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample15 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -432,20/*oSample*/,37/*tapset*/)  //  oSample20 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample18 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample18 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample18 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample18 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -432,21/*oSample*/,37/*tapset*/)  //  oSample21 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample20 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample20 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample20 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample20 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -432,23/*oSample*/,37/*tapset*/)  //  oSample23 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample21 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample21 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample21 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample21 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -416,0/*oSample*/,38/*tapset*/)  //  oSample0 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample23 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample23 tapSet37 Ch0  ISampleSet37 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,40/*R0 iSampleSet*/,41/*R1 iSampleSet*/) //  chan0,0 iSampleSet40,41
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample23 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample23 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -416,1/*oSample*/,38/*tapset*/)  //  oSample1 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -416,3/*oSample*/,38/*tapset*/)  //  oSample3 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -416,6/*oSample*/,38/*tapset*/)  //  oSample6 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -416,8/*oSample*/,38/*tapset*/)  //  oSample8 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -416,9/*oSample*/,38/*tapset*/)  //  oSample9 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -416,11/*oSample*/,38/*tapset*/)  //  oSample11 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -416,14/*oSample*/,38/*tapset*/)  //  oSample14 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -416,16/*oSample*/,38/*tapset*/)  //  oSample16 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample14 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample14 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample14 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample14 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -416,17/*oSample*/,38/*tapset*/)  //  oSample17 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample16 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample16 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample16 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample16 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -416,19/*oSample*/,38/*tapset*/)  //  oSample19 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample17 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample17 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample17 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample17 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -416,22/*oSample*/,38/*tapset*/)  //  oSample22 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample19 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample19 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample19 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample19 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -400,2/*oSample*/,39/*tapset*/)  //  oSample2 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample22 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample22 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample22 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample22 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -400,4/*oSample*/,39/*tapset*/)  //  oSample4 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -400,5/*oSample*/,39/*tapset*/)  //  oSample5 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -400,7/*oSample*/,39/*tapset*/)  //  oSample7 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -400,10/*oSample*/,39/*tapset*/)  //  oSample10 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -400,12/*oSample*/,39/*tapset*/)  //  oSample12 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -400,13/*oSample*/,39/*tapset*/)  //  oSample13 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample12 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample12 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample12 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample12 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -400,15/*oSample*/,39/*tapset*/)  //  oSample15 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample13 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample13 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample13 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample13 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -400,18/*oSample*/,39/*tapset*/)  //  oSample18 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample15 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample15 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample15 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample15 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -400,20/*oSample*/,39/*tapset*/)  //  oSample20 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample18 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample18 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample18 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample18 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -400,21/*oSample*/,39/*tapset*/)  //  oSample21 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample20 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample20 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample20 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample20 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -400,23/*oSample*/,39/*tapset*/)  //  oSample23 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample21 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample21 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample21 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample21 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -384,0/*oSample*/,40/*tapset*/)  //  oSample0 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample23 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample23 tapSet39 Ch0  ISampleSet39 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,42/*R0 iSampleSet*/,43/*R1 iSampleSet*/) //  chan0,0 iSampleSet42,43
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample23 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample23 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -384,1/*oSample*/,40/*tapset*/)  //  oSample1 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -384,3/*oSample*/,40/*tapset*/)  //  oSample3 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -384,6/*oSample*/,40/*tapset*/)  //  oSample6 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -384,8/*oSample*/,40/*tapset*/)  //  oSample8 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -384,9/*oSample*/,40/*tapset*/)  //  oSample9 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -384,11/*oSample*/,40/*tapset*/)  //  oSample11 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -384,14/*oSample*/,40/*tapset*/)  //  oSample14 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -384,16/*oSample*/,40/*tapset*/)  //  oSample16 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample14 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample14 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample14 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample14 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -384,17/*oSample*/,40/*tapset*/)  //  oSample17 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample16 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample16 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample16 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample16 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -384,19/*oSample*/,40/*tapset*/)  //  oSample19 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample17 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample17 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample17 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample17 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -384,22/*oSample*/,40/*tapset*/)  //  oSample22 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample19 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample19 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample19 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample19 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -368,2/*oSample*/,41/*tapset*/)  //  oSample2 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample22 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample22 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample22 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample22 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -368,4/*oSample*/,41/*tapset*/)  //  oSample4 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -368,5/*oSample*/,41/*tapset*/)  //  oSample5 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -368,7/*oSample*/,41/*tapset*/)  //  oSample7 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -368,10/*oSample*/,41/*tapset*/)  //  oSample10 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -368,12/*oSample*/,41/*tapset*/)  //  oSample12 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -368,13/*oSample*/,41/*tapset*/)  //  oSample13 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample12 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample12 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample12 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample12 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -368,15/*oSample*/,41/*tapset*/)  //  oSample15 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample13 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample13 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample13 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample13 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -368,18/*oSample*/,41/*tapset*/)  //  oSample18 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample15 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample15 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample15 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample15 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -368,20/*oSample*/,41/*tapset*/)  //  oSample20 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample18 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample18 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample18 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample18 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -368,21/*oSample*/,41/*tapset*/)  //  oSample21 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample20 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample20 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample20 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample20 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -368,23/*oSample*/,41/*tapset*/)  //  oSample23 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample21 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample21 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample21 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample21 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -352,0/*oSample*/,42/*tapset*/)  //  oSample0 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample23 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample23 tapSet41 Ch0  ISampleSet41 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,44/*R0 iSampleSet*/,45/*R1 iSampleSet*/) //  chan0,0 iSampleSet44,45
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample23 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample23 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -352,1/*oSample*/,42/*tapset*/)  //  oSample1 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -352,3/*oSample*/,42/*tapset*/)  //  oSample3 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -352,6/*oSample*/,42/*tapset*/)  //  oSample6 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -352,8/*oSample*/,42/*tapset*/)  //  oSample8 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -352,9/*oSample*/,42/*tapset*/)  //  oSample9 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -352,11/*oSample*/,42/*tapset*/)  //  oSample11 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -352,14/*oSample*/,42/*tapset*/)  //  oSample14 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -352,16/*oSample*/,42/*tapset*/)  //  oSample16 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample14 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample14 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample14 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample14 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -352,17/*oSample*/,42/*tapset*/)  //  oSample17 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample16 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample16 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample16 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample16 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -352,19/*oSample*/,42/*tapset*/)  //  oSample19 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample17 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample17 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample17 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample17 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -352,22/*oSample*/,42/*tapset*/)  //  oSample22 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample19 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample19 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample19 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample19 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -336,2/*oSample*/,43/*tapset*/)  //  oSample2 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample22 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample22 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample22 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample22 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -336,4/*oSample*/,43/*tapset*/)  //  oSample4 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -336,5/*oSample*/,43/*tapset*/)  //  oSample5 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -336,7/*oSample*/,43/*tapset*/)  //  oSample7 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -336,10/*oSample*/,43/*tapset*/)  //  oSample10 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -336,12/*oSample*/,43/*tapset*/)  //  oSample12 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -336,13/*oSample*/,43/*tapset*/)  //  oSample13 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample12 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample12 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample12 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample12 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -336,15/*oSample*/,43/*tapset*/)  //  oSample15 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample13 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample13 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample13 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample13 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -336,18/*oSample*/,43/*tapset*/)  //  oSample18 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample15 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample15 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample15 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample15 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -336,20/*oSample*/,43/*tapset*/)  //  oSample20 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample18 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample18 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample18 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample18 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -336,21/*oSample*/,43/*tapset*/)  //  oSample21 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample20 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample20 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample20 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample20 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -336,23/*oSample*/,43/*tapset*/)  //  oSample23 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample21 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample21 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample21 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample21 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -320,0/*oSample*/,44/*tapset*/)  //  oSample0 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample23 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample23 tapSet43 Ch0  ISampleSet43 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,46/*R0 iSampleSet*/,47/*R1 iSampleSet*/) //  chan0,0 iSampleSet46,47
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample23 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample23 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -320,1/*oSample*/,44/*tapset*/)  //  oSample1 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -320,3/*oSample*/,44/*tapset*/)  //  oSample3 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -320,6/*oSample*/,44/*tapset*/)  //  oSample6 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -320,8/*oSample*/,44/*tapset*/)  //  oSample8 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -320,9/*oSample*/,44/*tapset*/)  //  oSample9 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -320,11/*oSample*/,44/*tapset*/)  //  oSample11 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -320,14/*oSample*/,44/*tapset*/)  //  oSample14 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -320,16/*oSample*/,44/*tapset*/)  //  oSample16 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample14 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample14 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample14 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample14 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -320,17/*oSample*/,44/*tapset*/)  //  oSample17 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample16 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample16 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample16 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample16 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -320,19/*oSample*/,44/*tapset*/)  //  oSample19 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample17 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample17 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample17 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample17 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -320,22/*oSample*/,44/*tapset*/)  //  oSample22 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample19 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample19 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample19 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample19 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -304,2/*oSample*/,45/*tapset*/)  //  oSample2 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample22 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample22 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample22 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample22 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -304,4/*oSample*/,45/*tapset*/)  //  oSample4 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -304,5/*oSample*/,45/*tapset*/)  //  oSample5 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -304,7/*oSample*/,45/*tapset*/)  //  oSample7 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -304,10/*oSample*/,45/*tapset*/)  //  oSample10 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -304,12/*oSample*/,45/*tapset*/)  //  oSample12 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -304,13/*oSample*/,45/*tapset*/)  //  oSample13 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample12 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample12 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample12 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample12 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -304,15/*oSample*/,45/*tapset*/)  //  oSample15 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample13 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample13 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample13 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample13 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -304,18/*oSample*/,45/*tapset*/)  //  oSample18 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample15 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample15 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample15 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample15 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -304,20/*oSample*/,45/*tapset*/)  //  oSample20 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample18 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample18 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample18 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample18 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -304,21/*oSample*/,45/*tapset*/)  //  oSample21 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample20 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample20 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample20 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample20 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -304,23/*oSample*/,45/*tapset*/)  //  oSample23 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample21 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample21 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample21 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample21 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -288,0/*oSample*/,46/*tapset*/)  //  oSample0 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample23 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample23 tapSet45 Ch0  ISampleSet45 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,48/*R0 iSampleSet*/,49/*R1 iSampleSet*/) //  chan0,0 iSampleSet48,49
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample23 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample23 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -288,1/*oSample*/,46/*tapset*/)  //  oSample1 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -288,3/*oSample*/,46/*tapset*/)  //  oSample3 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -288,6/*oSample*/,46/*tapset*/)  //  oSample6 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -288,8/*oSample*/,46/*tapset*/)  //  oSample8 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -288,9/*oSample*/,46/*tapset*/)  //  oSample9 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -288,11/*oSample*/,46/*tapset*/)  //  oSample11 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -288,14/*oSample*/,46/*tapset*/)  //  oSample14 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -288,16/*oSample*/,46/*tapset*/)  //  oSample16 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample14 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample14 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample14 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample14 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -288,17/*oSample*/,46/*tapset*/)  //  oSample17 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample16 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample16 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample16 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample16 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -288,19/*oSample*/,46/*tapset*/)  //  oSample19 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample17 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample17 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample17 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample17 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -288,22/*oSample*/,46/*tapset*/)  //  oSample22 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample19 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample19 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample19 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample19 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -272,2/*oSample*/,47/*tapset*/)  //  oSample2 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample22 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample22 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample22 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample22 tapSet47 Ch0  ISampleSet47 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -272,4/*oSample*/,47/*tapset*/)  //  oSample4 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -272,5/*oSample*/,47/*tapset*/)  //  oSample5 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -272,7/*oSample*/,47/*tapset*/)  //  oSample7 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -272,10/*oSample*/,47/*tapset*/)  //  oSample10 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -272,12/*oSample*/,47/*tapset*/)  //  oSample12 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -272,13/*oSample*/,47/*tapset*/)  //  oSample13 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample12 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample12 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample12 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample12 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -272,15/*oSample*/,47/*tapset*/)  //  oSample15 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample13 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample13 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample13 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample13 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -272,18/*oSample*/,47/*tapset*/)  //  oSample18 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample15 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample15 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample15 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample15 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -272,20/*oSample*/,47/*tapset*/)  //  oSample20 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample18 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample18 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample18 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample18 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -272,21/*oSample*/,47/*tapset*/)  //  oSample21 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample20 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample20 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample20 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample20 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -272,23/*oSample*/,47/*tapset*/)  //  oSample23 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample21 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample21 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample21 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample21 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -256,0/*oSample*/,48/*tapset*/)  //  oSample0 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample23 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample23 tapSet47 Ch0  ISampleSet47 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,50/*R0 iSampleSet*/,51/*R1 iSampleSet*/) //  chan0,0 iSampleSet50,51
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample23 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample23 tapSet48 Ch0  ISampleSet48 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -256,1/*oSample*/,48/*tapset*/)  //  oSample1 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -256,3/*oSample*/,48/*tapset*/)  //  oSample3 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -256,6/*oSample*/,48/*tapset*/)  //  oSample6 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -256,8/*oSample*/,48/*tapset*/)  //  oSample8 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -256,9/*oSample*/,48/*tapset*/)  //  oSample9 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -256,11/*oSample*/,48/*tapset*/)  //  oSample11 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -256,14/*oSample*/,48/*tapset*/)  //  oSample14 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -256,16/*oSample*/,48/*tapset*/)  //  oSample16 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample14 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample14 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample14 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample14 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -256,17/*oSample*/,48/*tapset*/)  //  oSample17 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample16 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample16 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample16 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample16 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -256,19/*oSample*/,48/*tapset*/)  //  oSample19 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample17 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample17 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample17 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample17 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -256,22/*oSample*/,48/*tapset*/)  //  oSample22 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample19 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample19 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample19 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample19 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -240,2/*oSample*/,49/*tapset*/)  //  oSample2 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample22 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample22 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample22 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample22 tapSet49 Ch0  ISampleSet49 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -240,4/*oSample*/,49/*tapset*/)  //  oSample4 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -240,5/*oSample*/,49/*tapset*/)  //  oSample5 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -240,7/*oSample*/,49/*tapset*/)  //  oSample7 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -240,10/*oSample*/,49/*tapset*/)  //  oSample10 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -240,12/*oSample*/,49/*tapset*/)  //  oSample12 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -240,13/*oSample*/,49/*tapset*/)  //  oSample13 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample12 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample12 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample12 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample12 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -240,15/*oSample*/,49/*tapset*/)  //  oSample15 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample13 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample13 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample13 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample13 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -240,18/*oSample*/,49/*tapset*/)  //  oSample18 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample15 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample15 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample15 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample15 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -240,20/*oSample*/,49/*tapset*/)  //  oSample20 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample18 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample18 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample18 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample18 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -240,21/*oSample*/,49/*tapset*/)  //  oSample21 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample20 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample20 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample20 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample20 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -240,23/*oSample*/,49/*tapset*/)  //  oSample23 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample21 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample21 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample21 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample21 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -224,0/*oSample*/,50/*tapset*/)  //  oSample0 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample23 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample23 tapSet49 Ch0  ISampleSet49 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,52/*R0 iSampleSet*/,53/*R1 iSampleSet*/) //  chan0,0 iSampleSet52,53
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample23 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample23 tapSet50 Ch0  ISampleSet50 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -224,1/*oSample*/,50/*tapset*/)  //  oSample1 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -224,3/*oSample*/,50/*tapset*/)  //  oSample3 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -224,6/*oSample*/,50/*tapset*/)  //  oSample6 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -224,8/*oSample*/,50/*tapset*/)  //  oSample8 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -224,9/*oSample*/,50/*tapset*/)  //  oSample9 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -224,11/*oSample*/,50/*tapset*/)  //  oSample11 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -224,14/*oSample*/,50/*tapset*/)  //  oSample14 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -224,16/*oSample*/,50/*tapset*/)  //  oSample16 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample14 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample14 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample14 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample14 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -224,17/*oSample*/,50/*tapset*/)  //  oSample17 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample16 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample16 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample16 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample16 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -224,19/*oSample*/,50/*tapset*/)  //  oSample19 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample17 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample17 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample17 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample17 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -224,22/*oSample*/,50/*tapset*/)  //  oSample22 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample19 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample19 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample19 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample19 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -208,2/*oSample*/,51/*tapset*/)  //  oSample2 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample22 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample22 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample22 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample22 tapSet51 Ch0  ISampleSet51 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -208,4/*oSample*/,51/*tapset*/)  //  oSample4 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -208,5/*oSample*/,51/*tapset*/)  //  oSample5 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -208,7/*oSample*/,51/*tapset*/)  //  oSample7 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -208,10/*oSample*/,51/*tapset*/)  //  oSample10 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -208,12/*oSample*/,51/*tapset*/)  //  oSample12 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -208,13/*oSample*/,51/*tapset*/)  //  oSample13 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample12 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample12 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample12 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample12 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -208,15/*oSample*/,51/*tapset*/)  //  oSample15 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample13 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample13 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample13 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample13 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -208,18/*oSample*/,51/*tapset*/)  //  oSample18 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample15 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample15 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample15 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample15 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -208,20/*oSample*/,51/*tapset*/)  //  oSample20 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample18 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample18 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample18 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample18 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -208,21/*oSample*/,51/*tapset*/)  //  oSample21 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample20 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample20 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample20 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample20 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -208,23/*oSample*/,51/*tapset*/)  //  oSample23 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample21 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample21 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample21 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample21 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -192,0/*oSample*/,52/*tapset*/)  //  oSample0 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample23 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample23 tapSet51 Ch0  ISampleSet51 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,54/*R0 iSampleSet*/,55/*R1 iSampleSet*/) //  chan0,0 iSampleSet54,55
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample23 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample23 tapSet52 Ch0  ISampleSet52 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -192,1/*oSample*/,52/*tapset*/)  //  oSample1 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -192,3/*oSample*/,52/*tapset*/)  //  oSample3 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -192,6/*oSample*/,52/*tapset*/)  //  oSample6 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -192,8/*oSample*/,52/*tapset*/)  //  oSample8 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -192,9/*oSample*/,52/*tapset*/)  //  oSample9 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -192,11/*oSample*/,52/*tapset*/)  //  oSample11 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -192,14/*oSample*/,52/*tapset*/)  //  oSample14 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -192,16/*oSample*/,52/*tapset*/)  //  oSample16 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample14 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample14 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample14 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample14 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -192,17/*oSample*/,52/*tapset*/)  //  oSample17 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample16 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample16 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample16 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample16 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -192,19/*oSample*/,52/*tapset*/)  //  oSample19 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample17 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample17 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample17 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample17 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -192,22/*oSample*/,52/*tapset*/)  //  oSample22 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample19 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample19 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample19 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample19 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -176,2/*oSample*/,53/*tapset*/)  //  oSample2 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample22 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample22 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample22 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample22 tapSet53 Ch0  ISampleSet53 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -176,4/*oSample*/,53/*tapset*/)  //  oSample4 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -176,5/*oSample*/,53/*tapset*/)  //  oSample5 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -176,7/*oSample*/,53/*tapset*/)  //  oSample7 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -176,10/*oSample*/,53/*tapset*/)  //  oSample10 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -176,12/*oSample*/,53/*tapset*/)  //  oSample12 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -176,13/*oSample*/,53/*tapset*/)  //  oSample13 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample12 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample12 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample12 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample12 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -176,15/*oSample*/,53/*tapset*/)  //  oSample15 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample13 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample13 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample13 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample13 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -176,18/*oSample*/,53/*tapset*/)  //  oSample18 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample15 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample15 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample15 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample15 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -176,20/*oSample*/,53/*tapset*/)  //  oSample20 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample18 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample18 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample18 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample18 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -176,21/*oSample*/,53/*tapset*/)  //  oSample21 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample20 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample20 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample20 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample20 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -176,23/*oSample*/,53/*tapset*/)  //  oSample23 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample21 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample21 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample21 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample21 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -160,0/*oSample*/,54/*tapset*/)  //  oSample0 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample23 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample23 tapSet53 Ch0  ISampleSet53 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,56/*R0 iSampleSet*/,57/*R1 iSampleSet*/) //  chan0,0 iSampleSet56,57
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample23 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample23 tapSet54 Ch0  ISampleSet54 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -160,1/*oSample*/,54/*tapset*/)  //  oSample1 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -160,3/*oSample*/,54/*tapset*/)  //  oSample3 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -160,6/*oSample*/,54/*tapset*/)  //  oSample6 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -160,8/*oSample*/,54/*tapset*/)  //  oSample8 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -160,9/*oSample*/,54/*tapset*/)  //  oSample9 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -160,11/*oSample*/,54/*tapset*/)  //  oSample11 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -160,14/*oSample*/,54/*tapset*/)  //  oSample14 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -160,16/*oSample*/,54/*tapset*/)  //  oSample16 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample14 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample14 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample14 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample14 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -160,17/*oSample*/,54/*tapset*/)  //  oSample17 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample16 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample16 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample16 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample16 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -160,19/*oSample*/,54/*tapset*/)  //  oSample19 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample17 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample17 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample17 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample17 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -160,22/*oSample*/,54/*tapset*/)  //  oSample22 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample19 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample19 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample19 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample19 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -144,2/*oSample*/,55/*tapset*/)  //  oSample2 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample22 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample22 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample22 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample22 tapSet55 Ch0  ISampleSet55 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -144,4/*oSample*/,55/*tapset*/)  //  oSample4 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -144,5/*oSample*/,55/*tapset*/)  //  oSample5 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -144,7/*oSample*/,55/*tapset*/)  //  oSample7 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -144,10/*oSample*/,55/*tapset*/)  //  oSample10 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -144,12/*oSample*/,55/*tapset*/)  //  oSample12 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -144,13/*oSample*/,55/*tapset*/)  //  oSample13 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample12 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample12 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample12 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample12 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -144,15/*oSample*/,55/*tapset*/)  //  oSample15 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample13 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample13 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample13 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample13 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -144,18/*oSample*/,55/*tapset*/)  //  oSample18 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample15 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample15 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample15 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample15 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -144,20/*oSample*/,55/*tapset*/)  //  oSample20 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample18 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample18 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample18 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample18 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -144,21/*oSample*/,55/*tapset*/)  //  oSample21 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample20 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample20 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample20 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample20 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -144,23/*oSample*/,55/*tapset*/)  //  oSample23 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample21 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample21 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample21 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample21 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -128,0/*oSample*/,56/*tapset*/)  //  oSample0 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample23 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample23 tapSet55 Ch0  ISampleSet55 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,58/*R0 iSampleSet*/,59/*R1 iSampleSet*/) //  chan0,0 iSampleSet58,59
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample23 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample23 tapSet56 Ch0  ISampleSet56 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -128,1/*oSample*/,56/*tapset*/)  //  oSample1 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -128,3/*oSample*/,56/*tapset*/)  //  oSample3 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -128,6/*oSample*/,56/*tapset*/)  //  oSample6 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -128,8/*oSample*/,56/*tapset*/)  //  oSample8 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -128,9/*oSample*/,56/*tapset*/)  //  oSample9 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -128,11/*oSample*/,56/*tapset*/)  //  oSample11 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -128,14/*oSample*/,56/*tapset*/)  //  oSample14 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -128,16/*oSample*/,56/*tapset*/)  //  oSample16 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample14 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample14 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample14 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample14 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -128,17/*oSample*/,56/*tapset*/)  //  oSample17 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample16 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample16 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample16 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample16 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -128,19/*oSample*/,56/*tapset*/)  //  oSample19 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample17 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample17 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample17 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample17 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -128,22/*oSample*/,56/*tapset*/)  //  oSample22 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample19 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample19 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample19 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample19 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -112,2/*oSample*/,57/*tapset*/)  //  oSample2 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample22 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample22 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample22 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample22 tapSet57 Ch0  ISampleSet57 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -112,4/*oSample*/,57/*tapset*/)  //  oSample4 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -112,5/*oSample*/,57/*tapset*/)  //  oSample5 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -112,7/*oSample*/,57/*tapset*/)  //  oSample7 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -112,10/*oSample*/,57/*tapset*/)  //  oSample10 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -112,12/*oSample*/,57/*tapset*/)  //  oSample12 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -112,13/*oSample*/,57/*tapset*/)  //  oSample13 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample12 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample12 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample12 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample12 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -112,15/*oSample*/,57/*tapset*/)  //  oSample15 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample13 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample13 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample13 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample13 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -112,18/*oSample*/,57/*tapset*/)  //  oSample18 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample15 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample15 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample15 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample15 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -112,20/*oSample*/,57/*tapset*/)  //  oSample20 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample18 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample18 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample18 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample18 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -112,21/*oSample*/,57/*tapset*/)  //  oSample21 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample20 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample20 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample20 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample20 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -112,23/*oSample*/,57/*tapset*/)  //  oSample23 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample21 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample21 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample21 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample21 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -96,0/*oSample*/,58/*tapset*/)  //  oSample0 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample23 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample23 tapSet57 Ch0  ISampleSet57 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,60/*R0 iSampleSet*/,61/*R1 iSampleSet*/) //  chan0,0 iSampleSet60,61
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample23 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample23 tapSet58 Ch0  ISampleSet58 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -96,1/*oSample*/,58/*tapset*/)  //  oSample1 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -96,3/*oSample*/,58/*tapset*/)  //  oSample3 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -96,6/*oSample*/,58/*tapset*/)  //  oSample6 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -96,8/*oSample*/,58/*tapset*/)  //  oSample8 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -96,9/*oSample*/,58/*tapset*/)  //  oSample9 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -96,11/*oSample*/,58/*tapset*/)  //  oSample11 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -96,14/*oSample*/,58/*tapset*/)  //  oSample14 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -96,16/*oSample*/,58/*tapset*/)  //  oSample16 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample14 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample14 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample14 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample14 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -96,17/*oSample*/,58/*tapset*/)  //  oSample17 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample16 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample16 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample16 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample16 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -96,19/*oSample*/,58/*tapset*/)  //  oSample19 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample17 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample17 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample17 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample17 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -96,22/*oSample*/,58/*tapset*/)  //  oSample22 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample19 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample19 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample19 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample19 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -80,2/*oSample*/,59/*tapset*/)  //  oSample2 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample22 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample22 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample22 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample22 tapSet59 Ch0  ISampleSet59 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -80,4/*oSample*/,59/*tapset*/)  //  oSample4 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -80,5/*oSample*/,59/*tapset*/)  //  oSample5 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -80,7/*oSample*/,59/*tapset*/)  //  oSample7 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -80,10/*oSample*/,59/*tapset*/)  //  oSample10 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -80,12/*oSample*/,59/*tapset*/)  //  oSample12 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -80,13/*oSample*/,59/*tapset*/)  //  oSample13 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample12 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample12 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample12 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample12 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -80,15/*oSample*/,59/*tapset*/)  //  oSample15 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample13 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample13 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample13 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample13 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -80,18/*oSample*/,59/*tapset*/)  //  oSample18 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample15 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample15 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample15 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample15 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -80,20/*oSample*/,59/*tapset*/)  //  oSample20 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample18 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample18 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample18 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample18 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -80,21/*oSample*/,59/*tapset*/)  //  oSample21 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample20 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample20 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample20 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample20 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -80,23/*oSample*/,59/*tapset*/)  //  oSample23 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample21 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample21 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample21 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample21 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -64,0/*oSample*/,60/*tapset*/)  //  oSample0 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample23 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample23 tapSet59 Ch0  ISampleSet59 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,62/*R0 iSampleSet*/,63/*R1 iSampleSet*/) //  chan0,0 iSampleSet62,63
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample23 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample23 tapSet60 Ch0  ISampleSet60 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -64,1/*oSample*/,60/*tapset*/)  //  oSample1 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -64,3/*oSample*/,60/*tapset*/)  //  oSample3 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -64,6/*oSample*/,60/*tapset*/)  //  oSample6 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -64,8/*oSample*/,60/*tapset*/)  //  oSample8 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -64,9/*oSample*/,60/*tapset*/)  //  oSample9 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -64,11/*oSample*/,60/*tapset*/)  //  oSample11 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -64,14/*oSample*/,60/*tapset*/)  //  oSample14 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -64,16/*oSample*/,60/*tapset*/)  //  oSample16 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample14 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample14 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample14 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample14 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -64,17/*oSample*/,60/*tapset*/)  //  oSample17 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample16 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample16 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample16 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample16 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -64,19/*oSample*/,60/*tapset*/)  //  oSample19 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample17 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample17 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample17 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample17 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -64,22/*oSample*/,60/*tapset*/)  //  oSample22 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample19 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample19 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample19 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample19 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -48,2/*oSample*/,61/*tapset*/)  //  oSample2 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample22 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample22 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample22 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample22 tapSet61 Ch0  ISampleSet61 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -48,4/*oSample*/,61/*tapset*/)  //  oSample4 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -48,5/*oSample*/,61/*tapset*/)  //  oSample5 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -48,7/*oSample*/,61/*tapset*/)  //  oSample7 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -48,10/*oSample*/,61/*tapset*/)  //  oSample10 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -48,12/*oSample*/,61/*tapset*/)  //  oSample12 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -48,13/*oSample*/,61/*tapset*/)  //  oSample13 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample12 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample12 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample12 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample12 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -48,15/*oSample*/,61/*tapset*/)  //  oSample15 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample13 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample13 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample13 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample13 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -48,18/*oSample*/,61/*tapset*/)  //  oSample18 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample15 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample15 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample15 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample15 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -48,20/*oSample*/,61/*tapset*/)  //  oSample20 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample18 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample18 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample18 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample18 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -48,21/*oSample*/,61/*tapset*/)  //  oSample21 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample20 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample20 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample20 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample20 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -48,23/*oSample*/,61/*tapset*/)  //  oSample23 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample21 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample21 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample21 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample21 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -32,0/*oSample*/,62/*tapset*/)  //  oSample0 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample23 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample23 tapSet61 Ch0  ISampleSet61 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,64/*R0 iSampleSet*/,65/*R1 iSampleSet*/) //  chan0,0 iSampleSet64,65
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample23 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample23 tapSet62 Ch0  ISampleSet62 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -32,1/*oSample*/,62/*tapset*/)  //  oSample1 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -32,3/*oSample*/,62/*tapset*/)  //  oSample3 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -32,6/*oSample*/,62/*tapset*/)  //  oSample6 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -32,8/*oSample*/,62/*tapset*/)  //  oSample8 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -32,9/*oSample*/,62/*tapset*/)  //  oSample9 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -32,11/*oSample*/,62/*tapset*/)  //  oSample11 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -32,14/*oSample*/,62/*tapset*/)  //  oSample14 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -32,16/*oSample*/,62/*tapset*/)  //  oSample16 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample14 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample14 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample14 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample14 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -32,17/*oSample*/,62/*tapset*/)  //  oSample17 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample16 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample16 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample16 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample16 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -32,19/*oSample*/,62/*tapset*/)  //  oSample19 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample17 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample17 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample17 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample17 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -32,22/*oSample*/,62/*tapset*/)  //  oSample22 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample19 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample19 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample19 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample19 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -16,2/*oSample*/,63/*tapset*/)  //  oSample2 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample22 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample22 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample22 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample22 tapSet63 Ch0  ISampleSet63 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -16,4/*oSample*/,63/*tapset*/)  //  oSample4 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -16,5/*oSample*/,63/*tapset*/)  //  oSample5 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -16,7/*oSample*/,63/*tapset*/)  //  oSample7 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -16,10/*oSample*/,63/*tapset*/)  //  oSample10 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -16,12/*oSample*/,63/*tapset*/)  //  oSample12 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -16,13/*oSample*/,63/*tapset*/)  //  oSample13 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample12 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample12 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample12 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample12 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -16,15/*oSample*/,63/*tapset*/)  //  oSample15 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample13 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample13 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample13 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample13 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -16,18/*oSample*/,63/*tapset*/)  //  oSample18 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample15 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample15 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample15 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample15 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -16,20/*oSample*/,63/*tapset*/)  //  oSample20 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample18 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample18 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample18 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample18 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -16,21/*oSample*/,63/*tapset*/)  //  oSample21 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample20 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample20 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample20 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample20 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -16,23/*oSample*/,63/*tapset*/)  //  oSample23 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample21 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample21 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample21 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample21 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 0,0/*oSample*/,64/*tapset*/)  //  oSample0 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample23 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample23 tapSet63 Ch0  ISampleSet63 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,66/*R0 iSampleSet*/,67/*R1 iSampleSet*/) //  chan0,0 iSampleSet66,67
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample23 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample23 tapSet64 Ch0  ISampleSet64 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 0,1/*oSample*/,64/*tapset*/)  //  oSample1 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 0,3/*oSample*/,64/*tapset*/)  //  oSample3 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 0,6/*oSample*/,64/*tapset*/)  //  oSample6 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 0,8/*oSample*/,64/*tapset*/)  //  oSample8 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 0,9/*oSample*/,64/*tapset*/)  //  oSample9 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 0,11/*oSample*/,64/*tapset*/)  //  oSample11 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 0,14/*oSample*/,64/*tapset*/)  //  oSample14 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 0,16/*oSample*/,64/*tapset*/)  //  oSample16 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample14 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample14 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample14 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample14 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 0,17/*oSample*/,64/*tapset*/)  //  oSample17 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample16 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample16 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample16 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample16 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 0,19/*oSample*/,64/*tapset*/)  //  oSample19 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample17 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample17 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample17 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample17 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 0,22/*oSample*/,64/*tapset*/)  //  oSample22 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample19 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample19 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample19 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample19 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 16,2/*oSample*/,65/*tapset*/)  //  oSample2 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample22 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample22 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample22 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample22 tapSet65 Ch0  ISampleSet65 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 16,4/*oSample*/,65/*tapset*/)  //  oSample4 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 16,5/*oSample*/,65/*tapset*/)  //  oSample5 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 16,7/*oSample*/,65/*tapset*/)  //  oSample7 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 16,10/*oSample*/,65/*tapset*/)  //  oSample10 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 16,12/*oSample*/,65/*tapset*/)  //  oSample12 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 16,13/*oSample*/,65/*tapset*/)  //  oSample13 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample12 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample12 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample12 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample12 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 16,15/*oSample*/,65/*tapset*/)  //  oSample15 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample13 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample13 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample13 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample13 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 16,18/*oSample*/,65/*tapset*/)  //  oSample18 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample15 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample15 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample15 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample15 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 16,20/*oSample*/,65/*tapset*/)  //  oSample20 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample18 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample18 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample18 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample18 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 16,21/*oSample*/,65/*tapset*/)  //  oSample21 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample20 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample20 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample20 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample20 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 16,23/*oSample*/,65/*tapset*/)  //  oSample23 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample21 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample21 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample21 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample21 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 32,0/*oSample*/,66/*tapset*/)  //  oSample0 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample23 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample23 tapSet65 Ch0  ISampleSet65 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,68/*R0 iSampleSet*/,69/*R1 iSampleSet*/) //  chan0,0 iSampleSet68,69
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample23 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample23 tapSet66 Ch0  ISampleSet66 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 32,1/*oSample*/,66/*tapset*/)  //  oSample1 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 32,3/*oSample*/,66/*tapset*/)  //  oSample3 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 32,6/*oSample*/,66/*tapset*/)  //  oSample6 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 32,8/*oSample*/,66/*tapset*/)  //  oSample8 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 32,9/*oSample*/,66/*tapset*/)  //  oSample9 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 32,11/*oSample*/,66/*tapset*/)  //  oSample11 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 32,14/*oSample*/,66/*tapset*/)  //  oSample14 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 32,16/*oSample*/,66/*tapset*/)  //  oSample16 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample14 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample14 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample14 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample14 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 32,17/*oSample*/,66/*tapset*/)  //  oSample17 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample16 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample16 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample16 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample16 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 32,19/*oSample*/,66/*tapset*/)  //  oSample19 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample17 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample17 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample17 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample17 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 32,22/*oSample*/,66/*tapset*/)  //  oSample22 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample19 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample19 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample19 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample19 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 48,2/*oSample*/,67/*tapset*/)  //  oSample2 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample22 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample22 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample22 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample22 tapSet67 Ch0  ISampleSet67 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 48,4/*oSample*/,67/*tapset*/)  //  oSample4 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 48,5/*oSample*/,67/*tapset*/)  //  oSample5 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 48,7/*oSample*/,67/*tapset*/)  //  oSample7 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 48,10/*oSample*/,67/*tapset*/)  //  oSample10 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 48,12/*oSample*/,67/*tapset*/)  //  oSample12 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 48,13/*oSample*/,67/*tapset*/)  //  oSample13 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample12 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample12 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample12 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample12 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 48,15/*oSample*/,67/*tapset*/)  //  oSample15 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample13 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample13 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample13 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample13 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 48,18/*oSample*/,67/*tapset*/)  //  oSample18 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample15 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample15 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample15 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample15 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 48,20/*oSample*/,67/*tapset*/)  //  oSample20 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample18 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample18 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample18 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample18 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 48,21/*oSample*/,67/*tapset*/)  //  oSample21 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample20 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample20 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample20 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample20 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 48,23/*oSample*/,67/*tapset*/)  //  oSample23 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample21 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample21 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample21 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample21 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 64,0/*oSample*/,68/*tapset*/)  //  oSample0 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample23 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample23 tapSet67 Ch0  ISampleSet67 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,70/*R0 iSampleSet*/,71/*R1 iSampleSet*/) //  chan0,0 iSampleSet70,71
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample23 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample23 tapSet68 Ch0  ISampleSet68 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 64,1/*oSample*/,68/*tapset*/)  //  oSample1 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 64,3/*oSample*/,68/*tapset*/)  //  oSample3 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 64,6/*oSample*/,68/*tapset*/)  //  oSample6 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 64,8/*oSample*/,68/*tapset*/)  //  oSample8 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 64,9/*oSample*/,68/*tapset*/)  //  oSample9 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 64,11/*oSample*/,68/*tapset*/)  //  oSample11 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 64,14/*oSample*/,68/*tapset*/)  //  oSample14 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 64,16/*oSample*/,68/*tapset*/)  //  oSample16 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample14 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample14 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample14 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample14 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 64,17/*oSample*/,68/*tapset*/)  //  oSample17 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample16 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample16 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample16 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample16 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 64,19/*oSample*/,68/*tapset*/)  //  oSample19 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample17 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample17 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample17 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample17 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 64,22/*oSample*/,68/*tapset*/)  //  oSample22 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample19 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample19 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample19 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample19 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 80,2/*oSample*/,69/*tapset*/)  //  oSample2 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample22 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample22 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample22 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample22 tapSet69 Ch0  ISampleSet69 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 80,4/*oSample*/,69/*tapset*/)  //  oSample4 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 80,5/*oSample*/,69/*tapset*/)  //  oSample5 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 80,7/*oSample*/,69/*tapset*/)  //  oSample7 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 80,10/*oSample*/,69/*tapset*/)  //  oSample10 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 80,12/*oSample*/,69/*tapset*/)  //  oSample12 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 80,13/*oSample*/,69/*tapset*/)  //  oSample13 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample12 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample12 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample12 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample12 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 80,15/*oSample*/,69/*tapset*/)  //  oSample15 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample13 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample13 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample13 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample13 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 80,18/*oSample*/,69/*tapset*/)  //  oSample18 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample15 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample15 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample15 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample15 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 80,20/*oSample*/,69/*tapset*/)  //  oSample20 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample18 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample18 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample18 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample18 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 80,21/*oSample*/,69/*tapset*/)  //  oSample21 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample20 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample20 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample20 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample20 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 80,23/*oSample*/,69/*tapset*/)  //  oSample23 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample21 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample21 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample21 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample21 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 96,0/*oSample*/,70/*tapset*/)  //  oSample0 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample23 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample23 tapSet69 Ch0  ISampleSet69 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,72/*R0 iSampleSet*/,73/*R1 iSampleSet*/) //  chan0,0 iSampleSet72,73
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample23 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample23 tapSet70 Ch0  ISampleSet70 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 96,1/*oSample*/,70/*tapset*/)  //  oSample1 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 96,3/*oSample*/,70/*tapset*/)  //  oSample3 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 96,6/*oSample*/,70/*tapset*/)  //  oSample6 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 96,8/*oSample*/,70/*tapset*/)  //  oSample8 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 96,9/*oSample*/,70/*tapset*/)  //  oSample9 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 96,11/*oSample*/,70/*tapset*/)  //  oSample11 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 96,14/*oSample*/,70/*tapset*/)  //  oSample14 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 96,16/*oSample*/,70/*tapset*/)  //  oSample16 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample14 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample14 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample14 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample14 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 96,17/*oSample*/,70/*tapset*/)  //  oSample17 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample16 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample16 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample16 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample16 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 96,19/*oSample*/,70/*tapset*/)  //  oSample19 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample17 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample17 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample17 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample17 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 96,22/*oSample*/,70/*tapset*/)  //  oSample22 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample19 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample19 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample19 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample19 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 112,2/*oSample*/,71/*tapset*/)  //  oSample2 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample22 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample22 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample22 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample22 tapSet71 Ch0  ISampleSet71 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 112,4/*oSample*/,71/*tapset*/)  //  oSample4 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 112,5/*oSample*/,71/*tapset*/)  //  oSample5 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 112,7/*oSample*/,71/*tapset*/)  //  oSample7 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 112,10/*oSample*/,71/*tapset*/)  //  oSample10 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 112,12/*oSample*/,71/*tapset*/)  //  oSample12 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 112,13/*oSample*/,71/*tapset*/)  //  oSample13 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample12 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample12 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample12 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample12 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 112,15/*oSample*/,71/*tapset*/)  //  oSample15 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample13 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample13 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample13 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample13 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 112,18/*oSample*/,71/*tapset*/)  //  oSample18 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample15 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample15 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample15 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample15 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 112,20/*oSample*/,71/*tapset*/)  //  oSample20 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample18 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample18 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample18 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample18 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 112,21/*oSample*/,71/*tapset*/)  //  oSample21 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample20 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample20 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample20 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample20 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 112,23/*oSample*/,71/*tapset*/)  //  oSample23 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample21 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample21 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample21 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample21 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 128,0/*oSample*/,72/*tapset*/)  //  oSample0 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample23 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample23 tapSet71 Ch0  ISampleSet71 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,74/*R0 iSampleSet*/,75/*R1 iSampleSet*/) //  chan0,0 iSampleSet74,75
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample23 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample23 tapSet72 Ch0  ISampleSet72 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 128,1/*oSample*/,72/*tapset*/)  //  oSample1 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 128,3/*oSample*/,72/*tapset*/)  //  oSample3 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 128,6/*oSample*/,72/*tapset*/)  //  oSample6 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 128,8/*oSample*/,72/*tapset*/)  //  oSample8 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 128,9/*oSample*/,72/*tapset*/)  //  oSample9 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 128,11/*oSample*/,72/*tapset*/)  //  oSample11 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 128,14/*oSample*/,72/*tapset*/)  //  oSample14 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 128,16/*oSample*/,72/*tapset*/)  //  oSample16 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample14 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample14 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample14 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample14 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 128,17/*oSample*/,72/*tapset*/)  //  oSample17 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample16 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample16 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample16 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample16 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 128,19/*oSample*/,72/*tapset*/)  //  oSample19 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample17 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample17 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample17 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample17 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 128,22/*oSample*/,72/*tapset*/)  //  oSample22 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample19 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample19 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample19 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample19 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 144,2/*oSample*/,73/*tapset*/)  //  oSample2 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample22 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample22 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample22 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample22 tapSet73 Ch0  ISampleSet73 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 144,4/*oSample*/,73/*tapset*/)  //  oSample4 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 144,5/*oSample*/,73/*tapset*/)  //  oSample5 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 144,7/*oSample*/,73/*tapset*/)  //  oSample7 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 144,10/*oSample*/,73/*tapset*/)  //  oSample10 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 144,12/*oSample*/,73/*tapset*/)  //  oSample12 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 144,13/*oSample*/,73/*tapset*/)  //  oSample13 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample12 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample12 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample12 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample12 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 144,15/*oSample*/,73/*tapset*/)  //  oSample15 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample13 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample13 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample13 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample13 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 144,18/*oSample*/,73/*tapset*/)  //  oSample18 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample15 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample15 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample15 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample15 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 144,20/*oSample*/,73/*tapset*/)  //  oSample20 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample18 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample18 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample18 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample18 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 144,21/*oSample*/,73/*tapset*/)  //  oSample21 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample20 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample20 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample20 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample20 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 144,23/*oSample*/,73/*tapset*/)  //  oSample23 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample21 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample21 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample21 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample21 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 160,0/*oSample*/,74/*tapset*/)  //  oSample0 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample23 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample23 tapSet73 Ch0  ISampleSet73 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,76/*R0 iSampleSet*/,77/*R1 iSampleSet*/) //  chan0,0 iSampleSet76,77
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample23 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample23 tapSet74 Ch0  ISampleSet74 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 160,1/*oSample*/,74/*tapset*/)  //  oSample1 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 160,3/*oSample*/,74/*tapset*/)  //  oSample3 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 160,6/*oSample*/,74/*tapset*/)  //  oSample6 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 160,8/*oSample*/,74/*tapset*/)  //  oSample8 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 160,9/*oSample*/,74/*tapset*/)  //  oSample9 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 160,11/*oSample*/,74/*tapset*/)  //  oSample11 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 160,14/*oSample*/,74/*tapset*/)  //  oSample14 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 160,16/*oSample*/,74/*tapset*/)  //  oSample16 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample14 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample14 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample14 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample14 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 160,17/*oSample*/,74/*tapset*/)  //  oSample17 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample16 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample16 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample16 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample16 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 160,19/*oSample*/,74/*tapset*/)  //  oSample19 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample17 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample17 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample17 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample17 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 160,22/*oSample*/,74/*tapset*/)  //  oSample22 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample19 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample19 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample19 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample19 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 176,2/*oSample*/,75/*tapset*/)  //  oSample2 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample22 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample22 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample22 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample22 tapSet75 Ch0  ISampleSet75 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 176,4/*oSample*/,75/*tapset*/)  //  oSample4 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 176,5/*oSample*/,75/*tapset*/)  //  oSample5 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 176,7/*oSample*/,75/*tapset*/)  //  oSample7 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 176,10/*oSample*/,75/*tapset*/)  //  oSample10 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 176,12/*oSample*/,75/*tapset*/)  //  oSample12 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 176,13/*oSample*/,75/*tapset*/)  //  oSample13 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample12 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample12 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample12 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample12 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 176,15/*oSample*/,75/*tapset*/)  //  oSample15 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample13 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample13 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample13 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample13 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 176,18/*oSample*/,75/*tapset*/)  //  oSample18 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample15 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample15 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample15 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample15 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 176,20/*oSample*/,75/*tapset*/)  //  oSample20 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample18 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample18 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample18 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample18 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 176,21/*oSample*/,75/*tapset*/)  //  oSample21 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample20 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample20 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample20 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample20 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 176,23/*oSample*/,75/*tapset*/)  //  oSample23 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample21 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample21 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample21 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample21 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 192,0/*oSample*/,76/*tapset*/)  //  oSample0 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample23 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample23 tapSet75 Ch0  ISampleSet75 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,78/*R0 iSampleSet*/,79/*R1 iSampleSet*/) //  chan0,0 iSampleSet78,79
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample23 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample23 tapSet76 Ch0  ISampleSet76 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 192,1/*oSample*/,76/*tapset*/)  //  oSample1 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 192,3/*oSample*/,76/*tapset*/)  //  oSample3 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 192,6/*oSample*/,76/*tapset*/)  //  oSample6 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 192,8/*oSample*/,76/*tapset*/)  //  oSample8 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 192,9/*oSample*/,76/*tapset*/)  //  oSample9 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 192,11/*oSample*/,76/*tapset*/)  //  oSample11 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 192,14/*oSample*/,76/*tapset*/)  //  oSample14 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 192,16/*oSample*/,76/*tapset*/)  //  oSample16 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample14 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample14 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample14 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample14 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 192,17/*oSample*/,76/*tapset*/)  //  oSample17 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample16 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample16 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample16 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample16 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 192,19/*oSample*/,76/*tapset*/)  //  oSample19 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample17 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample17 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample17 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample17 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 192,22/*oSample*/,76/*tapset*/)  //  oSample22 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample19 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample19 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample19 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample19 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 208,2/*oSample*/,77/*tapset*/)  //  oSample2 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample22 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample22 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample22 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample22 tapSet77 Ch0  ISampleSet77 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 208,4/*oSample*/,77/*tapset*/)  //  oSample4 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 208,5/*oSample*/,77/*tapset*/)  //  oSample5 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 208,7/*oSample*/,77/*tapset*/)  //  oSample7 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 208,10/*oSample*/,77/*tapset*/)  //  oSample10 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 208,12/*oSample*/,77/*tapset*/)  //  oSample12 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 208,13/*oSample*/,77/*tapset*/)  //  oSample13 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample12 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample12 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample12 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample12 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 208,15/*oSample*/,77/*tapset*/)  //  oSample15 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample13 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample13 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample13 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample13 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 208,18/*oSample*/,77/*tapset*/)  //  oSample18 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample15 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample15 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample15 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample15 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 208,20/*oSample*/,77/*tapset*/)  //  oSample20 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample18 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample18 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample18 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample18 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 208,21/*oSample*/,77/*tapset*/)  //  oSample21 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample20 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample20 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample20 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample20 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 208,23/*oSample*/,77/*tapset*/)  //  oSample23 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample21 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample21 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample21 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample21 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 224,0/*oSample*/,78/*tapset*/)  //  oSample0 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample23 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample23 tapSet77 Ch0  ISampleSet77 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,80/*R0 iSampleSet*/,81/*R1 iSampleSet*/) //  chan0,0 iSampleSet80,81
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample23 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample23 tapSet78 Ch0  ISampleSet78 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 224,1/*oSample*/,78/*tapset*/)  //  oSample1 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 224,3/*oSample*/,78/*tapset*/)  //  oSample3 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 224,6/*oSample*/,78/*tapset*/)  //  oSample6 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 224,8/*oSample*/,78/*tapset*/)  //  oSample8 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 224,9/*oSample*/,78/*tapset*/)  //  oSample9 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 224,11/*oSample*/,78/*tapset*/)  //  oSample11 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 224,14/*oSample*/,78/*tapset*/)  //  oSample14 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 224,16/*oSample*/,78/*tapset*/)  //  oSample16 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample14 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample14 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample14 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample14 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 224,17/*oSample*/,78/*tapset*/)  //  oSample17 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample16 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample16 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample16 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample16 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 224,19/*oSample*/,78/*tapset*/)  //  oSample19 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample17 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample17 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample17 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample17 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 224,22/*oSample*/,78/*tapset*/)  //  oSample22 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample19 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample19 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample19 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample19 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 240,2/*oSample*/,79/*tapset*/)  //  oSample2 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample22 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample22 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample22 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample22 tapSet79 Ch0  ISampleSet79 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 240,4/*oSample*/,79/*tapset*/)  //  oSample4 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 240,5/*oSample*/,79/*tapset*/)  //  oSample5 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 240,7/*oSample*/,79/*tapset*/)  //  oSample7 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 240,10/*oSample*/,79/*tapset*/)  //  oSample10 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 240,12/*oSample*/,79/*tapset*/)  //  oSample12 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 240,13/*oSample*/,79/*tapset*/)  //  oSample13 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample12 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample12 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample12 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample12 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 240,15/*oSample*/,79/*tapset*/)  //  oSample15 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample13 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample13 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample13 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample13 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 240,18/*oSample*/,79/*tapset*/)  //  oSample18 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample15 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample15 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample15 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample15 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 240,20/*oSample*/,79/*tapset*/)  //  oSample20 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample18 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample18 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample18 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample18 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 240,21/*oSample*/,79/*tapset*/)  //  oSample21 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample20 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample20 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample20 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample20 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 240,23/*oSample*/,79/*tapset*/)  //  oSample23 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample21 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample21 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample21 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample21 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, 256,0/*oSample*/,80/*tapset*/)  //  oSample0 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample23 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample23 tapSet79 Ch0  ISampleSet79 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,82/*R0 iSampleSet*/,83/*R1 iSampleSet*/) //  chan0,0 iSampleSet82,83
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample23 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample23 tapSet80 Ch0  ISampleSet80 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 256,1/*oSample*/,80/*tapset*/)  //  oSample1 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 256,3/*oSample*/,80/*tapset*/)  //  oSample3 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 256,6/*oSample*/,80/*tapset*/)  //  oSample6 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M1,3/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 256,8/*oSample*/,80/*tapset*/)  //  oSample8 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M1,6/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 256,9/*oSample*/,80/*tapset*/)  //  oSample9 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 256,11/*oSample*/,80/*tapset*/)  //  oSample11 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 256,14/*oSample*/,80/*tapset*/)  //  oSample14 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 256,16/*oSample*/,80/*tapset*/)  //  oSample16 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample14 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample14 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample14 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample14 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 256,17/*oSample*/,80/*tapset*/)  //  oSample17 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample16 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample16 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample16 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample16 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 256,19/*oSample*/,80/*tapset*/)  //  oSample19 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample17 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample17 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample17 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample17 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 256,22/*oSample*/,80/*tapset*/)  //  oSample22 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample19 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample19 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample19 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample19 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 272,2/*oSample*/,81/*tapset*/)  //  oSample2 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample22 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample22 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample22 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample22 tapSet81 Ch0  ISampleSet81 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 272,4/*oSample*/,81/*tapset*/)  //  oSample4 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 272,5/*oSample*/,81/*tapset*/)  //  oSample5 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M0,4/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 272,7/*oSample*/,81/*tapset*/)  //  oSample7 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M0,5/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 272,10/*oSample*/,81/*tapset*/)  //  oSample10 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M0,7/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 272,12/*oSample*/,81/*tapset*/)  //  oSample12 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 272,13/*oSample*/,81/*tapset*/)  //  oSample13 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample12 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample12 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample12 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample12 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 272,15/*oSample*/,81/*tapset*/)  //  oSample15 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample13 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample13 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample13 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample13 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 272,18/*oSample*/,81/*tapset*/)  //  oSample18 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample15 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample15 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample15 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample15 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 272,20/*oSample*/,81/*tapset*/)  //  oSample20 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample18 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample18 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample18 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample18 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 272,21/*oSample*/,81/*tapset*/)  //  oSample21 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample20 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample20 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample20 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample20 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 272,23/*oSample*/,81/*tapset*/)  //  oSample23 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample21 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample21 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample21 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample21 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, 288,1/*oSample*/,82/*tapset*/)  //  oSample1 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample23 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample23 tapSet81 Ch0  ISampleSet81 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,84/*R0 iSampleSet*/,85/*R1 iSampleSet*/) //  chan0,0 iSampleSet84,85
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample23 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample23 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, 288,3/*oSample*/,82/*tapset*/)  //  oSample3 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch0  ISampleSet82 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 288,6/*oSample*/,82/*tapset*/)  //  oSample6 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M1,3/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 288,8/*oSample*/,82/*tapset*/)  //  oSample8 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, 288,9/*oSample*/,82/*tapset*/)  //  oSample9 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, 288,11/*oSample*/,82/*tapset*/)  //  oSample11 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, 288,14/*oSample*/,82/*tapset*/)  //  oSample14 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, 288,16/*oSample*/,82/*tapset*/)  //  oSample16 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample14 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample14 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample14 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample14 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, 288,17/*oSample*/,82/*tapset*/)  //  oSample17 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample16 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample16 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample16 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample16 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, 288,19/*oSample*/,82/*tapset*/)  //  oSample19 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample17 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample17 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample17 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample17 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, 288,22/*oSample*/,82/*tapset*/)  //  oSample22 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample19 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample19 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample19 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample19 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, 304,2/*oSample*/,83/*tapset*/)  //  oSample2 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample22 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample22 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample22 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample22 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, 304,4/*oSample*/,83/*tapset*/)  //  oSample4 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample2 tapSet83 Ch0  ISampleSet83 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 304,5/*oSample*/,83/*tapset*/)  //  oSample5 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M0,4/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 304,7/*oSample*/,83/*tapset*/)  //  oSample7 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 304,10/*oSample*/,83/*tapset*/)  //  oSample10 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, 304,12/*oSample*/,83/*tapset*/)  //  oSample12 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, 304,13/*oSample*/,83/*tapset*/)  //  oSample13 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample12 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample12 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample12 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample12 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, 304,15/*oSample*/,83/*tapset*/)  //  oSample15 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample13 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample13 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample13 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample13 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, 304,18/*oSample*/,83/*tapset*/)  //  oSample18 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample15 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample15 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample15 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample15 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, 304,20/*oSample*/,83/*tapset*/)  //  oSample20 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample18 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample18 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample18 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample18 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, 304,21/*oSample*/,83/*tapset*/)  //  oSample21 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample20 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample20 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample20 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample20 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 304,23/*oSample*/,83/*tapset*/)  //  oSample23 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample21 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample21 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample21 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample21 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, 320,3/*oSample*/,84/*tapset*/)  //  oSample3 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample23 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample23 tapSet83 Ch0  ISampleSet83 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,86/*R0 iSampleSet*/,87/*R1 iSampleSet*/) //  chan0,0 iSampleSet86,87
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample23 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample23 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 320,6/*oSample*/,84/*tapset*/)  //  oSample6 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample3 tapSet84 Ch0  ISampleSet84 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 320,8/*oSample*/,84/*tapset*/)  //  oSample8 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M1,6/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, 320,9/*oSample*/,84/*tapset*/)  //  oSample9 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, 320,11/*oSample*/,84/*tapset*/)  //  oSample11 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M1,9/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, 320,14/*oSample*/,84/*tapset*/)  //  oSample14 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, 320,16/*oSample*/,84/*tapset*/)  //  oSample16 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample14 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample14 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample14 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample14 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, 320,17/*oSample*/,84/*tapset*/)  //  oSample17 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample16 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample16 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample16 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample16 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, 320,19/*oSample*/,84/*tapset*/)  //  oSample19 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample17 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample17 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample17 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample17 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, 320,22/*oSample*/,84/*tapset*/)  //  oSample22 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample19 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample19 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample19 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample19 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 336,5/*oSample*/,85/*tapset*/)  //  oSample5 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample22 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample22 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample22 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample22 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 336,7/*oSample*/,85/*tapset*/)  //  oSample7 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M0,5/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch0  ISampleSet85 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 336,10/*oSample*/,85/*tapset*/)  //  oSample10 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, 336,12/*oSample*/,85/*tapset*/)  //  oSample12 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, 336,13/*oSample*/,85/*tapset*/)  //  oSample13 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample12 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample12 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample12 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample12 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, 336,15/*oSample*/,85/*tapset*/)  //  oSample15 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample13 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample13 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample13 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample13 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, 336,18/*oSample*/,85/*tapset*/)  //  oSample18 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample15 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample15 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample15 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample15 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, 336,20/*oSample*/,85/*tapset*/)  //  oSample20 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample18 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample18 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample18 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample18 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, 336,21/*oSample*/,85/*tapset*/)  //  oSample21 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample20 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample20 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample20 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample20 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 336,23/*oSample*/,85/*tapset*/)  //  oSample23 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample21 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample21 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample21 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample21 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 352,6/*oSample*/,86/*tapset*/)  //  oSample6 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample23 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample23 tapSet85 Ch0  ISampleSet85 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,88/*R0 iSampleSet*/,89/*R1 iSampleSet*/) //  chan0,0 iSampleSet88,89
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample23 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample23 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 352,8/*oSample*/,86/*tapset*/)  //  oSample8 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample6 tapSet86 Ch0  ISampleSet86 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 352,9/*oSample*/,86/*tapset*/)  //  oSample9 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 352,11/*oSample*/,86/*tapset*/)  //  oSample11 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M1,9/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 352,14/*oSample*/,86/*tapset*/)  //  oSample14 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 352,16/*oSample*/,86/*tapset*/)  //  oSample16 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample14 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample14 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample14 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample14 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 352,17/*oSample*/,86/*tapset*/)  //  oSample17 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample16 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample16 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample16 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample16 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 352,19/*oSample*/,86/*tapset*/)  //  oSample19 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample17 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample17 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample17 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample17 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 352,22/*oSample*/,86/*tapset*/)  //  oSample22 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample19 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample19 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample19 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample19 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 368,7/*oSample*/,87/*tapset*/)  //  oSample7 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample22 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample22 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample22 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample22 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 368,10/*oSample*/,87/*tapset*/)  //  oSample10 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M0,7/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample7 tapSet87 Ch0  ISampleSet87 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, 368,12/*oSample*/,87/*tapset*/)  //  oSample12 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, 368,13/*oSample*/,87/*tapset*/)  //  oSample13 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample12 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M0,12/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample12 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample12 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M1,12/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample12 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, 368,15/*oSample*/,87/*tapset*/)  //  oSample15 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample13 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample13 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample13 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample13 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, 368,18/*oSample*/,87/*tapset*/)  //  oSample18 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample15 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M0,15/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample15 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample15 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M1,15/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample15 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, 368,20/*oSample*/,87/*tapset*/)  //  oSample20 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample18 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample18 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample18 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M1,18/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample18 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, 368,21/*oSample*/,87/*tapset*/)  //  oSample21 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample20 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample20 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample20 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample20 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 368,23/*oSample*/,87/*tapset*/)  //  oSample23 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample21 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample21 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample21 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample21 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 384,9/*oSample*/,88/*tapset*/)  //  oSample9 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample23 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample23 tapSet87 Ch0  ISampleSet87 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,90/*R0 iSampleSet*/,91/*R1 iSampleSet*/) //  chan0,0 iSampleSet90,91
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample23 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample23 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 384,11/*oSample*/,88/*tapset*/)  //  oSample11 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch0  ISampleSet88 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 384,14/*oSample*/,88/*tapset*/)  //  oSample14 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 384,16/*oSample*/,88/*tapset*/)  //  oSample16 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample14 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample14 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample14 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample14 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 384,17/*oSample*/,88/*tapset*/)  //  oSample17 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample16 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample16 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample16 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample16 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 384,19/*oSample*/,88/*tapset*/)  //  oSample19 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample17 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample17 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample17 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample17 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 384,22/*oSample*/,88/*tapset*/)  //  oSample22 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample19 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample19 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample19 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample19 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 400,10/*oSample*/,89/*tapset*/)  //  oSample10 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample22 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample22 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample22 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample22 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, 400,12/*oSample*/,89/*tapset*/)  //  oSample12 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample10 tapSet89 Ch0  ISampleSet89 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 400,13/*oSample*/,89/*tapset*/)  //  oSample13 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample12 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M0,12/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample12 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample12 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M1,12/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample12 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 400,15/*oSample*/,89/*tapset*/)  //  oSample15 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample13 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample13 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample13 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample13 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 400,18/*oSample*/,89/*tapset*/)  //  oSample18 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample15 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample15 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample15 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample15 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 400,20/*oSample*/,89/*tapset*/)  //  oSample20 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample18 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample18 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample18 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample18 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 400,21/*oSample*/,89/*tapset*/)  //  oSample21 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample20 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample20 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample20 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample20 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 400,23/*oSample*/,89/*tapset*/)  //  oSample23 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample21 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample21 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample21 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample21 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 416,11/*oSample*/,90/*tapset*/)  //  oSample11 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample23 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample23 tapSet89 Ch0  ISampleSet89 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,92/*R0 iSampleSet*/,93/*R1 iSampleSet*/) //  chan0,0 iSampleSet92,93
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample23 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample23 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, 416,14/*oSample*/,90/*tapset*/)  //  oSample14 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample11 tapSet90 Ch0  ISampleSet90 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, 416,16/*oSample*/,90/*tapset*/)  //  oSample16 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample14 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample14 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample14 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample14 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, 416,17/*oSample*/,90/*tapset*/)  //  oSample17 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample16 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M0,16/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample16 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample16 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M1,16/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample16 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, 416,19/*oSample*/,90/*tapset*/)  //  oSample19 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample17 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M0,17/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample17 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample17 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M1,17/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample17 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 416,22/*oSample*/,90/*tapset*/)  //  oSample22 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample19 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M0,19/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample19 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample19 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M1,19/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample19 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, 432,13/*oSample*/,91/*tapset*/)  //  oSample13 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample22 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample22 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample22 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample22 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 432,15/*oSample*/,91/*tapset*/)  //  oSample15 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample13 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample13 tapSet91 Ch0  ISampleSet91 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 432,18/*oSample*/,91/*tapset*/)  //  oSample18 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample15 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample15 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample15 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M1,15/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample15 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 432,20/*oSample*/,91/*tapset*/)  //  oSample20 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample18 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample18 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample18 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample18 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 432,21/*oSample*/,91/*tapset*/)  //  oSample21 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample20 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample20 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample20 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample20 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 432,23/*oSample*/,91/*tapset*/)  //  oSample23 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample21 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample21 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample21 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample21 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, 448,14/*oSample*/,92/*tapset*/)  //  oSample14 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample23 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample23 tapSet91 Ch0  ISampleSet91 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,94/*R0 iSampleSet*/,95/*R1 iSampleSet*/) //  chan0,0 iSampleSet94,95
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample23 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample23 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, 448,16/*oSample*/,92/*tapset*/)  //  oSample16 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample14 tapSet92 Ch0  ISampleSet92 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, 448,17/*oSample*/,92/*tapset*/)  //  oSample17 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample16 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M0,16/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample16 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample16 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M1,16/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample16 tapSet93 Ch0  ISampleSet93 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, 448,19/*oSample*/,92/*tapset*/)  //  oSample19 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample17 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample17 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample17 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M1,17/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample17 tapSet93 Ch0  ISampleSet93 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, 448,22/*oSample*/,92/*tapset*/)  //  oSample22 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample19 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample19 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample19 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample19 tapSet93 Ch0  ISampleSet93 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, 464,15/*oSample*/,93/*tapset*/)  //  oSample15 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample22 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample22 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample22 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample22 tapSet93 Ch0  ISampleSet93 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, 464,18/*oSample*/,93/*tapset*/)  //  oSample18 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M0,15/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample15 tapSet93 Ch0  ISampleSet93 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, 464,20/*oSample*/,93/*tapset*/)  //  oSample20 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample18 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M0,18/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample18 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample18 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M1,18/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample18 tapSet94 Ch0  ISampleSet94 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, 464,21/*oSample*/,93/*tapset*/)  //  oSample21 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample20 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample20 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample20 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample20 tapSet94 Ch0  ISampleSet94 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, 464,23/*oSample*/,93/*tapset*/)  //  oSample23 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample21 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M0,21/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample21 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample21 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M1,21/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample21 tapSet94 Ch0  ISampleSet94 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, 480,17/*oSample*/,94/*tapset*/)  //  oSample17 tapSet94,95 iSampleSet94,95
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample23 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample23 tapSet93 Ch0  ISampleSet93 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,96/*R0 iSampleSet*/,97/*R1 iSampleSet*/) //  chan0,0 iSampleSet96,97
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample23 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample23 tapSet94 Ch0  ISampleSet94 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, 480,19/*oSample*/,94/*tapset*/)  //  oSample19 tapSet94,95 iSampleSet94,95
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample17 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M0,17/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample17 tapSet94 Ch0  ISampleSet94 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, 480,22/*oSample*/,94/*tapset*/)  //  oSample22 tapSet94,95 iSampleSet94,95
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample19 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample19 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample19 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M1,19/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample19 tapSet95 Ch0  ISampleSet95 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, 496,18/*oSample*/,95/*tapset*/)  //  oSample18 tapSet95,96 iSampleSet95,96
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample22 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample22 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample22 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample22 tapSet95 Ch0  ISampleSet95 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, 496,20/*oSample*/,95/*tapset*/)  //  oSample20 tapSet95,96 iSampleSet95,96
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M0,18/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample18 tapSet95 Ch0  ISampleSet95 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, 496,21/*oSample*/,95/*tapset*/)  //  oSample21 tapSet95,96 iSampleSet95,96
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample20 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample20 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample20 tapSet96 Ch0  ISampleSet96 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample20 tapSet96 Ch0  ISampleSet96 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 496,23/*oSample*/,95/*tapset*/)  //  oSample23 tapSet95,96 iSampleSet95,96
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample21 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample21 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample21 tapSet96 Ch0  ISampleSet96 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M1,21/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample21 tapSet96 Ch0  ISampleSet96 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, 512,19/*oSample*/,96/*tapset*/)  //  oSample19 tapSet96,97 iSampleSet96,97
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample23 tapSet95 Ch0  ISampleSet95 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,95/*tapsSet*/,95/*sampleSet*/)  // oSample23 tapSet95 Ch0  ISampleSet95 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,98/*R0 iSampleSet*/,99/*R1 iSampleSet*/) //  chan0,0 iSampleSet98,99
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample23 tapSet96 Ch0  ISampleSet96 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample23 tapSet96 Ch0  ISampleSet96 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, 512,22/*oSample*/,96/*tapset*/)  //  oSample22 tapSet96,97 iSampleSet96,97
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M0,19/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample19 tapSet96 Ch0  ISampleSet96 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, 528,21/*oSample*/,97/*tapset*/)  //  oSample21 tapSet97,98 iSampleSet97,98
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample22 tapSet96 Ch0  ISampleSet96 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,96/*tapsSet*/,96/*sampleSet*/)  // oSample22 tapSet96 Ch0  ISampleSet96 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample22 tapSet97 Ch0  ISampleSet97 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample22 tapSet97 Ch0  ISampleSet97 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 528,23/*oSample*/,97/*tapset*/)  //  oSample23 tapSet97,98 iSampleSet97,98
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample21 tapSet97 Ch0  ISampleSet97 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M0,21/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample21 tapSet97 Ch0  ISampleSet97 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, 544,22/*oSample*/,98/*tapset*/)  //  oSample22 tapSet98,99 iSampleSet98,99
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample23 tapSet97 Ch0  ISampleSet97 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,97/*tapsSet*/,97/*sampleSet*/)  // oSample23 tapSet97 Ch0  ISampleSet97 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,98/*tapsSet*/,98/*sampleSet*/)  // oSample23 tapSet98 Ch0  ISampleSet98 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,98/*tapsSet*/,98/*sampleSet*/)  // oSample23 tapSet98 Ch0  ISampleSet98 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, 560,23/*oSample*/,99/*tapset*/)  //  oSample23 tapSet99,100 iSampleSet99,100
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,98/*tapsSet*/,98/*sampleSet*/)  // oSample22 tapSet98 Ch0  ISampleSet98 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,99/*tapsSet*/,99/*sampleSet*/)  // oSample23 tapSet99 Ch0  ISampleSet99 
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
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo)
{
     return SsrcSampleRateConverter_insr_3_outsr_1_taps_328_mono_SsrcSampleFormat_int32::construct(*returnedInfo);
}
