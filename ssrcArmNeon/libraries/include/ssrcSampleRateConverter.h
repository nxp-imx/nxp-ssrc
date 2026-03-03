/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcSampleRateConverter_h
#define ssrcSampleRateConverter_h
#include "ssrcConverterAccess.h"
#include "ssrc_quantized_interpolation_filter.h"
//#include <memory>
#include <memory.h>
#include <stdlib.h>
#include <new>

/********************************************************************************
*
*******************************************************************************/
#ifdef USE_ARM_INLINE

    #include <unistd.h>
    #include <sys/ioctl.h>
    #include "ssrcNeonAssemberDef.h"
    #define TARGET TARGET_ARM

    #ifdef MESURE_PERFOMANCE
        inline void read_pmccntr(uint64_t &ret)
        {
            uint64_t val;
            asm volatile("mrs %0, pmccntr_el0" : "=r"(val));
            ret = val;
        }
    #else
        inline void read_pmccntr(uint64_t &ret)
        {
        }
    #endif
#else
    #include "ssrcNeonAssemblerDefInC.h"
    inline void read_pmccntr(uint64_t &ret)
    {
    }
    #ifdef __linux__
        #define TARGET TARGET_C_LINUX
    #else

        #define TARGET TARGET_C_MS
        typedef int cpu_set_t;

        inline void CPU_ZERO(int *ret)
        {
        }
        inline void CPU_SET(int a,int *ret)
        {
        }
        inline void sched_setaffinity(int a,int b, int *ret)
        {
        }
        inline int getpid()
        {
            return 0;
        }
        inline void *aligned_alloc(size_t alignment, size_t size)
        {
            return nullptr;
        }
    #endif
#endif
/********************************************************************************
*  calcualte log2 input
*
*******************************************************************************/
template <class _TYPE_> inline int msb(_TYPE_ input)
{
    int index = 0;
    uint64_t value = (uint64_t)input >> 1;
    for (index = 0; index < 64 && ((value >> index) != 0); index++)
    {
    }
    return index;
}

/********************************************************************************
*  aligned memory block
*
*******************************************************************************/
template<unsigned _TARGET_> struct AlignedMemmory
{
    uint8_t *orgPtr;
    uint8_t *alignedPtr;
    size_t pointerMask;
    size_t allocSizeInBytes;
    size_t sizeInBytes;
    AlignedMemmory()
    {
        orgPtr = nullptr;
        alignedPtr = nullptr;
        pointerMask = 0;
        allocSizeInBytes = 0;
        sizeInBytes = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    inline void *allocateAlignedMemory(size_t sizeInBytes, size_t extraBytes)
    {
        switch (_TARGET_)
        {
        case TARGET_C_MS:
            return allocateAlignedMemory_ms(sizeInBytes, extraBytes);
        default:
            return allocateAlignedMemory_arm(sizeInBytes, extraBytes);

        }

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    operator void *()
    {
        return alignedPtr;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    operator int32_t *()
    {
        return(int32_t *)alignedPtr;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    inline void freeMemory()
    {
        free(orgPtr);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    inline void *getMemoryPtr()
    {
        return orgPtr;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    inline void *getMemoryMask()
    {
        return (void *)pointerMask;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    inline size_t getSizeInBytes()
    {
        return sizeInBytes;
    }
    /********************************************************************************
    *
    *   allocSize = 1 << (log2Size+1)
    *
    *   AddressEnd = addressStart + 2*allocSize
    *
    *   xxx0yyyy xxx1yyyy
     *******************************************************************************/
    inline void *allocateAlignedMemory_arm(size_t requestedSizeInBytes, size_t extraBytes)
    {
        sizeInBytes = requestedSizeInBytes;
        unsigned log2SizeInBytes = msb(sizeInBytes);
        if (((size_t)1 << log2SizeInBytes) != sizeInBytes)
        {
            log2SizeInBytes += 1;
        }
        sizeInBytes = (size_t)1 << log2SizeInBytes;
        pointerMask = ~sizeInBytes;

        size_t mask = sizeInBytes - 1 + sizeInBytes;
        allocSizeInBytes = sizeInBytes + extraBytes;
        size_t alignment = sizeInBytes * 2;
        orgPtr = alignedPtr = (uint8_t *)aligned_alloc(alignment, allocSizeInBytes);
        return alignedPtr;

    }

    /********************************************************************************
    *
    *   allocSize = 1 << (log2Size+1)
    *
    *   AddressEnd = addressStart + 2*allocSize
    *
    *   xxx0yyyy xxx1yyyy
     *******************************************************************************/
    inline void *allocateAlignedMemory_ms(size_t requestedSizeInBytes, size_t extraBytes)
    {
        sizeInBytes = requestedSizeInBytes;
        unsigned log2SizeInBytes = msb(sizeInBytes);
        if (((size_t)1 << log2SizeInBytes) != sizeInBytes)
        {
            log2SizeInBytes += 1;
        }
        sizeInBytes = (size_t)1 << log2SizeInBytes;

        size_t mask = sizeInBytes - 1 + sizeInBytes;
        allocSizeInBytes = sizeInBytes * 3 + extraBytes;
        orgPtr = (uint8_t *)malloc(allocSizeInBytes);
        uint8_t *endPtr = orgPtr + allocSizeInBytes;
        if (orgPtr != nullptr)
        {
            pointerMask = ~sizeInBytes;
            if (((size_t)orgPtr & mask) == 0)
            {
                alignedPtr = orgPtr;
            }
            else if ((((size_t)orgPtr + sizeInBytes) & sizeInBytes) == 0)
            {
                alignedPtr = (uint8_t *)(((size_t)orgPtr + sizeInBytes) & ~mask);
            }
            else
            {
                alignedPtr = (uint8_t *)(((size_t)orgPtr + sizeInBytes * 2) &~mask);
            }
        }
        size_t finalSize = endPtr - alignedPtr;
        return alignedPtr;

    }
};
/********************************************************************************
*  sample Queue
*
*******************************************************************************/
template <bool _INPUT_QUEUE_TYPE_> class SsrcSampleQueue
{
public:
    static const unsigned tapsTransferUnitInWords = 8;
    static const unsigned sampleTransferUnitInWords = 8;
    static const unsigned queueMinSampleTransferUnitInWords = 128;
    static const unsigned sampleTransferUnitInBytes = sampleTransferUnitInWords * 4;
    static const bool inputQueueType = _INPUT_QUEUE_TYPE_;

    int32_t *sampleBufferQueue;
    int32_t *sampleBufferQueueWrapMask;
    
    unsigned putIndex;
    unsigned getIndex;

    unsigned getPutIndexMask;

    unsigned sampleBufferQueueSizeInSamples;
    unsigned extraSamplesPassedEnd;
    unsigned transferChunckSize;
    unsigned numberOfSamplesPerRun;
    AlignedMemmory< TARGET>  alignedMemory;

    uint64_t performanceCounterTotal;
    /********************************************************************************
    *
    *
    *******************************************************************************/
    SsrcSampleQueue()
    {
        sampleBufferQueue = nullptr;
        destruct();
        performanceCounterTotal = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    ~SsrcSampleQueue()
    {
        destruct();
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void reset()
    {
        putIndex = 0;
        getIndex = 0;
        performanceCounterTotal = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void clearPerformanceCounter()
    {
        performanceCounterTotal = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    uint64_t readPerformanceCounter()
    {
        return performanceCounterTotal ;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void destruct()
    {
        if (sampleBufferQueue != nullptr)
        {
            alignedMemory.freeMemory();
        }
        sampleBufferQueue = nullptr;
        sampleBufferQueueWrapMask = (int32_t *)0;
        sampleBufferQueueSizeInSamples = 0;
        extraSamplesPassedEnd = 0;
        putIndex = 0;
        getIndex = 0;
        getPutIndexMask = 0;
        transferChunckSize = 0;
        numberOfSamplesPerRun = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void updateGetPos(unsigned val)
    {
        getIndex += val;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void updatePutPos(unsigned val)
    {
        putIndex += val;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getQueuePointerMask(int32_t *(&ret))
    {
        ret = sampleBufferQueueWrapMask;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getQueuePointerMask(float *(&ret))
    {
        ret = (float *)(sampleBufferQueueWrapMask);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getCurrentGetPos(int32_t *(&ret))
    {
        ret = sampleBufferQueue + (getIndex & getPutIndexMask);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getCurrentGetPos(float *(&ret))
    {
        ret = (float *)(sampleBufferQueue + (getIndex & getPutIndexMask));
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getCurrentPutPos(int32_t *(&ret))
    {
        ret = sampleBufferQueue + (putIndex & getPutIndexMask);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void getCurrentPutPos(float *(&ret))
    {
        ret = (float *)(sampleBufferQueue + (putIndex & getPutIndexMask));
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    int32_t *maskPointer(int32_t *p)
    {
        return  (int32_t *)((uint64_t)p & (uint64_t)sampleBufferQueueWrapMask);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    float *maskPointer(float *p)
    {
        return (float *)((uint64_t)p & (uint64_t)sampleBufferQueueWrapMask);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool configure(SsrcSampleRateConverterInfo &resamplerInfo)
    {
        if (alignedMemory.getMemoryPtr() != nullptr)
        {
            destruct();
        }

        performanceCounterTotal = 0;
        unsigned minSize = (resamplerInfo.totalNumOutputSamplesPerRun + resamplerInfo.numberOftapsPerPhase) * 2;

        transferChunckSize = (inputQueueType ? resamplerInfo.inputTrasferSizeInTransferUnits : resamplerInfo.outputTrasferSizeInTransferUnits)*queueMinSampleTransferUnitInWords;

        if ((transferChunckSize %queueMinSampleTransferUnitInWords) != 0)
        {
            resamplerInfo.log.add("ERROR: invalid transfer chunck size:transfer chunck size needs to be multiple of 128");
            return false;
        }

        numberOfSamplesPerRun = inputQueueType ? resamplerInfo.totalNumberOfSamplesUsedPerRun : transferChunckSize;

        int chunksPerSamplesNeeded = ((numberOfSamplesPerRun+ transferChunckSize) / transferChunckSize);

        int logOfChunksPerSamplesNeeded = msb(chunksPerSamplesNeeded);
        int numberOfChunks = 1 << (logOfChunksPerSamplesNeeded+1);

        if (numberOfChunks < 8)
        {
            numberOfChunks = 8;
        }

        unsigned size =  transferChunckSize * numberOfChunks;
        if (size < minSize)
        {
            size = minSize;
        }
        if (size == 0)
        {
            resamplerInfo.log.add("ERROR: invalid queue size ");
            return false;
        }
        int sizeInBytes = sizeof(int32_t)*size;
        extraSamplesPassedEnd = inputQueueType ? resamplerInfo.numberOfTapsRedPerReadCycle : 0;

        sampleBufferQueue = (int32_t *)alignedMemory.allocateAlignedMemory(sizeInBytes,extraSamplesPassedEnd *sizeof(int32_t));


        sampleBufferQueueWrapMask = (int32_t *)alignedMemory.getMemoryMask();
        sampleBufferQueueSizeInSamples = (unsigned)(alignedMemory.getSizeInBytes() / sizeof(int32_t));
        getPutIndexMask = (unsigned)(sampleBufferQueueSizeInSamples - 1);


        if (sampleBufferQueue == nullptr)
        {
            destruct();
            resamplerInfo.log.add("ERROR: Memory allocation error:");
            return false;
        }
        else
        {
            return true;
        }
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    unsigned queueFulness()
    {
        return (putIndex - getIndex) ;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasChunkSamples()
    {
        return (putIndex - getIndex) >= transferChunckSize;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasOneRunFreeSpace()
    {
        return (sampleBufferQueueSizeInSamples - (putIndex - getIndex)) >= numberOfSamplesPerRun;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasFreeSpace(unsigned amount)
    {
        return (sampleBufferQueueSizeInSamples - (putIndex - getIndex)) >= amount;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasOneRunSamples()
    {
        return (putIndex - getIndex) >= numberOfSamplesPerRun;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasSamples(unsigned amount)
    {
        return (putIndex - getIndex) >= amount;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool hasChunkFreeSpace()
    {
        return (sampleBufferQueueSizeInSamples - (putIndex - getIndex)) >= transferChunckSize;
    }
    
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get(int32_t *outData)
    {
        if (!hasSamples(transferChunckSize))
            return false;

        uint64_t performanceCounterStart;
        read_pmccntr(performanceCounterStart);
        register int32x4_t sampleSet0 ArmRegister("v0"); // sample set 0
        register int32x4_t sampleSet1 ArmRegister("v1"); // sample set 1
        register int32x4_t sampleSet2 ArmRegister("v2"); // sample set 2
        register int32x4_t sampleSet3 ArmRegister("v3"); // sample set 3
        register int32_t *output ArmRegister("x4"); // phase0 taps pointer
        register int32_t *input ArmRegister("x5"); // phase1 taps pointer
        register int32_t *inputMask ArmRegister("x6"); // phase1 taps pointer
        output = outData;
        getCurrentGetPos(input);
        inputMask = sampleBufferQueueWrapMask;
        for (unsigned index = 0; index < transferChunckSize; index += queueMinSampleTransferUnitInWords)
        {
            asm_block_start()

                load_8_samples_queue(sampleSet0, sampleSet1, input)
                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)
                

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                mask_pointer(input, input, inputMask)

                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_vector_usage_output(sampleSet2)put_char(, )
                asm_vector_usage_output(sampleSet3)put_char(, )
                asm_register_usage_output(inputMask)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        getIndex += transferChunckSize;
        uint64_t performanceCounterEnd;
        read_pmccntr(performanceCounterEnd);
        performanceCounterTotal += performanceCounterEnd - performanceCounterStart;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get_FloatToInt(int32_t *outData)
    {
        if (!hasSamples(transferChunckSize))
            return false;

        uint64_t performanceCounterStart;
        read_pmccntr(performanceCounterStart);
        register int32x4_t sampleSet0 ArmRegister("v0"); // sample set 0
        register int32x4_t sampleSet1 ArmRegister("v1"); // sample set 1
        register int32x4_t sampleSet2 ArmRegister("v2"); // sample set 2
        register int32x4_t sampleSet3 ArmRegister("v3"); // sample set 3
        register int32_t *output ArmRegister("x4"); // phase0 taps pointer
        register int32_t *input ArmRegister("x5"); // phase1 taps pointer
        register int32_t *inputMask ArmRegister("x6"); // phase1 taps pointer
        output = outData;
        getCurrentGetPos(input);
        inputMask = sampleBufferQueueWrapMask;
        for (unsigned index = 0; index < transferChunckSize; index += queueMinSampleTransferUnitInWords)
        {
            asm_block_start()

                load_8_samples_queue(sampleSet0, sampleSet1, input)
                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)


                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_float32_to_int32(sampleSet0, sampleSet0)
                four_float32_to_int32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                four_float32_to_int32(sampleSet2, sampleSet2)
                four_float32_to_int32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                mask_pointer(input, input, inputMask)

                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_vector_usage_output(sampleSet2)put_char(, )
                asm_vector_usage_output(sampleSet3)put_char(, )
                asm_register_usage_output(inputMask)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        getIndex += transferChunckSize;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put(int32_t *inData)
    {
        if (!hasFreeSpace(transferChunckSize))
            return false;
        uint64_t performanceCounterStart;
        read_pmccntr(performanceCounterStart);
        register int32x4_t sampleSet0 ArmRegister("v0"); // sample set 0
        register int32x4_t sampleSet1 ArmRegister("v1"); // sample set 1
        register int32x4_t sampleSet2 ArmRegister("v2"); // sample set 2
        register int32x4_t sampleSet3 ArmRegister("v3"); // sample set 3
        register int32_t *output ArmRegister("x4"); // phase0 taps pointer
        register int32_t *input ArmRegister("x5"); // phase1 taps pointer
        register int32_t *outputMask ArmRegister("x6"); // phase1 taps pointer

        input = inData;
        getCurrentPutPos(output);
        outputMask = sampleBufferQueueWrapMask;
        for (unsigned index = 0; index < transferChunckSize; index += queueMinSampleTransferUnitInWords)
        {
            asm_block_start()

                load_8_samples_queue(sampleSet0, sampleSet1, input)
                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                store_8_samples_queue(sampleSet2, sampleSet3, output)
                mask_pointer(output, output, outputMask)
                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_vector_usage_output(sampleSet2)put_char(, )
                asm_vector_usage_output(sampleSet3)put_char(, )
                asm_register_usage_output(outputMask)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        putIndex += transferChunckSize;
        if (inputQueueType && ((putIndex & getPutIndexMask) <= transferChunckSize))
        {
            input = sampleBufferQueue;
            output = sampleBufferQueue + sampleBufferQueueSizeInSamples;
            asm_block_start()
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put_IntToFloat(int32_t *inData)
    {
        if (!hasFreeSpace(transferChunckSize))
            return false;
        uint64_t performanceCounterStart;
        read_pmccntr(performanceCounterStart);
        register int32x4_t sampleSet0 ArmRegister("v0"); // sample set 0
        register int32x4_t sampleSet1 ArmRegister("v1"); // sample set 1
        register int32x4_t sampleSet2 ArmRegister("v2"); // sample set 2
        register int32x4_t sampleSet3 ArmRegister("v3"); // sample set 3
        register int32_t *output ArmRegister("x4"); // phase0 taps pointer
        register int32_t *input ArmRegister("x5"); // phase1 taps pointer
        register int32_t *outputMask ArmRegister("x6"); // phase1 taps pointer

        input = inData;
        getCurrentPutPos(output);
        outputMask = sampleBufferQueueWrapMask;
        for (unsigned index = 0; index < transferChunckSize; index += queueMinSampleTransferUnitInWords)
        {
            asm_block_start()

                load_8_samples_queue(sampleSet0, sampleSet1, input)
                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)

                load_8_samples_queue(sampleSet2, sampleSet3, input)
                four_int32_to_float32(sampleSet0, sampleSet0)
                four_int32_to_float32(sampleSet1, sampleSet1)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                four_int32_to_float32(sampleSet2, sampleSet2)
                four_int32_to_float32(sampleSet3, sampleSet3)
                store_8_samples_queue(sampleSet2, sampleSet3, output)
                mask_pointer(output, output, outputMask)
                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_vector_usage_output(sampleSet2)put_char(, )
                asm_vector_usage_output(sampleSet3)put_char(, )
                asm_register_usage_output(outputMask)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        putIndex += transferChunckSize;
        if (inputQueueType && ((putIndex & getPutIndexMask) <= transferChunckSize))
        {
            input = sampleBufferQueue;
            output = sampleBufferQueue + sampleBufferQueueSizeInSamples;
            asm_block_start()
                load_8_samples_queue(sampleSet0, sampleSet1, input)
                store_8_samples_queue(sampleSet0, sampleSet1, output)
                put_char(:)
                asm_vector_usage_output(sampleSet0)put_char(, )
                asm_vector_usage_output(sampleSet1)put_char(, )
                asm_register_usage_output(output)put_char(, )
                asm_register_usage_output(input)
                put_char(:)
                put_char(:) STRING_INST(memory)
                asm_block_end()
        }
        return true;
    }
};
  
/********************************************************************************
*  sample rate converter interface class
*
*******************************************************************************/
class SsrcSampleRateConverter:
    public SsrcSampleRateConverterInterface
{
public:
    SsrcSampleQueue<true> inputQueue;
    SsrcSampleQueue<false> outputQueue;
    int16_t currentPhase;
    uint64_t performanceCounterTotal;
    /********************************************************************************
    *
    *
    *******************************************************************************/
    SsrcSampleRateConverter() :
        inputQueue(),
        outputQueue()
    {
        currentPhase = 0;
        performanceCounterTotal = 0;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual ~SsrcSampleRateConverter()
    {

    }
    /********************************************************************************
   *
   *
   *******************************************************************************/
    void clearPerformanceCounter()
    {
        performanceCounterTotal = 0;
        inputQueue.clearPerformanceCounter();
        outputQueue.clearPerformanceCounter();
    }
    /********************************************************************************
   *
   *
   *******************************************************************************/
    uint64_t readPerformanceCounter()
    {
        return performanceCounterTotal +
        inputQueue.readPerformanceCounter() +
        outputQueue.readPerformanceCounter();
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get(int32_t *data)
    {
        return outputQueue.get(data);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get_FloatToInt(int32_t *data)
    {
        return outputQueue.get_FloatToInt(data);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put(int32_t *data)
    {
        return inputQueue.put(data);

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put_IntToFloat(int32_t *data)
    {
        return inputQueue.put_IntToFloat(data);

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get(float *data)
    {
        return outputQueue.get((int32_t *)data);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool get_FloatToInt(float *data)
    {
        return outputQueue.get_FloatToInt((int32_t *)data);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put(float *data)
    {
        return inputQueue.put((int32_t *)data);

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool put_IntToFloat(float *data)
    {
        return inputQueue.put_IntToFloat((int32_t *)data);

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool haveEnoughSamplesToProcess()
    {
        return inputQueue.hasOneRunSamples();

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    int inputFulness()
    {
        return inputQueue.queueFulness();

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    int outputFulness()
    {
        return outputQueue.queueFulness();

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool haveEnoughOutputSamples()
    {
        return outputQueue.hasChunkSamples();

    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool getInfo(SsrcSampleRateConverterInfo &ssrcInfo)
    {
        return false;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool configure(SsrcSampleRateConverterInfo &config)
    {
        return false;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool destruct()
    {
        inputQueue.destruct();
        outputQueue.destruct();
        currentPhase = 0;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual void reset(unsigned phase = 0)
    {
        performanceCounterTotal = 0;
        inputQueue.reset();
        outputQueue.reset();
        unsigned maxPhase = getSampleRateRatioOutput();
        if (phase >= maxPhase)
        {
            phase = maxPhase - 1;
        }
        currentPhase = phase;
    }
    /********************************************************************************
    *  enough samples in input queue and space in output queue
    *
    *******************************************************************************/
    bool inputOutputQueueReadyForRun()
    {
        return inputQueue.hasOneRunSamples() && outputQueue.hasOneRunFreeSpace();
    }
    /********************************************************************************
    *  generate on set of output samples
    *
    *******************************************************************************/
    virtual bool process()
    {
        return false;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    bool processAndMeasureCycles()
    {
        uint64_t performanceCounterStart;
        read_pmccntr(performanceCounterStart);
        bool status = process();
        uint64_t performanceCounterEnd;
        read_pmccntr(performanceCounterEnd);
        performanceCounterTotal += performanceCounterEnd - performanceCounterStart;
        return status;
    }
    /********************************************************************************
    *  get number of phases
    *
    *******************************************************************************/
    virtual unsigned getSampleRateRatioOutput()
    {
        return 0;
    }
    /********************************************************************************
    *  get number of taps per phase
    *
    *******************************************************************************/
    virtual unsigned getNumberOfTapsPerPhase()
    {
        return 0;
    }
    /********************************************************************************
    *  get input/output sample rate ratio numurator 
    *
    *******************************************************************************/
    virtual unsigned getSampleRateRatioInput()
    {
        return 0;
    }
    /********************************************************************************
    *  get number of taps red per cycle
    *
    *******************************************************************************/
    virtual unsigned getNumberOfTapsRedPerReadCycle()
    {
        return 0;
    }
    /********************************************************************************
    *  get number of number samples are used per ssrc process
    *
    *******************************************************************************/
    virtual unsigned getTotalNumberOfSamplesUsedPerRun()
    {
        return 0;
    }
    /********************************************************************************
    *  get get total number samples output per run
    *
    *******************************************************************************/
    virtual unsigned getTotalNumOutputSamplesPerRun()
    {
        return 0;
    }

    /********************************************************************************
   *  get get total number samples output per run
   *
   *******************************************************************************/
    virtual unsigned getIsStereo()
    {
        return 0;
    }

    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual unsigned getnumOutputSamplesPerChanPerRun()
    {
        return 0;
    }
    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual bool getFilterInfo(SsrcFilterInfo &ret)
    {
        return false;
    }
};
/********************************************************************************
*  ssrc filter
*
*******************************************************************************/
template <unsigned _MUMBER_OF_PHASES_,
    unsigned _NUMBER_OF_TAPS_,
    unsigned _ZERO_EXTENSION_,
    int _TAP_LOAD_INSTRUCTION_OFFSET_/* TAP load instruction offset */>
class SsrcFilter
{
public:
    static const unsigned numberOfZeroExtension = _ZERO_EXTENSION_;
    static const unsigned totalNumberOfTaps = numberOfZeroExtension * 2 + _NUMBER_OF_TAPS_;
    static const unsigned numberOfTaps = _NUMBER_OF_TAPS_;
    static const unsigned numberOfPhases = _MUMBER_OF_PHASES_;
    static const int tapLoadInstructionOffset = _TAP_LOAD_INSTRUCTION_OFFSET_;

    

    int32_t (*filterTaps)[totalNumberOfTaps];
    int32_t (*filterTapsWithZero)[totalNumberOfTaps];
    QuantizedFitlerEntry * interpolationFilter;
    /********************************************************************************
    *
    *
    *******************************************************************************/
    SsrcFilter()
    {
        filterTaps = nullptr;
        filterTapsWithZero = nullptr;
        interpolationFilter = nullptr;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    ~SsrcFilter()
    {
        destruct();
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    int32_t *phase(int phaseNo)
    {
        return filterTapsWithZero[phaseNo];
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    template <class _TYPE_> void phase(int phaseNo, _TYPE_ &output, int offset = 0)
    {
        output = (_TYPE_)(filterTapsWithZero[phaseNo] - offset);
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    template <class _TYPE_> void phaseZero(_TYPE_ &output,int offset = 0)
    {
        output = (_TYPE_)(filterTapsWithZero[0]-offset);
    }
     /********************************************************************************
    *
    *
    *******************************************************************************/
    bool configure(SsrcSampleRateConverterInfo &resamplerInfo)
    {
        if (resamplerInfo.numberOftapsPerPhase == numberOfTaps && resamplerInfo.sampleRateRatioOutput == numberOfPhases)
        {
            if (
                resamplerInfo.interpolationFilter != nullptr &&
                resamplerInfo.interpolationFilter->numberOftapsPerPhase == resamplerInfo.numberOftapsPerPhase &&
                resamplerInfo.interpolationFilter->sampleRateRatioInput == resamplerInfo.sampleRateRatioInput &&
                resamplerInfo.interpolationFilter->sampleRateRatioOutput == resamplerInfo.sampleRateRatioOutput &&
                resamplerInfo.interpolationFilter->filter != nullptr
                )
            {
                filterTaps = (int32_t(*)[totalNumberOfTaps]) (resamplerInfo.interpolationFilter->filter);
                int offset = (int)numberOfZeroExtension - (tapLoadInstructionOffset / ((int)sizeof(int32_t)));
                filterTapsWithZero = (int32_t(*)[totalNumberOfTaps]) (&filterTaps[0][offset]);
                return true;
            }
        }
        resamplerInfo.log.add("ERROR: resampler configuration failed");
        return false;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    void zeroPadFilter(int32_t *nonPaddedFiter, int32_t *paddedFitler)
    {
        int32_t(*output)[totalNumberOfTaps] = (int32_t(*)[totalNumberOfTaps])paddedFitler;
        for (int phase = 0; phase < numberOfPhases; phase++)
        {
            int tap = 0;
            for (int index = 0; index < numberOfZeroExtension; index++, tap++)
            {
                output[phase][tap] = 0;
            }
            for (int index = 0; index < numberOfTaps; index++, tap++)
            {
                output[phase][tap] = nonPaddedFiter[phase*numberOfTaps + index];
            }
            for (int index = 0; index < numberOfZeroExtension; index++, tap++)
            {
                output[phase][tap] = 0;
            }
        }
    }
    /********************************************************************************
   *
   *
   *******************************************************************************/
    void *destruct()
    {
        if (usingDLL)
        {
            if (interpolationFilter != nullptr)
            {
                if (interpolationFilter->libHandle != nullptr)
                {
                    void *ret = interpolationFilter->libHandle;
                    interpolationFilter->libHandle = nullptr;
                    return ret;
                }
            }
        }
        return nullptr;
    }
    /********************************************************************************
   *
   *
   *******************************************************************************/
    void reset()
    {
        interpolationFilter = nullptr;
    }
    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    bool getFilterInfo(SsrcFilterInfo &ret)
    {
        ret.filterTaps = filterTaps[0];
        ret.filterTapsWithZero = filterTapsWithZero[0];
        ret.interpolationFilter = interpolationFilter;
        ret.numberOfPhases = numberOfPhases;
        ret.numberOfTaps = numberOfTaps;
        ret.numberOfZeroExtension = numberOfZeroExtension;
        ret.totalNumberOfTaps = totalNumberOfTaps;
        return true;
    }
};
/********************************************************************************
*  sample rate converter base class
*
*******************************************************************************/
template <
    class _SAMPLE_RATE_CONVERTER_CLASS_, /* sample rate converter class */
    int _SAMPLE_RATE_RATIO_INPUT_/* input sample rate */,
    int _SAMPLE_RATE_RATIO_OUTPUT_/* output sample rate */,
    int _NUMER_Of_TAPS_PER_PHASE /* num taps per phase */,
    int _NMBER_OF_TAPS_RED_PER_READ_CYCLE_/*  number of taps red per read cycle */,
    int _NUMBER_OF_SAMPLES_USED_PER_RUN_/*max samples needed per run*/,
    int _NUMBER_OF_OUTPUT_SAMPLES_PER_RUN_/* number of samples out per run */,
    bool _STEREO_/* stereo */,
    int _TAP_LOAD_INSTRUCTION_OFFSET_/* TAP load instruction offset */>
class SsrcSampleRateConverterTemplate : public SsrcSampleRateConverter
{
public:

    static const uint16_t sampleRateRatioInput = _SAMPLE_RATE_RATIO_INPUT_;
    static const uint16_t sampleRateRatioOutput = _SAMPLE_RATE_RATIO_OUTPUT_;
    static const uint16_t numberOftapsPerPhase = _NUMER_Of_TAPS_PER_PHASE;
    static const uint16_t numberOfTapsRedPerReadCycle = _NMBER_OF_TAPS_RED_PER_READ_CYCLE_;
    static const uint16_t numberOfSamplesUsedPerRunPerChan = _NUMBER_OF_SAMPLES_USED_PER_RUN_;
    static const uint16_t totalNumberOfSamplesUsedPerRun = _NUMBER_OF_SAMPLES_USED_PER_RUN_*(_STEREO_ + 1);
    static const uint16_t totalNumOutputSamplesPerRun = _NUMBER_OF_OUTPUT_SAMPLES_PER_RUN_;
    static const bool stereo = _STEREO_;
    static const uint16_t numOutputSamplesPerChanPerRun = totalNumOutputSamplesPerRun / (1 + stereo);
    static const uint8_t numberOfChannels = _STEREO_+1;

    /********************************************************************************
    *
    *
    *******************************************************************************/
    SsrcFilter<_SAMPLE_RATE_RATIO_OUTPUT_,_NUMER_Of_TAPS_PER_PHASE, _NMBER_OF_TAPS_RED_PER_READ_CYCLE_, _TAP_LOAD_INSTRUCTION_OFFSET_> filter;
    /********************************************************************************
    *
    *
    *******************************************************************************/
    SsrcSampleRateConverterTemplate():
        SsrcSampleRateConverter()

    {
        SsrcSampleRateConverter::destruct();
        destruct();
        SsrcSampleRateConverterInfo & info = static_cast<SsrcSampleRateConverterInfo &>(*this);
        getInfo(info);
    }
     /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual ~SsrcSampleRateConverterTemplate()
    {
        destruct();
    }
    void * operator new(size_t size)
    {
        void * p = malloc(size);

        return p;
    }
    void operator delete(void * p)
    {
        free(p);
    }

   /********************************************************************************
    *
    *
    *******************************************************************************/
    static SsrcSampleRateConverter *construct(SsrcSampleRateConverterDefinition &definition)
    {
        definition.sampleRateRatioInput = sampleRateRatioInput;
        definition.sampleRateRatioOutput = sampleRateRatioOutput;
        definition.numberOftapsPerPhase = numberOftapsPerPhase;
        definition.numberOfTapsRedPerReadCycle = numberOfTapsRedPerReadCycle;
        definition.numberOfSamplesUsedPerRunPerChan = numberOfSamplesUsedPerRunPerChan;
        definition.totalNumberOfSamplesUsedPerRun = totalNumberOfSamplesUsedPerRun;
        definition.totalNumOutputSamplesPerRun = totalNumOutputSamplesPerRun;
        definition.numOutputSamplesPerChanPerRun = numOutputSamplesPerChanPerRun;
        definition.numberOfChannels = numberOfChannels;
        definition.inputOutputTransferTransferUnitSize = SsrcSampleQueue<true>::queueMinSampleTransferUnitInWords;
        SsrcSampleRateConverter *converterPointer = new _SAMPLE_RATE_CONVERTER_CLASS_;
        return converterPointer;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool destruct()
    {
        filter.destruct();
        SsrcSampleRateConverter::destruct();
        currentPhase = 0;
        return true;
    }
    /********************************************************************************
    *  configure resampler
    *
    *******************************************************************************/
    virtual bool configure(SsrcSampleRateConverterInfo &resamplerInfo)
    {
        if (resamplerInfo.sampleRateRatioInput != sampleRateRatioInput ||
            resamplerInfo.sampleRateRatioOutput != sampleRateRatioOutput)
        {
            resamplerInfo.log.add("ERROR: input/output sampling rates not supported:");
            return false;
        }
        if (resamplerInfo.numberOftapsPerPhase != numberOftapsPerPhase)
        {
            resamplerInfo.log.add("ERROR: Interpolation filter: number of taps not valid:");
            return false;
        }
        if (resamplerInfo.stereo != stereo)
        {
            resamplerInfo.log.add("ERROR: Interpolation filter: number of channels not supported:");
            return false;
        }
        if (resamplerInfo.numberOfTapsRedPerReadCycle != numberOfTapsRedPerReadCycle)
        {
            resamplerInfo.log.add("ERROR: numberOfTapsRedPerReadCycle not supported:");
            return false;
        }
        resamplerInfo.numberOfSamplesUsedPerRunPerChan = numberOfSamplesUsedPerRunPerChan;
        resamplerInfo.totalNumberOfSamplesUsedPerRun = totalNumberOfSamplesUsedPerRun;
        resamplerInfo.numOutputSamplesPerChanPerRun = totalNumOutputSamplesPerRun / (1 + stereo);
        resamplerInfo.totalNumOutputSamplesPerRun = totalNumOutputSamplesPerRun;
        inputQueue.configure(resamplerInfo);
        outputQueue.configure(resamplerInfo);
        if (!filter.configure(resamplerInfo))
        {
            resamplerInfo.log.add("ERROR: Interpolation filter not found in the list");
            return false;
        }
        currentPhase = 0;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool getInfo(SsrcSampleRateConverterInfo &returnedInfo)
    {
        returnedInfo.sampleRateRatioInput = sampleRateRatioInput;
        returnedInfo.sampleRateRatioOutput = sampleRateRatioOutput;
        returnedInfo.numberOftapsPerPhase = numberOftapsPerPhase;
        returnedInfo.numberOfTapsRedPerReadCycle = numberOfTapsRedPerReadCycle;
        returnedInfo.numberOfSamplesUsedPerRunPerChan = numberOfSamplesUsedPerRunPerChan;
        returnedInfo.totalNumberOfSamplesUsedPerRun = totalNumberOfSamplesUsedPerRun;
        returnedInfo.totalNumOutputSamplesPerRun = totalNumOutputSamplesPerRun;
        returnedInfo.stereo = stereo;
        returnedInfo.numOutputSamplesPerChanPerRun = numOutputSamplesPerChanPerRun;
        returnedInfo.numberOfChannels = numberOfChannels;
        return true;
    }
    /********************************************************************************
    *
    *
    *******************************************************************************/
    virtual bool process()
    {
        return false;
    }
    /********************************************************************************
    *  get number of phases
    *
    *******************************************************************************/
    virtual unsigned getSampleRateRatioOutput()
    {
        return sampleRateRatioOutput;
    }
    /********************************************************************************
    *  get number of taps per phase
    *
    *******************************************************************************/
    virtual unsigned getNumberOfTapsPerPhase()
    {
        return numberOftapsPerPhase;
    }
    /********************************************************************************
    *  get input/output sample rate ratio numurator
    *
    *******************************************************************************/
    virtual unsigned getSampleRateRatioInput()
    {
        return sampleRateRatioInput;
    }
    /********************************************************************************
    *  get number of taps red per cycle
    *
    *******************************************************************************/
    virtual unsigned getNumberOfTapsRedPerReadCycle()
    {
        return numberOfTapsRedPerReadCycle;
    }
    /********************************************************************************
   *  get number of number samples are used per ssrc process
   *
   *******************************************************************************/
    virtual unsigned getTotalNumberOfSamplesUsedPerRun()
    {
        return totalNumberOfSamplesUsedPerRun;
    }
    /********************************************************************************
    *  get get total number samples output per run
    *
    *******************************************************************************/
    virtual unsigned getTotalNumOutputSamplesPerRun()
    {
        return totalNumOutputSamplesPerRun;
    }

    /********************************************************************************
   *  get get total number samples output per run
   *
   *******************************************************************************/
    virtual unsigned getIsStereo()
    {
        return stereo;
    }

    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual unsigned getnumOutputSamplesPerChanPerRun()
    {
        return numOutputSamplesPerChanPerRun;
    }
    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual bool getFilterInfo(SsrcFilterInfo &ret)
    {
        return filter.getFilterInfo(ret);
    }
    /********************************************************************************
     *  get get total number samples output samples per run per channel
     *
     *******************************************************************************/
    virtual void generateZeroPaddedFitler(int32_t *nonPaddedFiter, int32_t *paddedFitler)
    {
          filter.zeroPadFilter(nonPaddedFiter, paddedFitler);
    }
};

#endif
