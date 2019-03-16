/*
 * floattypes.h
 *
 *  Created on: Nov 28, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_QC_FLOATTYPES_H__2018_11_332_10_38_21
#define INCLUDE_SNES_DEV_QC_FLOATTYPES_H__2018_11_332_10_38_21

#include <qc/qcdefs.h>
#include <qc/inttypes.h>

#ifndef __cplusplus
#define __FLOAT16_TYPE__ __typeof__(1.hf)
#else
#define __FLOAT16_TYPE__ decltype(1.hf)
#endif

typedef __FLOAT16_TYPE__ _Float16; // @suppress("Function cannot be resolved")

typedef _Float16 float16_t;



float __builtin_infinityf() __attribute__((intrinsic));
double __builtin_infinity() __attribute__((intrinsic));
long double __builtin_infinityl() __attribute__((intrinsic));
float16_t __builtin_infinityh() __attribute__((intrinsic));








#endif /* INCLUDE_SNES_DEV_QC_FLOATTYPES_H__2018_11_332_10_38_21 */
