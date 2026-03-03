/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcsamplerateconverter_insr_4_outsr_1_taps_336_stereo_ssrcsampleformat_int32.h"
/********************************************************************************
*  iSample rate converter input iSample rate 4 output iSample rate 1 stereo
*
*******************************************************************************/
/********************************************************************************
*  
*
*******************************************************************************/
SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32::SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32()
{
}
/********************************************************************************
*  iSample processing
*
*******************************************************************************/
bool SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32::process()
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
    filter.phaseZero(oSample00FitlerP); // oSample pointer 0
    filter.phaseZero(oSample01FitlerP); // oSample pointer 1
    filter.phaseZero(oSample02FitlerP); // oSample pointer 2
    filter.phaseZero(oSample03FitlerP); // oSample pointer 3
    filter.phaseZero(oSample04FitlerP); // oSample pointer 4
    filter.phaseZero(oSample05FitlerP); // oSample pointer 5
    filter.phaseZero(oSample06FitlerP); // oSample pointer 6
    filter.phaseZero(oSample07FitlerP); // oSample pointer 7
    filter.phaseZero(oSample08FitlerP); // oSample pointer 8
    filter.phaseZero(oSample09FitlerP); // oSample pointer 9
    filter.phaseZero(oSample10FitlerP); // oSample pointer 10
    filter.phaseZero(oSample11FitlerP); // oSample pointer 11
    offsetP = 4 * 12;   // increment input iSample offset
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
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 0,0/*oSample*/,0/*tapset*/)  //  oSample0 tapSet0,1 iSampleSet0,1
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, 16,1/*oSample*/,1/*tapset*/)  //  oSample1 tapSet1,2 iSampleSet1,2
        clear_accumulator(oSample00AccumCh0,0/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch0  ISampleSet0 
        clear_accumulator(oSample00AccumCh1,0/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch1  ISampleSet0 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,0/*tapsSet*/,0/*sampleSet*/)  // oSample0 tapSet0 Ch1  ISampleSet0 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,2/*R0 iSampleSet*/,2/*R1 iSampleSet*/) //  chan0,1 iSampleSet2,2
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample0 tapSet1 Ch1  ISampleSet1 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 32,0/*oSample*/,2/*tapset*/)  //  oSample0 tapSet2,3 iSampleSet2,3
        clear_accumulator(oSample01AccumCh0,1/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch0  ISampleSet1 
        clear_accumulator(oSample01AccumCh1,1/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch1  ISampleSet1 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,1/*tapsSet*/,1/*sampleSet*/)  // oSample1 tapSet1 Ch1  ISampleSet1 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,3/*R0 iSampleSet*/,3/*R1 iSampleSet*/) //  chan0,1 iSampleSet3,3
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample1 tapSet2 Ch1  ISampleSet2 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 32,2/*oSample*/,2/*tapset*/)  //  oSample2 tapSet2,3 iSampleSet2,3
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample0 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample0 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 48,1/*oSample*/,3/*tapset*/)  //  oSample1 tapSet3,4 iSampleSet3,4
        clear_accumulator(oSample02AccumCh0,2/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch0  ISampleSet2 
        clear_accumulator(oSample02AccumCh1,2/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch1  ISampleSet2 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,2/*tapsSet*/,2/*sampleSet*/)  // oSample2 tapSet2 Ch1  ISampleSet2 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,4/*R0 iSampleSet*/,4/*R1 iSampleSet*/) //  chan0,1 iSampleSet4,4
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample2 tapSet3 Ch1  ISampleSet3 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 48,3/*oSample*/,3/*tapset*/)  //  oSample3 tapSet3,4 iSampleSet3,4
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample1 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample1 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 64,0/*oSample*/,4/*tapset*/)  //  oSample0 tapSet4,5 iSampleSet4,5
        clear_accumulator(oSample03AccumCh0,3/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch0  ISampleSet3 
        clear_accumulator(oSample03AccumCh1,3/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch1  ISampleSet3 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,3/*tapsSet*/,3/*sampleSet*/)  // oSample3 tapSet3 Ch1  ISampleSet3 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,5/*R0 iSampleSet*/,5/*R1 iSampleSet*/) //  chan0,1 iSampleSet5,5
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample3 tapSet4 Ch1  ISampleSet4 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 64,2/*oSample*/,4/*tapset*/)  //  oSample2 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample0 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample0 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 64,4/*oSample*/,4/*tapset*/)  //  oSample4 tapSet4,5 iSampleSet4,5
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample2 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample2 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, 80,1/*oSample*/,5/*tapset*/)  //  oSample1 tapSet5,6 iSampleSet5,6
        clear_accumulator(oSample04AccumCh0,4/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch0  ISampleSet4 
        clear_accumulator(oSample04AccumCh1,4/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch1  ISampleSet4 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,4/*tapsSet*/,4/*sampleSet*/)  // oSample4 tapSet4 Ch1  ISampleSet4 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,6/*R0 iSampleSet*/,6/*R1 iSampleSet*/) //  chan0,1 iSampleSet6,6
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample4 tapSet5 Ch1  ISampleSet5 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, 80,3/*oSample*/,5/*tapset*/)  //  oSample3 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample1 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample1 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 80,5/*oSample*/,5/*tapset*/)  //  oSample5 tapSet5,6 iSampleSet5,6
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,3/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,3/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample3 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,3/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,3/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample3 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 96,0/*oSample*/,6/*tapset*/)  //  oSample0 tapSet6,7 iSampleSet6,7
        clear_accumulator(oSample05AccumCh0,5/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch0  ISampleSet5 
        clear_accumulator(oSample05AccumCh1,5/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch1  ISampleSet5 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,5/*tapsSet*/,5/*sampleSet*/)  // oSample5 tapSet5 Ch1  ISampleSet5 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,7/*R0 iSampleSet*/,7/*R1 iSampleSet*/) //  chan0,1 iSampleSet7,7
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample5 tapSet6 Ch1  ISampleSet6 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 96,2/*oSample*/,6/*tapset*/)  //  oSample2 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample0 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample0 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 96,4/*oSample*/,6/*tapset*/)  //  oSample4 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample2 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample2 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 96,6/*oSample*/,6/*tapset*/)  //  oSample6 tapSet6,7 iSampleSet6,7
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample4 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample4 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 112,1/*oSample*/,7/*tapset*/)  //  oSample1 tapSet7,8 iSampleSet7,8
        clear_accumulator(oSample06AccumCh0,6/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch0  ISampleSet6 
        clear_accumulator(oSample06AccumCh1,6/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch1  ISampleSet6 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,6/*tapsSet*/,6/*sampleSet*/)  // oSample6 tapSet6 Ch1  ISampleSet6 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,8/*R0 iSampleSet*/,8/*R1 iSampleSet*/) //  chan0,1 iSampleSet8,8
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample6 tapSet7 Ch1  ISampleSet7 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 112,3/*oSample*/,7/*tapset*/)  //  oSample3 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample1 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample1 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 112,5/*oSample*/,7/*tapset*/)  //  oSample5 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample3 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample3 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 112,7/*oSample*/,7/*tapset*/)  //  oSample7 tapSet7,8 iSampleSet7,8
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample5 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample5 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 128,0/*oSample*/,8/*tapset*/)  //  oSample0 tapSet8,9 iSampleSet8,9
        clear_accumulator(oSample07AccumCh0,7/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch0  ISampleSet7 
        clear_accumulator(oSample07AccumCh1,7/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch1  ISampleSet7 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,7/*tapsSet*/,7/*sampleSet*/)  // oSample7 tapSet7 Ch1  ISampleSet7 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,9/*R0 iSampleSet*/,9/*R1 iSampleSet*/) //  chan0,1 iSampleSet9,9
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample7 tapSet8 Ch1  ISampleSet8 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 128,2/*oSample*/,8/*tapset*/)  //  oSample2 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample0 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample0 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 128,4/*oSample*/,8/*tapset*/)  //  oSample4 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample2 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample2 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 128,6/*oSample*/,8/*tapset*/)  //  oSample6 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample4 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample4 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 128,8/*oSample*/,8/*tapset*/)  //  oSample8 tapSet8,9 iSampleSet8,9
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample6 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample6 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample01FitlerP, 144,1/*oSample*/,9/*tapset*/)  //  oSample1 tapSet9,10 iSampleSet9,10
        clear_accumulator(oSample08AccumCh0,8/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch0  ISampleSet8 
        clear_accumulator(oSample08AccumCh1,8/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch1  ISampleSet8 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,8/*tapsSet*/,8/*sampleSet*/)  // oSample8 tapSet8 Ch1  ISampleSet8 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,10/*R0 iSampleSet*/,10/*R1 iSampleSet*/) //  chan0,1 iSampleSet10,10
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample8 tapSet9 Ch1  ISampleSet9 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample03FitlerP, 144,3/*oSample*/,9/*tapset*/)  //  oSample3 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,1/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,1/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample1 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,1/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,1/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample1 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample05FitlerP, 144,5/*oSample*/,9/*tapset*/)  //  oSample5 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,3/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,3/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,3/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample3 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,3/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,3/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,3/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample3 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample07FitlerP, 144,7/*oSample*/,9/*tapset*/)  //  oSample7 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,5/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,5/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample5 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,5/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,5/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample5 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample09FitlerP, 144,9/*oSample*/,9/*tapset*/)  //  oSample9 tapSet9,10 iSampleSet9,10
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,7/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,7/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,7/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample7 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,7/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,7/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample7 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 160,0/*oSample*/,10/*tapset*/)  //  oSample0 tapSet10,11 iSampleSet10,11
        clear_accumulator(oSample09AccumCh0,9/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,9/*oSample*/,0/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch0  ISampleSet9 
        clear_accumulator(oSample09AccumCh1,9/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch1  ISampleSet9 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,9/*oSample*/,1/*chan*/,9/*tapsSet*/,9/*sampleSet*/)  // oSample9 tapSet9 Ch1  ISampleSet9 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,11/*R0 iSampleSet*/,11/*R1 iSampleSet*/) //  chan0,1 iSampleSet11,11
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,9/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,9/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample9 tapSet10 Ch1  ISampleSet10 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 160,2/*oSample*/,10/*tapset*/)  //  oSample2 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample0 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample0 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 160,4/*oSample*/,10/*tapset*/)  //  oSample4 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample2 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample2 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 160,6/*oSample*/,10/*tapset*/)  //  oSample6 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample4 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample4 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 160,8/*oSample*/,10/*tapset*/)  //  oSample8 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample6 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample6 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 160,10/*oSample*/,10/*tapset*/)  //  oSample10 tapSet10,11 iSampleSet10,11
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample8 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample8 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 176,1/*oSample*/,11/*tapset*/)  //  oSample1 tapSet11,12 iSampleSet11,12
        clear_accumulator(oSample10AccumCh0,10/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch0  ISampleSet10 
        clear_accumulator(oSample10AccumCh1,10/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch1  ISampleSet10 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,10/*tapsSet*/,10/*sampleSet*/)  // oSample10 tapSet10 Ch1  ISampleSet10 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,12/*R0 iSampleSet*/,12/*R1 iSampleSet*/) //  chan0,1 iSampleSet12,12
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample10 tapSet11 Ch1  ISampleSet11 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 176,3/*oSample*/,11/*tapset*/)  //  oSample3 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample1 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample1 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 176,5/*oSample*/,11/*tapset*/)  //  oSample5 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample3 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample3 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 176,7/*oSample*/,11/*tapset*/)  //  oSample7 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample5 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample5 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 176,9/*oSample*/,11/*tapset*/)  //  oSample9 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample7 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample7 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 176,11/*oSample*/,11/*tapset*/)  //  oSample11 tapSet11,12 iSampleSet11,12
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample9 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample9 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 192,0/*oSample*/,12/*tapset*/)  //  oSample0 tapSet12,13 iSampleSet12,13
        clear_accumulator(oSample11AccumCh0,11/*oSample*/,0/*chan*/)
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch0  ISampleSet11 
        clear_accumulator(oSample11AccumCh1,11/*oSample*/,1/*chan*/)
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch1  ISampleSet11 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,11/*tapsSet*/,11/*sampleSet*/)  // oSample11 tapSet11 Ch1  ISampleSet11 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,13/*R0 iSampleSet*/,13/*R1 iSampleSet*/) //  chan0,1 iSampleSet13,13
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample11 tapSet12 Ch1  ISampleSet12 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 192,2/*oSample*/,12/*tapset*/)  //  oSample2 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample0 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample0 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 192,4/*oSample*/,12/*tapset*/)  //  oSample4 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample2 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample2 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 192,6/*oSample*/,12/*tapset*/)  //  oSample6 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample4 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample4 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 192,8/*oSample*/,12/*tapset*/)  //  oSample8 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample6 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample6 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 192,10/*oSample*/,12/*tapset*/)  //  oSample10 tapSet12,13 iSampleSet12,13
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample8 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample8 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 208,1/*oSample*/,13/*tapset*/)  //  oSample1 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch0  ISampleSet12 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch1  ISampleSet12 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,12/*tapsSet*/,12/*sampleSet*/)  // oSample10 tapSet12 Ch1  ISampleSet12 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,14/*R0 iSampleSet*/,14/*R1 iSampleSet*/) //  chan0,1 iSampleSet14,14
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample10 tapSet13 Ch1  ISampleSet13 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 208,3/*oSample*/,13/*tapset*/)  //  oSample3 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample1 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample1 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 208,5/*oSample*/,13/*tapset*/)  //  oSample5 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample3 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample3 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 208,7/*oSample*/,13/*tapset*/)  //  oSample7 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample5 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample5 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 208,9/*oSample*/,13/*tapset*/)  //  oSample9 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample7 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample7 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 208,11/*oSample*/,13/*tapset*/)  //  oSample11 tapSet13,14 iSampleSet13,14
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample9 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample9 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 224,0/*oSample*/,14/*tapset*/)  //  oSample0 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch0  ISampleSet13 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch1  ISampleSet13 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,13/*tapsSet*/,13/*sampleSet*/)  // oSample11 tapSet13 Ch1  ISampleSet13 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,15/*R0 iSampleSet*/,15/*R1 iSampleSet*/) //  chan0,1 iSampleSet15,15
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample11 tapSet14 Ch1  ISampleSet14 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 224,2/*oSample*/,14/*tapset*/)  //  oSample2 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample0 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample0 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 224,4/*oSample*/,14/*tapset*/)  //  oSample4 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample2 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample2 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 224,6/*oSample*/,14/*tapset*/)  //  oSample6 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample4 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample4 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 224,8/*oSample*/,14/*tapset*/)  //  oSample8 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample6 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample6 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 224,10/*oSample*/,14/*tapset*/)  //  oSample10 tapSet14,15 iSampleSet14,15
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample8 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample8 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 240,1/*oSample*/,15/*tapset*/)  //  oSample1 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch0  ISampleSet14 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch1  ISampleSet14 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,14/*tapsSet*/,14/*sampleSet*/)  // oSample10 tapSet14 Ch1  ISampleSet14 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,16/*R0 iSampleSet*/,16/*R1 iSampleSet*/) //  chan0,1 iSampleSet16,16
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample10 tapSet15 Ch1  ISampleSet15 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 240,3/*oSample*/,15/*tapset*/)  //  oSample3 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample1 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample1 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 240,5/*oSample*/,15/*tapset*/)  //  oSample5 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample3 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample3 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 240,7/*oSample*/,15/*tapset*/)  //  oSample7 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample5 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample5 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 240,9/*oSample*/,15/*tapset*/)  //  oSample9 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample7 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample7 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 240,11/*oSample*/,15/*tapset*/)  //  oSample11 tapSet15,16 iSampleSet15,16
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample9 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample9 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 256,0/*oSample*/,16/*tapset*/)  //  oSample0 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch0  ISampleSet15 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch1  ISampleSet15 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,15/*tapsSet*/,15/*sampleSet*/)  // oSample11 tapSet15 Ch1  ISampleSet15 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,17/*R0 iSampleSet*/,17/*R1 iSampleSet*/) //  chan0,1 iSampleSet17,17
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample11 tapSet16 Ch1  ISampleSet16 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 256,2/*oSample*/,16/*tapset*/)  //  oSample2 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample0 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample0 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 256,4/*oSample*/,16/*tapset*/)  //  oSample4 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample2 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample2 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 256,6/*oSample*/,16/*tapset*/)  //  oSample6 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample4 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample4 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 256,8/*oSample*/,16/*tapset*/)  //  oSample8 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample6 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample6 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 256,10/*oSample*/,16/*tapset*/)  //  oSample10 tapSet16,17 iSampleSet16,17
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample8 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample8 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 272,1/*oSample*/,17/*tapset*/)  //  oSample1 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch0  ISampleSet16 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch1  ISampleSet16 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,16/*tapsSet*/,16/*sampleSet*/)  // oSample10 tapSet16 Ch1  ISampleSet16 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,18/*R0 iSampleSet*/,18/*R1 iSampleSet*/) //  chan0,1 iSampleSet18,18
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample10 tapSet17 Ch1  ISampleSet17 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 272,3/*oSample*/,17/*tapset*/)  //  oSample3 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample1 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample1 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 272,5/*oSample*/,17/*tapset*/)  //  oSample5 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample3 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample3 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 272,7/*oSample*/,17/*tapset*/)  //  oSample7 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample5 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample5 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 272,9/*oSample*/,17/*tapset*/)  //  oSample9 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample7 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample7 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 272,11/*oSample*/,17/*tapset*/)  //  oSample11 tapSet17,18 iSampleSet17,18
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample9 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample9 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 288,0/*oSample*/,18/*tapset*/)  //  oSample0 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch0  ISampleSet17 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch1  ISampleSet17 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,17/*tapsSet*/,17/*sampleSet*/)  // oSample11 tapSet17 Ch1  ISampleSet17 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,19/*R0 iSampleSet*/,19/*R1 iSampleSet*/) //  chan0,1 iSampleSet19,19
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample11 tapSet18 Ch1  ISampleSet18 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 288,2/*oSample*/,18/*tapset*/)  //  oSample2 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample0 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample0 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 288,4/*oSample*/,18/*tapset*/)  //  oSample4 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample2 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample2 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 288,6/*oSample*/,18/*tapset*/)  //  oSample6 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample4 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample4 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 288,8/*oSample*/,18/*tapset*/)  //  oSample8 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample6 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample6 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 288,10/*oSample*/,18/*tapset*/)  //  oSample10 tapSet18,19 iSampleSet18,19
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample8 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample8 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 304,1/*oSample*/,19/*tapset*/)  //  oSample1 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch0  ISampleSet18 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch1  ISampleSet18 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,18/*tapsSet*/,18/*sampleSet*/)  // oSample10 tapSet18 Ch1  ISampleSet18 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,20/*R0 iSampleSet*/,20/*R1 iSampleSet*/) //  chan0,1 iSampleSet20,20
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample10 tapSet19 Ch1  ISampleSet19 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 304,3/*oSample*/,19/*tapset*/)  //  oSample3 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample1 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample1 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 304,5/*oSample*/,19/*tapset*/)  //  oSample5 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample3 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample3 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 304,7/*oSample*/,19/*tapset*/)  //  oSample7 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample5 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample5 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 304,9/*oSample*/,19/*tapset*/)  //  oSample9 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample7 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample7 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 304,11/*oSample*/,19/*tapset*/)  //  oSample11 tapSet19,20 iSampleSet19,20
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample9 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample9 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 320,0/*oSample*/,20/*tapset*/)  //  oSample0 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch0  ISampleSet19 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch1  ISampleSet19 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,19/*tapsSet*/,19/*sampleSet*/)  // oSample11 tapSet19 Ch1  ISampleSet19 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,21/*R0 iSampleSet*/,21/*R1 iSampleSet*/) //  chan0,1 iSampleSet21,21
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample11 tapSet20 Ch1  ISampleSet20 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 320,2/*oSample*/,20/*tapset*/)  //  oSample2 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample0 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample0 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 320,4/*oSample*/,20/*tapset*/)  //  oSample4 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample2 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample2 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 320,6/*oSample*/,20/*tapset*/)  //  oSample6 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample4 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample4 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 320,8/*oSample*/,20/*tapset*/)  //  oSample8 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample6 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample6 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 320,10/*oSample*/,20/*tapset*/)  //  oSample10 tapSet20,21 iSampleSet20,21
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample8 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample8 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 336,1/*oSample*/,21/*tapset*/)  //  oSample1 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch0  ISampleSet20 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch1  ISampleSet20 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,20/*tapsSet*/,20/*sampleSet*/)  // oSample10 tapSet20 Ch1  ISampleSet20 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,22/*R0 iSampleSet*/,22/*R1 iSampleSet*/) //  chan0,1 iSampleSet22,22
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample10 tapSet21 Ch1  ISampleSet21 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 336,3/*oSample*/,21/*tapset*/)  //  oSample3 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample1 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample1 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 336,5/*oSample*/,21/*tapset*/)  //  oSample5 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample3 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample3 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 336,7/*oSample*/,21/*tapset*/)  //  oSample7 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample5 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample5 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 336,9/*oSample*/,21/*tapset*/)  //  oSample9 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample7 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample7 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 336,11/*oSample*/,21/*tapset*/)  //  oSample11 tapSet21,22 iSampleSet21,22
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample9 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample9 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 352,0/*oSample*/,22/*tapset*/)  //  oSample0 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch0  ISampleSet21 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch1  ISampleSet21 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,21/*tapsSet*/,21/*sampleSet*/)  // oSample11 tapSet21 Ch1  ISampleSet21 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,23/*R0 iSampleSet*/,23/*R1 iSampleSet*/) //  chan0,1 iSampleSet23,23
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample11 tapSet22 Ch1  ISampleSet22 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 352,2/*oSample*/,22/*tapset*/)  //  oSample2 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample0 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample0 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 352,4/*oSample*/,22/*tapset*/)  //  oSample4 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample2 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample2 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 352,6/*oSample*/,22/*tapset*/)  //  oSample6 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample4 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample4 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 352,8/*oSample*/,22/*tapset*/)  //  oSample8 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample6 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample6 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 352,10/*oSample*/,22/*tapset*/)  //  oSample10 tapSet22,23 iSampleSet22,23
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample8 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample8 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 368,1/*oSample*/,23/*tapset*/)  //  oSample1 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch0  ISampleSet22 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch1  ISampleSet22 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,22/*tapsSet*/,22/*sampleSet*/)  // oSample10 tapSet22 Ch1  ISampleSet22 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,24/*R0 iSampleSet*/,24/*R1 iSampleSet*/) //  chan0,1 iSampleSet24,24
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample10 tapSet23 Ch1  ISampleSet23 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 368,3/*oSample*/,23/*tapset*/)  //  oSample3 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample1 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample1 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 368,5/*oSample*/,23/*tapset*/)  //  oSample5 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample3 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample3 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 368,7/*oSample*/,23/*tapset*/)  //  oSample7 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample5 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample5 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 368,9/*oSample*/,23/*tapset*/)  //  oSample9 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample7 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample7 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 368,11/*oSample*/,23/*tapset*/)  //  oSample11 tapSet23,24 iSampleSet23,24
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample9 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample9 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 384,0/*oSample*/,24/*tapset*/)  //  oSample0 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch0  ISampleSet23 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch1  ISampleSet23 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,23/*tapsSet*/,23/*sampleSet*/)  // oSample11 tapSet23 Ch1  ISampleSet23 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,25/*R0 iSampleSet*/,25/*R1 iSampleSet*/) //  chan0,1 iSampleSet25,25
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample11 tapSet24 Ch1  ISampleSet24 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 384,2/*oSample*/,24/*tapset*/)  //  oSample2 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample0 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample0 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 384,4/*oSample*/,24/*tapset*/)  //  oSample4 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample2 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample2 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 384,6/*oSample*/,24/*tapset*/)  //  oSample6 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample4 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample4 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 384,8/*oSample*/,24/*tapset*/)  //  oSample8 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample6 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample6 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 384,10/*oSample*/,24/*tapset*/)  //  oSample10 tapSet24,25 iSampleSet24,25
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample8 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample8 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 400,1/*oSample*/,25/*tapset*/)  //  oSample1 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch0  ISampleSet24 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch1  ISampleSet24 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,24/*tapsSet*/,24/*sampleSet*/)  // oSample10 tapSet24 Ch1  ISampleSet24 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,26/*R0 iSampleSet*/,26/*R1 iSampleSet*/) //  chan0,1 iSampleSet26,26
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample10 tapSet25 Ch1  ISampleSet25 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 400,3/*oSample*/,25/*tapset*/)  //  oSample3 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample1 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample1 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 400,5/*oSample*/,25/*tapset*/)  //  oSample5 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample3 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample3 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 400,7/*oSample*/,25/*tapset*/)  //  oSample7 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample5 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample5 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 400,9/*oSample*/,25/*tapset*/)  //  oSample9 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample7 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample7 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 400,11/*oSample*/,25/*tapset*/)  //  oSample11 tapSet25,26 iSampleSet25,26
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample9 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample9 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 416,0/*oSample*/,26/*tapset*/)  //  oSample0 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch0  ISampleSet25 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch1  ISampleSet25 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,25/*tapsSet*/,25/*sampleSet*/)  // oSample11 tapSet25 Ch1  ISampleSet25 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,27/*R0 iSampleSet*/,27/*R1 iSampleSet*/) //  chan0,1 iSampleSet27,27
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample11 tapSet26 Ch1  ISampleSet26 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 416,2/*oSample*/,26/*tapset*/)  //  oSample2 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample0 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample0 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 416,4/*oSample*/,26/*tapset*/)  //  oSample4 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample2 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample2 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 416,6/*oSample*/,26/*tapset*/)  //  oSample6 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample4 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample4 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 416,8/*oSample*/,26/*tapset*/)  //  oSample8 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample6 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample6 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 416,10/*oSample*/,26/*tapset*/)  //  oSample10 tapSet26,27 iSampleSet26,27
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample8 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample8 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 432,1/*oSample*/,27/*tapset*/)  //  oSample1 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch0  ISampleSet26 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch1  ISampleSet26 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,26/*tapsSet*/,26/*sampleSet*/)  // oSample10 tapSet26 Ch1  ISampleSet26 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,28/*R0 iSampleSet*/,28/*R1 iSampleSet*/) //  chan0,1 iSampleSet28,28
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample10 tapSet27 Ch1  ISampleSet27 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 432,3/*oSample*/,27/*tapset*/)  //  oSample3 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample1 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample1 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 432,5/*oSample*/,27/*tapset*/)  //  oSample5 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample3 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample3 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 432,7/*oSample*/,27/*tapset*/)  //  oSample7 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample5 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample5 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 432,9/*oSample*/,27/*tapset*/)  //  oSample9 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample7 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample7 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 432,11/*oSample*/,27/*tapset*/)  //  oSample11 tapSet27,28 iSampleSet27,28
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample9 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample9 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 448,0/*oSample*/,28/*tapset*/)  //  oSample0 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch0  ISampleSet27 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch1  ISampleSet27 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,27/*tapsSet*/,27/*sampleSet*/)  // oSample11 tapSet27 Ch1  ISampleSet27 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,29/*R0 iSampleSet*/,29/*R1 iSampleSet*/) //  chan0,1 iSampleSet29,29
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample11 tapSet28 Ch1  ISampleSet28 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 448,2/*oSample*/,28/*tapset*/)  //  oSample2 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample0 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample0 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 448,4/*oSample*/,28/*tapset*/)  //  oSample4 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample2 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample2 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 448,6/*oSample*/,28/*tapset*/)  //  oSample6 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample4 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample4 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 448,8/*oSample*/,28/*tapset*/)  //  oSample8 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample6 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample6 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 448,10/*oSample*/,28/*tapset*/)  //  oSample10 tapSet28,29 iSampleSet28,29
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample8 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample8 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 464,1/*oSample*/,29/*tapset*/)  //  oSample1 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch0  ISampleSet28 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch1  ISampleSet28 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,28/*tapsSet*/,28/*sampleSet*/)  // oSample10 tapSet28 Ch1  ISampleSet28 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,30/*R0 iSampleSet*/,30/*R1 iSampleSet*/) //  chan0,1 iSampleSet30,30
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample10 tapSet29 Ch1  ISampleSet29 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 464,3/*oSample*/,29/*tapset*/)  //  oSample3 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample1 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample1 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 464,5/*oSample*/,29/*tapset*/)  //  oSample5 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample3 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample3 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 464,7/*oSample*/,29/*tapset*/)  //  oSample7 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample5 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample5 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 464,9/*oSample*/,29/*tapset*/)  //  oSample9 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample7 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample7 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 464,11/*oSample*/,29/*tapset*/)  //  oSample11 tapSet29,30 iSampleSet29,30
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample9 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample9 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 480,0/*oSample*/,30/*tapset*/)  //  oSample0 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch0  ISampleSet29 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch1  ISampleSet29 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,29/*tapsSet*/,29/*sampleSet*/)  // oSample11 tapSet29 Ch1  ISampleSet29 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,31/*R0 iSampleSet*/,31/*R1 iSampleSet*/) //  chan0,1 iSampleSet31,31
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample11 tapSet30 Ch1  ISampleSet30 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 480,2/*oSample*/,30/*tapset*/)  //  oSample2 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample0 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample0 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 480,4/*oSample*/,30/*tapset*/)  //  oSample4 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample2 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample2 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 480,6/*oSample*/,30/*tapset*/)  //  oSample6 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample4 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample4 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 480,8/*oSample*/,30/*tapset*/)  //  oSample8 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample6 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample6 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 480,10/*oSample*/,30/*tapset*/)  //  oSample10 tapSet30,31 iSampleSet30,31
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample8 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample8 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 496,1/*oSample*/,31/*tapset*/)  //  oSample1 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch0  ISampleSet30 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch1  ISampleSet30 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,30/*tapsSet*/,30/*sampleSet*/)  // oSample10 tapSet30 Ch1  ISampleSet30 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,32/*R0 iSampleSet*/,32/*R1 iSampleSet*/) //  chan0,1 iSampleSet32,32
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample10 tapSet31 Ch1  ISampleSet31 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 496,3/*oSample*/,31/*tapset*/)  //  oSample3 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample1 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample1 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 496,5/*oSample*/,31/*tapset*/)  //  oSample5 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample3 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample3 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 496,7/*oSample*/,31/*tapset*/)  //  oSample7 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample5 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample5 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 496,9/*oSample*/,31/*tapset*/)  //  oSample9 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample7 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample7 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 496,11/*oSample*/,31/*tapset*/)  //  oSample11 tapSet31,32 iSampleSet31,32
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample9 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample9 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 512,0/*oSample*/,32/*tapset*/)  //  oSample0 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch0  ISampleSet31 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch1  ISampleSet31 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,31/*tapsSet*/,31/*sampleSet*/)  // oSample11 tapSet31 Ch1  ISampleSet31 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,33/*R0 iSampleSet*/,33/*R1 iSampleSet*/) //  chan0,1 iSampleSet33,33
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample11 tapSet32 Ch1  ISampleSet32 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 512,2/*oSample*/,32/*tapset*/)  //  oSample2 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample0 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample0 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 512,4/*oSample*/,32/*tapset*/)  //  oSample4 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample2 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample2 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 512,6/*oSample*/,32/*tapset*/)  //  oSample6 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample4 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample4 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 512,8/*oSample*/,32/*tapset*/)  //  oSample8 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample6 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample6 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 512,10/*oSample*/,32/*tapset*/)  //  oSample10 tapSet32,33 iSampleSet32,33
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample8 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample8 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 528,1/*oSample*/,33/*tapset*/)  //  oSample1 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch0  ISampleSet32 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch1  ISampleSet32 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,32/*tapsSet*/,32/*sampleSet*/)  // oSample10 tapSet32 Ch1  ISampleSet32 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,34/*R0 iSampleSet*/,34/*R1 iSampleSet*/) //  chan0,1 iSampleSet34,34
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample10 tapSet33 Ch1  ISampleSet33 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 528,3/*oSample*/,33/*tapset*/)  //  oSample3 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample1 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample1 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 528,5/*oSample*/,33/*tapset*/)  //  oSample5 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample3 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample3 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 528,7/*oSample*/,33/*tapset*/)  //  oSample7 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample5 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample5 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 528,9/*oSample*/,33/*tapset*/)  //  oSample9 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample7 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample7 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 528,11/*oSample*/,33/*tapset*/)  //  oSample11 tapSet33,34 iSampleSet33,34
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample9 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample9 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 544,0/*oSample*/,34/*tapset*/)  //  oSample0 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch0  ISampleSet33 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch1  ISampleSet33 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,33/*tapsSet*/,33/*sampleSet*/)  // oSample11 tapSet33 Ch1  ISampleSet33 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,35/*R0 iSampleSet*/,35/*R1 iSampleSet*/) //  chan0,1 iSampleSet35,35
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample11 tapSet34 Ch1  ISampleSet34 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 544,2/*oSample*/,34/*tapset*/)  //  oSample2 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample0 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample0 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 544,4/*oSample*/,34/*tapset*/)  //  oSample4 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample2 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample2 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 544,6/*oSample*/,34/*tapset*/)  //  oSample6 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample4 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample4 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 544,8/*oSample*/,34/*tapset*/)  //  oSample8 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample6 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample6 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 544,10/*oSample*/,34/*tapset*/)  //  oSample10 tapSet34,35 iSampleSet34,35
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample8 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample8 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 560,1/*oSample*/,35/*tapset*/)  //  oSample1 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch0  ISampleSet34 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch1  ISampleSet34 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,34/*tapsSet*/,34/*sampleSet*/)  // oSample10 tapSet34 Ch1  ISampleSet34 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,36/*R0 iSampleSet*/,36/*R1 iSampleSet*/) //  chan0,1 iSampleSet36,36
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample10 tapSet35 Ch1  ISampleSet35 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 560,3/*oSample*/,35/*tapset*/)  //  oSample3 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample1 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample1 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 560,5/*oSample*/,35/*tapset*/)  //  oSample5 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample3 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample3 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 560,7/*oSample*/,35/*tapset*/)  //  oSample7 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample5 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample5 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 560,9/*oSample*/,35/*tapset*/)  //  oSample9 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample7 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample7 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 560,11/*oSample*/,35/*tapset*/)  //  oSample11 tapSet35,36 iSampleSet35,36
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample9 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample9 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 576,0/*oSample*/,36/*tapset*/)  //  oSample0 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch0  ISampleSet35 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch1  ISampleSet35 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,35/*tapsSet*/,35/*sampleSet*/)  // oSample11 tapSet35 Ch1  ISampleSet35 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,37/*R0 iSampleSet*/,37/*R1 iSampleSet*/) //  chan0,1 iSampleSet37,37
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample11 tapSet36 Ch1  ISampleSet36 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 576,2/*oSample*/,36/*tapset*/)  //  oSample2 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample0 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample0 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 576,4/*oSample*/,36/*tapset*/)  //  oSample4 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample2 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample2 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 576,6/*oSample*/,36/*tapset*/)  //  oSample6 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample4 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample4 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 576,8/*oSample*/,36/*tapset*/)  //  oSample8 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample6 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample6 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 576,10/*oSample*/,36/*tapset*/)  //  oSample10 tapSet36,37 iSampleSet36,37
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample8 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample8 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 592,1/*oSample*/,37/*tapset*/)  //  oSample1 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch0  ISampleSet36 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch1  ISampleSet36 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,36/*tapsSet*/,36/*sampleSet*/)  // oSample10 tapSet36 Ch1  ISampleSet36 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,38/*R0 iSampleSet*/,38/*R1 iSampleSet*/) //  chan0,1 iSampleSet38,38
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample10 tapSet37 Ch1  ISampleSet37 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 592,3/*oSample*/,37/*tapset*/)  //  oSample3 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample1 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample1 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 592,5/*oSample*/,37/*tapset*/)  //  oSample5 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample3 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample3 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 592,7/*oSample*/,37/*tapset*/)  //  oSample7 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample5 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample5 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 592,9/*oSample*/,37/*tapset*/)  //  oSample9 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample7 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample7 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 592,11/*oSample*/,37/*tapset*/)  //  oSample11 tapSet37,38 iSampleSet37,38
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample9 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample9 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 608,0/*oSample*/,38/*tapset*/)  //  oSample0 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch0  ISampleSet37 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch1  ISampleSet37 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,37/*tapsSet*/,37/*sampleSet*/)  // oSample11 tapSet37 Ch1  ISampleSet37 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,39/*R0 iSampleSet*/,39/*R1 iSampleSet*/) //  chan0,1 iSampleSet39,39
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample11 tapSet38 Ch1  ISampleSet38 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 608,2/*oSample*/,38/*tapset*/)  //  oSample2 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample0 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample0 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 608,4/*oSample*/,38/*tapset*/)  //  oSample4 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample2 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample2 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 608,6/*oSample*/,38/*tapset*/)  //  oSample6 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample4 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample4 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 608,8/*oSample*/,38/*tapset*/)  //  oSample8 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample6 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample6 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 608,10/*oSample*/,38/*tapset*/)  //  oSample10 tapSet38,39 iSampleSet38,39
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample8 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample8 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 624,1/*oSample*/,39/*tapset*/)  //  oSample1 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch0  ISampleSet38 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch1  ISampleSet38 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,38/*tapsSet*/,38/*sampleSet*/)  // oSample10 tapSet38 Ch1  ISampleSet38 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,40/*R0 iSampleSet*/,40/*R1 iSampleSet*/) //  chan0,1 iSampleSet40,40
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample10 tapSet39 Ch1  ISampleSet39 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 624,3/*oSample*/,39/*tapset*/)  //  oSample3 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample1 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample1 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 624,5/*oSample*/,39/*tapset*/)  //  oSample5 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample3 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample3 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 624,7/*oSample*/,39/*tapset*/)  //  oSample7 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample5 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample5 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 624,9/*oSample*/,39/*tapset*/)  //  oSample9 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample7 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample7 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 624,11/*oSample*/,39/*tapset*/)  //  oSample11 tapSet39,40 iSampleSet39,40
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample9 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample9 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 640,0/*oSample*/,40/*tapset*/)  //  oSample0 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch0  ISampleSet39 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch1  ISampleSet39 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,39/*tapsSet*/,39/*sampleSet*/)  // oSample11 tapSet39 Ch1  ISampleSet39 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,41/*R0 iSampleSet*/,41/*R1 iSampleSet*/) //  chan0,1 iSampleSet41,41
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample11 tapSet40 Ch1  ISampleSet40 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 640,2/*oSample*/,40/*tapset*/)  //  oSample2 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample0 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample0 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 640,4/*oSample*/,40/*tapset*/)  //  oSample4 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample2 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample2 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 640,6/*oSample*/,40/*tapset*/)  //  oSample6 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample4 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample4 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 640,8/*oSample*/,40/*tapset*/)  //  oSample8 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample6 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample6 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 640,10/*oSample*/,40/*tapset*/)  //  oSample10 tapSet40,41 iSampleSet40,41
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample8 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample8 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 656,1/*oSample*/,41/*tapset*/)  //  oSample1 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch0  ISampleSet40 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch1  ISampleSet40 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,40/*tapsSet*/,40/*sampleSet*/)  // oSample10 tapSet40 Ch1  ISampleSet40 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,42/*R0 iSampleSet*/,42/*R1 iSampleSet*/) //  chan0,1 iSampleSet42,42
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample10 tapSet41 Ch1  ISampleSet41 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 656,3/*oSample*/,41/*tapset*/)  //  oSample3 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample1 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample1 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 656,5/*oSample*/,41/*tapset*/)  //  oSample5 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample3 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample3 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 656,7/*oSample*/,41/*tapset*/)  //  oSample7 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample5 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample5 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 656,9/*oSample*/,41/*tapset*/)  //  oSample9 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample7 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample7 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 656,11/*oSample*/,41/*tapset*/)  //  oSample11 tapSet41,42 iSampleSet41,42
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample9 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample9 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 672,0/*oSample*/,42/*tapset*/)  //  oSample0 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch0  ISampleSet41 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch1  ISampleSet41 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,41/*tapsSet*/,41/*sampleSet*/)  // oSample11 tapSet41 Ch1  ISampleSet41 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,43/*R0 iSampleSet*/,43/*R1 iSampleSet*/) //  chan0,1 iSampleSet43,43
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample11 tapSet42 Ch1  ISampleSet42 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 672,2/*oSample*/,42/*tapset*/)  //  oSample2 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample0 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample0 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 672,4/*oSample*/,42/*tapset*/)  //  oSample4 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample2 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample2 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 672,6/*oSample*/,42/*tapset*/)  //  oSample6 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample4 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample4 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 672,8/*oSample*/,42/*tapset*/)  //  oSample8 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample6 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample6 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 672,10/*oSample*/,42/*tapset*/)  //  oSample10 tapSet42,43 iSampleSet42,43
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample8 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample8 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 688,1/*oSample*/,43/*tapset*/)  //  oSample1 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch0  ISampleSet42 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch1  ISampleSet42 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,42/*tapsSet*/,42/*sampleSet*/)  // oSample10 tapSet42 Ch1  ISampleSet42 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,44/*R0 iSampleSet*/,44/*R1 iSampleSet*/) //  chan0,1 iSampleSet44,44
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample10 tapSet43 Ch1  ISampleSet43 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 688,3/*oSample*/,43/*tapset*/)  //  oSample3 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample1 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample1 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 688,5/*oSample*/,43/*tapset*/)  //  oSample5 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample3 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample3 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 688,7/*oSample*/,43/*tapset*/)  //  oSample7 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample5 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample5 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 688,9/*oSample*/,43/*tapset*/)  //  oSample9 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample7 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample7 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 688,11/*oSample*/,43/*tapset*/)  //  oSample11 tapSet43,44 iSampleSet43,44
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample9 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample9 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 704,0/*oSample*/,44/*tapset*/)  //  oSample0 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch0  ISampleSet43 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch1  ISampleSet43 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,43/*tapsSet*/,43/*sampleSet*/)  // oSample11 tapSet43 Ch1  ISampleSet43 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,45/*R0 iSampleSet*/,45/*R1 iSampleSet*/) //  chan0,1 iSampleSet45,45
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample11 tapSet44 Ch1  ISampleSet44 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 704,2/*oSample*/,44/*tapset*/)  //  oSample2 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample0 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample0 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 704,4/*oSample*/,44/*tapset*/)  //  oSample4 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample2 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample2 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 704,6/*oSample*/,44/*tapset*/)  //  oSample6 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample4 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample4 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 704,8/*oSample*/,44/*tapset*/)  //  oSample8 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample6 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample6 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 704,10/*oSample*/,44/*tapset*/)  //  oSample10 tapSet44,45 iSampleSet44,45
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample8 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample8 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 720,1/*oSample*/,45/*tapset*/)  //  oSample1 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch0  ISampleSet44 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch1  ISampleSet44 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,44/*tapsSet*/,44/*sampleSet*/)  // oSample10 tapSet44 Ch1  ISampleSet44 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,46/*R0 iSampleSet*/,46/*R1 iSampleSet*/) //  chan0,1 iSampleSet46,46
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample10 tapSet45 Ch1  ISampleSet45 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 720,3/*oSample*/,45/*tapset*/)  //  oSample3 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample1 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample1 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 720,5/*oSample*/,45/*tapset*/)  //  oSample5 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample3 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample3 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 720,7/*oSample*/,45/*tapset*/)  //  oSample7 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample5 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample5 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 720,9/*oSample*/,45/*tapset*/)  //  oSample9 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample7 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample7 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 720,11/*oSample*/,45/*tapset*/)  //  oSample11 tapSet45,46 iSampleSet45,46
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample9 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample9 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 736,0/*oSample*/,46/*tapset*/)  //  oSample0 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch0  ISampleSet45 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch1  ISampleSet45 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,45/*tapsSet*/,45/*sampleSet*/)  // oSample11 tapSet45 Ch1  ISampleSet45 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,47/*R0 iSampleSet*/,47/*R1 iSampleSet*/) //  chan0,1 iSampleSet47,47
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample11 tapSet46 Ch1  ISampleSet46 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 736,2/*oSample*/,46/*tapset*/)  //  oSample2 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample0 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample0 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 736,4/*oSample*/,46/*tapset*/)  //  oSample4 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample2 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample2 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 736,6/*oSample*/,46/*tapset*/)  //  oSample6 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample4 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample4 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 736,8/*oSample*/,46/*tapset*/)  //  oSample8 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample6 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample6 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 736,10/*oSample*/,46/*tapset*/)  //  oSample10 tapSet46,47 iSampleSet46,47
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample8 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample8 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 752,1/*oSample*/,47/*tapset*/)  //  oSample1 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch0  ISampleSet46 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch1  ISampleSet46 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,46/*tapsSet*/,46/*sampleSet*/)  // oSample10 tapSet46 Ch1  ISampleSet46 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,48/*R0 iSampleSet*/,48/*R1 iSampleSet*/) //  chan0,1 iSampleSet48,48
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample10 tapSet47 Ch1  ISampleSet47 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 752,3/*oSample*/,47/*tapset*/)  //  oSample3 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample1 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample1 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 752,5/*oSample*/,47/*tapset*/)  //  oSample5 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample3 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample3 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 752,7/*oSample*/,47/*tapset*/)  //  oSample7 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample5 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample5 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 752,9/*oSample*/,47/*tapset*/)  //  oSample9 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample7 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample7 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 752,11/*oSample*/,47/*tapset*/)  //  oSample11 tapSet47,48 iSampleSet47,48
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample9 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample9 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 768,0/*oSample*/,48/*tapset*/)  //  oSample0 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch0  ISampleSet47 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch1  ISampleSet47 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,47/*tapsSet*/,47/*sampleSet*/)  // oSample11 tapSet47 Ch1  ISampleSet47 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,49/*R0 iSampleSet*/,49/*R1 iSampleSet*/) //  chan0,1 iSampleSet49,49
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample11 tapSet48 Ch1  ISampleSet48 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 768,2/*oSample*/,48/*tapset*/)  //  oSample2 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample0 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample0 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 768,4/*oSample*/,48/*tapset*/)  //  oSample4 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample2 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample2 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 768,6/*oSample*/,48/*tapset*/)  //  oSample6 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample4 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample4 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 768,8/*oSample*/,48/*tapset*/)  //  oSample8 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample6 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample6 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 768,10/*oSample*/,48/*tapset*/)  //  oSample10 tapSet48,49 iSampleSet48,49
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample8 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample8 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 784,1/*oSample*/,49/*tapset*/)  //  oSample1 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch0  ISampleSet48 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch1  ISampleSet48 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,48/*tapsSet*/,48/*sampleSet*/)  // oSample10 tapSet48 Ch1  ISampleSet48 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,50/*R0 iSampleSet*/,50/*R1 iSampleSet*/) //  chan0,1 iSampleSet50,50
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample10 tapSet49 Ch1  ISampleSet49 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 784,3/*oSample*/,49/*tapset*/)  //  oSample3 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample1 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample1 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 784,5/*oSample*/,49/*tapset*/)  //  oSample5 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample3 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample3 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 784,7/*oSample*/,49/*tapset*/)  //  oSample7 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample5 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample5 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 784,9/*oSample*/,49/*tapset*/)  //  oSample9 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample7 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample7 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 784,11/*oSample*/,49/*tapset*/)  //  oSample11 tapSet49,50 iSampleSet49,50
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample9 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample9 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 800,0/*oSample*/,50/*tapset*/)  //  oSample0 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch0  ISampleSet49 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch1  ISampleSet49 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,49/*tapsSet*/,49/*sampleSet*/)  // oSample11 tapSet49 Ch1  ISampleSet49 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,51/*R0 iSampleSet*/,51/*R1 iSampleSet*/) //  chan0,1 iSampleSet51,51
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample11 tapSet50 Ch1  ISampleSet50 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 800,2/*oSample*/,50/*tapset*/)  //  oSample2 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample0 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample0 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 800,4/*oSample*/,50/*tapset*/)  //  oSample4 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample2 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample2 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 800,6/*oSample*/,50/*tapset*/)  //  oSample6 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample4 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample4 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 800,8/*oSample*/,50/*tapset*/)  //  oSample8 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample6 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample6 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 800,10/*oSample*/,50/*tapset*/)  //  oSample10 tapSet50,51 iSampleSet50,51
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample8 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample8 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 816,1/*oSample*/,51/*tapset*/)  //  oSample1 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch0  ISampleSet50 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch1  ISampleSet50 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,50/*tapsSet*/,50/*sampleSet*/)  // oSample10 tapSet50 Ch1  ISampleSet50 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,52/*R0 iSampleSet*/,52/*R1 iSampleSet*/) //  chan0,1 iSampleSet52,52
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample10 tapSet51 Ch1  ISampleSet51 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 816,3/*oSample*/,51/*tapset*/)  //  oSample3 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample1 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample1 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 816,5/*oSample*/,51/*tapset*/)  //  oSample5 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample3 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample3 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 816,7/*oSample*/,51/*tapset*/)  //  oSample7 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample5 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample5 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 816,9/*oSample*/,51/*tapset*/)  //  oSample9 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample7 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample7 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 816,11/*oSample*/,51/*tapset*/)  //  oSample11 tapSet51,52 iSampleSet51,52
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample9 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample9 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 832,0/*oSample*/,52/*tapset*/)  //  oSample0 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch0  ISampleSet51 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch1  ISampleSet51 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,51/*tapsSet*/,51/*sampleSet*/)  // oSample11 tapSet51 Ch1  ISampleSet51 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,53/*R0 iSampleSet*/,53/*R1 iSampleSet*/) //  chan0,1 iSampleSet53,53
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample11 tapSet52 Ch1  ISampleSet52 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 832,2/*oSample*/,52/*tapset*/)  //  oSample2 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample0 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample0 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 832,4/*oSample*/,52/*tapset*/)  //  oSample4 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample2 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample2 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 832,6/*oSample*/,52/*tapset*/)  //  oSample6 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample4 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample4 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 832,8/*oSample*/,52/*tapset*/)  //  oSample8 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample6 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample6 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 832,10/*oSample*/,52/*tapset*/)  //  oSample10 tapSet52,53 iSampleSet52,53
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample8 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample8 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 848,1/*oSample*/,53/*tapset*/)  //  oSample1 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch0  ISampleSet52 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch1  ISampleSet52 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,52/*tapsSet*/,52/*sampleSet*/)  // oSample10 tapSet52 Ch1  ISampleSet52 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,54/*R0 iSampleSet*/,54/*R1 iSampleSet*/) //  chan0,1 iSampleSet54,54
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample10 tapSet53 Ch1  ISampleSet53 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 848,3/*oSample*/,53/*tapset*/)  //  oSample3 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample1 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample1 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 848,5/*oSample*/,53/*tapset*/)  //  oSample5 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample3 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample3 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 848,7/*oSample*/,53/*tapset*/)  //  oSample7 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample5 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample5 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 848,9/*oSample*/,53/*tapset*/)  //  oSample9 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample7 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample7 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 848,11/*oSample*/,53/*tapset*/)  //  oSample11 tapSet53,54 iSampleSet53,54
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample9 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample9 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 864,0/*oSample*/,54/*tapset*/)  //  oSample0 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch0  ISampleSet53 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch1  ISampleSet53 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,53/*tapsSet*/,53/*sampleSet*/)  // oSample11 tapSet53 Ch1  ISampleSet53 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,55/*R0 iSampleSet*/,55/*R1 iSampleSet*/) //  chan0,1 iSampleSet55,55
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample11 tapSet54 Ch1  ISampleSet54 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 864,2/*oSample*/,54/*tapset*/)  //  oSample2 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample0 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample0 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 864,4/*oSample*/,54/*tapset*/)  //  oSample4 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample2 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample2 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 864,6/*oSample*/,54/*tapset*/)  //  oSample6 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample4 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample4 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 864,8/*oSample*/,54/*tapset*/)  //  oSample8 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample6 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample6 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 864,10/*oSample*/,54/*tapset*/)  //  oSample10 tapSet54,55 iSampleSet54,55
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample8 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample8 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 880,1/*oSample*/,55/*tapset*/)  //  oSample1 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch0  ISampleSet54 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch1  ISampleSet54 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,54/*tapsSet*/,54/*sampleSet*/)  // oSample10 tapSet54 Ch1  ISampleSet54 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,56/*R0 iSampleSet*/,56/*R1 iSampleSet*/) //  chan0,1 iSampleSet56,56
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample10 tapSet55 Ch1  ISampleSet55 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 880,3/*oSample*/,55/*tapset*/)  //  oSample3 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample1 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample1 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 880,5/*oSample*/,55/*tapset*/)  //  oSample5 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample3 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample3 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 880,7/*oSample*/,55/*tapset*/)  //  oSample7 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample5 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample5 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 880,9/*oSample*/,55/*tapset*/)  //  oSample9 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample7 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample7 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 880,11/*oSample*/,55/*tapset*/)  //  oSample11 tapSet55,56 iSampleSet55,56
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample9 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample9 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 896,0/*oSample*/,56/*tapset*/)  //  oSample0 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch0  ISampleSet55 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch1  ISampleSet55 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,55/*tapsSet*/,55/*sampleSet*/)  // oSample11 tapSet55 Ch1  ISampleSet55 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,57/*R0 iSampleSet*/,57/*R1 iSampleSet*/) //  chan0,1 iSampleSet57,57
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample11 tapSet56 Ch1  ISampleSet56 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 896,2/*oSample*/,56/*tapset*/)  //  oSample2 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample0 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample0 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 896,4/*oSample*/,56/*tapset*/)  //  oSample4 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample2 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample2 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 896,6/*oSample*/,56/*tapset*/)  //  oSample6 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample4 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample4 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 896,8/*oSample*/,56/*tapset*/)  //  oSample8 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample6 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample6 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 896,10/*oSample*/,56/*tapset*/)  //  oSample10 tapSet56,57 iSampleSet56,57
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample8 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample8 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 912,1/*oSample*/,57/*tapset*/)  //  oSample1 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch0  ISampleSet56 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch1  ISampleSet56 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,56/*tapsSet*/,56/*sampleSet*/)  // oSample10 tapSet56 Ch1  ISampleSet56 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,58/*R0 iSampleSet*/,58/*R1 iSampleSet*/) //  chan0,1 iSampleSet58,58
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample10 tapSet57 Ch1  ISampleSet57 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 912,3/*oSample*/,57/*tapset*/)  //  oSample3 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample1 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample1 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 912,5/*oSample*/,57/*tapset*/)  //  oSample5 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample3 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample3 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 912,7/*oSample*/,57/*tapset*/)  //  oSample7 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample5 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample5 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 912,9/*oSample*/,57/*tapset*/)  //  oSample9 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample7 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample7 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 912,11/*oSample*/,57/*tapset*/)  //  oSample11 tapSet57,58 iSampleSet57,58
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample9 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample9 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 928,0/*oSample*/,58/*tapset*/)  //  oSample0 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch0  ISampleSet57 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch1  ISampleSet57 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,57/*tapsSet*/,57/*sampleSet*/)  // oSample11 tapSet57 Ch1  ISampleSet57 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,59/*R0 iSampleSet*/,59/*R1 iSampleSet*/) //  chan0,1 iSampleSet59,59
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample11 tapSet58 Ch1  ISampleSet58 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 928,2/*oSample*/,58/*tapset*/)  //  oSample2 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample0 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample0 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 928,4/*oSample*/,58/*tapset*/)  //  oSample4 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample2 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample2 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 928,6/*oSample*/,58/*tapset*/)  //  oSample6 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample4 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample4 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 928,8/*oSample*/,58/*tapset*/)  //  oSample8 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample6 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample6 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 928,10/*oSample*/,58/*tapset*/)  //  oSample10 tapSet58,59 iSampleSet58,59
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample8 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample8 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 944,1/*oSample*/,59/*tapset*/)  //  oSample1 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch0  ISampleSet58 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch1  ISampleSet58 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,58/*tapsSet*/,58/*sampleSet*/)  // oSample10 tapSet58 Ch1  ISampleSet58 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,60/*R0 iSampleSet*/,60/*R1 iSampleSet*/) //  chan0,1 iSampleSet60,60
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample10 tapSet59 Ch1  ISampleSet59 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 944,3/*oSample*/,59/*tapset*/)  //  oSample3 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample1 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample1 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 944,5/*oSample*/,59/*tapset*/)  //  oSample5 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample3 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample3 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 944,7/*oSample*/,59/*tapset*/)  //  oSample7 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample5 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample5 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 944,9/*oSample*/,59/*tapset*/)  //  oSample9 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample7 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample7 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 944,11/*oSample*/,59/*tapset*/)  //  oSample11 tapSet59,60 iSampleSet59,60
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample9 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample9 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 960,0/*oSample*/,60/*tapset*/)  //  oSample0 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch0  ISampleSet59 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch1  ISampleSet59 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,59/*tapsSet*/,59/*sampleSet*/)  // oSample11 tapSet59 Ch1  ISampleSet59 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,61/*R0 iSampleSet*/,61/*R1 iSampleSet*/) //  chan0,1 iSampleSet61,61
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample11 tapSet60 Ch1  ISampleSet60 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 960,2/*oSample*/,60/*tapset*/)  //  oSample2 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample0 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample0 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 960,4/*oSample*/,60/*tapset*/)  //  oSample4 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample2 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample2 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 960,6/*oSample*/,60/*tapset*/)  //  oSample6 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample4 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample4 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 960,8/*oSample*/,60/*tapset*/)  //  oSample8 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample6 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample6 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 960,10/*oSample*/,60/*tapset*/)  //  oSample10 tapSet60,61 iSampleSet60,61
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample8 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample8 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 976,1/*oSample*/,61/*tapset*/)  //  oSample1 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch0  ISampleSet60 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch1  ISampleSet60 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,60/*tapsSet*/,60/*sampleSet*/)  // oSample10 tapSet60 Ch1  ISampleSet60 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,62/*R0 iSampleSet*/,62/*R1 iSampleSet*/) //  chan0,1 iSampleSet62,62
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample10 tapSet61 Ch1  ISampleSet61 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 976,3/*oSample*/,61/*tapset*/)  //  oSample3 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample1 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample1 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 976,5/*oSample*/,61/*tapset*/)  //  oSample5 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample3 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample3 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 976,7/*oSample*/,61/*tapset*/)  //  oSample7 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample5 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample5 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 976,9/*oSample*/,61/*tapset*/)  //  oSample9 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample7 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample7 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 976,11/*oSample*/,61/*tapset*/)  //  oSample11 tapSet61,62 iSampleSet61,62
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample9 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample9 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 992,0/*oSample*/,62/*tapset*/)  //  oSample0 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch0  ISampleSet61 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch1  ISampleSet61 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,61/*tapsSet*/,61/*sampleSet*/)  // oSample11 tapSet61 Ch1  ISampleSet61 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,63/*R0 iSampleSet*/,63/*R1 iSampleSet*/) //  chan0,1 iSampleSet63,63
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample11 tapSet62 Ch1  ISampleSet62 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 992,2/*oSample*/,62/*tapset*/)  //  oSample2 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample0 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample0 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 992,4/*oSample*/,62/*tapset*/)  //  oSample4 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample2 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample2 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 992,6/*oSample*/,62/*tapset*/)  //  oSample6 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample4 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample4 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 992,8/*oSample*/,62/*tapset*/)  //  oSample8 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample6 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample6 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 992,10/*oSample*/,62/*tapset*/)  //  oSample10 tapSet62,63 iSampleSet62,63
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample8 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample8 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1008,1/*oSample*/,63/*tapset*/)  //  oSample1 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch0  ISampleSet62 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch1  ISampleSet62 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,62/*tapsSet*/,62/*sampleSet*/)  // oSample10 tapSet62 Ch1  ISampleSet62 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,64/*R0 iSampleSet*/,64/*R1 iSampleSet*/) //  chan0,1 iSampleSet64,64
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample10 tapSet63 Ch1  ISampleSet63 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1008,3/*oSample*/,63/*tapset*/)  //  oSample3 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample1 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample1 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1008,5/*oSample*/,63/*tapset*/)  //  oSample5 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample3 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample3 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1008,7/*oSample*/,63/*tapset*/)  //  oSample7 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample5 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample5 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1008,9/*oSample*/,63/*tapset*/)  //  oSample9 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample7 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample7 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1008,11/*oSample*/,63/*tapset*/)  //  oSample11 tapSet63,64 iSampleSet63,64
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample9 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample9 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1024,0/*oSample*/,64/*tapset*/)  //  oSample0 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch0  ISampleSet63 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch1  ISampleSet63 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,63/*tapsSet*/,63/*sampleSet*/)  // oSample11 tapSet63 Ch1  ISampleSet63 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,65/*R0 iSampleSet*/,65/*R1 iSampleSet*/) //  chan0,1 iSampleSet65,65
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample11 tapSet64 Ch1  ISampleSet64 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1024,2/*oSample*/,64/*tapset*/)  //  oSample2 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample0 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample0 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1024,4/*oSample*/,64/*tapset*/)  //  oSample4 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample2 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample2 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1024,6/*oSample*/,64/*tapset*/)  //  oSample6 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample4 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample4 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1024,8/*oSample*/,64/*tapset*/)  //  oSample8 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample6 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample6 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1024,10/*oSample*/,64/*tapset*/)  //  oSample10 tapSet64,65 iSampleSet64,65
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample8 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample8 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1040,1/*oSample*/,65/*tapset*/)  //  oSample1 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch0  ISampleSet64 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch1  ISampleSet64 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,64/*tapsSet*/,64/*sampleSet*/)  // oSample10 tapSet64 Ch1  ISampleSet64 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,66/*R0 iSampleSet*/,66/*R1 iSampleSet*/) //  chan0,1 iSampleSet66,66
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample10 tapSet65 Ch1  ISampleSet65 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1040,3/*oSample*/,65/*tapset*/)  //  oSample3 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample1 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample1 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1040,5/*oSample*/,65/*tapset*/)  //  oSample5 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample3 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample3 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1040,7/*oSample*/,65/*tapset*/)  //  oSample7 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample5 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample5 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1040,9/*oSample*/,65/*tapset*/)  //  oSample9 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample7 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample7 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1040,11/*oSample*/,65/*tapset*/)  //  oSample11 tapSet65,66 iSampleSet65,66
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample9 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample9 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1056,0/*oSample*/,66/*tapset*/)  //  oSample0 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch0  ISampleSet65 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch1  ISampleSet65 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,65/*tapsSet*/,65/*sampleSet*/)  // oSample11 tapSet65 Ch1  ISampleSet65 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,67/*R0 iSampleSet*/,67/*R1 iSampleSet*/) //  chan0,1 iSampleSet67,67
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample11 tapSet66 Ch1  ISampleSet66 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1056,2/*oSample*/,66/*tapset*/)  //  oSample2 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample0 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample0 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1056,4/*oSample*/,66/*tapset*/)  //  oSample4 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample2 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample2 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1056,6/*oSample*/,66/*tapset*/)  //  oSample6 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample4 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample4 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1056,8/*oSample*/,66/*tapset*/)  //  oSample8 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample6 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample6 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1056,10/*oSample*/,66/*tapset*/)  //  oSample10 tapSet66,67 iSampleSet66,67
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample8 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample8 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1072,1/*oSample*/,67/*tapset*/)  //  oSample1 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch0  ISampleSet66 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch1  ISampleSet66 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,66/*tapsSet*/,66/*sampleSet*/)  // oSample10 tapSet66 Ch1  ISampleSet66 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,68/*R0 iSampleSet*/,68/*R1 iSampleSet*/) //  chan0,1 iSampleSet68,68
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample10 tapSet67 Ch1  ISampleSet67 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1072,3/*oSample*/,67/*tapset*/)  //  oSample3 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample1 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample1 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1072,5/*oSample*/,67/*tapset*/)  //  oSample5 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample3 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample3 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1072,7/*oSample*/,67/*tapset*/)  //  oSample7 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample5 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample5 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1072,9/*oSample*/,67/*tapset*/)  //  oSample9 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample7 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample7 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1072,11/*oSample*/,67/*tapset*/)  //  oSample11 tapSet67,68 iSampleSet67,68
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample9 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample9 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1088,0/*oSample*/,68/*tapset*/)  //  oSample0 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch0  ISampleSet67 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch1  ISampleSet67 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,67/*tapsSet*/,67/*sampleSet*/)  // oSample11 tapSet67 Ch1  ISampleSet67 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,69/*R0 iSampleSet*/,69/*R1 iSampleSet*/) //  chan0,1 iSampleSet69,69
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample11 tapSet68 Ch1  ISampleSet68 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1088,2/*oSample*/,68/*tapset*/)  //  oSample2 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample0 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample0 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1088,4/*oSample*/,68/*tapset*/)  //  oSample4 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample2 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample2 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1088,6/*oSample*/,68/*tapset*/)  //  oSample6 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample4 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample4 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1088,8/*oSample*/,68/*tapset*/)  //  oSample8 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample6 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample6 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1088,10/*oSample*/,68/*tapset*/)  //  oSample10 tapSet68,69 iSampleSet68,69
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample8 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample8 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1104,1/*oSample*/,69/*tapset*/)  //  oSample1 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch0  ISampleSet68 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch1  ISampleSet68 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,68/*tapsSet*/,68/*sampleSet*/)  // oSample10 tapSet68 Ch1  ISampleSet68 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,70/*R0 iSampleSet*/,70/*R1 iSampleSet*/) //  chan0,1 iSampleSet70,70
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample10 tapSet69 Ch1  ISampleSet69 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1104,3/*oSample*/,69/*tapset*/)  //  oSample3 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample1 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample1 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1104,5/*oSample*/,69/*tapset*/)  //  oSample5 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample3 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample3 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1104,7/*oSample*/,69/*tapset*/)  //  oSample7 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample5 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample5 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1104,9/*oSample*/,69/*tapset*/)  //  oSample9 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample7 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample7 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1104,11/*oSample*/,69/*tapset*/)  //  oSample11 tapSet69,70 iSampleSet69,70
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample9 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample9 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1120,0/*oSample*/,70/*tapset*/)  //  oSample0 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch0  ISampleSet69 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch1  ISampleSet69 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,69/*tapsSet*/,69/*sampleSet*/)  // oSample11 tapSet69 Ch1  ISampleSet69 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,71/*R0 iSampleSet*/,71/*R1 iSampleSet*/) //  chan0,1 iSampleSet71,71
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample11 tapSet70 Ch1  ISampleSet70 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1120,2/*oSample*/,70/*tapset*/)  //  oSample2 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample0 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample0 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1120,4/*oSample*/,70/*tapset*/)  //  oSample4 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample2 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample2 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1120,6/*oSample*/,70/*tapset*/)  //  oSample6 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample4 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample4 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1120,8/*oSample*/,70/*tapset*/)  //  oSample8 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample6 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample6 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1120,10/*oSample*/,70/*tapset*/)  //  oSample10 tapSet70,71 iSampleSet70,71
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample8 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample8 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1136,1/*oSample*/,71/*tapset*/)  //  oSample1 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch0  ISampleSet70 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch1  ISampleSet70 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,70/*tapsSet*/,70/*sampleSet*/)  // oSample10 tapSet70 Ch1  ISampleSet70 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,72/*R0 iSampleSet*/,72/*R1 iSampleSet*/) //  chan0,1 iSampleSet72,72
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample10 tapSet71 Ch1  ISampleSet71 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1136,3/*oSample*/,71/*tapset*/)  //  oSample3 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample1 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample1 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1136,5/*oSample*/,71/*tapset*/)  //  oSample5 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample3 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample3 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1136,7/*oSample*/,71/*tapset*/)  //  oSample7 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample5 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample5 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1136,9/*oSample*/,71/*tapset*/)  //  oSample9 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample7 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample7 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1136,11/*oSample*/,71/*tapset*/)  //  oSample11 tapSet71,72 iSampleSet71,72
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample9 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample9 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1152,0/*oSample*/,72/*tapset*/)  //  oSample0 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch0  ISampleSet71 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch1  ISampleSet71 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,71/*tapsSet*/,71/*sampleSet*/)  // oSample11 tapSet71 Ch1  ISampleSet71 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,73/*R0 iSampleSet*/,73/*R1 iSampleSet*/) //  chan0,1 iSampleSet73,73
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample11 tapSet72 Ch1  ISampleSet72 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1152,2/*oSample*/,72/*tapset*/)  //  oSample2 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample0 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample0 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1152,4/*oSample*/,72/*tapset*/)  //  oSample4 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample2 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample2 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1152,6/*oSample*/,72/*tapset*/)  //  oSample6 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample4 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample4 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1152,8/*oSample*/,72/*tapset*/)  //  oSample8 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample6 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample6 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1152,10/*oSample*/,72/*tapset*/)  //  oSample10 tapSet72,73 iSampleSet72,73
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample8 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample8 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1168,1/*oSample*/,73/*tapset*/)  //  oSample1 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch0  ISampleSet72 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch1  ISampleSet72 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,72/*tapsSet*/,72/*sampleSet*/)  // oSample10 tapSet72 Ch1  ISampleSet72 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,74/*R0 iSampleSet*/,74/*R1 iSampleSet*/) //  chan0,1 iSampleSet74,74
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample10 tapSet73 Ch1  ISampleSet73 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1168,3/*oSample*/,73/*tapset*/)  //  oSample3 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample1 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample1 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1168,5/*oSample*/,73/*tapset*/)  //  oSample5 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample3 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample3 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1168,7/*oSample*/,73/*tapset*/)  //  oSample7 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample5 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample5 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1168,9/*oSample*/,73/*tapset*/)  //  oSample9 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample7 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample7 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1168,11/*oSample*/,73/*tapset*/)  //  oSample11 tapSet73,74 iSampleSet73,74
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample9 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample9 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1184,0/*oSample*/,74/*tapset*/)  //  oSample0 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch0  ISampleSet73 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch1  ISampleSet73 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,73/*tapsSet*/,73/*sampleSet*/)  // oSample11 tapSet73 Ch1  ISampleSet73 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,75/*R0 iSampleSet*/,75/*R1 iSampleSet*/) //  chan0,1 iSampleSet75,75
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample11 tapSet74 Ch1  ISampleSet74 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1184,2/*oSample*/,74/*tapset*/)  //  oSample2 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample0 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample0 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1184,4/*oSample*/,74/*tapset*/)  //  oSample4 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample2 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample2 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1184,6/*oSample*/,74/*tapset*/)  //  oSample6 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample4 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample4 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1184,8/*oSample*/,74/*tapset*/)  //  oSample8 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample6 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample6 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1184,10/*oSample*/,74/*tapset*/)  //  oSample10 tapSet74,75 iSampleSet74,75
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample8 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample8 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1200,1/*oSample*/,75/*tapset*/)  //  oSample1 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch0  ISampleSet74 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch1  ISampleSet74 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,74/*tapsSet*/,74/*sampleSet*/)  // oSample10 tapSet74 Ch1  ISampleSet74 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,76/*R0 iSampleSet*/,76/*R1 iSampleSet*/) //  chan0,1 iSampleSet76,76
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample10 tapSet75 Ch1  ISampleSet75 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1200,3/*oSample*/,75/*tapset*/)  //  oSample3 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample1 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample1 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1200,5/*oSample*/,75/*tapset*/)  //  oSample5 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample3 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample3 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1200,7/*oSample*/,75/*tapset*/)  //  oSample7 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample5 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample5 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1200,9/*oSample*/,75/*tapset*/)  //  oSample9 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample7 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample7 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1200,11/*oSample*/,75/*tapset*/)  //  oSample11 tapSet75,76 iSampleSet75,76
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample9 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample9 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1216,0/*oSample*/,76/*tapset*/)  //  oSample0 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch0  ISampleSet75 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch1  ISampleSet75 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,75/*tapsSet*/,75/*sampleSet*/)  // oSample11 tapSet75 Ch1  ISampleSet75 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,77/*R0 iSampleSet*/,77/*R1 iSampleSet*/) //  chan0,1 iSampleSet77,77
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample11 tapSet76 Ch1  ISampleSet76 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1216,2/*oSample*/,76/*tapset*/)  //  oSample2 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample0 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample0 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1216,4/*oSample*/,76/*tapset*/)  //  oSample4 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample2 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample2 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1216,6/*oSample*/,76/*tapset*/)  //  oSample6 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample4 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample4 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1216,8/*oSample*/,76/*tapset*/)  //  oSample8 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample6 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample6 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1216,10/*oSample*/,76/*tapset*/)  //  oSample10 tapSet76,77 iSampleSet76,77
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample8 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample8 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1232,1/*oSample*/,77/*tapset*/)  //  oSample1 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch0  ISampleSet76 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch1  ISampleSet76 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,76/*tapsSet*/,76/*sampleSet*/)  // oSample10 tapSet76 Ch1  ISampleSet76 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,78/*R0 iSampleSet*/,78/*R1 iSampleSet*/) //  chan0,1 iSampleSet78,78
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample10 tapSet77 Ch1  ISampleSet77 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1232,3/*oSample*/,77/*tapset*/)  //  oSample3 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample1 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample1 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1232,5/*oSample*/,77/*tapset*/)  //  oSample5 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample3 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample3 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1232,7/*oSample*/,77/*tapset*/)  //  oSample7 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample5 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample5 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1232,9/*oSample*/,77/*tapset*/)  //  oSample9 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample7 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample7 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1232,11/*oSample*/,77/*tapset*/)  //  oSample11 tapSet77,78 iSampleSet77,78
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample9 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample9 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1248,0/*oSample*/,78/*tapset*/)  //  oSample0 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch0  ISampleSet77 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch1  ISampleSet77 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,77/*tapsSet*/,77/*sampleSet*/)  // oSample11 tapSet77 Ch1  ISampleSet77 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,79/*R0 iSampleSet*/,79/*R1 iSampleSet*/) //  chan0,1 iSampleSet79,79
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample11 tapSet78 Ch1  ISampleSet78 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1248,2/*oSample*/,78/*tapset*/)  //  oSample2 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample0 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample0 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1248,4/*oSample*/,78/*tapset*/)  //  oSample4 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample2 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample2 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1248,6/*oSample*/,78/*tapset*/)  //  oSample6 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample4 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample4 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1248,8/*oSample*/,78/*tapset*/)  //  oSample8 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample6 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample6 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1248,10/*oSample*/,78/*tapset*/)  //  oSample10 tapSet78,79 iSampleSet78,79
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample8 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample8 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1264,1/*oSample*/,79/*tapset*/)  //  oSample1 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch0  ISampleSet78 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch1  ISampleSet78 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,78/*tapsSet*/,78/*sampleSet*/)  // oSample10 tapSet78 Ch1  ISampleSet78 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,80/*R0 iSampleSet*/,80/*R1 iSampleSet*/) //  chan0,1 iSampleSet80,80
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample10 tapSet79 Ch1  ISampleSet79 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1264,3/*oSample*/,79/*tapset*/)  //  oSample3 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample1 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample1 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1264,5/*oSample*/,79/*tapset*/)  //  oSample5 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample3 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample3 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1264,7/*oSample*/,79/*tapset*/)  //  oSample7 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample5 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample5 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1264,9/*oSample*/,79/*tapset*/)  //  oSample9 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample7 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample7 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1264,11/*oSample*/,79/*tapset*/)  //  oSample11 tapSet79,80 iSampleSet79,80
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample9 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample9 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1280,0/*oSample*/,80/*tapset*/)  //  oSample0 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch0  ISampleSet79 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch1  ISampleSet79 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,79/*tapsSet*/,79/*sampleSet*/)  // oSample11 tapSet79 Ch1  ISampleSet79 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,81/*R0 iSampleSet*/,81/*R1 iSampleSet*/) //  chan0,1 iSampleSet81,81
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample11 tapSet80 Ch1  ISampleSet80 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1280,2/*oSample*/,80/*tapset*/)  //  oSample2 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample0 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample0 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1280,4/*oSample*/,80/*tapset*/)  //  oSample4 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample2 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample2 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1280,6/*oSample*/,80/*tapset*/)  //  oSample6 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample4 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample4 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1280,8/*oSample*/,80/*tapset*/)  //  oSample8 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample6 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample6 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1280,10/*oSample*/,80/*tapset*/)  //  oSample10 tapSet80,81 iSampleSet80,81
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample8 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample8 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1296,1/*oSample*/,81/*tapset*/)  //  oSample1 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch0  ISampleSet80 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch1  ISampleSet80 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,80/*tapsSet*/,80/*sampleSet*/)  // oSample10 tapSet80 Ch1  ISampleSet80 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,82/*R0 iSampleSet*/,82/*R1 iSampleSet*/) //  chan0,1 iSampleSet82,82
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample10 tapSet81 Ch1  ISampleSet81 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1296,3/*oSample*/,81/*tapset*/)  //  oSample3 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample1 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample1 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1296,5/*oSample*/,81/*tapset*/)  //  oSample5 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample3 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample3 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1296,7/*oSample*/,81/*tapset*/)  //  oSample7 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample5 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample5 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1296,9/*oSample*/,81/*tapset*/)  //  oSample9 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample7 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample7 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1296,11/*oSample*/,81/*tapset*/)  //  oSample11 tapSet81,82 iSampleSet81,82
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample9 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample9 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample00FitlerP, 1312,0/*oSample*/,82/*tapset*/)  //  oSample0 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch0  ISampleSet81 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch1  ISampleSet81 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,81/*tapsSet*/,81/*sampleSet*/)  // oSample11 tapSet81 Ch1  ISampleSet81 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,83/*R0 iSampleSet*/,83/*R1 iSampleSet*/) //  chan0,1 iSampleSet83,83
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample11 tapSet82 Ch1  ISampleSet82 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample02FitlerP, 1312,2/*oSample*/,82/*tapset*/)  //  oSample2 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample0 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,0/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample0 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample0 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,0/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample0 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_lower(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample0 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample00AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,0/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample0 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample0 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample00AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,0/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample0 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1312,4/*oSample*/,82/*tapset*/)  //  oSample4 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,2/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,2/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample2 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample2 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,2/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample2 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample2 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,2/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample2 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1312,6/*oSample*/,82/*tapset*/)  //  oSample6 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample4 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample4 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1312,8/*oSample*/,82/*tapset*/)  //  oSample8 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample6 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample6 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1312,10/*oSample*/,82/*tapset*/)  //  oSample10 tapSet82,83 iSampleSet82,83
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample8 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample8 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample01FitlerP, 1328,1/*oSample*/,83/*tapset*/)  //  oSample1 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch0  ISampleSet82 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch1  ISampleSet82 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,82/*tapsSet*/,82/*sampleSet*/)  // oSample10 tapSet82 Ch1  ISampleSet82 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,84/*R0 iSampleSet*/,84/*R1 iSampleSet*/) //  chan0,1 iSampleSet84,84
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample10 tapSet83 Ch1  ISampleSet83 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1328,3/*oSample*/,83/*tapset*/)  //  oSample3 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample1 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,1/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample1 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample1 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,1/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample1 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_lower(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample1 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample01AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,1/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample1 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample1 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample01AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,1/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample1 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1328,5/*oSample*/,83/*tapset*/)  //  oSample5 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample3 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample3 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample3 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample3 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample3 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1328,7/*oSample*/,83/*tapset*/)  //  oSample7 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample5 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample5 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1328,9/*oSample*/,83/*tapset*/)  //  oSample9 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample7 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample7 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1328,11/*oSample*/,83/*tapset*/)  //  oSample11 tapSet83,84 iSampleSet83,84
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample9 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample9 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample02FitlerP, 1344,2/*oSample*/,84/*tapset*/)  //  oSample2 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch0  ISampleSet83 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch1  ISampleSet83 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,83/*tapsSet*/,83/*sampleSet*/)  // oSample11 tapSet83 Ch1  ISampleSet83 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,85/*R0 iSampleSet*/,85/*R1 iSampleSet*/) //  chan0,1 iSampleSet85,85
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample11 tapSet84 Ch1  ISampleSet84 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample04FitlerP, 1344,4/*oSample*/,84/*tapset*/)  //  oSample4 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample2 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,2/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample2 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample2 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,2/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample2 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_lower(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample2 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample02AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,2/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample2 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample2 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample02AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,2/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample2 tapSet85 Ch1  ISampleSet85 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 1344,6/*oSample*/,84/*tapset*/)  //  oSample6 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,4/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,4/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,4/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample4 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample4 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,4/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample4 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,4/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample4 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,4/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample4 tapSet85 Ch1  ISampleSet85 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 1344,8/*oSample*/,84/*tapset*/)  //  oSample8 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample6 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample6 tapSet85 Ch1  ISampleSet85 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 1344,10/*oSample*/,84/*tapset*/)  //  oSample10 tapSet84,85 iSampleSet84,85
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample8 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample8 tapSet85 Ch1  ISampleSet85 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample03FitlerP, 1360,3/*oSample*/,85/*tapset*/)  //  oSample3 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch0  ISampleSet84 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch1  ISampleSet84 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,84/*tapsSet*/,84/*sampleSet*/)  // oSample10 tapSet84 Ch1  ISampleSet84 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,86/*R0 iSampleSet*/,86/*R1 iSampleSet*/) //  chan0,1 iSampleSet86,86
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample10 tapSet85 Ch1  ISampleSet85 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1360,5/*oSample*/,85/*tapset*/)  //  oSample5 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample3 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,3/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample3 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample3 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,3/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample3 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_lower(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample3 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample03AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,3/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample3 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample3 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample03AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,3/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample3 tapSet86 Ch1  ISampleSet86 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1360,7/*oSample*/,85/*tapset*/)  //  oSample7 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample5 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample5 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample5 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample5 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample5 tapSet86 Ch1  ISampleSet86 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1360,9/*oSample*/,85/*tapset*/)  //  oSample9 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample7 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample7 tapSet86 Ch1  ISampleSet86 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1360,11/*oSample*/,85/*tapset*/)  //  oSample11 tapSet85,86 iSampleSet85,86
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample9 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample9 tapSet86 Ch1  ISampleSet86 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample04FitlerP, 1376,4/*oSample*/,86/*tapset*/)  //  oSample4 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch0  ISampleSet85 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch1  ISampleSet85 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,85/*tapsSet*/,85/*sampleSet*/)  // oSample11 tapSet85 Ch1  ISampleSet85 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,87/*R0 iSampleSet*/,87/*R1 iSampleSet*/) //  chan0,1 iSampleSet87,87
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample11 tapSet86 Ch1  ISampleSet86 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample06FitlerP, 1376,6/*oSample*/,86/*tapset*/)  //  oSample6 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample4 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,4/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample4 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample4 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,4/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample4 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_lower(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample4 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample04AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,4/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample4 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample4 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample04AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,4/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample4 tapSet87 Ch1  ISampleSet87 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1376,8/*oSample*/,86/*tapset*/)  //  oSample8 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample6 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,6/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample6 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample6 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,6/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample6 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample6 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,6/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample6 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample6 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,6/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample6 tapSet87 Ch1  ISampleSet87 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1376,10/*oSample*/,86/*tapset*/)  //  oSample10 tapSet86,87 iSampleSet86,87
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample8 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample8 tapSet87 Ch1  ISampleSet87 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample05FitlerP, 1392,5/*oSample*/,87/*tapset*/)  //  oSample5 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch0  ISampleSet86 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch1  ISampleSet86 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,86/*tapsSet*/,86/*sampleSet*/)  // oSample10 tapSet86 Ch1  ISampleSet86 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,88/*R0 iSampleSet*/,88/*R1 iSampleSet*/) //  chan0,1 iSampleSet88,88
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample10 tapSet87 Ch1  ISampleSet87 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1392,7/*oSample*/,87/*tapset*/)  //  oSample7 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample5 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,5/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample5 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample5 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,5/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample5 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_lower(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample5 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample05AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,5/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample5 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample5 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample05AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,5/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample5 tapSet88 Ch1  ISampleSet88 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1392,9/*oSample*/,87/*tapset*/)  //  oSample9 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample7 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample7 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample7 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample7 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample7 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample7 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample7 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample7 tapSet88 Ch1  ISampleSet88 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1392,11/*oSample*/,87/*tapset*/)  //  oSample11 tapSet87,88 iSampleSet87,88
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample9 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample9 tapSet88 Ch1  ISampleSet88 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample06FitlerP, 1408,6/*oSample*/,88/*tapset*/)  //  oSample6 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch0  ISampleSet87 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch1  ISampleSet87 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,87/*tapsSet*/,87/*sampleSet*/)  // oSample11 tapSet87 Ch1  ISampleSet87 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,89/*R0 iSampleSet*/,89/*R1 iSampleSet*/) //  chan0,1 iSampleSet89,89
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample11 tapSet88 Ch1  ISampleSet88 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample08FitlerP, 1408,8/*oSample*/,88/*tapset*/)  //  oSample8 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample6 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,6/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample6 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample6 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,6/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample6 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_lower(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample6 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample06AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,6/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample6 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample6 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample06AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,6/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample6 tapSet89 Ch1  ISampleSet89 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 1408,10/*oSample*/,88/*tapset*/)  //  oSample10 tapSet88,89 iSampleSet88,89
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample8 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,8/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample8 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample8 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,8/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample8 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample8 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,8/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample8 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample8 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,8/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample8 tapSet89 Ch1  ISampleSet89 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample07FitlerP, 1424,7/*oSample*/,89/*tapset*/)  //  oSample7 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch0  ISampleSet88 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch1  ISampleSet88 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,88/*tapsSet*/,88/*sampleSet*/)  // oSample10 tapSet88 Ch1  ISampleSet88 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,90/*R0 iSampleSet*/,90/*R1 iSampleSet*/) //  chan0,1 iSampleSet90,90
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample10 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample10 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample10 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample10 tapSet89 Ch1  ISampleSet89 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1424,9/*oSample*/,89/*tapset*/)  //  oSample9 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample7 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,7/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample7 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample7 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,7/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample7 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_lower(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample7 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample07AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,7/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample7 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample7 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_upper(oSample07AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,7/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample7 tapSet90 Ch1  ISampleSet90 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1424,11/*oSample*/,89/*tapset*/)  //  oSample11 tapSet89,90 iSampleSet89,90
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample9 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample9 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample9 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample9 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample9 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample9 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample9 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample9 tapSet90 Ch1  ISampleSet90 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample08FitlerP, 1440,8/*oSample*/,90/*tapset*/)  //  oSample8 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch0  ISampleSet89 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch1  ISampleSet89 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,89/*tapsSet*/,89/*sampleSet*/)  // oSample11 tapSet89 Ch1  ISampleSet89 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,91/*R0 iSampleSet*/,91/*R1 iSampleSet*/) //  chan0,1 iSampleSet91,91
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample11 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample11 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample11 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample11 tapSet90 Ch1  ISampleSet90 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample10FitlerP, 1440,10/*oSample*/,90/*tapset*/)  //  oSample10 tapSet90,91 iSampleSet90,91
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample8 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,8/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample8 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample8 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,8/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample8 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_lower(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample8 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample08AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,8/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample8 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample8 tapSet91 Ch1  ISampleSet91 
        multiply_and_accum_upper(oSample08AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,8/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample8 tapSet91 Ch1  ISampleSet91 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample09FitlerP, 1456,9/*oSample*/,91/*tapset*/)  //  oSample9 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample10 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M0,10/*oSample*/,0/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample10 tapSet90 Ch0  ISampleSet90 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample10 tapSet90 Ch1  ISampleSet90 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M0,10/*oSample*/,1/*chan*/,90/*tapsSet*/,90/*sampleSet*/)  // oSample10 tapSet90 Ch1  ISampleSet90 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,92/*R0 iSampleSet*/,92/*R1 iSampleSet*/) //  chan0,1 iSampleSet92,92
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample10 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M1,10/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample10 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample10 tapSet91 Ch1  ISampleSet91 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M1,10/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample10 tapSet91 Ch1  ISampleSet91 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1456,11/*oSample*/,91/*tapset*/)  //  oSample11 tapSet91,92 iSampleSet91,92
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample9 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M0,9/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample9 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample9 tapSet91 Ch1  ISampleSet91 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M0,9/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample9 tapSet91 Ch1  ISampleSet91 
        multiply_and_accum_lower(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample9 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample09AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M1,9/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample9 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample9 tapSet92 Ch1  ISampleSet92 
        multiply_and_accum_upper(oSample09AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M1,9/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample9 tapSet92 Ch1  ISampleSet92 
        load_8_filter_taps_autoinc( tapSet_G0_M0, tapSet_G0_M1, oSample10FitlerP, 1472,10/*oSample*/,92/*tapset*/)  //  oSample10 tapSet92,93 iSampleSet92,93
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample11 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample11 tapSet91 Ch0  ISampleSet91 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample11 tapSet91 Ch1  ISampleSet91 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,91/*tapsSet*/,91/*sampleSet*/)  // oSample11 tapSet91 Ch1  ISampleSet91 
        load_8_samples_stereo(iSampleSet_G1_Ch0, iSampleSet_G1_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,93/*R0 iSampleSet*/,93/*R1 iSampleSet*/) //  chan0,1 iSampleSet93,93
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample11 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample11 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample11 tapSet92 Ch1  ISampleSet92 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample11 tapSet92 Ch1  ISampleSet92 
        load_8_filter_taps_autoinc( tapSet_G1_M0, tapSet_G1_M1, oSample11FitlerP, 1488,11/*oSample*/,93/*tapset*/)  //  oSample11 tapSet93,94 iSampleSet93,94
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample10 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G0_Ch0, tapSet_G0_M0,10/*oSample*/,0/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample10 tapSet92 Ch0  ISampleSet92 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample10 tapSet92 Ch1  ISampleSet92 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G0_Ch1, tapSet_G0_M0,10/*oSample*/,1/*chan*/,92/*tapsSet*/,92/*sampleSet*/)  // oSample10 tapSet92 Ch1  ISampleSet92 
        load_8_samples_stereo(iSampleSet_G0_Ch0, iSampleSet_G0_Ch1, inputISampleQueueP,0/*R0 chan*/,1/*R1 chan*/,94/*R0 iSampleSet*/,94/*R1 iSampleSet*/) //  chan0,1 iSampleSet94,94
        mask_pointer(inputISampleQueueP,inputISampleQueueP,inputISampleQueuePMask)    // wrap iSampleSet pointer queue
        multiply_and_accum_lower(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample10 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample10AccumCh0, iSampleSet_G1_Ch0, tapSet_G0_M1,10/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample10 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_lower(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample10 tapSet93 Ch1  ISampleSet93 
        multiply_and_accum_upper(oSample10AccumCh1, iSampleSet_G1_Ch1, tapSet_G0_M1,10/*oSample*/,1/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample10 tapSet93 Ch1  ISampleSet93 
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample11 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G1_Ch0, tapSet_G1_M0,11/*oSample*/,0/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample11 tapSet93 Ch0  ISampleSet93 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample11 tapSet93 Ch1  ISampleSet93 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G1_Ch1, tapSet_G1_M0,11/*oSample*/,1/*chan*/,93/*tapsSet*/,93/*sampleSet*/)  // oSample11 tapSet93 Ch1  ISampleSet93 
        multiply_and_accum_lower(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample11 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_upper(oSample11AccumCh0, iSampleSet_G0_Ch0, tapSet_G1_M1,11/*oSample*/,0/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample11 tapSet94 Ch0  ISampleSet94 
        multiply_and_accum_lower(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample11 tapSet94 Ch1  ISampleSet94 
        multiply_and_accum_upper(oSample11AccumCh1, iSampleSet_G0_Ch1, tapSet_G1_M1,11/*oSample*/,1/*chan*/,94/*tapsSet*/,94/*sampleSet*/)  // oSample11 tapSet94 Ch1  ISampleSet94 
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
extern "C" SsrcSampleRateConverterInterface * construct_SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32(SsrcSampleRateConverterDefinition *returnedInfo)
{
     return SsrcSampleRateConverter_insr_4_outsr_1_taps_336_stereo_SsrcSampleFormat_int32::construct(*returnedInfo);
}
