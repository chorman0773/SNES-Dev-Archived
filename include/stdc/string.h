/*
 * string.h
 *
 *  Created on: Nov 29, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_STDC_STRING_H__2018_11_333_23_01_39
#define INCLUDE_STDC_STRING_H__2018_11_333_23_01_39

#include <snes-dev/qc/inttypes.h>


#define memcpy(src,dest,size) __builtin_memcpy(__builtin_bank((src)),__builtin_bank((dest)),__builtin_address((src)),__builtin_address((dest)),(size))
#define memmove(src,dest,size) __builtin_memcpy(__builtin_bank((src)),0x7e,__builtin_address((src)),0x0000,size);__builtin_memcpy(0x7e,__builtin_bank((dest)),0x0000,__builtin_address((dest)))
#define memset(target,byte,size) __builtin_memset(target,byte,size)

size_t strlen(const char* str);


#endif /* INCLUDE_STDC_STRING_H__2018_11_333_23_01_39 */
