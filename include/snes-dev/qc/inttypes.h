/*
 * inttypes.h
 *
 *  Created on: Nov 28, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38
#define INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38

#include <snes-dev/qc/qcdefs.h>

//Basic Typedef for 16-byte (really long) integers
typedef unsigned long long _UInt128 __attribute__((align(16),size(16),qcsize(128)));
typedef long long _Int128 __attribute__((align(16),size(16),qcsize(128)));



#endif /* INCLUDE_SNES_DEV_QC_INTTYPES_H__2018_11_332_11_09_38 */
