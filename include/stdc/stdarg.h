/*
 * stdarg.h
 *
 *  Created on: Jul 29, 2019
 *      Author: chorm
 */

#ifndef INCLUDE_STDC_STDARG_H__2019_07_29_09_48_44
#define INCLUDE_STDC_STDARG_H__2019_07_29_09_48_44

#ifndef __va_list_type
#define __va_list_type char*
#endif

typedef __va_list_type va_list;

#define va_start(list,lastarg) __builtin_va_start(list,lastarg)
#define va_end(list) __builtin_va_end(list)
#define va_arg(list,type) (type)__builtin_va_arg(list,sizeof(type))

#define __va_copy(list1,list2) __builtin_va_copy(list1,list2)


#ifdef __want_va_copy
#define va_copy(list1,list2) __va_copy(list1,list2)
#endif

#endif /* INCLUDE_STDC_STDARG_H__2019_07_29_09_48_44 */
