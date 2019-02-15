/*
 * qcdefs.h
 *
 *  Created on: Nov 26, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_QC_QCDEFS_H__2018_11_330_16_34_48
#define INCLUDE_SNES_DEV_QC_QCDEFS_H__2018_11_330_16_34_48

#ifdef __cplusplus
#define _CDECL extern "C"
#else
#define _CDECL
#endif

#ifndef __cplusplus
#define inline __inline__
#endif


#define __intrinsic _CDECL inline

#define __convention __attribute__((convetion(intrinsic)))

#ifdef __OAPI_CAN_ACCESS_LLVMDEFS
#define _LLVMDEFINE_OP(op,type,intrinsic) _Pragma(opai bindop op type intrinsic);
#define _LLVMDEFINEINTRINSIC(name,expn) _Pragma(oapi createintrinsic name expn);
#else
#define _LLVMDEFINE_OP(op,type,intrinsic)
#define _LLVMDEFINEINTRINSIC(name,expn)
#endif
#define _QCMkType(name,underlying,size,kind)

#define _QCBindType(Type,Tag,Underlying,QCType)



#define _QCOP2(type,prefix,suffix,name)\
	_CDECL __qc##type __qc_##prefix##name##suffix(__qc##type _1,__qc##type _2) __convention;\
	__intrinsic type __builtin_##prefix##name##suffix(type _1,type _2) __convention{\
		__qc##type __val_1 = {.val = _1};\
		__qc##type __val_2 = {.val = _2};\
		return __qc_##prefix##name##suffix(__val_1,__val_2).val;\
	}\
	_LLVMDEFINEINTRINSIC(__builtin_##prefix##name##suffix,__builtin_##prefix##name##suffix);

#define _QCOP1(type,prefix,suffix,name)\
	_CDECL __qc##type __qc_##prefix##name##suffix(__qc##type _1) __convention;\
	__intrinsic type __builtin_##prefix##name##suffix(type _1) __convention{\
		__qc##type __val_1 = {.val = _1};\
		return __qc_##prefix##name##suffix(__val_1).val;\
	}\
	_LLVMDEFINEINTRINSIC(__builtin_##prefix##name##suffix,__builtin_##prefix##name##suffix);


#define _QCBINDOP(type,prefix,suffix,name) _LLVMDEFINE_OP(name,type,__builtin_##prefix##name##suffix)

#define _QCDEFINEQCOPS(type,suffix,QCType)\
	_QCOP2(type,,suffix,add)\
	_QCOP2(type,,suffix,sub)\
	_QCOP2(type,,suffix,mul)\
	_QCOP2(type,,suffix,div)\
	_QCOP1(type,,suffix,umn)\
	_QCBINDOP(type,,suffix,add)\
	_QCBINDOP(type,,suffix,sub)\
	_QCBINDOP(type,,suffix,mul)\
	_QCBINDOP(type,,suffix,div)\
	_QCBINDOP(type,,suffix,umn)

#define _QCDEFINEQCBITOPS(type,suffix,QCType)\
	_QCOP2(type,b,suffix,and)\
	_QCOP2(type,b,suffix,or)\
	_QCOP2(type,b,suffix,xor)\
	_QCOP2(type,b,suffix,lsh)\
	_QCOP2(type,b,suffix,rsh)\
	_QCOP1(type,b,suffix,not)\
	_QCBINDOP(type,b,suffix,and)\
	_QCBINDOP(type,b,suffix,or)\
	_QCBINDOP(type,b,suffix,xor)\
	_QCBINDOP(type,b,suffix,lsh)\
	_QCBINDOP(type,b,suffix,rsh)\
	_QCBINDOP(type,b,suffix,not)

#define _QC_DEFINE_FPMATHINTRINSICS(type,QCType,Suffix,Tag)\
	_QCOP1(type,m,Tag,sqrt)\
	_QCOP1(type,m,Tag,cbrt)\
	_QCOP2(type,m,Tag,pow)\
	_QCOP1(type,m,Tag,exp)\
	_QCOP2(type,m,Tag,fma)\
	_QCOP1(type,m,Tag,exp2)\
	_QCOP1(type,m,Tag,expm1)\
	_QCOP1(type,m,Tag,log)\
	_QCOP1(type,m,Tag,log2)\
	_QCOP1(type,m,Tag,log10)\
	_QCOP1(type,m,Tag,logp1)\
	_QCOP2(type,m,Tag,hypot)\
	_QCOP1(type,m,Tag,sin)\
	_QCOP1(type,m,Tag,cos)\
	_QCOP1(type,m,Tag,tan)\
	_QCOP1(type,m,Tag,sinh)\
	_QCOP1(type,m,Tag,cosh)\
	_QCOP1(type,m,Tag,tanh)\
	_QCOP1(type,m,Tag,asin)\
	_QCOP1(type,m,Tag,acos)\
	_QCOP1(type,m,Tag,atan)\
	_QCOP1(type,m,Tag,asinh)\
	_QCOP1(type,m,Tag,acosh)\
	_QCOP1(type,m,Tag,atanh)\
	_QCOP1(type,m,Tag,erf)\
	_QCOP1(type,m,Tag,erfc)\
	_QCOP1(type,m,Tag,tgamma)\
	_QCOP1(type,m,Tag,lgamma)\
	_QCOP1(type,m,Tag,invsqrt)


#define _QC_FPNOTE(tstrict,type)

#define __strict strict
#define __relaxed


#define _QCIntegral 1
#define _QCFloat 2
#define _QCSpecial 128

#pragma macros hide(push,*)
#define __qc_oapi_dotypedef0(name,qcname,sizetag,aligntag,...)
#pragma macros hide(pop)
#pragma macros import("__qc_oapi_dotypedef",name,qcname,sizetag,aligntag,...) define("__qc_oapi_dotypedef0",name,qcname,underlyingtag,sizetag,aligntag,...)

#define __qc_oapi_dotypedef(name,qcname,sizetag,aligntag,...) __qc_oapi_dotypedef0(name,qcname,sizetag,aligntag,__VA_ARGS__); typedef name qcname

#pragma macros hide(push,*)
#define __qc_oapi_mkconversion(from,to,cvtfunc,...)
#pragma macros hide(pop)
#pragma macros import("__qc_def",from,to,cvtfunc,...) define("__qc_def",from,to,cvtfunc,...)

#define _QCSPECIAL __qcspecial
#define _QCFLOAT __qcfloatp
#define _QCSTRICT __qcstrictfp
#define _QCSZ(size) __qcsz_##size
#define _QCALIGN(align) __qcalign##align
#define _QCUNDERLYING(underlying) __qcunderlying_##underlying
#define _QCNAME(name) __qc_##name
#define _QCSIGNED __qcint_signed2scompl
#define _QCUNSIGNED __qcint_unsigned
#define _QCSUFFIX(sfx) __qcsuffix_##sfx

#define _QCNARROWING __qccvt_prop_narrowing
#define _QCEXPLICIT __qccvt_prop_explicit

#endif /* INCLUDE_SNES_DEV_QC_QCDEFS_H__2018_11_330_16_34_48 */
