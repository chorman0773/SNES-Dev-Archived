/*
 * cdecl.h
 *
 *  Created on: Dec 3, 2018
 *      Author: chorm
 */

#ifndef INCLUDE_BITS_CDECL_H__2018_12_337_11_45_15
#define INCLUDE_BITS_CDECL_H__2018_12_337_11_45_15

#ifdef __cplusplus
#define _CDECL extern"C"
#define _NOEXCEPT noexcept
#else
#define _CDECL
#define _NOEXCEPT
#endif


#define _Noreturn __attribute__((noreturn))

typedef void _Noreturn_t;

#endif /* INCLUDE_BITS_CDECL_H__2018_12_337_11_45_15 */
