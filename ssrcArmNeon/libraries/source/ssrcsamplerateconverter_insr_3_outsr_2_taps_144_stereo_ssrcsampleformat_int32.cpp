/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcsamplerateconverter_insr_3_outsr_2_taps_144_stereo_ssrcsampleformat_int32.h"
/********************************************************************************
*  iSample rate converter input iSample rate 3 output iSample rate 2 stereo
*
*******************************************************************************/
/********************************************************************************
*  
*
*******************************************************************************/
SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32::SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32()
{
}
/********************************************************************************
*  iSample processing
*
*******************************************************************************/
bool SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32::process()
{
    if (!inputOutputQueueReadyForRun()) return false;
    register int64x2_t oSample00AccumCh0 ArmRegister("v0"); // oSample0 chan0 oSample accumulators
    register int64x2_t oSample00AccumCh1 ArmRegister("v1"); // oSample0 chan1 oSample accumulators
    register int64x2_t oSample01AccumCh0 ArmRegister("v2"); // oSample1 chan0 oSample accumulators
    register int64x2_t oSample01AccumCh1 ArmRegister("v3"); // oSample1 chan1 oSample accumulators
    register int64x2_t oSample02AccumCh0 ArmRegister("v4"); // oSample2 chan0 oSample accumulators
    register int64x2_t oSample02AccumCh1 ArmRegister("v5"); // oSample2 chan1 oSample accumulators
    register int64x2_t oSample03AccumCh0 ArmRegister("v6"); // oSample3 chan0 oSample accumulators
    register int64x2_t oSample03AccumCh1 ArmRegister("v7"); // oSample3 chan1 oSample accumulators
    register int64x2_t oSample04AccumCh0 ArmRegister("v8"); // oSample4 chan0 oSample accumulators
    register int64x2_t oSample04AccumCh1 ArmRegister("v9"); // oSample4 chan1 oSample accumulators
    register int64x2_t oSample05AccumCh0 ArmRegister("v10"); // oSample5 chan0 oSample accumulators
    register int64x2_t oSample05AccumCh1 ArmRegister("v11"); // oSample5 chan1 oSample accumulators
    register int64x2_t oSample06AccumCh0 ArmRegister("v12"); // oSample6 chan0 oSample accumulators
    register int64x2_t oSample06AccumCh1 ArmRegister("v13"); // oSample6 chan1 oSample accumulators
    register int64x2_t oSample07AccumCh0 ArmRegister("v14"); // oSample7 chan0 oSample accumulators
    register int64x2_t oSample07AccumCh1 ArmRegister("v15"); // oSample7 chan1 oSample accumulators
    register int64x2_t oSample08AccumCh0 ArmRegister("v16"); // oSample8 chan0 oSample accumulators
    register int64x2_t oSample08AccumCh1 ArmRegister("v17"); // oSample8 chan1 oSample accumulators
    register int64x2_t oSample09AccumCh0 ArmRegister("v18"); // oSample9 chan0 oSample accumulators
    register int64x2_t oSample09AccumCh1 ArmRegister("v19"); // oSample9 chan1 oSample accumulators
    register int64x2_t oSample10AccumCh0 ArmRegister("v20"); // oSample10 chan0 oSample accumulators
    register int64x2_t oSample10AccumCh1 ArmRegister("v21"); // oSample10 chan1 oSample accumulators
    register int64x2_t oSample11AccumCh0 ArmRegister("v22"); // oSample11 chan0 oSample accumulators
    register int64x2_t oSample11AccumCh1 ArmRegister("v23"); // oSample11 chan1 oSample accumulators
    register int32x4_t tapSet_G0_M0 ArmRegister("v24"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G0_M1 ArmRegister("v25"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G1_M0 ArmRegister("v26"); // OSamples filter tapSet ping pong registers
    register int32x4_t tapSet_G1_M1 ArmRegister("v27"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G0_Ch0 ArmRegister("v28"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G0_Ch1 ArmRegister("v29"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G1_Ch0 ArmRegister("v30"); // OSamples filter tapSet ping pong registers
    register int32x4_t iSampleSet_G1_Ch1 ArmRegister("v31"); // OSamples filter tapSet ping pong registers
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
    register int32_t *inputISampleQueueP ArmRegister("x12"); // input iSample queue pointer
    register int32_t *inputISampleQueuePMask ArmRegister("x13"); // input iSample queue pointer wrap mask
    register int32_t *outputSampleQueueP ArmRegister("x14"); // output iSample queue pointer
    register int32_t *outputSampleQueuePMask ArmRegister("x15"); // output iSample queue pointer wrap mask
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
    inputQueue.getCurrentGetPos(inputISampleQueueP);
    outputQueue.getCurrentPutPos(outputSampleQueueP);
    inputQueue.getQueuePointerMask(inputISampleQueuePMask);
    outputQueue.getQueuePointerMask(outputSampleQueuePMask);
    inputQueue.updateGetPos(offsetP*numberOfChannels);
    outputQueue.updatePutPos(totalNumOutputSamplesPerRun);
    asm_block_start() 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,0/*R0 iSampleSet*/,0/*R1 iSampleSet*/) //  chan0,1 iSampleSet0,0
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,1/*R0 iSampleSet*/,1/*R1 iSampleSet*/) //  chan0,1 iSampleSet1,1
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -1024,0/*oSample*/,0/*tapset*/)  //  oSample0 tapSet0,1 iSampleSet0,1
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -1024,1/*oSample*/,0/*tapset*/)  //  oSample1 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample00AccumCh0,0/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        clear_accumulator(oSample00AccumCh1,0/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch1  ISampleSet0 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch1  ISampleSet0 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch1  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -1024,2/*oSample*/,0/*tapset*/)  //  oSample2 tapSet0,1 iSampleSet0,1
        clear_accumulator(oSample01AccumCh0,1/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch0  ISampleSet0 
        clear_accumulator(oSample01AccumCh1,1/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch1  ISampleSet0 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample1 tapSet0 Ch1  ISampleSet0 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch1  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -1008,3/*oSample*/,1/*tapset*/)  //  oSample3 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample02AccumCh0,2/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample2 tapSet0 Ch0  ISampleSet0 
        clear_accumulator(oSample02AccumCh1,2/*oSample*/,1/*chan*/)
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample2 tapSet0 Ch1  ISampleSet0 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,2/*R0 iSampleSet*/,2/*R1 iSampleSet*/) //  chan0,1 iSampleSet2,2
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample2 tapSet1 Ch1  ISampleSet1 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -1008,4/*oSample*/,1/*tapset*/)  //  oSample4 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample03AccumCh0,3/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch0  ISampleSet1 
        clear_accumulator(oSample03AccumCh1,3/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample3 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample3 tapSet2 Ch1  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -1008,5/*oSample*/,1/*tapset*/)  //  oSample5 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample04AccumCh0,4/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample4 tapSet1 Ch0  ISampleSet1 
        clear_accumulator(oSample04AccumCh1,4/*oSample*/,1/*chan*/)
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample4 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample4 tapSet2 Ch1  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, -992,0/*oSample*/,2/*tapset*/)  //  oSample0 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample05AccumCh0,5/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample5 tapSet1 Ch0  ISampleSet1 
        clear_accumulator(oSample05AccumCh1,5/*oSample*/,1/*chan*/)
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample5 tapSet1 Ch1  ISampleSet1 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,3/*R0 iSampleSet*/,3/*R1 iSampleSet*/) //  chan0,1 iSampleSet3,3
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample5 tapSet2 Ch1  ISampleSet2 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -992,1/*oSample*/,2/*tapset*/)  //  oSample1 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -992,2/*oSample*/,2/*tapset*/)  //  oSample2 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -992,6/*oSample*/,2/*tapset*/)  //  oSample6 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -992,7/*oSample*/,2/*tapset*/)  //  oSample7 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample06AccumCh0,6/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch0  ISampleSet2 
        clear_accumulator(oSample06AccumCh1,6/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample6 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample6 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -976,3/*oSample*/,3/*tapset*/)  //  oSample3 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample07AccumCh0,7/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample7 tapSet2 Ch0  ISampleSet2 
        clear_accumulator(oSample07AccumCh1,7/*oSample*/,1/*chan*/)
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,7/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample7 tapSet2 Ch1  ISampleSet2 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,4/*R0 iSampleSet*/,4/*R1 iSampleSet*/) //  chan0,1 iSampleSet4,4
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample7 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -976,4/*oSample*/,3/*tapset*/)  //  oSample4 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -976,5/*oSample*/,3/*tapset*/)  //  oSample5 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample4 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -976,8/*oSample*/,3/*tapset*/)  //  oSample8 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample5 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample5 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -976,9/*oSample*/,3/*tapset*/)  //  oSample9 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample08AccumCh0,8/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch0  ISampleSet3 
        clear_accumulator(oSample08AccumCh1,8/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample8 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample8 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -976,10/*oSample*/,3/*tapset*/)  //  oSample10 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample09AccumCh0,9/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch0  ISampleSet3 
        clear_accumulator(oSample09AccumCh1,9/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample9 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample9 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -960,0/*oSample*/,4/*tapset*/)  //  oSample0 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample10AccumCh0,10/*oSample*/,0/*chan*/)
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample10 tapSet3 Ch0  ISampleSet3 
        clear_accumulator(oSample10AccumCh1,10/*oSample*/,1/*chan*/)
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample10 tapSet3 Ch1  ISampleSet3 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,5/*R0 iSampleSet*/,5/*R1 iSampleSet*/) //  chan0,1 iSampleSet5,5
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample10 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -960,1/*oSample*/,4/*tapset*/)  //  oSample1 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -960,2/*oSample*/,4/*tapset*/)  //  oSample2 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -960,6/*oSample*/,4/*tapset*/)  //  oSample6 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -960,7/*oSample*/,4/*tapset*/)  //  oSample7 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample6 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample6 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -960,11/*oSample*/,4/*tapset*/)  //  oSample11 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample7 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample7 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -944,3/*oSample*/,5/*tapset*/)  //  oSample3 tapSet5,6 iSampleSet5,6
        clear_accumulator(oSample11AccumCh0,11/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch0  ISampleSet4 
        clear_accumulator(oSample11AccumCh1,11/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample11 tapSet4 Ch1  ISampleSet4 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,6/*R0 iSampleSet*/,6/*R1 iSampleSet*/) //  chan0,1 iSampleSet6,6
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample11 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -944,4/*oSample*/,5/*tapset*/)  //  oSample4 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -944,5/*oSample*/,5/*tapset*/)  //  oSample5 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -944,8/*oSample*/,5/*tapset*/)  //  oSample8 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -944,9/*oSample*/,5/*tapset*/)  //  oSample9 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample8 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample8 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -944,10/*oSample*/,5/*tapset*/)  //  oSample10 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample9 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample9 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -928,0/*oSample*/,6/*tapset*/)  //  oSample0 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample10 tapSet5 Ch1  ISampleSet5 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,7/*R0 iSampleSet*/,7/*R1 iSampleSet*/) //  chan0,1 iSampleSet7,7
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample10 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -928,1/*oSample*/,6/*tapset*/)  //  oSample1 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -928,2/*oSample*/,6/*tapset*/)  //  oSample2 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -928,6/*oSample*/,6/*tapset*/)  //  oSample6 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -928,7/*oSample*/,6/*tapset*/)  //  oSample7 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -928,11/*oSample*/,6/*tapset*/)  //  oSample11 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample7 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -912,3/*oSample*/,7/*tapset*/)  //  oSample3 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample11 tapSet6 Ch1  ISampleSet6 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,8/*R0 iSampleSet*/,8/*R1 iSampleSet*/) //  chan0,1 iSampleSet8,8
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample11 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -912,4/*oSample*/,7/*tapset*/)  //  oSample4 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -912,5/*oSample*/,7/*tapset*/)  //  oSample5 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -912,8/*oSample*/,7/*tapset*/)  //  oSample8 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -912,9/*oSample*/,7/*tapset*/)  //  oSample9 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample8 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -912,10/*oSample*/,7/*tapset*/)  //  oSample10 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample9 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample9 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -896,0/*oSample*/,8/*tapset*/)  //  oSample0 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample10 tapSet7 Ch1  ISampleSet7 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,9/*R0 iSampleSet*/,9/*R1 iSampleSet*/) //  chan0,1 iSampleSet9,9
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample10 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -896,1/*oSample*/,8/*tapset*/)  //  oSample1 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -896,2/*oSample*/,8/*tapset*/)  //  oSample2 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -896,6/*oSample*/,8/*tapset*/)  //  oSample6 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -896,7/*oSample*/,8/*tapset*/)  //  oSample7 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -896,11/*oSample*/,8/*tapset*/)  //  oSample11 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -880,3/*oSample*/,9/*tapset*/)  //  oSample3 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample11 tapSet8 Ch1  ISampleSet8 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,10/*R0 iSampleSet*/,10/*R1 iSampleSet*/) //  chan0,1 iSampleSet10,10
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample11 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -880,4/*oSample*/,9/*tapset*/)  //  oSample4 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -880,5/*oSample*/,9/*tapset*/)  //  oSample5 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -880,8/*oSample*/,9/*tapset*/)  //  oSample8 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -880,9/*oSample*/,9/*tapset*/)  //  oSample9 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -880,10/*oSample*/,9/*tapset*/)  //  oSample10 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -864,0/*oSample*/,10/*tapset*/)  //  oSample0 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample10 tapSet9 Ch1  ISampleSet9 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,11/*R0 iSampleSet*/,11/*R1 iSampleSet*/) //  chan0,1 iSampleSet11,11
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -864,1/*oSample*/,10/*tapset*/)  //  oSample1 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -864,2/*oSample*/,10/*tapset*/)  //  oSample2 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -864,6/*oSample*/,10/*tapset*/)  //  oSample6 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -864,7/*oSample*/,10/*tapset*/)  //  oSample7 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -864,11/*oSample*/,10/*tapset*/)  //  oSample11 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -848,3/*oSample*/,11/*tapset*/)  //  oSample3 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample11 tapSet10 Ch1  ISampleSet10 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,12/*R0 iSampleSet*/,12/*R1 iSampleSet*/) //  chan0,1 iSampleSet12,12
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -848,4/*oSample*/,11/*tapset*/)  //  oSample4 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -848,5/*oSample*/,11/*tapset*/)  //  oSample5 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -848,8/*oSample*/,11/*tapset*/)  //  oSample8 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -848,9/*oSample*/,11/*tapset*/)  //  oSample9 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -848,10/*oSample*/,11/*tapset*/)  //  oSample10 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -832,0/*oSample*/,12/*tapset*/)  //  oSample0 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch1  ISampleSet11 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,13/*R0 iSampleSet*/,13/*R1 iSampleSet*/) //  chan0,1 iSampleSet13,13
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -832,1/*oSample*/,12/*tapset*/)  //  oSample1 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -832,2/*oSample*/,12/*tapset*/)  //  oSample2 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -832,6/*oSample*/,12/*tapset*/)  //  oSample6 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -832,7/*oSample*/,12/*tapset*/)  //  oSample7 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -832,11/*oSample*/,12/*tapset*/)  //  oSample11 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -816,3/*oSample*/,13/*tapset*/)  //  oSample3 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch1  ISampleSet12 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,14/*R0 iSampleSet*/,14/*R1 iSampleSet*/) //  chan0,1 iSampleSet14,14
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -816,4/*oSample*/,13/*tapset*/)  //  oSample4 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -816,5/*oSample*/,13/*tapset*/)  //  oSample5 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -816,8/*oSample*/,13/*tapset*/)  //  oSample8 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -816,9/*oSample*/,13/*tapset*/)  //  oSample9 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -816,10/*oSample*/,13/*tapset*/)  //  oSample10 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -800,0/*oSample*/,14/*tapset*/)  //  oSample0 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch1  ISampleSet13 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,15/*R0 iSampleSet*/,15/*R1 iSampleSet*/) //  chan0,1 iSampleSet15,15
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -800,1/*oSample*/,14/*tapset*/)  //  oSample1 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -800,2/*oSample*/,14/*tapset*/)  //  oSample2 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -800,6/*oSample*/,14/*tapset*/)  //  oSample6 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -800,7/*oSample*/,14/*tapset*/)  //  oSample7 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -800,11/*oSample*/,14/*tapset*/)  //  oSample11 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -784,3/*oSample*/,15/*tapset*/)  //  oSample3 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch1  ISampleSet14 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,16/*R0 iSampleSet*/,16/*R1 iSampleSet*/) //  chan0,1 iSampleSet16,16
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -784,4/*oSample*/,15/*tapset*/)  //  oSample4 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -784,5/*oSample*/,15/*tapset*/)  //  oSample5 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -784,8/*oSample*/,15/*tapset*/)  //  oSample8 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -784,9/*oSample*/,15/*tapset*/)  //  oSample9 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -784,10/*oSample*/,15/*tapset*/)  //  oSample10 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -768,0/*oSample*/,16/*tapset*/)  //  oSample0 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch1  ISampleSet15 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,17/*R0 iSampleSet*/,17/*R1 iSampleSet*/) //  chan0,1 iSampleSet17,17
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -768,1/*oSample*/,16/*tapset*/)  //  oSample1 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -768,2/*oSample*/,16/*tapset*/)  //  oSample2 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -768,6/*oSample*/,16/*tapset*/)  //  oSample6 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -768,7/*oSample*/,16/*tapset*/)  //  oSample7 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -768,11/*oSample*/,16/*tapset*/)  //  oSample11 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -752,3/*oSample*/,17/*tapset*/)  //  oSample3 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch1  ISampleSet16 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,18/*R0 iSampleSet*/,18/*R1 iSampleSet*/) //  chan0,1 iSampleSet18,18
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -752,4/*oSample*/,17/*tapset*/)  //  oSample4 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -752,5/*oSample*/,17/*tapset*/)  //  oSample5 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -752,8/*oSample*/,17/*tapset*/)  //  oSample8 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -752,9/*oSample*/,17/*tapset*/)  //  oSample9 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -752,10/*oSample*/,17/*tapset*/)  //  oSample10 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -736,0/*oSample*/,18/*tapset*/)  //  oSample0 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch1  ISampleSet17 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,19/*R0 iSampleSet*/,19/*R1 iSampleSet*/) //  chan0,1 iSampleSet19,19
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -736,1/*oSample*/,18/*tapset*/)  //  oSample1 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -736,2/*oSample*/,18/*tapset*/)  //  oSample2 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -736,6/*oSample*/,18/*tapset*/)  //  oSample6 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -736,7/*oSample*/,18/*tapset*/)  //  oSample7 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -736,11/*oSample*/,18/*tapset*/)  //  oSample11 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -720,3/*oSample*/,19/*tapset*/)  //  oSample3 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch1  ISampleSet18 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,20/*R0 iSampleSet*/,20/*R1 iSampleSet*/) //  chan0,1 iSampleSet20,20
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -720,4/*oSample*/,19/*tapset*/)  //  oSample4 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -720,5/*oSample*/,19/*tapset*/)  //  oSample5 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -720,8/*oSample*/,19/*tapset*/)  //  oSample8 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -720,9/*oSample*/,19/*tapset*/)  //  oSample9 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -720,10/*oSample*/,19/*tapset*/)  //  oSample10 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -704,0/*oSample*/,20/*tapset*/)  //  oSample0 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch1  ISampleSet19 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,21/*R0 iSampleSet*/,21/*R1 iSampleSet*/) //  chan0,1 iSampleSet21,21
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -704,1/*oSample*/,20/*tapset*/)  //  oSample1 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -704,2/*oSample*/,20/*tapset*/)  //  oSample2 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -704,6/*oSample*/,20/*tapset*/)  //  oSample6 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -704,7/*oSample*/,20/*tapset*/)  //  oSample7 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -704,11/*oSample*/,20/*tapset*/)  //  oSample11 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -688,3/*oSample*/,21/*tapset*/)  //  oSample3 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch1  ISampleSet20 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,22/*R0 iSampleSet*/,22/*R1 iSampleSet*/) //  chan0,1 iSampleSet22,22
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -688,4/*oSample*/,21/*tapset*/)  //  oSample4 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -688,5/*oSample*/,21/*tapset*/)  //  oSample5 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -688,8/*oSample*/,21/*tapset*/)  //  oSample8 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -688,9/*oSample*/,21/*tapset*/)  //  oSample9 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -688,10/*oSample*/,21/*tapset*/)  //  oSample10 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -672,0/*oSample*/,22/*tapset*/)  //  oSample0 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch1  ISampleSet21 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,23/*R0 iSampleSet*/,23/*R1 iSampleSet*/) //  chan0,1 iSampleSet23,23
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -672,1/*oSample*/,22/*tapset*/)  //  oSample1 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -672,2/*oSample*/,22/*tapset*/)  //  oSample2 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -672,6/*oSample*/,22/*tapset*/)  //  oSample6 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -672,7/*oSample*/,22/*tapset*/)  //  oSample7 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -672,11/*oSample*/,22/*tapset*/)  //  oSample11 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -656,3/*oSample*/,23/*tapset*/)  //  oSample3 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch1  ISampleSet22 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,24/*R0 iSampleSet*/,24/*R1 iSampleSet*/) //  chan0,1 iSampleSet24,24
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -656,4/*oSample*/,23/*tapset*/)  //  oSample4 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -656,5/*oSample*/,23/*tapset*/)  //  oSample5 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -656,8/*oSample*/,23/*tapset*/)  //  oSample8 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -656,9/*oSample*/,23/*tapset*/)  //  oSample9 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -656,10/*oSample*/,23/*tapset*/)  //  oSample10 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -640,0/*oSample*/,24/*tapset*/)  //  oSample0 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch1  ISampleSet23 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,25/*R0 iSampleSet*/,25/*R1 iSampleSet*/) //  chan0,1 iSampleSet25,25
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -640,1/*oSample*/,24/*tapset*/)  //  oSample1 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -640,2/*oSample*/,24/*tapset*/)  //  oSample2 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -640,6/*oSample*/,24/*tapset*/)  //  oSample6 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -640,7/*oSample*/,24/*tapset*/)  //  oSample7 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -640,11/*oSample*/,24/*tapset*/)  //  oSample11 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -624,3/*oSample*/,25/*tapset*/)  //  oSample3 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch1  ISampleSet24 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,26/*R0 iSampleSet*/,26/*R1 iSampleSet*/) //  chan0,1 iSampleSet26,26
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -624,4/*oSample*/,25/*tapset*/)  //  oSample4 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -624,5/*oSample*/,25/*tapset*/)  //  oSample5 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -624,8/*oSample*/,25/*tapset*/)  //  oSample8 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -624,9/*oSample*/,25/*tapset*/)  //  oSample9 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -624,10/*oSample*/,25/*tapset*/)  //  oSample10 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -608,0/*oSample*/,26/*tapset*/)  //  oSample0 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch1  ISampleSet25 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,27/*R0 iSampleSet*/,27/*R1 iSampleSet*/) //  chan0,1 iSampleSet27,27
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -608,1/*oSample*/,26/*tapset*/)  //  oSample1 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -608,2/*oSample*/,26/*tapset*/)  //  oSample2 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -608,6/*oSample*/,26/*tapset*/)  //  oSample6 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -608,7/*oSample*/,26/*tapset*/)  //  oSample7 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -608,11/*oSample*/,26/*tapset*/)  //  oSample11 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -592,3/*oSample*/,27/*tapset*/)  //  oSample3 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch1  ISampleSet26 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,28/*R0 iSampleSet*/,28/*R1 iSampleSet*/) //  chan0,1 iSampleSet28,28
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -592,4/*oSample*/,27/*tapset*/)  //  oSample4 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -592,5/*oSample*/,27/*tapset*/)  //  oSample5 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -592,8/*oSample*/,27/*tapset*/)  //  oSample8 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -592,9/*oSample*/,27/*tapset*/)  //  oSample9 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -592,10/*oSample*/,27/*tapset*/)  //  oSample10 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -576,0/*oSample*/,28/*tapset*/)  //  oSample0 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch1  ISampleSet27 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,29/*R0 iSampleSet*/,29/*R1 iSampleSet*/) //  chan0,1 iSampleSet29,29
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -576,1/*oSample*/,28/*tapset*/)  //  oSample1 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -576,2/*oSample*/,28/*tapset*/)  //  oSample2 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -576,6/*oSample*/,28/*tapset*/)  //  oSample6 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -576,7/*oSample*/,28/*tapset*/)  //  oSample7 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -576,11/*oSample*/,28/*tapset*/)  //  oSample11 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -560,3/*oSample*/,29/*tapset*/)  //  oSample3 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch1  ISampleSet28 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,30/*R0 iSampleSet*/,30/*R1 iSampleSet*/) //  chan0,1 iSampleSet30,30
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -560,4/*oSample*/,29/*tapset*/)  //  oSample4 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -560,5/*oSample*/,29/*tapset*/)  //  oSample5 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -560,8/*oSample*/,29/*tapset*/)  //  oSample8 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -560,9/*oSample*/,29/*tapset*/)  //  oSample9 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -560,10/*oSample*/,29/*tapset*/)  //  oSample10 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -544,0/*oSample*/,30/*tapset*/)  //  oSample0 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch1  ISampleSet29 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,31/*R0 iSampleSet*/,31/*R1 iSampleSet*/) //  chan0,1 iSampleSet31,31
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -544,1/*oSample*/,30/*tapset*/)  //  oSample1 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -544,2/*oSample*/,30/*tapset*/)  //  oSample2 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -544,6/*oSample*/,30/*tapset*/)  //  oSample6 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -544,7/*oSample*/,30/*tapset*/)  //  oSample7 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -544,11/*oSample*/,30/*tapset*/)  //  oSample11 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -528,3/*oSample*/,31/*tapset*/)  //  oSample3 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch1  ISampleSet30 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,32/*R0 iSampleSet*/,32/*R1 iSampleSet*/) //  chan0,1 iSampleSet32,32
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -528,4/*oSample*/,31/*tapset*/)  //  oSample4 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -528,5/*oSample*/,31/*tapset*/)  //  oSample5 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -528,8/*oSample*/,31/*tapset*/)  //  oSample8 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -528,9/*oSample*/,31/*tapset*/)  //  oSample9 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -528,10/*oSample*/,31/*tapset*/)  //  oSample10 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -512,0/*oSample*/,32/*tapset*/)  //  oSample0 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch1  ISampleSet31 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,33/*R0 iSampleSet*/,33/*R1 iSampleSet*/) //  chan0,1 iSampleSet33,33
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -512,1/*oSample*/,32/*tapset*/)  //  oSample1 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -512,2/*oSample*/,32/*tapset*/)  //  oSample2 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -512,6/*oSample*/,32/*tapset*/)  //  oSample6 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -512,7/*oSample*/,32/*tapset*/)  //  oSample7 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -512,11/*oSample*/,32/*tapset*/)  //  oSample11 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -496,3/*oSample*/,33/*tapset*/)  //  oSample3 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch1  ISampleSet32 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,34/*R0 iSampleSet*/,34/*R1 iSampleSet*/) //  chan0,1 iSampleSet34,34
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -496,4/*oSample*/,33/*tapset*/)  //  oSample4 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -496,5/*oSample*/,33/*tapset*/)  //  oSample5 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -496,8/*oSample*/,33/*tapset*/)  //  oSample8 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -496,9/*oSample*/,33/*tapset*/)  //  oSample9 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -496,10/*oSample*/,33/*tapset*/)  //  oSample10 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample00FitlerP, -480,0/*oSample*/,34/*tapset*/)  //  oSample0 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch1  ISampleSet33 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,35/*R0 iSampleSet*/,35/*R1 iSampleSet*/) //  chan0,1 iSampleSet35,35
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, -480,1/*oSample*/,34/*tapset*/)  //  oSample1 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,0/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,0/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, -480,2/*oSample*/,34/*tapset*/)  //  oSample2 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -480,6/*oSample*/,34/*tapset*/)  //  oSample6 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -480,7/*oSample*/,34/*tapset*/)  //  oSample7 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -480,11/*oSample*/,34/*tapset*/)  //  oSample11 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, -464,3/*oSample*/,35/*tapset*/)  //  oSample3 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch1  ISampleSet34 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,36/*R0 iSampleSet*/,36/*R1 iSampleSet*/) //  chan0,1 iSampleSet36,36
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, -464,4/*oSample*/,35/*tapset*/)  //  oSample4 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, -464,5/*oSample*/,35/*tapset*/)  //  oSample5 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, -464,8/*oSample*/,35/*tapset*/)  //  oSample8 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -464,9/*oSample*/,35/*tapset*/)  //  oSample9 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -464,10/*oSample*/,35/*tapset*/)  //  oSample10 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, -448,1/*oSample*/,36/*tapset*/)  //  oSample1 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch1  ISampleSet35 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,37/*R0 iSampleSet*/,37/*R1 iSampleSet*/) //  chan0,1 iSampleSet37,37
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, -448,2/*oSample*/,36/*tapset*/)  //  oSample2 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, -448,6/*oSample*/,36/*tapset*/)  //  oSample6 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, -448,7/*oSample*/,36/*tapset*/)  //  oSample7 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -448,11/*oSample*/,36/*tapset*/)  //  oSample11 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,7/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,7/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, -432,3/*oSample*/,37/*tapset*/)  //  oSample3 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch1  ISampleSet36 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,38/*R0 iSampleSet*/,38/*R1 iSampleSet*/) //  chan0,1 iSampleSet38,38
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, -432,4/*oSample*/,37/*tapset*/)  //  oSample4 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,3/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, -432,5/*oSample*/,37/*tapset*/)  //  oSample5 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,4/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, -432,8/*oSample*/,37/*tapset*/)  //  oSample8 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, -432,9/*oSample*/,37/*tapset*/)  //  oSample9 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, -432,10/*oSample*/,37/*tapset*/)  //  oSample10 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, -416,6/*oSample*/,38/*tapset*/)  //  oSample6 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch1  ISampleSet37 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,39/*R0 iSampleSet*/,39/*R1 iSampleSet*/) //  chan0,1 iSampleSet39,39
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, -416,7/*oSample*/,38/*tapset*/)  //  oSample7 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample11FitlerP, -416,11/*oSample*/,38/*tapset*/)  //  oSample11 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, -400,9/*oSample*/,39/*tapset*/)  //  oSample9 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,11/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch1  ISampleSet38 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,40/*R0 iSampleSet*/,40/*R1 iSampleSet*/) //  chan0,1 iSampleSet40,40
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,11/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, -400,10/*oSample*/,39/*tapset*/)  //  oSample10 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_temporal( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, -384,11/*oSample*/,40/*tapset*/)  //  oSample11 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch1  ISampleSet40 
        add_two_halfs_of_accumulator(oSample00AccumCh0,0/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample00AccumCh0,0/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample00AccumCh0,0/*offset in R*/,0/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample00AccumCh1,0/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample00AccumCh1,0/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample00AccumCh1,1/*offset in R*/,0/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample01AccumCh0,1/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample01AccumCh0,1/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample01AccumCh0,2/*offset in R*/,1/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample01AccumCh1,1/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample01AccumCh1,1/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample01AccumCh1,3/*offset in R*/,1/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample02AccumCh0,2/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample02AccumCh0,2/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample02AccumCh0,0/*offset in R*/,2/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample02AccumCh1,2/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample02AccumCh1,2/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample02AccumCh1,1/*offset in R*/,2/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample03AccumCh0,3/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample03AccumCh0,3/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample03AccumCh0,2/*offset in R*/,3/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample03AccumCh1,3/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample03AccumCh1,3/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample03AccumCh1,3/*offset in R*/,3/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G0_Ch0,iSampleSet_G0_Ch1,outputSampleQueueP,0)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        add_two_halfs_of_accumulator(oSample04AccumCh0,4/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample04AccumCh0,4/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch0,oSample04AccumCh0,0/*offset in R*/,4/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample04AccumCh1,4/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample04AccumCh1,4/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch0,oSample04AccumCh1,1/*offset in R*/,4/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample05AccumCh0,5/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample05AccumCh0,5/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch0,oSample05AccumCh0,2/*offset in R*/,5/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample05AccumCh1,5/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample05AccumCh1,5/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch0,oSample05AccumCh1,3/*offset in R*/,5/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample06AccumCh0,6/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample06AccumCh0,6/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch1,oSample06AccumCh0,0/*offset in R*/,6/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample06AccumCh1,6/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample06AccumCh1,6/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch1,oSample06AccumCh1,1/*offset in R*/,6/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample07AccumCh0,7/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample07AccumCh0,7/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch1,oSample07AccumCh0,2/*offset in R*/,7/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample07AccumCh1,7/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample07AccumCh1,7/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G1_Ch1,oSample07AccumCh1,3/*offset in R*/,7/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G1_Ch0,iSampleSet_G1_Ch1,outputSampleQueueP,32)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        add_two_halfs_of_accumulator(oSample08AccumCh0,8/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample08AccumCh0,8/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample08AccumCh0,0/*offset in R*/,8/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample08AccumCh1,8/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample08AccumCh1,8/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample08AccumCh1,1/*offset in R*/,8/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample09AccumCh0,9/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample09AccumCh0,9/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample09AccumCh0,2/*offset in R*/,9/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample09AccumCh1,9/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample09AccumCh1,9/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch0,oSample09AccumCh1,3/*offset in R*/,9/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample10AccumCh0,10/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample10AccumCh0,10/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample10AccumCh0,0/*offset in R*/,10/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample10AccumCh1,10/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample10AccumCh1,10/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample10AccumCh1,1/*offset in R*/,10/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample11AccumCh0,11/*oSample*/,0/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample11AccumCh0,11/*oSample*/,0/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample11AccumCh0,2/*offset in R*/,11/*oSample*/,0/*chan*/)  //  transfer accumulator to iSample output register 
        add_two_halfs_of_accumulator(oSample11AccumCh1,11/*oSample*/,1/*chan*/)  //add accumulated two parts of accumulator 
        normalize_accumulator_to_32b(oSample11AccumCh1,11/*oSample*/,1/*chan*/)  // mormalize 64b acc to 32b 
        transfer_accumulator_to_sample_register(iSampleSet_G0_Ch1,oSample11AccumCh1,3/*offset in R*/,11/*oSample*/,1/*chan*/)  //  transfer accumulator to iSample output register 
        store_8_samples(iSampleSet_G0_Ch0,iSampleSet_G0_Ch1,outputSampleQueueP,64)  // write register pair to output buffer 
        mask_pointer(outputSampleQueueP,outputSampleQueueP,outputSampleQueuePMask)    // wrap iSampleSet pointer queue
        put_char(:)
        asm_vector_usage_output(oSample00AccumCh0)put_char(,)
        asm_vector_usage_output(oSample00AccumCh1)put_char(,)
        asm_vector_usage_output(oSample01AccumCh0)put_char(,)
        asm_vector_usage_output(oSample01AccumCh1)put_char(,)
        asm_vector_usage_output(oSample02AccumCh0)put_char(,)
        asm_vector_usage_output(oSample02AccumCh1)put_char(,)
        asm_vector_usage_output(oSample03AccumCh0)put_char(,)
        asm_vector_usage_output(oSample03AccumCh1)put_char(,)
        asm_vector_usage_output(oSample04AccumCh0)put_char(,)
        asm_vector_usage_output(oSample04AccumCh1)put_char(,)
        asm_vector_usage_output(oSample05AccumCh0)put_char(,)
        asm_vector_usage_output(oSample05AccumCh1)put_char(,)
        asm_vector_usage_output(oSample06AccumCh0)put_char(,)
        asm_vector_usage_output(oSample06AccumCh1)put_char(,)
        asm_vector_usage_output(oSample07AccumCh0)put_char(,)
        asm_vector_usage_output(oSample07AccumCh1)put_char(,)
        asm_vector_usage_output(oSample08AccumCh0)put_char(,)
        asm_vector_usage_output(oSample08AccumCh1)put_char(,)
        asm_vector_usage_output(oSample09AccumCh0)put_char(,)
        asm_vector_usage_output(oSample09AccumCh1)put_char(,)
        asm_vector_usage_output(oSample10AccumCh0)put_char(,)
        asm_vector_usage_output(oSample10AccumCh1)put_char(,)
        asm_vector_usage_output(oSample11AccumCh0)put_char(,)
        asm_vector_usage_output(oSample11AccumCh1)put_char(,)
        asm_vector_usage_output(tapSet_G0_M0)put_char(,)
        asm_vector_usage_output(tapSet_G0_M1)put_char(,)
        asm_vector_usage_output(tapSet_G1_M0)put_char(,)
        asm_vector_usage_output(tapSet_G1_M1)put_char(,)
        asm_vector_usage_output(iSampleSet_G0_Ch0)put_char(,)
        asm_vector_usage_output(iSampleSet_G0_Ch1)put_char(,)
        asm_vector_usage_output(iSampleSet_G1_Ch0)put_char(,)
        asm_vector_usage_output(iSampleSet_G1_Ch1)put_char(,)
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
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo)
{
     return SsrcSampleRateConverter_insr_3_outsr_2_taps_144_stereo_SsrcSampleFormat_int32::construct(*returnedInfo);
}
