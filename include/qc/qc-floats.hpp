/*
 * qc-floats.h
 *
 *  Created on: Nov 26, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_QC_QC_FLOATS_H__2018_11_330_17_07_54
#define INCLUDE_SNES_DEV_QC_QC_FLOATS_H__2018_11_330_17_07_54

#include <qc/qcdefs.h>
#include <qc/inttypes.h>
#include <qc/floattypes.h>

typedef long double _LDouble;

#define _QCMKBinaryFP(FPType, BitsT, Tag, Size,ExpBits,SigBits,Strict)\
	_QCMkType(FPType,BitsT,Size,_QCFloat);\
	typedef union __qc_float##Size{\
		BitsT bits: Size;\
		FPType val;\
		struct{\
			BitsT sign:1;\
			BitsT exp: ExpBits;\
			BitsT sig: SigBits;\
		}rep;\
	} __qc##FPType;\
	_QCDEFINEQCOPS(FPType,Tag,__qc##FPType);\
	_QC_DEFINE_FPMATHINTRINSICS(FPType,__qc##FPType,float##Size,Tag);

_QCMKBinaryFP(float,unsigned,f,32,8,23,__strict);
_QCMKBinaryFP(double,unsigned long long,d,64,11,52,__strict);
_QCMKBinaryFP(_LDouble,_UInt128,l,128,15,112,__relaxed);
_QCMKBinaryFP(_Float16,unsigned short,fh,16,5,10,__relaxed);

#endif /* INCLUDE_SNES_DEV_QC_QC_FLOATS_H__2018_11_330_17_07_54 */
