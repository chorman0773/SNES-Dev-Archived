/*
 * exceptions.h
 *
 *  Created on: Dec. 28, 2018
 *      Author: connor
 */

#ifndef INCLUDE_ABI_EXCEPTIONS_H__2018_12_362_13_29_15
#define INCLUDE_ABI_EXCEPTIONS_H__2018_12_362_13_29_15

#include <bits/cdecl.h>
#include <abi/cxa.hpp>
#include <setjmp.h>

_CDECL struct exception_info* __uncaught_exception();
_CDECL struct exception_info* __mk_exception_info(void*,const void*,copyctor,dtor);
_CDECL void __dup_exception_info(struct exception_info*);
_CDECL void __free_exception_info(struct exception_info*);
_CDECL int __uncaught_exceptions();

_CDECL void __throw(const struct exception_info*,pcaddr);
_CDECL void __do_unwind();
_CDECL void __unwind_end(pcaddr);
_CDECL void __set_uncaught_exception_sentinal(jmpbuff*,pcaddr);

#endif /* INCLUDE_ABI_EXCEPTIONS_H__2018_12_362_13_29_15 */
