/*
 * setjmp.h
 *
 *  Created on: Dec. 28, 2018
 *      Author: connor
 */

#ifndef INCLUDE_STDC_SETJMP_H__2018_12_362_13_34_29
#define INCLUDE_STDC_SETJMP_H__2018_12_362_13_34_29

#include <bits/cdecl.h>

typedef struct __jmpbuff{
	void* addr;
	void* stackBase;
	void* stackPointer;
}jmpbuff;

_CDECL int __setjmp(jmpbuff*);
_CDECL _Noreturn _Noreturn_t __longjmp(const jmpbuff*,int);

#define setjmp(buff) __setjmp(&buff)
#define longjmp(buff,val) __longjmp(&buff,val)

#endif /* INCLUDE_STDC_SETJMP_H__2018_12_362_13_34_29 */
