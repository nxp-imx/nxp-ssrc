/********************************************************************************
* Copyright (c) 2011-2019 Freescale Semiconductor, Inc. All Rights Reserved
* Copyright 2019-2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#include "ssrcConverterAccess.h"
#include "ssrcSampleRateConverter.h"
/********************************************************************************
*
*
*******************************************************************************/
extern "C" unsigned getInputOutputTransferTransferUnitSize()
{
    return SsrcSampleQueue<true>::queueMinSampleTransferUnitInWords;
}
