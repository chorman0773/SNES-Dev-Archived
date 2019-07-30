/*
 * gc-ints.h
 *
 *  Created on: Nov 23, 2018
 *      Author: chorm
 */

#ifndef QC_GC_INTS_H__2018_11_327_00_15_53
#define QC_GC_INTS_H__2018_11_327_00_15_53

#include <bits/cdecl.h>
#include <qc/inttypes.h>

#define __MK_INT_HELPER_TYPES(type,bits)\
	typedef struct __div##bits{\
		type __quo;\
		type __rem;\
	} __qc_div##bits;

#define __DEF_INT_UOP(name,type,bits)\
	_CDECL type __qc_i##bits##name(type __a);

#define __DEF_INT_BOP(name,type,bits)\
		_CDECL type __qc_i##bits##name(type __a,type __b);

#define __DEF_INT_DIV(type,bits)\
		__qc_div##bits __qc_i##bits##div_op(type __de,type __dv);\
		_CDECL __inline__ type __qc_i##bits##div(type __de,type __dv){\
			return __qc_i##bits##div_op(__de,__dv).__quo;\
		}\
		_CDECL __inline type __qc_i##bits##mod(type __de,type __dv){\
			return __qc_i##bits##div_op(__de,__dv).__rem;\
		}

#define __DEF_INT_OPS(type,bits)\
	__MK_INT_HELPER_TYPES(type,bits);\
	__DEF_INT_UOP(umn,type,bits);\
	__DEF_INT_BOP(add,type,bits);\
	__DEF_INT_



#endif /* QC_GC_INTS_H__2018_11_327_00_15_53 */
