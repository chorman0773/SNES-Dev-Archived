/*
 * gc-ints.h
 *
 *  Created on: Nov 23, 2018
 *      Author: chorm
 */

#ifndef QC_GC_INTS_H__2018_11_327_00_15_53
#define QC_GC_INTS_H__2018_11_327_00_15_53

#include <snes-dev/qc/inttypes.h>


__inline__ unsigned char __builtinqc_mul8(unsigned char a,unsigned char b) __attribute__((intrinsic,always_inline,naked)){
	__builtin_acc8();
	__builtin_accumulator() = a;
	__asm__ volatile("sta $00:4202");
	__builtin_accumulator() = b;
	__asm__ volatile("sta $00:4203");
	__asm__ volatile("lda $00:4216");
	return __builtin_accumulator();
}

typedef struct div8_result{
	unsigned char quotient;
	unsigned char remainder;
} div8_result_t;

__inline__ div8_result_t __builtinqc_div8(unsigned char a,unsigned char b) __attribute__((intrinsic,always_inline)){
	div8_result_t res;
	__builtin_acc8();
	__builtin_accumulator() = a;
	__asm__ volatile("sta $00:4204");
	__asm__ volatile("stz $00:4205");
	__builtin_accumulator() = b;
	__asm__ volatile("sta $00:4206");
	__asm__ volatile("lda $00:4214");
	res.quotient = __builtin_accumulator();
	__asm__ volatile("lda $00:4216");
	res.remainder = __builtin_accumulator();
	return res;
}

__inline__ unsigned short __builtinqc_mul16_8(unsigned short a,unsigned char b) __attribute__((intrinsic,always_inline)){
	__builtin_acc8();
	__builtin_accumulator() = a&0xff;
	__asm__ volatile("sta $00:211B");
	__builtin_accumulator() = a>>8;
	__asm__ volatile("sta $00:211B");
	__builtin_accumulator() = b;
	__asm__ volatile("sta $00:211C");
	__asm__ volatile("ldx $00:2124");
	return __builtin_indexX();
}


#endif /* QC_GC_INTS_H__2018_11_327_00_15_53 */
