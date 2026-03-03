/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019,2022 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcNeonAssemberDef_h
#define ssrcNeonAssemberDef_h
#ifdef USE_ARM_INLINE
#include <arm_neon.h>
#include <memory.h>
#include <asm/unistd.h>
//#include <memory>



#define STRING_INST(...) #__VA_ARGS__
#define put_char(...) __VA_ARGS__





#define asm_block_start() asm volatile (
#define asm_block_end() );

#define ArmRegister(_REG_) __asm(_REG_)
/********************************************************************************
* transfer accumulator to sample output register
*
*******************************************************************************/
#define transfer_accumulator_to_sample_register(_SampleSet_X_Chx_,_phaseXAccumChx_,_DES_OFFSET_,_OSample_,_Channel_) STRING_INST(MOV     %[_SampleSet_X_Chx_].s[_DES_OFFSET_],%[_phaseXAccumChx_].s[0];\n)

/********************************************************************************
* shift right 64 bit acc by 31 bits to convert acc to 32 bit output
*
*******************************************************************************/
#define normalize_accumulator_to_32b(_phaseXAccumChx_,_OSample_,_Channel_) STRING_INST(SQSHRN   %[_phaseXAccumChx_].2s, %[_phaseXAccumChx_].2d,31;\n)
/********************************************************************************
* add two 64 bit part of accumulator to generate final accumulator value
*
*******************************************************************************/
#define add_two_halfs_of_accumulator(_phaseXAccumChx_, _OSample_,_Channel_) STRING_INST(ADDP   %d[_phaseXAccumChx_], %[_phaseXAccumChx_].2d;\n) //add accumulated two parts of accumulator 
/********************************************************************************
* add accumulator 4 parts 2 at a time 
*  faddp output0,[acc0part0,acc0part1,acc0part2,acc0part3], acc1[acc1part0,acc1part1,acc1part2,acc1part3]
*  output0 = [acc0part0+acc0part1,acc0part2+acc0part3,acc1part0+acc1part1,acc1part2+acc1part3]
*
*  faddp output1,[acc2part0,acc2part1,acc2part2,acc2part3], acc1[acc3part0,acc3part1,acc3part2,acc3part3]
*  output1 = [acc0part2+acc2part1,acc2part2+acc2part3,acc3part0+acc3part1,acc3part2+acc3part3]
*
*  faddp output3,output0, output1
*  output3 = [acc0part2+acc2part1+acc2part2+acc2part3,acc3part0+acc3part1+acc3part2+acc3part3,acc0part2+acc2part1+acc2part2+acc2part3,acc3part0+acc3part1+acc3part2+acc3part3]
*******************************************************************************/
#define sum_accumulator_float32(_out_, _phaseXAccumChx_0_,_phaseXAccumChx_1_,_PHASE_,_CHAN_) STRING_INST(faddp   %[_out_].4s,%[_phaseXAccumChx_0_].4s, %[_phaseXAccumChx_1_].4s;\n) //add accumulated two parts of accumulator 
/********************************************************************************
* load 8 samples from interleaved format for two channels
*
*******************************************************************************/
#define load_8_samples_stereo(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_) STRING_INST(LD2     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* store 8 samples to interleaved format for two channels
*
*******************************************************************************/
#define store_8_samples_interleaved(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) STRING_INST(ST2     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* store 8 samples
*
*******************************************************************************/
#define store_8_samples(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_SampleQueueP_Index_) STRING_INST(ST1     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* store 8 samples
*
*******************************************************************************/
#define store_8_samples_queue(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) STRING_INST(ST1     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* load 8 samples for single channel
*
*******************************************************************************/
#define load_8_samples(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_) STRING_INST(LD1     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* load 8 samples for single channel 
*
*******************************************************************************/
#define load_8_samples_queue(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) STRING_INST(LD1     {%[_Samples_X_Ch0_].4s,%[_Samples_X_Ch1_].4s},[%[_SampleQueueP_]],32;\n)
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_nontemporal(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) STRING_INST(LDNP    %q[_Phase_x_Coef_x_],%q[_Phase_x_Coef_y_],[%[_phasexxFitlerP_],_OFFSET_];\n)
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_autoinc(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) STRING_INST(LD1    {%[_Phase_x_Coef_x_].4s,%[_Phase_x_Coef_y_].4s},[%[_phasexxFitlerP_]],32;\n)
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_temporal(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) STRING_INST(LDP    %q[_Phase_x_Coef_x_],%q[_Phase_x_Coef_y_],[%[_phasexxFitlerP_],_OFFSET_];\n)
/********************************************************************************
* load register from pointer and increment pointer
*
*******************************************************************************/
#define load_32b_inc_pointer(_out_r_,_dataP_) STRING_INST(LDR %w[_out_r_], [%[_dataP_]],4;\n)
/********************************************************************************
* multiply and accumulate 2 lower samples with 2 lower filter coeff into a phase accumulator register
*
*******************************************************************************/
#define multiply_and_accum_lower(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_Channel_,_TapSetNo_,_ISampleSetNo_) STRING_INST(SMLAL     %[_phasexxAccum_].2d,%[_Samples_x_Chx_].2s,%[Phase_x_Coef_x].2s;\n)

/********************************************************************************
* multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
*
*******************************************************************************/
#define multiply_and_accum_upper(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_Channel_,_TapSetNo_,_ISampleSetNo_) STRING_INST(SMLAL2    %[_phasexxAccum_].2d,%[_Samples_x_Chx_].4s,%[Phase_x_Coef_x].4s;\n)
/********************************************************************************
* multiply and accumulate 4 samples and four coeff
*
*******************************************************************************/
#define multiply_and_accum_float32(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_Channel_,_TapSetNo_,_ISampleSetNo_) STRING_INST(FMLA     %[_phasexxAccum_].4s,%[_Samples_x_Chx_].4s,%[Phase_x_Coef_x].4s;\n)
/********************************************************************************
* load 8 samples from interleaved format for two channels
*
*******************************************************************************/
#define mask_pointer(_Output_,_InputA_,_InputB_) STRING_INST(AND      %[_Output_],%[_InputA_],%[_InputB_];\n)

/********************************************************************************
* clear vector register
*
*******************************************************************************/
#define clear_accumulator(_Output_,_OSample_,_Channel_) STRING_INST(MOVI    %[_Output_].2d,0;\n)
/********************************************************************************
* convert four float32 to int32
*
*******************************************************************************/
#define four_float32_to_int32(_out_int32_v_,_in_float32_v_) STRING_INST(FCVTAS     %[_out_int32_v_].4s,%[_in_float32_v_].4s;\n)

/********************************************************************************
* convert four int32 to float32
*
*******************************************************************************/
#define four_int32_to_float32(_out_float32_v_,_in_int32_v_) STRING_INST(SCVTF     %[_out_float32_v_].4s,%[_in_int32_v_].4s;\n)

/********************************************************************************
* duplicate vector element from input in index to all elements of output
*
*******************************************************************************/
#define duplate_vector_element_float32(_out_float32_v_,_input_float32_x_) STRING_INST(DUP     %[_out_float32_v_].4s,%w[_input_float32_x_];\n)
/********************************************************************************
* insert a register value into vector element 
* _out_float32_v_[_output_index_] = _input_float32_r_
*
*******************************************************************************/
#define insert_into_vector_element_float32(_out_float32_v_,_output_index_,_input_float32_r_) STRING_INST(INS     %[_out_float32_v_].4s[_output_index_],%[_input_float32_r_].4s;\n)
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ &  _in2_float32_v_
*
*******************************************************************************/
#define four_and_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) STRING_INST(AND     %[_out_float32_v_].16b,%[_in1_float32_v_].16b,%[_in2_float32_v_].16b;\n)

/********************************************************************************
* _out_float32_v_ = _in_float32_v_ ==  [0,0,0,0]
*
*******************************************************************************/
#define four_compare_greater_than_zero_float32(_out_float32_v_,_in_float32_v_) STRING_INST(FCMGT     %[_out_float32_v_].4s,%[_in_float32_v_].4s,0;\n)
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ -  _in2_float32_v_
*
*******************************************************************************/
#define four_subtract_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) STRING_INST(FSUB     %[_out_float32_v_].4s,%[_in1_float32_v_].4s,%[_in2_float32_v_].4s;\n)
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ +  _in2_float32_v_
*
*******************************************************************************/
#define four_add_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) STRING_INST(FADD     %[_out_float32_v_].4s,%[_in1_float32_v_].4s,%[_in2_float32_v_].4s;\n)
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ *  _in2_float32_v_
*
*******************************************************************************/
#define four_multiply_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) STRING_INST(FMUL     %[_out_float32_v_].4s,%[_in1_float32_v_].4s,%[_in2_float32_v_].4s;\n)

/********************************************************************************
* asm vector register usage
*
*******************************************************************************/
#define asm_vector_usage_output(_Vector_) [_Vector_] "+w" (_Vector_) 

/********************************************************************************
* asm vector register usage
*
*******************************************************************************/
#define asm_register_usage_output(_Register_) [_Register_] "+r" (_Register_) 

#endif /*USE_ARM_INLINE*/
#endif /* ssrcNeonAssemberDef_h */
