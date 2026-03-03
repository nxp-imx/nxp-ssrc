/********************************************************************************
* Copyright 2024 NXP
*
* SPDX-License-Identifier: BSD-3-Clause
*******************************************************************************/
#ifndef ssrcWrapper_h
#define ssrcWrapper_h

#include <stdio.h>
#include <inttypes.h>

struct SsrcConverterInstance;

#ifdef __cplusplus
extern "C" {
#endif

struct SsrcConverterInstance* ssrc_wrapper_create(void);

void ssrc_wrapper_detroy(struct SsrcConverterInstance *instance);

int ssrc_wrapper_config(struct SsrcConverterInstance **instance, int sampleFormat, int channels, int input_rate, int output_rate, int quality);

int ssrc_wrapper_process(struct SsrcConverterInstance *instance, size_t in_chunk, size_t *out_chunk, int32_t *in_p, int32_t *out_p);

#ifdef __cplusplus
}
#endif

#endif
