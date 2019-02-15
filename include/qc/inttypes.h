/*
 * inttypes.h
 *
 *  Created on: Nov 28, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38
#define INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38

#include <snes-dev/qc/qcdefs.h>

#ifdef __cplusplus
#define __SIZE_TYPE__ decltype(sizeof(int))
#else
#define __SIZE_TYPE__ __typeof__(sizeof(int))
#endif

#ifdef __cplusplus
#define __DIFF_TYPE__ decltype(((int*)0)-((int*)0))
#else
#define __DIFF_TYPE__ __typeof__(((int*)0)-((int*)0))
#endif

#ifndef __cplusplus
typedef __typeof__(L'\0') wchar_t;
typedef __typeof__(u'\u0000') char16_t;
typedef __typeof__(U'\U00000000') char32_t;
#endif

#ifdef __cplusplus
#define __INT128_TYPE__ decltype(0x7fffffffffffffffffffffffffffffffi128)
#define __UINT128_TYPE__ decltype(0xffffffffffffffffffffffffffffffffu128)
#else
#define __INT128_TYPE__ __typeof__(0x7fffffffffffffffffffffffffffffffi128)
#define __UINT128_TYPE__ __typeof__(0xffffffffffffffffffffffffffffffffi128)
#endif


//Basic Typedef for 16-byte (really long) integers
typedef __INT128_TYPE__ _UInt128;
typedef __UINT128_TYPE__ _Int128; // @suppress("Function cannot be resolved")

//QC Definitions
 // @suppress("Function cannot be resolved")


//Stuff for <stdint.h>
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned uint32_t;
typedef int int32_t;
typedef unsigned long long uint64_t;
typedef long long int64_t;
typedef __SIZE_TYPE__ size_t;
typedef __DIFF_TYPE__ ptrdiff_t;
typedef long intptr_t;
typedef unsigned long uintptr_t;
typedef _UInt128 uint128_t;
typedef _Int128 int128_t;

typedef unsigned char uint_least8_t;
typedef signed char int_least8_t;
typedef unsigned short uint_least16_t;
typedef short int_least16_t;
typedef unsigned uint_least32_t;
typedef int int_least32_t;
typedef unsigned long long uint_least64_t;
typedef long long int_least64_t;

typedef unsigned short uint_fast8_t;
typedef short int_fast8_t;
typedef unsigned short uint_fast16_t;
typedef short int_fast16_t;
typedef unsigned uint_fast32_t;
typedef int int_fast32_t;
typedef unsigned long long uint_fast64_t;
typedef long long int_fast64_t;

typedef _UInt128 uintmax_t;
typedef _Int128 intmax_t;

#define INT8_MIN (int8_t)(-128)
#define INT8_MAX (int8_t)(127)
#define UINT8_MIN (uint8_t)(0)
#define UINT8_MAX (uint8_t)(255)
#define INT_FAST8_MIN (int_fast8_t)(-128)
#define INT_FAST8_MAX (int_fast8_t)(127)
#define UINT_FAST8_MIN (uint_fast8_t)(0)
#define UINT_FAST8_MAX (uint_fast8_t)(255)
#define INT_LEAST8_MIN (int_least8_t)(-128)
#define INT_LEAST8_MAX (int_least8_t)(127)
#define UINT_LEAST8_MIN (uint_least8_t)(0)
#define UINT_LEAST8_MAX (uint_fast8_t)(255)
#define INT16_MIN (int16_t)(-32768)
#define INT16_MAX (int16_t)(32767)
#define UINT16_MIN (uint16_t)(0)
#define UINT16_MAX (uint16_t)(65535)
#define INT_FAST16_MIN (int_fast16_t)(-32768)
#define INT_FAST16_MAX (int_fast16_t)(32767)
#define UINT_FAST16_MIN (uint_fast16_t)(0)
#define UINT_FAST16_MAX (uint_fast16_t)(65535)
#define INT_LEAST16_MIN (int_least16_t)(-32768)
#define INT_LEAST16_MAX (int_least16_t)(32767)
#define UINT_LEAST16_MIN (uint_least16_t)(0)
#define UINT_LEAST16_MAX (uint_least16_t)(65535)
#define INT32_MIN (int32_t)(-0x80000000)
#define INT32_MAX (int32_t) (0x7fffffff)
#define UINT32_MIN (uint32_t)(0)
#define UINT32_MAX (uint32_t)(0xfffffff)
#define INT_LEAST32_MIN (int_least32_t)(-0x80000000)
#define INT_LEAST32_MAX (int_least32_t) (0x7fffffff)
#define UINT_LEAST32_MIN (uint_least32_t)(0)
#define UINT_LEAST32_MAX (uint_least32_t)(0xfffffff)
#define INT_FAST32_MIN (int_fast32_t)(-0x80000000)
#define INT_FAST32_MAX (int_fast32_t) (0x7fffffff)
#define UINT_FAST32_MIN (uint_fast32_t)(0)
#define UINT_FAST32_MAX (uint_fast32_t)(0xfffffff)
#define INT64_MIN (int64_t)(-0x8000000000000000)
#define INT32_MAX (int64_t) (0x7fffffffffffffff)
#define UINT32_MIN (uint64_t)(0)
#define UINT32_MAX (uint64_t)(0xfffffffffffffff)
#define INT_LEAST64_MIN (int_least64_t)(-0x8000000000000000)
#define INT_LEAST64_MAX (int_least64_t) (0x7fffffffffffffff)
#define UINT_LEAST64_MIN (uint_least64_t)(0)
#define UINT_LEAST64_MAX (uint_least64_t)(0xfffffffffffffff)
#define INT_FAST64_MIN (int_fast64_t)(-0x8000000000000000)
#define INT_FAST64_MAX (int_fast64_t) (0x7fffffffffffffff)
#define UINT_FAST64_MIN (uint_fast64_t)(0)
#define UINT_FAST64_MAX (uint_fast64_t)(0xfffffffffffffff)


#define INTMAX_MIN (intmax_t)(-0x80000000000000000000000000000000i128)
#define INTMAX_MAX (intmax_t)(0x7ffffffffffffffffffffffffffffffi128)
#define UINTMAX_MAX (uintmax_t)(0xffffffffffffffffffffffffffffffu128)
#define UINTMAX_MAX (uintmax_t)(0)

#define SIZE_MAX (size_t)(0xffff)
#define PTRDIFF_MAX (ptrdiff_t)(0x7fff)
#define PTRDIFF_MIN (ptrdiff_t)(-0x8000)
#define SIZE_MIN (size_t)(0)


#endif /* INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38 */
