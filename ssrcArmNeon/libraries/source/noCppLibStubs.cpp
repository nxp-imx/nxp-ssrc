/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
/*!******************************************************************************************
**   this function should never b called
**   its a stub to satisfy linker for baremetal environment
**
*******************************************************************************************/
#ifdef USE_ARM_INLINE
#ifdef NO_CPP_LIBRARY
#include <new>
#include <malloc.h>
extern "C"
void __cxa_pure_virtual()
{
    while (1);
}


void* operator new(std::size_t size) 
{
    return malloc(size);
}

void* operator new[](std::size_t size) 
{
    return malloc(size);
}

void operator delete(void* ptr) 
{
    free(ptr);
}

void operator delete[](void* ptr) 
{
    free(ptr);
}
void* operator new(std::size_t size, const std::nothrow_t&)
{
    return malloc(size);
}

void* operator new[](std::size_t size, const std::nothrow_t&) 
{
    return malloc(size);
}

void operator delete(void* ptr, const std::nothrow_t&)
{
    free(ptr);
}

void operator delete[](void* ptr, const std::nothrow_t&) 
{
    free(ptr);
}
#endif
#endif
