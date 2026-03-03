/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcsamplerateconverter_insr_1024_outsr_441_taps_136_mono_ssrcsampleformat_int32.h"
/********************************************************************************
*  iSample rate converter input iSample rate 1024 output iSample rate 441 mono
*
*******************************************************************************/
/********************************************************************************
*  
*
*******************************************************************************/
SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32::SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32()
{
}
/********************************************************************************
*  iSample processing
*
*******************************************************************************/
bool SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32::process()
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
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -1024,0/*oSample*/,0/*tapset*/)  //  oSample0 tapSet0,1 iSampleSet0,1
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -1024,1/*oSample*/,0/*tapset*/)  //  oSample1 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample00Accum,0/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -1008,2/*oSample*/,1/*tapset*/)  //  oSample2 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample01Accum,1/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -1008,3/*oSample*/,1/*tapset*/)  //  oSample3 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample02Accum,2/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -992,0/*oSample*/,2/*tapset*/)  //  oSample0 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample03Accum,3/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch0  ISampleSet1 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,4/*R0 iSampleSet*/,5/*R1 iSampleSet*/) //  chan0,0 iSampleSet4,5
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -992,1/*oSample*/,2/*tapset*/)  //  oSample1 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -992,4/*oSample*/,2/*tapset*/)  //  oSample4 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -992,5/*oSample*/,2/*tapset*/)  //  oSample5 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample04Accum,4/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -976,2/*oSample*/,3/*tapset*/)  //  oSample2 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample05Accum,5/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -976,3/*oSample*/,3/*tapset*/)  //  oSample3 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -976,6/*oSample*/,3/*tapset*/)  //  oSample6 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -960,0/*oSample*/,4/*tapset*/)  //  oSample0 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample06Accum,6/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,6/*R0 iSampleSet*/,7/*R1 iSampleSet*/) //  chan0,0 iSampleSet6,7
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -960,1/*oSample*/,4/*tapset*/)  //  oSample1 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -960,4/*oSample*/,4/*tapset*/)  //  oSample4 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -960,5/*oSample*/,4/*tapset*/)  //  oSample5 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -960,7/*oSample*/,4/*tapset*/)  //  oSample7 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -960,8/*oSample*/,4/*tapset*/)  //  oSample8 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample07Accum,7/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -944,2/*oSample*/,5/*tapset*/)  //  oSample2 tapSet5,6 iSampleSet5,6
        clear_accumulator(oSample08Accum,8/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -944,3/*oSample*/,5/*tapset*/)  //  oSample3 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -944,6/*oSample*/,5/*tapset*/)  //  oSample6 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -944,9/*oSample*/,5/*tapset*/)  //  oSample9 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -944,10/*oSample*/,5/*tapset*/)  //  oSample10 tapSet5,6 iSampleSet5,6
        clear_accumulator(oSample09Accum,9/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -928,0/*oSample*/,6/*tapset*/)  //  oSample0 tapSet6,7 iSampleSet6,7
        clear_accumulator(oSample10Accum,10/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch0  ISampleSet5 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,8/*R0 iSampleSet*/,9/*R1 iSampleSet*/) //  chan0,0 iSampleSet8,9
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -928,1/*oSample*/,6/*tapset*/)  //  oSample1 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -928,4/*oSample*/,6/*tapset*/)  //  oSample4 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -928,5/*oSample*/,6/*tapset*/)  //  oSample5 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -928,7/*oSample*/,6/*tapset*/)  //  oSample7 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -928,8/*oSample*/,6/*tapset*/)  //  oSample8 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -928,11/*oSample*/,6/*tapset*/)  //  oSample11 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -928,12/*oSample*/,6/*tapset*/)  //  oSample12 tapSet6,7 iSampleSet6,7
        clear_accumulator(oSample11Accum,11/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -912,2/*oSample*/,7/*tapset*/)  //  oSample2 tapSet7,8 iSampleSet7,8
        clear_accumulator(oSample12Accum,12/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample12 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample12 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample12 tapSet7 Ch0  ISampleSet7 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -912,3/*oSample*/,7/*tapset*/)  //  oSample3 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -912,6/*oSample*/,7/*tapset*/)  //  oSample6 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -912,9/*oSample*/,7/*tapset*/)  //  oSample9 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -912,10/*oSample*/,7/*tapset*/)  //  oSample10 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -912,13/*oSample*/,7/*tapset*/)  //  oSample13 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -896,0/*oSample*/,8/*tapset*/)  //  oSample0 tapSet8,9 iSampleSet8,9
        clear_accumulator(oSample13Accum,13/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample13 tapSet7 Ch0  ISampleSet7 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,10/*R0 iSampleSet*/,11/*R1 iSampleSet*/) //  chan0,0 iSampleSet10,11
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample13 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample13 tapSet8 Ch0  ISampleSet8 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -896,1/*oSample*/,8/*tapset*/)  //  oSample1 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -896,4/*oSample*/,8/*tapset*/)  //  oSample4 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -896,5/*oSample*/,8/*tapset*/)  //  oSample5 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -896,7/*oSample*/,8/*tapset*/)  //  oSample7 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -896,8/*oSample*/,8/*tapset*/)  //  oSample8 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -896,11/*oSample*/,8/*tapset*/)  //  oSample11 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -896,12/*oSample*/,8/*tapset*/)  //  oSample12 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -896,14/*oSample*/,8/*tapset*/)  //  oSample14 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample12 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample12 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample12 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -896,15/*oSample*/,8/*tapset*/)  //  oSample15 tapSet8,9 iSampleSet8,9
        clear_accumulator(oSample14Accum,14/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample14 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample14 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample14 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample14 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -880,2/*oSample*/,9/*tapset*/)  //  oSample2 tapSet9,10 iSampleSet9,10
        clear_accumulator(oSample15Accum,15/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample15 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample15 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample15 tapSet9 Ch0  ISampleSet9 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -880,3/*oSample*/,9/*tapset*/)  //  oSample3 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -880,6/*oSample*/,9/*tapset*/)  //  oSample6 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -880,9/*oSample*/,9/*tapset*/)  //  oSample9 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -880,10/*oSample*/,9/*tapset*/)  //  oSample10 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -880,13/*oSample*/,9/*tapset*/)  //  oSample13 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -880,16/*oSample*/,9/*tapset*/)  //  oSample16 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample13 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample13 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample13 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -880,17/*oSample*/,9/*tapset*/)  //  oSample17 tapSet9,10 iSampleSet9,10
        clear_accumulator(oSample16Accum,16/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample16 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample16 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample16 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample16 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -864,0/*oSample*/,10/*tapset*/)  //  oSample0 tapSet10,11 iSampleSet10,11
        clear_accumulator(oSample17Accum,17/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample17 tapSet9 Ch0  ISampleSet9 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,12/*R0 iSampleSet*/,13/*R1 iSampleSet*/) //  chan0,0 iSampleSet12,13
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample17 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample17 tapSet10 Ch0  ISampleSet10 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -864,1/*oSample*/,10/*tapset*/)  //  oSample1 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -864,4/*oSample*/,10/*tapset*/)  //  oSample4 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G1_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -864,5/*oSample*/,10/*tapset*/)  //  oSample5 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -864,7/*oSample*/,10/*tapset*/)  //  oSample7 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -864,8/*oSample*/,10/*tapset*/)  //  oSample8 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -864,11/*oSample*/,10/*tapset*/)  //  oSample11 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -864,12/*oSample*/,10/*tapset*/)  //  oSample12 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -864,14/*oSample*/,10/*tapset*/)  //  oSample14 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample12 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample12 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -864,15/*oSample*/,10/*tapset*/)  //  oSample15 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample14 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample14 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample14 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -864,18/*oSample*/,10/*tapset*/)  //  oSample18 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample15 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample15 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample15 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -848,2/*oSample*/,11/*tapset*/)  //  oSample2 tapSet11,12 iSampleSet11,12
        clear_accumulator(oSample18Accum,18/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample18 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample18 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample18 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample18 tapSet11 Ch0  ISampleSet11 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -848,3/*oSample*/,11/*tapset*/)  //  oSample3 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -848,6/*oSample*/,11/*tapset*/)  //  oSample6 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -848,9/*oSample*/,11/*tapset*/)  //  oSample9 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -848,10/*oSample*/,11/*tapset*/)  //  oSample10 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -848,13/*oSample*/,11/*tapset*/)  //  oSample13 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -848,16/*oSample*/,11/*tapset*/)  //  oSample16 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample13 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample13 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -848,17/*oSample*/,11/*tapset*/)  //  oSample17 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample16 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample16 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample16 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -848,19/*oSample*/,11/*tapset*/)  //  oSample19 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample17 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample17 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample17 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample17 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -848,20/*oSample*/,11/*tapset*/)  //  oSample20 tapSet11,12 iSampleSet11,12
        clear_accumulator(oSample19Accum,19/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample19 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample19 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample19 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample19 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -832,0/*oSample*/,12/*tapset*/)  //  oSample0 tapSet12,13 iSampleSet12,13
        clear_accumulator(oSample20Accum,20/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample20 tapSet11 Ch0  ISampleSet11 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,14/*R0 iSampleSet*/,15/*R1 iSampleSet*/) //  chan0,0 iSampleSet14,15
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample20 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample20 tapSet12 Ch0  ISampleSet12 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -832,1/*oSample*/,12/*tapset*/)  //  oSample1 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -832,4/*oSample*/,12/*tapset*/)  //  oSample4 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -832,5/*oSample*/,12/*tapset*/)  //  oSample5 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -832,7/*oSample*/,12/*tapset*/)  //  oSample7 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -832,8/*oSample*/,12/*tapset*/)  //  oSample8 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -832,11/*oSample*/,12/*tapset*/)  //  oSample11 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -832,12/*oSample*/,12/*tapset*/)  //  oSample12 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -832,14/*oSample*/,12/*tapset*/)  //  oSample14 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample12 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample12 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -832,15/*oSample*/,12/*tapset*/)  //  oSample15 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample14 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample14 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -832,18/*oSample*/,12/*tapset*/)  //  oSample18 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample15 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample15 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -832,21/*oSample*/,12/*tapset*/)  //  oSample21 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample18 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample18 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample18 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample18 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -832,22/*oSample*/,12/*tapset*/)  //  oSample22 tapSet12,13 iSampleSet12,13
        clear_accumulator(oSample21Accum,21/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample21 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample21 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample21 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample21 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -816,2/*oSample*/,13/*tapset*/)  //  oSample2 tapSet13,14 iSampleSet13,14
        clear_accumulator(oSample22Accum,22/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample22 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample22 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample22 tapSet13 Ch0  ISampleSet13 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -816,3/*oSample*/,13/*tapset*/)  //  oSample3 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -816,6/*oSample*/,13/*tapset*/)  //  oSample6 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -816,9/*oSample*/,13/*tapset*/)  //  oSample9 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -816,10/*oSample*/,13/*tapset*/)  //  oSample10 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -816,13/*oSample*/,13/*tapset*/)  //  oSample13 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -816,16/*oSample*/,13/*tapset*/)  //  oSample16 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample13 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample13 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -816,17/*oSample*/,13/*tapset*/)  //  oSample17 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample16 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample16 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -816,19/*oSample*/,13/*tapset*/)  //  oSample19 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample17 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample17 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -816,20/*oSample*/,13/*tapset*/)  //  oSample20 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample19 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample19 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample19 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -816,23/*oSample*/,13/*tapset*/)  //  oSample23 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample20 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample20 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample20 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample20 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -800,0/*oSample*/,14/*tapset*/)  //  oSample0 tapSet14,15 iSampleSet14,15
        clear_accumulator(oSample23Accum,23/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample23 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample23 tapSet13 Ch0  ISampleSet13 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,16/*R0 iSampleSet*/,17/*R1 iSampleSet*/) //  chan0,0 iSampleSet16,17
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample23 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample23 tapSet14 Ch0  ISampleSet14 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -800,1/*oSample*/,14/*tapset*/)  //  oSample1 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -800,4/*oSample*/,14/*tapset*/)  //  oSample4 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -800,5/*oSample*/,14/*tapset*/)  //  oSample5 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -800,7/*oSample*/,14/*tapset*/)  //  oSample7 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -800,8/*oSample*/,14/*tapset*/)  //  oSample8 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -800,11/*oSample*/,14/*tapset*/)  //  oSample11 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -800,12/*oSample*/,14/*tapset*/)  //  oSample12 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -800,14/*oSample*/,14/*tapset*/)  //  oSample14 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample12 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample12 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -800,15/*oSample*/,14/*tapset*/)  //  oSample15 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample14 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample14 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -800,18/*oSample*/,14/*tapset*/)  //  oSample18 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample15 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample15 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -800,21/*oSample*/,14/*tapset*/)  //  oSample21 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample18 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample18 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -800,22/*oSample*/,14/*tapset*/)  //  oSample22 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample21 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample21 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample21 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample21 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -784,2/*oSample*/,15/*tapset*/)  //  oSample2 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample22 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample22 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample22 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample22 tapSet15 Ch0  ISampleSet15 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -784,3/*oSample*/,15/*tapset*/)  //  oSample3 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -784,6/*oSample*/,15/*tapset*/)  //  oSample6 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -784,9/*oSample*/,15/*tapset*/)  //  oSample9 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -784,10/*oSample*/,15/*tapset*/)  //  oSample10 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -784,13/*oSample*/,15/*tapset*/)  //  oSample13 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -784,16/*oSample*/,15/*tapset*/)  //  oSample16 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample13 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample13 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -784,17/*oSample*/,15/*tapset*/)  //  oSample17 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample16 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample16 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -784,19/*oSample*/,15/*tapset*/)  //  oSample19 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample17 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample17 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -784,20/*oSample*/,15/*tapset*/)  //  oSample20 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample19 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample19 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -784,23/*oSample*/,15/*tapset*/)  //  oSample23 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample20 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample20 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -768,0/*oSample*/,16/*tapset*/)  //  oSample0 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample23 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample23 tapSet15 Ch0  ISampleSet15 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,18/*R0 iSampleSet*/,19/*R1 iSampleSet*/) //  chan0,0 iSampleSet18,19
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample23 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample23 tapSet16 Ch0  ISampleSet16 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -768,1/*oSample*/,16/*tapset*/)  //  oSample1 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -768,4/*oSample*/,16/*tapset*/)  //  oSample4 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -768,5/*oSample*/,16/*tapset*/)  //  oSample5 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -768,7/*oSample*/,16/*tapset*/)  //  oSample7 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -768,8/*oSample*/,16/*tapset*/)  //  oSample8 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -768,11/*oSample*/,16/*tapset*/)  //  oSample11 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -768,12/*oSample*/,16/*tapset*/)  //  oSample12 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -768,14/*oSample*/,16/*tapset*/)  //  oSample14 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample12 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample12 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -768,15/*oSample*/,16/*tapset*/)  //  oSample15 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample14 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample14 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -768,18/*oSample*/,16/*tapset*/)  //  oSample18 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample15 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample15 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -768,21/*oSample*/,16/*tapset*/)  //  oSample21 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample18 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample18 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -768,22/*oSample*/,16/*tapset*/)  //  oSample22 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample21 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample21 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -752,2/*oSample*/,17/*tapset*/)  //  oSample2 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample22 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample22 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample22 tapSet17 Ch0  ISampleSet17 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -752,3/*oSample*/,17/*tapset*/)  //  oSample3 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -752,6/*oSample*/,17/*tapset*/)  //  oSample6 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -752,9/*oSample*/,17/*tapset*/)  //  oSample9 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -752,10/*oSample*/,17/*tapset*/)  //  oSample10 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -752,13/*oSample*/,17/*tapset*/)  //  oSample13 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -752,16/*oSample*/,17/*tapset*/)  //  oSample16 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample13 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample13 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -752,17/*oSample*/,17/*tapset*/)  //  oSample17 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample16 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample16 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -752,19/*oSample*/,17/*tapset*/)  //  oSample19 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample17 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample17 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -752,20/*oSample*/,17/*tapset*/)  //  oSample20 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample19 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample19 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -752,23/*oSample*/,17/*tapset*/)  //  oSample23 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample20 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample20 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -736,0/*oSample*/,18/*tapset*/)  //  oSample0 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample23 tapSet17 Ch0  ISampleSet17 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,20/*R0 iSampleSet*/,21/*R1 iSampleSet*/) //  chan0,0 iSampleSet20,21
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample23 tapSet18 Ch0  ISampleSet18 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -736,1/*oSample*/,18/*tapset*/)  //  oSample1 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -736,4/*oSample*/,18/*tapset*/)  //  oSample4 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -736,5/*oSample*/,18/*tapset*/)  //  oSample5 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -736,7/*oSample*/,18/*tapset*/)  //  oSample7 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -736,8/*oSample*/,18/*tapset*/)  //  oSample8 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -736,11/*oSample*/,18/*tapset*/)  //  oSample11 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -736,12/*oSample*/,18/*tapset*/)  //  oSample12 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -736,14/*oSample*/,18/*tapset*/)  //  oSample14 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample12 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample12 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -736,15/*oSample*/,18/*tapset*/)  //  oSample15 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample14 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample14 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -736,18/*oSample*/,18/*tapset*/)  //  oSample18 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample15 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample15 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -736,21/*oSample*/,18/*tapset*/)  //  oSample21 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample18 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample18 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -736,22/*oSample*/,18/*tapset*/)  //  oSample22 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample21 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample21 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -720,2/*oSample*/,19/*tapset*/)  //  oSample2 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample22 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample22 tapSet19 Ch0  ISampleSet19 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -720,3/*oSample*/,19/*tapset*/)  //  oSample3 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -720,6/*oSample*/,19/*tapset*/)  //  oSample6 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -720,9/*oSample*/,19/*tapset*/)  //  oSample9 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -720,10/*oSample*/,19/*tapset*/)  //  oSample10 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -720,13/*oSample*/,19/*tapset*/)  //  oSample13 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -720,16/*oSample*/,19/*tapset*/)  //  oSample16 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample13 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample13 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -720,17/*oSample*/,19/*tapset*/)  //  oSample17 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample16 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample16 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -720,19/*oSample*/,19/*tapset*/)  //  oSample19 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample17 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample17 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -720,20/*oSample*/,19/*tapset*/)  //  oSample20 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample19 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample19 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -720,23/*oSample*/,19/*tapset*/)  //  oSample23 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample20 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample20 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -704,0/*oSample*/,20/*tapset*/)  //  oSample0 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample23 tapSet19 Ch0  ISampleSet19 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,22/*R0 iSampleSet*/,23/*R1 iSampleSet*/) //  chan0,0 iSampleSet22,23
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample23 tapSet20 Ch0  ISampleSet20 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -704,1/*oSample*/,20/*tapset*/)  //  oSample1 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -704,4/*oSample*/,20/*tapset*/)  //  oSample4 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -704,5/*oSample*/,20/*tapset*/)  //  oSample5 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -704,7/*oSample*/,20/*tapset*/)  //  oSample7 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -704,8/*oSample*/,20/*tapset*/)  //  oSample8 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -704,11/*oSample*/,20/*tapset*/)  //  oSample11 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -704,12/*oSample*/,20/*tapset*/)  //  oSample12 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -704,14/*oSample*/,20/*tapset*/)  //  oSample14 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample12 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample12 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -704,15/*oSample*/,20/*tapset*/)  //  oSample15 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample14 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample14 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -704,18/*oSample*/,20/*tapset*/)  //  oSample18 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample15 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample15 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -704,21/*oSample*/,20/*tapset*/)  //  oSample21 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample18 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample18 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -704,22/*oSample*/,20/*tapset*/)  //  oSample22 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample21 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample21 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -688,2/*oSample*/,21/*tapset*/)  //  oSample2 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample22 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample22 tapSet21 Ch0  ISampleSet21 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -688,3/*oSample*/,21/*tapset*/)  //  oSample3 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -688,6/*oSample*/,21/*tapset*/)  //  oSample6 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -688,9/*oSample*/,21/*tapset*/)  //  oSample9 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -688,10/*oSample*/,21/*tapset*/)  //  oSample10 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -688,13/*oSample*/,21/*tapset*/)  //  oSample13 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -688,16/*oSample*/,21/*tapset*/)  //  oSample16 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample13 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample13 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -688,17/*oSample*/,21/*tapset*/)  //  oSample17 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample16 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample16 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -688,19/*oSample*/,21/*tapset*/)  //  oSample19 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample17 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample17 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -688,20/*oSample*/,21/*tapset*/)  //  oSample20 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample19 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample19 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -688,23/*oSample*/,21/*tapset*/)  //  oSample23 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample20 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample20 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -672,0/*oSample*/,22/*tapset*/)  //  oSample0 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample23 tapSet21 Ch0  ISampleSet21 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,24/*R0 iSampleSet*/,25/*R1 iSampleSet*/) //  chan0,0 iSampleSet24,25
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample23 tapSet22 Ch0  ISampleSet22 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -672,1/*oSample*/,22/*tapset*/)  //  oSample1 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -672,4/*oSample*/,22/*tapset*/)  //  oSample4 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -672,5/*oSample*/,22/*tapset*/)  //  oSample5 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -672,7/*oSample*/,22/*tapset*/)  //  oSample7 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -672,8/*oSample*/,22/*tapset*/)  //  oSample8 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -672,11/*oSample*/,22/*tapset*/)  //  oSample11 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -672,12/*oSample*/,22/*tapset*/)  //  oSample12 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -672,14/*oSample*/,22/*tapset*/)  //  oSample14 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample12 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample12 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -672,15/*oSample*/,22/*tapset*/)  //  oSample15 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample14 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample14 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -672,18/*oSample*/,22/*tapset*/)  //  oSample18 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample15 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample15 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -672,21/*oSample*/,22/*tapset*/)  //  oSample21 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample18 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample18 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -672,22/*oSample*/,22/*tapset*/)  //  oSample22 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample21 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample21 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -656,2/*oSample*/,23/*tapset*/)  //  oSample2 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample22 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample22 tapSet23 Ch0  ISampleSet23 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -656,3/*oSample*/,23/*tapset*/)  //  oSample3 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -656,6/*oSample*/,23/*tapset*/)  //  oSample6 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -656,9/*oSample*/,23/*tapset*/)  //  oSample9 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -656,10/*oSample*/,23/*tapset*/)  //  oSample10 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -656,13/*oSample*/,23/*tapset*/)  //  oSample13 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -656,16/*oSample*/,23/*tapset*/)  //  oSample16 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample13 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample13 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -656,17/*oSample*/,23/*tapset*/)  //  oSample17 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample16 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample16 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -656,19/*oSample*/,23/*tapset*/)  //  oSample19 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample17 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample17 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -656,20/*oSample*/,23/*tapset*/)  //  oSample20 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample19 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample19 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -656,23/*oSample*/,23/*tapset*/)  //  oSample23 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample20 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample20 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -640,0/*oSample*/,24/*tapset*/)  //  oSample0 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample23 tapSet23 Ch0  ISampleSet23 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,26/*R0 iSampleSet*/,27/*R1 iSampleSet*/) //  chan0,0 iSampleSet26,27
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample23 tapSet24 Ch0  ISampleSet24 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -640,1/*oSample*/,24/*tapset*/)  //  oSample1 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -640,4/*oSample*/,24/*tapset*/)  //  oSample4 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -640,5/*oSample*/,24/*tapset*/)  //  oSample5 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -640,7/*oSample*/,24/*tapset*/)  //  oSample7 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -640,8/*oSample*/,24/*tapset*/)  //  oSample8 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -640,11/*oSample*/,24/*tapset*/)  //  oSample11 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -640,12/*oSample*/,24/*tapset*/)  //  oSample12 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -640,14/*oSample*/,24/*tapset*/)  //  oSample14 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample12 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample12 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -640,15/*oSample*/,24/*tapset*/)  //  oSample15 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample14 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample14 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -640,18/*oSample*/,24/*tapset*/)  //  oSample18 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample15 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample15 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -640,21/*oSample*/,24/*tapset*/)  //  oSample21 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample18 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample18 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -640,22/*oSample*/,24/*tapset*/)  //  oSample22 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample21 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample21 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -624,2/*oSample*/,25/*tapset*/)  //  oSample2 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample22 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample22 tapSet25 Ch0  ISampleSet25 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -624,3/*oSample*/,25/*tapset*/)  //  oSample3 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -624,6/*oSample*/,25/*tapset*/)  //  oSample6 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -624,9/*oSample*/,25/*tapset*/)  //  oSample9 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -624,10/*oSample*/,25/*tapset*/)  //  oSample10 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -624,13/*oSample*/,25/*tapset*/)  //  oSample13 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -624,16/*oSample*/,25/*tapset*/)  //  oSample16 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample13 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample13 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample13 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -624,17/*oSample*/,25/*tapset*/)  //  oSample17 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample16 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample16 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -624,19/*oSample*/,25/*tapset*/)  //  oSample19 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample17 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample17 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -624,20/*oSample*/,25/*tapset*/)  //  oSample20 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample19 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample19 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -624,23/*oSample*/,25/*tapset*/)  //  oSample23 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample20 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample20 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -608,0/*oSample*/,26/*tapset*/)  //  oSample0 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample23 tapSet25 Ch0  ISampleSet25 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,28/*R0 iSampleSet*/,29/*R1 iSampleSet*/) //  chan0,0 iSampleSet28,29
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample23 tapSet26 Ch0  ISampleSet26 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -608,1/*oSample*/,26/*tapset*/)  //  oSample1 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -608,4/*oSample*/,26/*tapset*/)  //  oSample4 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -608,5/*oSample*/,26/*tapset*/)  //  oSample5 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -608,7/*oSample*/,26/*tapset*/)  //  oSample7 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -608,8/*oSample*/,26/*tapset*/)  //  oSample8 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -608,11/*oSample*/,26/*tapset*/)  //  oSample11 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -608,12/*oSample*/,26/*tapset*/)  //  oSample12 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -608,14/*oSample*/,26/*tapset*/)  //  oSample14 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample12 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample12 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample12 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample12 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -608,15/*oSample*/,26/*tapset*/)  //  oSample15 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample14 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample14 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample14 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample14 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -608,18/*oSample*/,26/*tapset*/)  //  oSample18 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample15 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample15 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample15 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample15 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -608,21/*oSample*/,26/*tapset*/)  //  oSample21 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample18 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample18 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample18 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -608,22/*oSample*/,26/*tapset*/)  //  oSample22 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample21 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample21 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample21 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -592,2/*oSample*/,27/*tapset*/)  //  oSample2 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample22 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample22 tapSet27 Ch0  ISampleSet27 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -592,3/*oSample*/,27/*tapset*/)  //  oSample3 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -592,6/*oSample*/,27/*tapset*/)  //  oSample6 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -592,9/*oSample*/,27/*tapset*/)  //  oSample9 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -592,10/*oSample*/,27/*tapset*/)  //  oSample10 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -592,13/*oSample*/,27/*tapset*/)  //  oSample13 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -592,16/*oSample*/,27/*tapset*/)  //  oSample16 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample13 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample13 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample13 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample13 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -592,17/*oSample*/,27/*tapset*/)  //  oSample17 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample16 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample16 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample16 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample16 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -592,19/*oSample*/,27/*tapset*/)  //  oSample19 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample17 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample17 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample17 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample17 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -592,20/*oSample*/,27/*tapset*/)  //  oSample20 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample19 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample19 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample19 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample19 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -592,23/*oSample*/,27/*tapset*/)  //  oSample23 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample20 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample20 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample20 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample20 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -576,0/*oSample*/,28/*tapset*/)  //  oSample0 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample23 tapSet27 Ch0  ISampleSet27 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,30/*R0 iSampleSet*/,31/*R1 iSampleSet*/) //  chan0,0 iSampleSet30,31
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample23 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample23 tapSet28 Ch0  ISampleSet28 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -576,1/*oSample*/,28/*tapset*/)  //  oSample1 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -576,4/*oSample*/,28/*tapset*/)  //  oSample4 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -576,5/*oSample*/,28/*tapset*/)  //  oSample5 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -576,7/*oSample*/,28/*tapset*/)  //  oSample7 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -576,8/*oSample*/,28/*tapset*/)  //  oSample8 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -576,11/*oSample*/,28/*tapset*/)  //  oSample11 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -576,12/*oSample*/,28/*tapset*/)  //  oSample12 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -576,14/*oSample*/,28/*tapset*/)  //  oSample14 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample12 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample12 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample12 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample12 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -576,15/*oSample*/,28/*tapset*/)  //  oSample15 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample14 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample14 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample14 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample14 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -576,18/*oSample*/,28/*tapset*/)  //  oSample18 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample15 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample15 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample15 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample15 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -576,21/*oSample*/,28/*tapset*/)  //  oSample21 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample18 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample18 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample18 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample18 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -576,22/*oSample*/,28/*tapset*/)  //  oSample22 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample21 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample21 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample21 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample21 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -560,2/*oSample*/,29/*tapset*/)  //  oSample2 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample22 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample22 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample22 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample22 tapSet29 Ch0  ISampleSet29 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -560,3/*oSample*/,29/*tapset*/)  //  oSample3 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -560,6/*oSample*/,29/*tapset*/)  //  oSample6 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -560,9/*oSample*/,29/*tapset*/)  //  oSample9 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -560,10/*oSample*/,29/*tapset*/)  //  oSample10 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -560,13/*oSample*/,29/*tapset*/)  //  oSample13 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -560,16/*oSample*/,29/*tapset*/)  //  oSample16 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample13 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample13 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample13 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample13 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -560,17/*oSample*/,29/*tapset*/)  //  oSample17 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample16 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample16 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample16 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample16 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -560,19/*oSample*/,29/*tapset*/)  //  oSample19 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample17 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample17 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample17 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample17 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -560,20/*oSample*/,29/*tapset*/)  //  oSample20 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample19 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample19 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample19 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample19 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -560,23/*oSample*/,29/*tapset*/)  //  oSample23 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample20 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample20 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample20 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample20 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -544,0/*oSample*/,30/*tapset*/)  //  oSample0 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample23 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample23 tapSet29 Ch0  ISampleSet29 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,32/*R0 iSampleSet*/,33/*R1 iSampleSet*/) //  chan0,0 iSampleSet32,33
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample23 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample23 tapSet30 Ch0  ISampleSet30 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -544,1/*oSample*/,30/*tapset*/)  //  oSample1 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G1_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -544,4/*oSample*/,30/*tapset*/)  //  oSample4 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -544,5/*oSample*/,30/*tapset*/)  //  oSample5 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -544,7/*oSample*/,30/*tapset*/)  //  oSample7 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -544,8/*oSample*/,30/*tapset*/)  //  oSample8 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -544,11/*oSample*/,30/*tapset*/)  //  oSample11 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -544,12/*oSample*/,30/*tapset*/)  //  oSample12 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -544,14/*oSample*/,30/*tapset*/)  //  oSample14 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample12 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample12 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample12 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample12 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -544,15/*oSample*/,30/*tapset*/)  //  oSample15 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample14 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample14 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample14 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample14 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -544,18/*oSample*/,30/*tapset*/)  //  oSample18 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample15 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample15 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample15 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample15 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -544,21/*oSample*/,30/*tapset*/)  //  oSample21 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample18 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample18 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample18 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample18 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -544,22/*oSample*/,30/*tapset*/)  //  oSample22 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample21 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample21 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample21 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample21 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -528,2/*oSample*/,31/*tapset*/)  //  oSample2 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample22 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample22 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample22 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample22 tapSet31 Ch0  ISampleSet31 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -528,3/*oSample*/,31/*tapset*/)  //  oSample3 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -528,6/*oSample*/,31/*tapset*/)  //  oSample6 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -528,9/*oSample*/,31/*tapset*/)  //  oSample9 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -528,10/*oSample*/,31/*tapset*/)  //  oSample10 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -528,13/*oSample*/,31/*tapset*/)  //  oSample13 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -528,16/*oSample*/,31/*tapset*/)  //  oSample16 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample13 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample13 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample13 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample13 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -528,17/*oSample*/,31/*tapset*/)  //  oSample17 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample16 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample16 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample16 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample16 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -528,19/*oSample*/,31/*tapset*/)  //  oSample19 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample17 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample17 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample17 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample17 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -528,20/*oSample*/,31/*tapset*/)  //  oSample20 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample19 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample19 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample19 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample19 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -528,23/*oSample*/,31/*tapset*/)  //  oSample23 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample20 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample20 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample20 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample20 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -512,0/*oSample*/,32/*tapset*/)  //  oSample0 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample23 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample23 tapSet31 Ch0  ISampleSet31 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,34/*R0 iSampleSet*/,35/*R1 iSampleSet*/) //  chan0,0 iSampleSet34,35
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample23 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample23 tapSet32 Ch0  ISampleSet32 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -512,1/*oSample*/,32/*tapset*/)  //  oSample1 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample00Accum, iSampleSet_G0_M1, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -512,4/*oSample*/,32/*tapset*/)  //  oSample4 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G0_M1, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -512,5/*oSample*/,32/*tapset*/)  //  oSample5 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G0_M1, tapSet_G1_M1,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -512,7/*oSample*/,32/*tapset*/)  //  oSample7 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M1, tapSet_G0_M1,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -512,8/*oSample*/,32/*tapset*/)  //  oSample8 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G1_M1,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -512,11/*oSample*/,32/*tapset*/)  //  oSample11 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G0_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -512,12/*oSample*/,32/*tapset*/)  //  oSample12 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G1_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -512,14/*oSample*/,32/*tapset*/)  //  oSample14 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample12 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample12 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample12 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G0_M1,12/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample12 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -512,15/*oSample*/,32/*tapset*/)  //  oSample15 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample14 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample14 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample14 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample14 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -512,18/*oSample*/,32/*tapset*/)  //  oSample18 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample15 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample15 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample15 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample15 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -512,21/*oSample*/,32/*tapset*/)  //  oSample21 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample18 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample18 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample18 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample18 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -512,22/*oSample*/,32/*tapset*/)  //  oSample22 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample21 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample21 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample21 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample21 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -496,2/*oSample*/,33/*tapset*/)  //  oSample2 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample22 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample22 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample22 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample22 tapSet33 Ch0  ISampleSet33 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -496,3/*oSample*/,33/*tapset*/)  //  oSample3 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G0_M1, tapSet_G0_M0,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample02Accum, iSampleSet_G1_M0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -496,6/*oSample*/,33/*tapset*/)  //  oSample6 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G0_M1, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -496,9/*oSample*/,33/*tapset*/)  //  oSample9 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M1, tapSet_G0_M0,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -496,10/*oSample*/,33/*tapset*/)  //  oSample10 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -496,13/*oSample*/,33/*tapset*/)  //  oSample13 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -496,16/*oSample*/,33/*tapset*/)  //  oSample16 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample13 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample13 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample13 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample13 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -496,17/*oSample*/,33/*tapset*/)  //  oSample17 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample16 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample16 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample16 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample16 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -496,19/*oSample*/,33/*tapset*/)  //  oSample19 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample17 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample17 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample17 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample17 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -496,20/*oSample*/,33/*tapset*/)  //  oSample20 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample19 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample19 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample19 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample19 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -496,23/*oSample*/,33/*tapset*/)  //  oSample23 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample20 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample20 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample20 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample20 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -480,1/*oSample*/,34/*tapset*/)  //  oSample1 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample23 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample23 tapSet33 Ch0  ISampleSet33 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,36/*R0 iSampleSet*/,37/*R1 iSampleSet*/) //  chan0,0 iSampleSet36,37
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample23 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample23 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -480,4/*oSample*/,34/*tapset*/)  //  oSample4 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample01Accum, iSampleSet_G1_M0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -480,5/*oSample*/,34/*tapset*/)  //  oSample5 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample04Accum, iSampleSet_G1_M1, tapSet_G0_M1,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -480,7/*oSample*/,34/*tapset*/)  //  oSample7 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G1_M1, tapSet_G1_M1,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -480,8/*oSample*/,34/*tapset*/)  //  oSample8 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G1_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -480,11/*oSample*/,34/*tapset*/)  //  oSample11 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -480,12/*oSample*/,34/*tapset*/)  //  oSample12 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -480,14/*oSample*/,34/*tapset*/)  //  oSample14 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample12 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample12 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample12 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample12 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -480,15/*oSample*/,34/*tapset*/)  //  oSample15 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample14 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample14 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample14 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample14 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -480,18/*oSample*/,34/*tapset*/)  //  oSample18 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample15 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample15 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample15 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample15 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -480,21/*oSample*/,34/*tapset*/)  //  oSample21 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample18 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample18 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample18 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample18 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -480,22/*oSample*/,34/*tapset*/)  //  oSample22 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample21 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample21 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample21 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample21 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -464,2/*oSample*/,35/*tapset*/)  //  oSample2 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample22 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample22 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample22 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample22 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -464,3/*oSample*/,35/*tapset*/)  //  oSample3 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample02Accum, iSampleSet_G1_M1, tapSet_G1_M0,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -464,6/*oSample*/,35/*tapset*/)  //  oSample6 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample03Accum, iSampleSet_G1_M1, tapSet_G0_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -464,9/*oSample*/,35/*tapset*/)  //  oSample9 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G1_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample06Accum, iSampleSet_G0_M0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -464,10/*oSample*/,35/*tapset*/)  //  oSample10 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -464,13/*oSample*/,35/*tapset*/)  //  oSample13 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -464,16/*oSample*/,35/*tapset*/)  //  oSample16 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample13 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample13 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample13 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample13 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -464,17/*oSample*/,35/*tapset*/)  //  oSample17 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample16 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample16 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample16 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample16 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -464,19/*oSample*/,35/*tapset*/)  //  oSample19 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample17 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample17 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample17 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample17 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -464,20/*oSample*/,35/*tapset*/)  //  oSample20 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample19 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample19 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample19 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample19 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -464,23/*oSample*/,35/*tapset*/)  //  oSample23 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample20 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample20 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample20 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample20 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -448,4/*oSample*/,36/*tapset*/)  //  oSample4 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample23 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample23 tapSet35 Ch0  ISampleSet35 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,38/*R0 iSampleSet*/,39/*R1 iSampleSet*/) //  chan0,0 iSampleSet38,39
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample23 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample23 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -448,5/*oSample*/,36/*tapset*/)  //  oSample5 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample04Accum, iSampleSet_G0_M0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -448,7/*oSample*/,36/*tapset*/)  //  oSample7 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample05Accum, iSampleSet_G0_M0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -448,8/*oSample*/,36/*tapset*/)  //  oSample8 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample07Accum, iSampleSet_G0_M1, tapSet_G0_M1,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -448,11/*oSample*/,36/*tapset*/)  //  oSample11 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G0_M1, tapSet_G1_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -448,12/*oSample*/,36/*tapset*/)  //  oSample12 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G0_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -448,14/*oSample*/,36/*tapset*/)  //  oSample14 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample12 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample12 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample12 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample12 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -448,15/*oSample*/,36/*tapset*/)  //  oSample15 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample14 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample14 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample14 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample14 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -448,18/*oSample*/,36/*tapset*/)  //  oSample18 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample15 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample15 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample15 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample15 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -448,21/*oSample*/,36/*tapset*/)  //  oSample21 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample18 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample18 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample18 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample18 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -448,22/*oSample*/,36/*tapset*/)  //  oSample22 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample21 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample21 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample21 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample21 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -432,6/*oSample*/,37/*tapset*/)  //  oSample6 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample22 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample22 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample22 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample22 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -432,9/*oSample*/,37/*tapset*/)  //  oSample9 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample06Accum, iSampleSet_G0_M1, tapSet_G1_M0,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -432,10/*oSample*/,37/*tapset*/)  //  oSample10 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G0_M1, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample09Accum, iSampleSet_G1_M0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -432,13/*oSample*/,37/*tapset*/)  //  oSample13 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G0_M1, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -432,16/*oSample*/,37/*tapset*/)  //  oSample16 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample13 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample13 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample13 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M0, tapSet_G0_M1,13/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample13 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -432,17/*oSample*/,37/*tapset*/)  //  oSample17 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample16 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample16 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample16 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample16 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -432,19/*oSample*/,37/*tapset*/)  //  oSample19 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample17 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample17 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample17 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample17 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -432,20/*oSample*/,37/*tapset*/)  //  oSample20 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample19 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample19 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample19 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample19 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -432,23/*oSample*/,37/*tapset*/)  //  oSample23 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample20 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample20 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample20 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample20 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -416,7/*oSample*/,38/*tapset*/)  //  oSample7 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample23 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample23 tapSet37 Ch0  ISampleSet37 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,40/*R0 iSampleSet*/,41/*R1 iSampleSet*/) //  chan0,0 iSampleSet40,41
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample23 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample23 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -416,8/*oSample*/,38/*tapset*/)  //  oSample8 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample07Accum, iSampleSet_G1_M0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -416,11/*oSample*/,38/*tapset*/)  //  oSample11 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample08Accum, iSampleSet_G1_M0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample12FitlerP, -416,12/*oSample*/,38/*tapset*/)  //  oSample12 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample11Accum, iSampleSet_G1_M1, tapSet_G0_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -416,14/*oSample*/,38/*tapset*/)  //  oSample14 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample12 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M0, tapSet_G1_M0,12/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample12 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample12 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G1_M1, tapSet_G1_M1,12/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample12 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -416,15/*oSample*/,38/*tapset*/)  //  oSample15 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample14 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample14 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample14 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G1_M1, tapSet_G0_M1,14/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample14 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -416,18/*oSample*/,38/*tapset*/)  //  oSample18 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample15 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample15 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample15 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M1, tapSet_G1_M1,15/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample15 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -416,21/*oSample*/,38/*tapset*/)  //  oSample21 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample18 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample18 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample18 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample18 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -416,22/*oSample*/,38/*tapset*/)  //  oSample22 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample21 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample21 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample21 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample21 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -400,9/*oSample*/,39/*tapset*/)  //  oSample9 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample22 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample22 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample22 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample22 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -400,10/*oSample*/,39/*tapset*/)  //  oSample10 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample09Accum, iSampleSet_G1_M1, tapSet_G1_M0,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample13FitlerP, -400,13/*oSample*/,39/*tapset*/)  //  oSample13 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample10Accum, iSampleSet_G1_M1, tapSet_G0_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample16FitlerP, -400,16/*oSample*/,39/*tapset*/)  //  oSample16 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample13 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G1_M1, tapSet_G1_M0,13/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample13 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample13 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M0, tapSet_G1_M1,13/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample13 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample17FitlerP, -400,17/*oSample*/,39/*tapset*/)  //  oSample17 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample16 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M1, tapSet_G0_M0,16/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample16 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample16 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M0, tapSet_G0_M1,16/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample16 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample19FitlerP, -400,19/*oSample*/,39/*tapset*/)  //  oSample19 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample17 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G1_M0,17/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample17 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample17 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M0, tapSet_G1_M1,17/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample17 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample20FitlerP, -400,20/*oSample*/,39/*tapset*/)  //  oSample20 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample19 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G0_M0,19/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample19 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample19 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G0_M1,19/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample19 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -400,23/*oSample*/,39/*tapset*/)  //  oSample23 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample20 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G1_M0,20/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample20 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample20 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G1_M1,20/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample20 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -384,11/*oSample*/,40/*tapset*/)  //  oSample11 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample23 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample23 tapSet39 Ch0  ISampleSet39 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,42/*R0 iSampleSet*/,43/*R1 iSampleSet*/) //  chan0,0 iSampleSet42,43
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample23 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G0_M1,23/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample23 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample12FitlerP, -384,12/*oSample*/,40/*tapset*/)  //  oSample12 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample11Accum, iSampleSet_G0_M0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample14FitlerP, -384,14/*oSample*/,40/*tapset*/)  //  oSample14 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample12 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample12Accum, iSampleSet_G0_M0, tapSet_G0_M0,12/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample12 tapSet40 Ch0  ISampleSet40 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample15FitlerP, -384,15/*oSample*/,40/*tapset*/)  //  oSample15 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample14 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M0, tapSet_G1_M0,14/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample14 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample14 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample14Accum, iSampleSet_G0_M1, tapSet_G1_M1,14/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample14 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample18FitlerP, -384,18/*oSample*/,40/*tapset*/)  //  oSample18 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample15 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M0, tapSet_G0_M0,15/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample15 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample15 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G0_M1, tapSet_G0_M1,15/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample15 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -384,21/*oSample*/,40/*tapset*/)  //  oSample21 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample18 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M0, tapSet_G1_M0,18/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample18 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample18 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G0_M1, tapSet_G1_M1,18/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample18 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -384,22/*oSample*/,40/*tapset*/)  //  oSample22 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample21 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample21 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample21 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G0_M1,21/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample21 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample13FitlerP, -368,13/*oSample*/,41/*tapset*/)  //  oSample13 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample22 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample22 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample22 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G1_M1,22/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample22 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -368,16/*oSample*/,41/*tapset*/)  //  oSample16 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample13 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample13Accum, iSampleSet_G0_M1, tapSet_G0_M0,13/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample13 tapSet41 Ch0  ISampleSet41 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -368,17/*oSample*/,41/*tapset*/)  //  oSample17 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample16 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G0_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample16 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample16 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample16Accum, iSampleSet_G1_M0, tapSet_G1_M1,16/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample16 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -368,19/*oSample*/,41/*tapset*/)  //  oSample19 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample17 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G0_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample17 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample17 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M0, tapSet_G0_M1,17/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample17 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -368,20/*oSample*/,41/*tapset*/)  //  oSample20 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample19 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample19 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample19 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample19 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -368,23/*oSample*/,41/*tapset*/)  //  oSample23 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample20 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample20 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample20 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample20 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample14FitlerP, -352,14/*oSample*/,42/*tapset*/)  //  oSample14 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample23 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample23 tapSet41 Ch0  ISampleSet41 
        load_8_samples(iSampleSet_G0_M0, iSampleSet_G0_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,44/*R0 iSampleSet*/,45/*R1 iSampleSet*/) //  chan0,0 iSampleSet44,45
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample23 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample23 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample15FitlerP, -352,15/*oSample*/,42/*tapset*/)  //  oSample15 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample14Accum, iSampleSet_G1_M0, tapSet_G0_M0,14/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample14 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -352,18/*oSample*/,42/*tapset*/)  //  oSample18 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample15 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample15Accum, iSampleSet_G1_M0, tapSet_G1_M0,15/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample15 tapSet42 Ch0  ISampleSet42 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -352,21/*oSample*/,42/*tapset*/)  //  oSample21 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample18 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample18 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample18 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample18Accum, iSampleSet_G1_M1, tapSet_G0_M1,18/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample18 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -352,22/*oSample*/,42/*tapset*/)  //  oSample22 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample21 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample21 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample21 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G1_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample21 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample16FitlerP, -336,16/*oSample*/,43/*tapset*/)  //  oSample16 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample22 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample22 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample22 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample22 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample17FitlerP, -336,17/*oSample*/,43/*tapset*/)  //  oSample17 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample16Accum, iSampleSet_G1_M1, tapSet_G1_M0,16/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample16 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -336,19/*oSample*/,43/*tapset*/)  //  oSample19 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample17 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample17Accum, iSampleSet_G1_M1, tapSet_G0_M0,17/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample17 tapSet43 Ch0  ISampleSet43 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -336,20/*oSample*/,43/*tapset*/)  //  oSample20 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample19 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G1_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample19 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample19 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample19Accum, iSampleSet_G0_M0, tapSet_G1_M1,19/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample19 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -336,23/*oSample*/,43/*tapset*/)  //  oSample23 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample20 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G1_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample20 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample20 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M0, tapSet_G0_M1,20/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample20 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample18FitlerP, -320,18/*oSample*/,44/*tapset*/)  //  oSample18 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample23 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample23 tapSet43 Ch0  ISampleSet43 
        load_8_samples(iSampleSet_G1_M0, iSampleSet_G1_M1, inputISampleQueueP,0/*R0 chan*/,0/*R1 chan*/,46/*R0 iSampleSet*/,47/*R1 iSampleSet*/) //  chan0,0 iSampleSet46,47
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample23 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample23 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample21FitlerP, -320,21/*oSample*/,44/*tapset*/)  //  oSample21 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample18Accum, iSampleSet_G0_M0, tapSet_G0_M0,18/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample18 tapSet44 Ch0  ISampleSet44 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample22FitlerP, -320,22/*oSample*/,44/*tapset*/)  //  oSample22 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample21 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M0, tapSet_G1_M0,21/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample21 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample21 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample21Accum, iSampleSet_G0_M1, tapSet_G1_M1,21/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample21 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample19FitlerP, -304,19/*oSample*/,45/*tapset*/)  //  oSample19 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample22 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M0, tapSet_G0_M0,22/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample22 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample22 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G0_M1, tapSet_G0_M1,22/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample22 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample20FitlerP, -304,20/*oSample*/,45/*tapset*/)  //  oSample20 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample19Accum, iSampleSet_G0_M1, tapSet_G1_M0,19/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample19 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample23FitlerP, -304,23/*oSample*/,45/*tapset*/)  //  oSample23 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample20 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample20Accum, iSampleSet_G0_M1, tapSet_G0_M0,20/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample20 tapSet45 Ch0  ISampleSet45 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample21FitlerP, -288,21/*oSample*/,46/*tapset*/)  //  oSample21 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample23 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G0_M1, tapSet_G1_M0,23/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample23 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample23 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample23Accum, iSampleSet_G1_M0, tapSet_G1_M1,23/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample23 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_nontemporal( tapSet_G1_M0, tapSet_G1_M1, oSample22FitlerP, -288,22/*oSample*/,46/*tapset*/)  //  oSample22 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample21Accum, iSampleSet_G1_M0, tapSet_G0_M0,21/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample21 tapSet46 Ch0  ISampleSet46 
        load_8_filter_taps_nontemporal( tapSet_G0_M0, tapSet_G0_M1, oSample23FitlerP, -272,23/*oSample*/,47/*tapset*/)  //  oSample23 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample22 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample22Accum, iSampleSet_G1_M0, tapSet_G1_M0,22/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample22 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample23Accum, iSampleSet_G1_M1, tapSet_G0_M0,23/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample23 tapSet47 Ch0  ISampleSet47 
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
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo)
{
     return SsrcSampleRateConverter_insr_1024_outsr_441_taps_136_mono_SsrcSampleFormat_int32::construct(*returnedInfo);
}
