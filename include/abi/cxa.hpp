/*
 * cxa.hpp
 *
 *  Created on: Dec 3, 2018
 *      Author: chorm
 */

#ifndef __INCLUDE_ABI_CXA_HPP__2018_12_03_11_42_46
#define __INCLUDE_ABI_CXA_HPP__2018_12_03_11_42_46

#include <bits/cdecl.h>


typedef void* pcaddr;

typedef void(__attribute__((convention(this))) thiscallfn)(void*);

typedef thiscallfn dtor;
typedef void(__attribute__((convention(this))) copyctor)(void*,const void*);

struct vtable{
	const void* __typeid;
	short __mdoOff;
	thiscallfn* __vfunc[];
};

struct unwind_dtor_handler{
	pcaddr __start;
	pcaddr __end;
	dtor* __dtor;
	short __frameBaseOffset;
};

struct exception_info{
	void* except;
	const void* rtti;
	dtor* __dtor;
	copyctor* __copyctor;
};

_CDECL const vtable* __cxa_getvtable(void*);

_CDECL const void* __cxa_typeid(void*);

_CDECL void* __cxa_dynamic_cast(void*,const void*);



#endif /* __INCLUDE_ABI_CXA_HPP__2018_12_03_11_42_46 */
