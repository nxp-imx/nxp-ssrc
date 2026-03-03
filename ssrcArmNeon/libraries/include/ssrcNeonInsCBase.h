/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcNeonInsCBase_h
#define ssrcNeonInsCBase_h
#ifndef USE_ARM_INLINE
#include <cstdint>
#include "ssrcSampleRateConverterConfig.h"
/********************************************************************************
*
*
*******************************************************************************/
struct int32x4_t
{
    union
    {
        int32_t v32[4];
        uint32_t u32[4];
        float vf32[4];
    };
    int32_t &operator[] (int index)
    {
        return v32[index];
    }
};
/********************************************************************************
*
*
*******************************************************************************/
struct float32x4_t
{
    union
    {
        float v32[4];
        uint32_t u32[4];
        int32_t i32[4];
    };
    float &operator[] (int index)
    {
        return v32[index];
    }
};



/********************************************************************************
*
*
*******************************************************************************/
struct int64x2_t
{
    union
    {
        int32_t v32[4];
        int64_t v64[2];
    };
    int32_t &operator[] (int index)
    {
        return v32[index];
    }
};
/********************************************************************************
*
*
*******************************************************************************/
struct NeonInsCBase :
    public SsrcSampleRateConverterInfo
{

    /********************************************************************************
    *
    *
    *******************************************************************************/
    NeonInsCBase()
    {
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void configure(SsrcSampleRateConverterInfo &_resamplerInfo)
    {
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void resetTrace()
    {
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void reset(unsigned startPhase)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceClear(unsigned oSampleNo, unsigned oChannel)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceAcc(int32_t sample, int32_t taps, unsigned oSampleNo, unsigned oChannel,int64_t sum)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceLoadTaps(int32_t tap, unsigned tapNo, unsigned oSampleNo)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceLoadSamples(int32_t sample, unsigned oChannel)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceTransferSamples(int64_t acc, int32_t sample,unsigned offset, unsigned oSampleNo, unsigned oChannel)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceStoreSamples(int32_t sample)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool verify()
    {
        return true;
    }
    /********************************************************************************
    * transfer accumulator to sample output register
    *
    *******************************************************************************/
    virtual void transfer_accumulator_to_sample_register_c(int32x4_t &des, int64x2_t &accum, int offset,unsigned oSample,unsigned chan)
    {
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void sum_accumulator_float32_c(float32x4_t &out, float32x4_t &phaseXAccumChx_0, float32x4_t &phaseXAccumChx_1)
    {
    }
    /********************************************************************************
    * add two 64 bit part of accumulator to generate final accumulator value
    *
    *******************************************************************************/
    virtual void add_two_halfs_of_accumulator_c(int64x2_t &accum, unsigned oSample, unsigned chan)
    {
    }
    /********************************************************************************
    * shift right 64 bit acc by 31 bits to convert acc to 32 bit output
    *
    *******************************************************************************/
    virtual void normalize_accumulator_to_32b_c(int64x2_t &accum, unsigned oSample, unsigned chan)
    {
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void load_8_samples_stereo_c(float32x4_t &ch0, float32x4_t &ch1, float *(&data),unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void load_8_samples_stereo_c(int32x4_t &ch0, int32x4_t &ch1, int32_t *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, int32_t *(&data))
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_interleaved_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_c(float32x4_t &low, float32x4_t &hi, float *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, int32_t *(&data))
    {
    }
    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), int byteOffset,unsigned oSample, unsigned tapSetNo)
    {
    }
    /********************************************************************************
    *load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_c(float32x4_t &low, float32x4_t &hi, float *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
    }
    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_autoinc_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
    }
    /********************************************************************************
    *load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_autoinc_c(float32x4_t &low, float32x4_t &hi, float *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
    }
    /********************************************************************************
    * multiply and accumulate 2 lower samples with 2 lower filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_lower_c(int64x2_t &accum, int32x4_t &sample, int32x4_t &taps , unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
    }
    /********************************************************************************
    * multiply and accumulate 2 lower samples with 2 lower filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_lower_c(float32x4_t &accum, float32x4_t &sample, float32x4_t &taps, unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
    }
    /********************************************************************************
    * multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_upper_c(int64x2_t &accum, int32x4_t &sample, int32x4_t &taps, unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
    }
    /********************************************************************************
    * multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_float32_c(float32x4_t &accum, float32x4_t &sample, float32x4_t &taps, unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
    }
    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(int32x4_t &_out_int32_r_, int32x4_t &_in_float32_r_)
    {
    }
    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(float32x4_t &_out_int32_r_, float32x4_t &_in_float32_r_)
    {
    }
    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(int32x4_t &_out_int32_r_, float32x4_t &_in_float32_r_)
    {
    }

    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(int32x4_t &_out_float32_r_, int32x4_t &_in_int32_r_)
    {

    }

    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(float32x4_t &_out_float32_r_, int32x4_t &_in_int32_r_)
    {

    }
    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(float32x4_t &_out_float32_r_, float32x4_t &_in_int32_r_)
    {

    }

    /********************************************************************************
    * duplicate vector element from input in index to all elements of output
    *
    *******************************************************************************/
    virtual void  duplate_vector_element_float32_c(float32x4_t &_out_float32_v_, float _input_float32_w_)
    {

    }
    /********************************************************************************
    * load floatd32 and increment pointer
    *
    *******************************************************************************/
    virtual void  load_32b_inc_pointer_c(float &_out_float32_r_, float *(&_list_p_))
    {

    }

    /********************************************************************************
    * insert a register value into vector element
    * _out_float32_v_[_output_index_] = _input_float32_r_
    *
    *******************************************************************************/
    virtual void  insert_into_vector_element_float32_c(float32x4_t &_out_float32_v_,int _output_index_, float &_input_float32_r_)
    {

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ &  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_and_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t &_in2_float32_v_)
    {

    }

    /********************************************************************************
    * _out_float32_v_ = _in_float32_v_ ==  [0,0,0,0]
    *
    *******************************************************************************/
    virtual void  four_compare_greater_than_zero_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in_float32_v_)
    {

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ -  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_subtract_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ *  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_multiply_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ +  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_add_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {

    }

    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void mask_pointer_c(int32_t *(&out), int32_t *(&in0), int32_t *(&in1))
    {
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void mask_pointer_c(float *(&out), float *(&in0), float *(&in1))
    {
    }
    /********************************************************************************
    * clear vector register
    *
    *******************************************************************************/
    virtual  void clear_accumulator_c(int64x2_t &reg, unsigned oSample, unsigned oChannel)
    {
    }

    /********************************************************************************
    * clear vector register
    *
    *******************************************************************************/
    virtual  void clear_accumulator_c(float32x4_t &reg, unsigned oSample, unsigned oChannel)
    {
    }

};

/********************************************************************************
*
*
*******************************************************************************/
template <class _SAMPLE_TYPE_,class _ACC_TYPE_> struct AccTrace
{
    unsigned oSampleNo;
    _SAMPLE_TYPE_ sample;
    _ACC_TYPE_ tap;
   bool operator != (AccTrace &other)
   {
       return sample != other.sample ||  tap != other.tap;
   }
};


/********************************************************************************
*
*
*******************************************************************************/
struct NeonExec
{
    static NeonInsCBase *f;
    NeonInsCBase baseNeonInsC;
    NeonExec()
    {
        f = &baseNeonInsC;
    }
    static void setNeonIns(NeonInsCBase &_neonInsC)
    {
        f = &_neonInsC;
    }
    static void setNeonIns(NeonInsCBase *_neonInsC)
    {
        f = _neonInsC;
    }
};
#endif /*USE_ARM_INLINE*/
#endif /*ssrcNeonInsCBase_h*/
