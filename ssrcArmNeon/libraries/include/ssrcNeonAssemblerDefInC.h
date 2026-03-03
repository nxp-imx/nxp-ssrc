/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcNeonAssemberDef_h
#define ssrcNeonAssemberDef_h
#ifndef USE_ARM_INLINE
#include <cstdint>
#include <memory.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <malloc.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>   
#include <sstream>
#include <iostream>
#include <iomanip>


#include "ssrcSampleRateConverterConfig.h"
#include "ssrcNeonInsCBase.h"

using namespace std;





/********************************************************************************
*
*
*******************************************************************************/
struct NeonInsC :
    public NeonInsCBase
{

    /********************************************************************************
    *
    *
    *******************************************************************************/
    NeonInsC()
    {
        reset(0);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void configure(SsrcSampleRateConverterInfo &_resamplerInfo)
    {
        SsrcSampleRateConverterInfo &resamplerInfo = static_cast<SsrcSampleRateConverterInfo &>(*this);
        resamplerInfo = _resamplerInfo;
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
    virtual void traceAcc(int32_t sample, int32_t taps, unsigned oSampleNo, unsigned oChannel, int64_t sum)
    {

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceAcc(float sample, float taps, unsigned oSampleNo, unsigned oChannel, float sum)
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
    virtual void traceLoadTaps(float tap, unsigned tapNo, unsigned oSampleNo)
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
    virtual void traceLoadSamples(float sample, unsigned oChannel)
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
    virtual void traceStoreSamples(float sample)
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
    *
    *
    *******************************************************************************/
    virtual void fillFilterWithSequence(SsrcSampleRateConverterInterface &ssrc)
    {

    }
    /********************************************************************************
    * transfer accumulator to sample output register
    *
    *******************************************************************************/
    virtual void transfer_accumulator_to_sample_register_c(int32x4_t &des, int64x2_t &accum, int offset,unsigned oSample,unsigned chan)
    {
        des[offset] = accum.v32[0];
        traceTransferSamples(accum.v64[0], des[offset],offset, oSample, chan);
    }
    /********************************************************************************
    * add accumulator 4 parts 2 at a time
    *******************************************************************************/
    virtual void sum_accumulator_float32_c(float32x4_t &out, float32x4_t &phaseXAccumChx_0, float32x4_t &phaseXAccumChx_1)
    {
        float32x4_t sum;
        sum[0] = phaseXAccumChx_0[0] + phaseXAccumChx_0[1];
        sum[1] = phaseXAccumChx_0[2] + phaseXAccumChx_0[3];
        sum[2] = phaseXAccumChx_1[0] + phaseXAccumChx_1[1];
        sum[3] = phaseXAccumChx_1[2] + phaseXAccumChx_1[3];
        out = sum;
    }
    /********************************************************************************
   * add two 64 bit part of accumulator to generate final accumulator value
   *
   *******************************************************************************/
    virtual void add_two_halfs_of_accumulator_c(int64x2_t &accum, unsigned oSample, unsigned chan)
    {
        int64_t sum = accum.v64[0] + accum.v64[1];
        accum.v64[0] = sum;
    }
    /********************************************************************************
    * shift right 64 bit acc by 31 bits to convert acc to 32 bit output
    *
    *******************************************************************************/
    virtual void normalize_accumulator_to_32b_c(int64x2_t &accum, unsigned oSample, unsigned chan)
    {
        int64_t norm = accum.v64[0] >> 31;
        int32_t output = (int32_t)(norm > INT32_MAX ? INT32_MAX : (norm < INT32_MIN ? INT32_MIN : norm));
        accum.v32[0] = output;
        accum.v32[1] = 0;
        norm = accum.v64[1] >> 31;
        output = (int32_t)(norm > INT32_MAX ? INT32_MAX : (norm < INT32_MIN ? INT32_MIN : norm));
        accum.v32[2] = output;
        accum.v32[3] = 0;

    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void load_8_samples_stereo_c(int32x4_t &ch0, int32x4_t &ch1, int32_t *(&data),unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            ch0[index] = *data++;
            traceLoadSamples(ch0[index], 0);
            ch1[index] = *data++;
            traceLoadSamples(ch1[index], 1);
        }
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void load_8_samples_stereo_c(float32x4_t &ch0, float32x4_t &ch1, float *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            ch0[index] = *data++;
            traceLoadSamples(ch0[index], 0);
            ch1[index] = *data++;
            traceLoadSamples(ch1[index], 1);
        }
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low[index];
            traceStoreSamples(low[index]);
        }
        for (int index = 0; index < 4; index++)
        {
            *data++ = hi[index];
            traceStoreSamples(hi[index]);
        }
    }
    /********************************************************************************
   * store 8 samples
   *
   *******************************************************************************/
    virtual  void store_8_samples_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low[index];
            traceStoreSamples(low[index]);
        }
        for (int index = 0; index < 4; index++)
        {
            *data++ = hi[index];
            traceStoreSamples(hi[index]);
        }
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, int32_t *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low.i32[index];
        }
        for (int index = 0; index < 4; index++)
        {
            *data++ = hi.i32[index];
        }
    }
    /********************************************************************************
    * store 8 samples interleaved
    *
    *******************************************************************************/
    virtual  void store_8_samples_interleaved_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low[index];
            *data++ = hi[index];
        }

    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low[index];
        }
        for (int index = 0; index < 4; index++)
        {
            *data++ = hi[index];
        }
    }
    /********************************************************************************
    * store 8 samples
    *
    *******************************************************************************/
    virtual  void store_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            *data++ = low[index];
        }
        for (int index = 0; index < 4; index++)
        {
            *data++ = hi[index];
        }
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
            traceLoadSamples(low[index], 0);
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
            traceLoadSamples(hi[index], 0);
        }
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_c(float32x4_t &low, float32x4_t &hi, float *(&data), unsigned r0Chan, unsigned r1Chan, unsigned r0SampleSetNo, unsigned r1SampleSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
            traceLoadSamples(low[index], 0);
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
            traceLoadSamples(hi[index], 0);
        }
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
        }
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, float *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
        }
    }
    /********************************************************************************
    * load 8 samples for single channel
    *
    *******************************************************************************/
    virtual  void load_8_samples_queue_c(float32x4_t &low, float32x4_t &hi, int32_t *(&data))
    {
        for (int index = 0; index < 4; index++)
        {
            low.i32[index] = *data++;
        }
        for (int index = 0; index < 4; index++)
        {
            hi.i32[index] = *data++;
        }
    }
    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), int byteOffset,unsigned oSample, unsigned tapSetNo)
    {
        int offset = byteOffset / sizeof(int32_t);
        for (int index = 0; index < 4; index++)
        {
            low[index] = data[index + offset];
            traceLoadTaps(low[index], index + offset, oSample);
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = data[index + 4 + offset];
            traceLoadTaps(hi[index], index + 4 + offset, oSample);
        }
    }
    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_c(float32x4_t &low, float32x4_t &hi, float *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
        int offset = byteOffset / sizeof(int32_t);
        for (int index = 0; index < 4; index++)
        {
            low[index] = data[index + offset];
            traceLoadTaps(low[index], index + offset, oSample);
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = data[index + 4 + offset];
            traceLoadTaps(hi[index], index + 4 + offset, oSample);
        }
    }




    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_autoinc_c(int32x4_t &low, int32x4_t &hi, int32_t *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
        }
    }
    /********************************************************************************
    * load 2x4 filter coefficients from one phase
    *
    *******************************************************************************/
    virtual  void load_8_filter_taps_autoinc_c(float32x4_t &low, float32x4_t &hi, float *(&data), int byteOffset, unsigned oSample, unsigned tapSetNo)
    {
        for (int index = 0; index < 4; index++)
        {
            low[index] = *data++;
        }
        for (int index = 0; index < 4; index++)
        {
            hi[index] = *data++;
        }
    }







    /********************************************************************************
    * multiply and accumulate 2 lower samples with 2 lower filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_lower_c(int64x2_t &accum, int32x4_t &sample, int32x4_t &taps , unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
        accum.v64[0] = accum.v64[0] + (int64_t)sample[0] * (int64_t)taps[0];
        traceAcc(sample[0], taps[0], oSample, oChannel, accum.v64[0]);
        accum.v64[0] = accum.v64[0] + (int64_t)sample[1] * (int64_t)taps[1];;
        traceAcc(sample[1], taps[1], oSample, oChannel, accum.v64[0]);
    }
    /********************************************************************************
    * multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_upper_c(int64x2_t &accum, int32x4_t &sample, int32x4_t &taps, unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
        accum.v64[1] = accum.v64[1] + (int64_t)sample[2] * (int64_t)taps[2];
        traceAcc(sample[2], taps[2], oSample, oChannel, accum.v64[1]);
        accum.v64[1] = accum.v64[1] + (int64_t)sample[3] * (int64_t)taps[3];
        traceAcc(sample[3], taps[3], oSample, oChannel, accum.v64[1]);
    }
    /********************************************************************************
    * multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
    *
    *******************************************************************************/
    virtual  void multiply_and_accum_float32_c(float32x4_t &accum, float32x4_t &sample, float32x4_t &taps, unsigned oSample, unsigned oChannel, unsigned tapSetNo, unsigned sampleSetNo)
    {
        accum[0] += sample[0] * taps[0];
        traceAcc(sample[0], taps[0], oSample, oChannel, accum[0]);
        accum[1] += sample[1] * taps[1];
        traceAcc(sample[1], taps[1], oSample, oChannel, accum[1]);
        accum[2] += sample[2] * taps[2];
        traceAcc(sample[2], taps[2], oSample, oChannel, accum[2]);
        accum[3] += sample[3] * taps[3];
        traceAcc(sample[3], taps[3], oSample, oChannel, accum[3]);
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void mask_pointer_c(int32_t *(&out), int32_t *(&in0), int32_t *(&in1))
    {
        uint64_t int0_u = (uint64_t)in0;
        uint64_t int1_u = (uint64_t)in1;
        uint64_t out_u = int0_u & int1_u;
        out = (int32_t *)(out_u);
    }
    /********************************************************************************
    * load 8 samples from interleaved format for two channels
    *
    *******************************************************************************/
    virtual void  mask_pointer_c(float *(&out), float *(&in0), float *(&in1))
    {
        uint64_t int0_u = (uint64_t)in0;
        uint64_t int1_u = (uint64_t)in1;
        uint64_t out_u = int0_u & int1_u;
        out = (float *)(out_u);
    }
    /********************************************************************************
    * clear vector register
    *
    *******************************************************************************/
    virtual  void clear_accumulator_c(int64x2_t &reg, unsigned oSample, unsigned oChannel)
    {
        reg[0] = reg[1] = reg[2] = reg[3] = 0;
    }
    /********************************************************************************
    * clear vector register
    *
    *******************************************************************************/
    virtual  void clear_accumulator_c(float32x4_t &reg, unsigned oSample, unsigned oChannel)
    {
        reg[0] = reg[1] = reg[2] = reg[3] = 0;
    }

    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(int32x4_t _out_int32_r_, int32x4_t _in_float32_r_)
    {
        _out_int32_r_[0] = (int32_t)_in_float32_r_.vf32[0];
        _out_int32_r_[1] = (int32_t)_in_float32_r_.vf32[1];
        _out_int32_r_[2] = (int32_t)_in_float32_r_.vf32[2];
        _out_int32_r_[3] = (int32_t)_in_float32_r_.vf32[3];
    }
    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(int32x4_t &_out_int32_r_, float32x4_t &_in_float32_r_)
    {
        _out_int32_r_[0] = (int32_t)_in_float32_r_[0];
        _out_int32_r_[1] = (int32_t)_in_float32_r_[1];
        _out_int32_r_[2] = (int32_t)_in_float32_r_[2];
        _out_int32_r_[3] = (int32_t)_in_float32_r_[3];
    }
    /********************************************************************************
    * convert four float32 to int32
    *
    *******************************************************************************/
    virtual  void  four_float32_to_int32_c(float32x4_t &_out_int32_r_, float32x4_t &_in_float32_r_)
    {
        _out_int32_r_.i32[0] = (int32_t)_in_float32_r_[0];
        _out_int32_r_.i32[1] = (int32_t)_in_float32_r_[1];
        _out_int32_r_.i32[2] = (int32_t)_in_float32_r_[2];
        _out_int32_r_.i32[3] = (int32_t)_in_float32_r_[3];
    }
    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(int32x4_t &_out_float32_r_, int32x4_t &_in_int32_r_)
    {
        _out_float32_r_.vf32[0] = (float)_in_int32_r_[0];
        _out_float32_r_.vf32[1] = (float)_in_int32_r_[1];
        _out_float32_r_.vf32[2] = (float)_in_int32_r_[2];
        _out_float32_r_.vf32[3] = (float)_in_int32_r_[3];

    }

    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(float32x4_t &_out_float32_r_, int32x4_t &_in_int32_r_)
    {
        _out_float32_r_[0] = (float)_in_int32_r_[0];
        _out_float32_r_[1] = (float)_in_int32_r_[1];
        _out_float32_r_[2] = (float)_in_int32_r_[2];
        _out_float32_r_[3] = (float)_in_int32_r_[3];

    }

    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(float32x4_t &_out_float32_r_, float32x4_t &_in_int32_r_)
    {
        _out_float32_r_[0] = (float)_in_int32_r_.i32[0];
        _out_float32_r_[1] = (float)_in_int32_r_.i32[1];
        _out_float32_r_[2] = (float)_in_int32_r_.i32[2];
        _out_float32_r_[3] = (float)_in_int32_r_.i32[3];

    }

    /********************************************************************************
    * convert four int32 to float32
    *
    *******************************************************************************/
    virtual void four_int32_to_float32_c(int32x4_t _out_float32_r_, int32x4_t _in_int32_r_)
    {
        _out_float32_r_.vf32[0] = (float)_in_int32_r_[0];
        _out_float32_r_.vf32[1] = (float)_in_int32_r_[1];
        _out_float32_r_.vf32[2] = (float)_in_int32_r_[2];
        _out_float32_r_.vf32[3] = (float)_in_int32_r_[3];

    }
    /********************************************************************************
    * duplicate vector element from input in index to all elements of output
    *
    *******************************************************************************/
    virtual void  duplate_vector_element_float32_c(float32x4_t &_out_float32_v_, float _input_float32_w_)
    {
        _out_float32_v_.v32[0] = _input_float32_w_;
        _out_float32_v_.v32[1] = _input_float32_w_;
        _out_float32_v_.v32[2] = _input_float32_w_;
        _out_float32_v_.v32[3] = _input_float32_w_;

    }
    /********************************************************************************
    * load flaotd32 and increment pointer
    *
    *******************************************************************************/
    virtual void  load_32b_inc_pointer_c(float &_out_float32_r_, float *(&_list_p_))
    {
        _out_float32_r_ = *_list_p_++;
    }

    /********************************************************************************
    * insert a register value into vector element
    * _out_float32_v_[_output_index_] = _input_float32_r_
    *
    *******************************************************************************/
    virtual void  insert_into_vector_element_float32_c(float32x4_t &_out_float32_v_, int _output_index_, float &_input_float32_r_)
    {
        _out_float32_v_.v32[_output_index_] = _input_float32_r_;

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ &  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_and_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t &_in2_float32_v_)
    {
        _out_float32_v_.u32[0] = _in1_float32_v_.u32[0] & _in2_float32_v_.u32[0];
        _out_float32_v_.u32[1] = _in1_float32_v_.u32[1] & _in2_float32_v_.u32[1];
        _out_float32_v_.u32[2] = _in1_float32_v_.u32[2] & _in2_float32_v_.u32[2];
        _out_float32_v_.u32[3] = _in1_float32_v_.u32[3] & _in2_float32_v_.u32[3];
    }

    /********************************************************************************
    * _out_float32_v_ = _in_float32_v_ ==  [0,0,0,0]
    *
    *******************************************************************************/
    virtual void  four_compare_greater_than_zero_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in_float32_v_)
    {
        _out_float32_v_.u32[0] = _in_float32_v_[0] > 0 ? 0xffffffff : 0;
        _out_float32_v_.u32[1] = _in_float32_v_[1] > 0 ? 0xffffffff : 0;
        _out_float32_v_.u32[2] = _in_float32_v_[2] > 0 ? 0xffffffff : 0;
        _out_float32_v_.u32[3] = _in_float32_v_[3] > 0 ? 0xffffffff : 0;

    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ -  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_subtract_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {
        _out_float32_v_[0] = _in1_float32_v_[0] - _in2_float32_v_[0];
        _out_float32_v_[1] = _in1_float32_v_[1] - _in2_float32_v_[1];
        _out_float32_v_[2] = _in1_float32_v_[2] - _in2_float32_v_[2];
        _out_float32_v_[3] = _in1_float32_v_[3] - _in2_float32_v_[3];
    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ -  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_add_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {
        _out_float32_v_[0] = _in1_float32_v_[0] + _in2_float32_v_[0];
        _out_float32_v_[1] = _in1_float32_v_[1] + _in2_float32_v_[1];
        _out_float32_v_[2] = _in1_float32_v_[2] + _in2_float32_v_[2];
        _out_float32_v_[3] = _in1_float32_v_[3] + _in2_float32_v_[3];
    }
    /********************************************************************************
    * _out_float32_v_ = _in1_float32_v_ *  _in2_float32_v_
    *
    *******************************************************************************/
    virtual void  four_multiply_float32_c(float32x4_t &_out_float32_v_, float32x4_t & _in1_float32_v_, float32x4_t & _in2_float32_v_)
    {
        _out_float32_v_[0] = _in1_float32_v_[0] * _in2_float32_v_[0];
        _out_float32_v_[1] = _in1_float32_v_[1] * _in2_float32_v_[1];
        _out_float32_v_[2] = _in1_float32_v_[2] * _in2_float32_v_[2];
        _out_float32_v_[3] = _in1_float32_v_[3] * _in2_float32_v_[3];
    }


};


/********************************************************************************
*
*
*******************************************************************************/
template <class _SAMPLE_TYPE_,class _ACC_TYPE_> struct NeonInsCTrace :
    NeonInsC
{
    vector<vector<AccTrace<_SAMPLE_TYPE_, _ACC_TYPE_>>> traceListCh[2];
    vector<unsigned> currrentIndex[2];
    unsigned phase;
    unsigned startSampleIndex;
    ofstream traceFile;
    unsigned oSampleNo;
    unsigned sampleGroupNo;
    /********************************************************************************
    *
    *
    *******************************************************************************/
    NeonInsCTrace(SsrcSampleRateConverterInfo &config):
        NeonInsC()
    {
        configure(config);
        traceListCh[0].resize(numOutputSamplesPerChanPerRun);
        traceListCh[1].resize(numOutputSamplesPerChanPerRun);
        currrentIndex[0].resize(numOutputSamplesPerChanPerRun);
        currrentIndex[1].resize(numOutputSamplesPerChanPerRun);
        for (unsigned index = 0; index < numOutputSamplesPerChanPerRun; index++)
        {
            traceListCh[0][index].resize(numberOfSamplesUsedPerRunPerChan);
            traceListCh[1][index].resize(numberOfSamplesUsedPerRunPerChan);
            currrentIndex[0][index] = 0;
            currrentIndex[1][index] = 0;
        }
        reset(0);
        traceFile.open("tracefile.txt", ofstream::out);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void reset(unsigned startPhase)
    {
        phase = startPhase;
        startSampleIndex = 0;
        oSampleNo = 0;
        sampleGroupNo = 0;
        for (unsigned index = 0; index < numOutputSamplesPerChanPerRun; index++)
        {
            currrentIndex[0][index] = 0;
            currrentIndex[1][index] = 0;
        }
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void resetTrace()
    {
        for (unsigned index = 0; index < numOutputSamplesPerChanPerRun; index++)
        {
            currrentIndex[0][index] = 0;
            currrentIndex[1][index] = 0;
        }
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceAcc(_SAMPLE_TYPE_ sample, _SAMPLE_TYPE_ taps, unsigned oSampleNo, unsigned oChannel, _ACC_TYPE_ sum)
    {
        AccTrace< _SAMPLE_TYPE_, _ACC_TYPE_> trace;
        trace.sample = sample;
        trace.tap = taps;
        trace.oSampleNo = oSampleNo;
        traceListCh[oChannel][oSampleNo][currrentIndex[oChannel][oSampleNo]++] = trace;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void error(AccTrace < _SAMPLE_TYPE_, _ACC_TYPE_> &expected, AccTrace < _SAMPLE_TYPE_, _ACC_TYPE_> &got)
    {
        traceFile << "expected >";
        expected.print(traceFile);
        traceFile << endl;

        traceFile << "got      >";
        got.print(traceFile);
        traceFile << endl;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool verify()
    {
        for (unsigned oSample = 0; oSample < numOutputSamplesPerChanPerRun; oSample++, oSampleNo++)
        {
            unsigned  tapIndex = 0;
            unsigned  sampleIndex = startSampleIndex;
            for (int chan = 0; chan < (1 + stereo); chan++)
            {
                size_t size = traceListCh[chan][oSample].size();
                for (unsigned index = 0; index < size && tapIndex < numberOftapsPerPhase; index++)
                {
                   AccTrace< _SAMPLE_TYPE_, _ACC_TYPE_> &got = traceListCh[chan][oSample][index];
                    if (got.tap >= 0)
                    {
                        AccTrace < _SAMPLE_TYPE_, _ACC_TYPE_> expected;
                        expected.sample = (_SAMPLE_TYPE_)sampleIndex;
                        expected.tap = (_SAMPLE_TYPE_)tapIndex;
                        expected.oSampleNo = oSampleNo;

                        bool equal = (expected != got);

                        traceFile << sampleGroupNo << ',' << got.oSampleNo << ',' << got.sample << ',' << got.tap << ',' << expected.oSampleNo << ',' << expected.sample << ',' << expected.tap << ',' << equal << endl;

                        sampleIndex++;
                        tapIndex++;
                    }
                }
            }
            phase = phase + sampleRateRatioInput;
            startSampleIndex += phase / sampleRateRatioOutput;
            phase = phase % sampleRateRatioOutput;
        }
        sampleGroupNo++;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void fillFilterWithSequence(SsrcSampleRateConverterInterface &ssrc)
    {
        SsrcFilterInfo filterInfo;
        ssrc.getFilterInfo(filterInfo);
        _SAMPLE_TYPE_ *filterTaps = (_SAMPLE_TYPE_ *)filterInfo.filterTaps;
        for (unsigned phase = 0; phase < filterInfo.numberOfPhases; phase++)
        {
            int tap = phase * filterInfo.totalNumberOfTaps;
            for (unsigned index = 0; index < filterInfo.numberOfZeroExtension; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index - (_SAMPLE_TYPE_)filterInfo.numberOfZeroExtension;
                filterTaps[tap] = setting;
            }
            for (unsigned index = 0; index < filterInfo.numberOfTaps; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index;
                filterTaps[tap] = setting;
            }
            for (unsigned index = 0; index < filterInfo.numberOfZeroExtension; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index - (_SAMPLE_TYPE_)filterInfo.numberOfZeroExtension;
                filterTaps[tap] = setting;
            }
        }
    }
};

/********************************************************************************
*
*
*******************************************************************************/
template <class _SAMPLE_TYPE_, class _ACC_TYPE_>  struct NeonInsCTraceFile :
    NeonInsC
{
    ofstream outFileAcc;
    ofstream outFileInSample;
    ofstream outFileFitlerTaps;
    ofstream outFileosampleTransfer;
    ofstream outFileosample;

    struct AccFileTrace
    {
        _SAMPLE_TYPE_ sample;
        _SAMPLE_TYPE_ tap;
        _ACC_TYPE_ sum;
    };
    struct OsampleFileTrace
    {
        _ACC_TYPE_ acc;
        _SAMPLE_TYPE_ sample;
    };

    vector<_SAMPLE_TYPE_> isampleTraceData[2];
    unsigned isampleCurrentIndex[2];

    vector<OsampleFileTrace> osampleTransferTraceData[2];
    unsigned osampleTRasnferCurrentIndex[2];

    vector<_SAMPLE_TYPE_> osampleTraceData;
    unsigned osampleCurrentIndex;

    vector<vector<AccFileTrace>> accTraceListCh[2];
    vector<unsigned> accCurrentIndex[2];

    vector<vector<_SAMPLE_TYPE_>> tapTraceList;
    vector<unsigned> tapCurrentIndex;
    int traceChan;
    unsigned maxAccIndex;
     /********************************************************************************
    *
    *
    *******************************************************************************/
    NeonInsCTraceFile()
    {

    }
   /********************************************************************************
    *
    *
    *******************************************************************************/
    void configure(SsrcSampleRateConverterInfo &config)
    {
        NeonInsC::configure(config);

        outFileAcc.open("accTRace.csv");
        outFileInSample.open("inSample.csv");
        outFileFitlerTaps.open("filterTaps.csv");
        outFileosampleTransfer.open("outSampleTransfer.csv");
        outFileosample.open("outsample.csv");
        accTraceListCh[0].resize(numOutputSamplesPerChanPerRun);
        accTraceListCh[1].resize(numOutputSamplesPerChanPerRun);
        accCurrentIndex[0].resize(numOutputSamplesPerChanPerRun);
        accCurrentIndex[1].resize(numOutputSamplesPerChanPerRun);
        
        tapTraceList.resize(numOutputSamplesPerChanPerRun);
        tapCurrentIndex.resize(numOutputSamplesPerChanPerRun);

        isampleTraceData[0].resize(numberOfSamplesUsedPerRunPerChan);
        isampleTraceData[1].resize(numberOfSamplesUsedPerRunPerChan);
        isampleCurrentIndex[0] = 0;
        isampleCurrentIndex[1] = 0;

        osampleTransferTraceData[0].resize(numOutputSamplesPerChanPerRun);
        osampleTransferTraceData[1].resize(numOutputSamplesPerChanPerRun);
        osampleTRasnferCurrentIndex[0] = 0;
        osampleTRasnferCurrentIndex[1] = 0;

        osampleTraceData.resize(totalNumOutputSamplesPerRun+16);
        osampleCurrentIndex = 0;

        for (unsigned index = 0; index < numOutputSamplesPerChanPerRun; index++)
        {
            accTraceListCh[0][index].resize(numberOfSamplesUsedPerRunPerChan);
            accTraceListCh[1][index].resize(numberOfSamplesUsedPerRunPerChan);
            accCurrentIndex[0][index] = 0;
            accCurrentIndex[1][index] = 0;


            tapTraceList[index].resize(numberOfSamplesUsedPerRunPerChan);
            tapCurrentIndex[index] = 0;

        }
        traceChan = 0;
        maxAccIndex = 0;
    }
    ~NeonInsCTraceFile()
    {
        outFileAcc.close();
        outFileInSample.close();
        outFileFitlerTaps.close();
        outFileosampleTransfer.close();
        outFileosample.close();
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void resetTrace()
    {
        isampleCurrentIndex[0] = 0;
        isampleCurrentIndex[1] = 0;
        osampleTRasnferCurrentIndex[0] = 0;
        osampleTRasnferCurrentIndex[1] = 0;
        osampleCurrentIndex = 0;
        maxAccIndex = 0;
        for (unsigned index = 0; index < numOutputSamplesPerChanPerRun; index++)
        {
            accCurrentIndex[0][index] = 0;
            accCurrentIndex[1][index] = 0;
            tapCurrentIndex[index] = 0;
        }
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool verify()
    {
        for (unsigned oSampleNo = 0; oSampleNo < numOutputSamplesPerChanPerRun; oSampleNo++)
        {
            for (unsigned oChannel = 0; oChannel < numberOfChannels; oChannel++)
            {
                outFileAcc << "ch_" << oChannel << "_o_" << oSampleNo << "_sum,";
                outFileAcc << "ch_" << oChannel << "_o_" << oSampleNo << "_tap,";
                outFileAcc << "ch_" << oChannel << "_o_" << oSampleNo << "_sam,";
            }
        }
        outFileAcc << endl;
        for (unsigned index = 0; index < maxAccIndex; index++)
        {
            for (unsigned oSampleNo = 0; oSampleNo < numOutputSamplesPerChanPerRun; oSampleNo++)
            {
                for (unsigned oChannel = 0; oChannel < numberOfChannels; oChannel++)
                {
                    if (index < accCurrentIndex[oChannel][oSampleNo])
                    {
                        AccFileTrace &trace = accTraceListCh[oChannel][oSampleNo][index];
                        outFileAcc << std::setprecision(13) << trace.sum << ',' << std::setprecision(13) << trace.tap << ',' << std::setprecision(13) << trace.sample << ',';
                    }
                    else
                    {
                        outFileAcc << "    ," <<"    ," << "      ,";

                    }
                }
                if (index < tapCurrentIndex[oSampleNo])
                {
                    outFileFitlerTaps << tapTraceList[oSampleNo][index] << ',';
                }
            }
            outFileAcc << endl;
            outFileFitlerTaps << endl;
        }
        for (unsigned oSampleNo = 0; oSampleNo < numOutputSamplesPerChanPerRun; oSampleNo++)
        {
            for (unsigned oChannel = 0; oChannel < numberOfChannels; oChannel++)
            {
                OsampleFileTrace &trace = osampleTransferTraceData[oChannel][oSampleNo];
                outFileAcc << trace.acc << ',' << std::setprecision(13) << trace.sample << ',' << "  " << ',';
            }
        }
        outFileAcc << endl;
        return true;
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
    virtual void traceAcc(_SAMPLE_TYPE_ sample, _SAMPLE_TYPE_ taps, unsigned oSampleNo, unsigned oChannel, _ACC_TYPE_ sum)
    {
        AccFileTrace trace;
        trace.sample = sample;
        trace.tap = taps;
        trace.sum = sum;
        accTraceListCh[oChannel][oSampleNo][accCurrentIndex[oChannel][oSampleNo]++] = trace;
        maxAccIndex = (maxAccIndex > accCurrentIndex[oChannel][oSampleNo]? maxAccIndex : accCurrentIndex[oChannel][oSampleNo]);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceLoadTaps(_SAMPLE_TYPE_ tap, unsigned tapNo, unsigned oSampleNo)
    {
        tapTraceList[oSampleNo][tapCurrentIndex[oSampleNo]++] = tap;

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceLoadSamples(_SAMPLE_TYPE_ sample, unsigned oChannel)
    {
        isampleTraceData[oChannel][isampleCurrentIndex[oChannel]++] = sample;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceTransferSamples(_ACC_TYPE_ acc, _SAMPLE_TYPE_ sample, unsigned offset, unsigned oSampleNo, unsigned oChannel)
    {
        OsampleFileTrace trace;
        trace.acc = acc;
        trace.sample = sample;
        osampleTransferTraceData[oChannel][osampleTRasnferCurrentIndex[oChannel]++] = trace;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void traceStoreSamples(_SAMPLE_TYPE_ sample)
    {
        if (false)
        {
            if (traceChan == (numberOfChannels - 1))
            {
                traceChan = 0;
                outFileosample << std::setprecision(13) << sample << endl;
            }
            else
            {
                traceChan++;
                outFileosample << std::setprecision(13) << sample << ",";
            }
        }
        osampleTraceData[osampleCurrentIndex++] = sample;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void fillFilterWithSequence(SsrcSampleRateConverterInterface &ssrc)
    {
        SsrcFilterInfo filterInfo;
        ssrc.getFilterInfo(filterInfo);
        _SAMPLE_TYPE_ *filterTaps = (_SAMPLE_TYPE_ *)filterInfo.filterTaps;
        for (unsigned phase = 0; phase < filterInfo.numberOfPhases; phase++)
        {
            int tap = phase* filterInfo.totalNumberOfTaps;
            for (unsigned index = 0; index < filterInfo.numberOfZeroExtension; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index - (_SAMPLE_TYPE_)filterInfo.numberOfZeroExtension;
                filterTaps[tap] = setting;
            }
            for (unsigned index = 0; index < filterInfo.numberOfTaps; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index;
                filterTaps[tap] = setting;
            }
            for (unsigned index = 0; index < filterInfo.numberOfZeroExtension; index++, tap++)
            {
                _SAMPLE_TYPE_ setting = (_SAMPLE_TYPE_)index - (_SAMPLE_TYPE_)filterInfo.numberOfZeroExtension;
                filterTaps[tap] = setting;
            }
        }
    }
};

#define ArmRegister(_REG_) 
#define STRING_INST(...) 
#define put_char(...) 

#define asm_block_start()
#define asm_block_end()
/********************************************************************************
* transfer accumulator to sample output register
*
*******************************************************************************/
#define transfer_accumulator_to_sample_register(_SampleSet_X_Chx_,_phaseXAccumChx_,_DES_OFFSET_,_OSample_,_Channel_) NeonExec::f->transfer_accumulator_to_sample_register_c(_SampleSet_X_Chx_,_phaseXAccumChx_,_DES_OFFSET_,_OSample_,_Channel_);


/********************************************************************************
* add two 64 bit part of accumulator to generate final accumulator value
*
*******************************************************************************/
#define add_two_halfs_of_accumulator(_phaseXAccumChx_, _OSample_,_Channel_) NeonExec::f->add_two_halfs_of_accumulator_c(_phaseXAccumChx_,_OSample_,_Channel_);
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
#define sum_accumulator_float32(_out_, _phaseXAccumChx_0_,_phaseXAccumChx_1_,_p0_,_p1_) NeonExec::f->sum_accumulator_float32_c(_out_, _phaseXAccumChx_0_,_phaseXAccumChx_1_);

/********************************************************************************
* shift right 64 bit acc by 31 bits to convert acc to 32 bit output
*
*******************************************************************************/
#define normalize_accumulator_to_32b(_phaseXAccumChx_,_OSample_,_Channel_) NeonExec::f->normalize_accumulator_to_32b_c(_phaseXAccumChx_,_OSample_,_Channel_);
/********************************************************************************
* load 8 samples from interleaved format for two channels
*
*******************************************************************************/
#define load_8_samples_stereo(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_) NeonExec::f->load_8_samples_stereo_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_);
/********************************************************************************
* store 8 samples
*
*******************************************************************************/
#define store_8_samples(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_SampleQueueP_Index_) NeonExec::f->store_8_samples_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_);
/********************************************************************************
* store 8 samples
*
*******************************************************************************/
#define store_8_samples_queue(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) NeonExec::f->store_8_samples_queue_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_);
/********************************************************************************
* store 8 samples to interleaved format for two channels
*
*******************************************************************************/
#define store_8_samples_interleaved(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) NeonExec::f->store_8_samples_interleaved_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_);
/********************************************************************************
* load 8 samples for single channel
*
*******************************************************************************/
#define load_8_samples(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_) NeonExec::f->load_8_samples_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_,_R0_Channel_,_R1_Channel_,_R0_SampleSetNo_,_R1_SampleSetNo_);
/********************************************************************************
* load 8 samples for single channel
*
*******************************************************************************/
#define load_8_samples_queue(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_) NeonExec::f->load_8_samples_queue_c(_Samples_X_Ch0_,_Samples_X_Ch1_,_SampleQueueP_);
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_nontemporal(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) NeonExec::f->load_8_filter_taps_c(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_);
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_temporal(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) NeonExec::f->load_8_filter_taps_c(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_);
/********************************************************************************
* load 2x4 filter coefficients from one phase
*
*******************************************************************************/
#define load_8_filter_taps_autoinc(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_) NeonExec::f->load_8_filter_taps_autoinc_c(_Phase_x_Coef_x_,_Phase_x_Coef_y_,_phasexxFitlerP_,_OFFSET_,_OSample_,_TapSetNo_);
/********************************************************************************
 * multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
 *
 *******************************************************************************/
#define multiply_and_accum_lower(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_OChannel_,_TapSetNo_,_ISampleSetNo_) NeonExec::f->multiply_and_accum_lower_c(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_OChannel_,_TapSetNo_,_ISampleSetNo_);
/********************************************************************************
* multiply and accumulate 2 upper samples with 2 2upper filter coeff into a phase accumulator register
*
*******************************************************************************/
#define multiply_and_accum_upper(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_OChannel_,_TapSetNo_,_ISampleSetNo_) NeonExec::f->multiply_and_accum_upper_c(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_OChannel_,_TapSetNo_,_ISampleSetNo_);
/********************************************************************************
* multiply and accumulate 4 samples and four coeff
*
*******************************************************************************/
#define multiply_and_accum_float32(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_Channel_,_TapSetNo_,_ISampleSetNo_)  NeonExec::f->multiply_and_accum_float32_c(_phasexxAccum_,_Samples_x_Chx_,Phase_x_Coef_x,_OSample_,_Channel_,_TapSetNo_,_ISampleSetNo_);
/********************************************************************************
* load 8 samples from interleaved format for two channels
*
*******************************************************************************/
#define mask_pointer(_Output_,_InputA_,_InputB_) NeonExec::f->mask_pointer_c(_Output_,_InputA_,_InputB_);
/********************************************************************************
* convert four float32 to int32
*
*******************************************************************************/
#define four_float32_to_int32(_out_int32_r_,_in_float32_r_) NeonExec::f->four_float32_to_int32_c(_out_int32_r_,_in_float32_r_);

/********************************************************************************
* convert four int32 to float32
*
*******************************************************************************/
#define four_int32_to_float32(_out_float32_r_,_in_int32_r_) NeonExec::f->four_int32_to_float32_c(_out_float32_r_,_in_int32_r_);

/********************************************************************************
* duplicate vector element from input in index to all elements of output
*
*******************************************************************************/
#define duplate_vector_element_float32(_out_float32_v_,_input_float32_w_) NeonExec::f->duplate_vector_element_float32_c(_out_float32_v_,_input_float32_w_);


/********************************************************************************
* load flaotd32 and increment pointer
*
*******************************************************************************/
#define  load_32b_inc_pointer(_out_float32_r_, _list_p_) NeonExec::f->load_32b_inc_pointer_c(_out_float32_r_, _list_p_);

/********************************************************************************
* insert a register value into vector element
* _out_float32_v_[_output_index_] = _input_float32_r_
*
*******************************************************************************/
#define insert_into_vector_element_float32(_out_float32_v_,_output_index_,_input_float32_r_)  NeonExec::f->insert_into_vector_element_float32_c(_out_float32_v_,_output_index_,_input_float32_r_);
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ &  _in2_float32_v_
*
*******************************************************************************/
#define four_and_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) NeonExec::f->four_and_float32_c(_out_float32_v_,_in1_float32_v_,_in2_float32_v_);

/********************************************************************************
* _out_float32_v_ = _in_float32_v_ ==  [0,0,0,0]
*
*******************************************************************************/
#define four_compare_greater_than_zero_float32(_out_float32_v_,_in_float32_v_) NeonExec::f->four_compare_greater_than_zero_float32_c(_out_float32_v_,_in_float32_v_);
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ -  _in2_float32_v_
*
*******************************************************************************/
#define four_subtract_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) NeonExec::f->four_subtract_float32_c(_out_float32_v_,_in1_float32_v_,_in2_float32_v_);
/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ *  _in2_float32_v_
*
*******************************************************************************/
#define four_multiply_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) NeonExec::f->four_multiply_float32_c(_out_float32_v_,_in1_float32_v_,_in2_float32_v_);

/********************************************************************************
* _out_float32_v_ = _in1_float32_v_ +  _in2_float32_v_
*
*******************************************************************************/
#define four_add_float32(_out_float32_v_,_in1_float32_v_,_in2_float32_v_) NeonExec::f->four_add_float32_c(_out_float32_v_,_in1_float32_v_,_in2_float32_v_);

/********************************************************************************
* clear vector register
*
*******************************************************************************/
#define clear_accumulator(_Output_,_OSample_,_OChannel_) NeonExec::f->clear_accumulator_c(_Output_,_OSample_,_OChannel_);
#define asm_vector_usage_output(_Vector_) 
#define asm_register_usage_output(_Register_)  
#define register 
#endif /*USE_ARM_INLINE*/
#endif /*ssrcNeonAssemberDef_h*/
