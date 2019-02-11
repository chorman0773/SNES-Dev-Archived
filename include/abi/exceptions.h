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

/**
 * Gets a pointer to the active uncaught exception or null if such an exception does not exist.
 * If called during stack-unwinding, returns a pointer to the exception that is unwinding the stack.
 * If called from an uncaught exceptions sential, returns a pointer to the uncaught exception.
 * Otherwise, returns a null pointer.
 *
 * CAUTION: The returned pointer does not have its refcount updated. If it needs to be updated, call __dup_exception_info() on the returned pointer.
 */
_CDECL struct exception_info* __uncaught_exception()_NOEXCEPT;

/**
 * Allocates a buffer that contains the information needed to throw an exception, and a copy of its first argument.
 * @param obj a pointer to the temporary object that is being thrown or created by std::make_exception_ptr.
 * @param rtti a pointer to the runtime type-identification of the object being thrown.
 * @param _copyctor a pointer to the thiscall function which is used to copy the object to the temporary buffer, or null for a memory copy.
 * @param _dtor a pointer to the thiscall function that destroys the object being thrown after the last instance of the buffer is freed or null for a no-op destructor.
 */
_CDECL struct exception_info* __allocate_exception_buffer(const void* obj,const void* rtti,copyctor* _copyctor,dtor* _dtor)_NOEXCEPT;

/**
 * Duplicates an exception buffer.
 * If the pointer has been freed already, or is not the result of __allocate_exception_buffer, the behavior is undefined.
 * Otherwise, increases the reference count of the exception object pointed to by buff
 */
_CDECL void __dup_exception_buffer(struct exception_info* buff)_NOEXCEPT;

/**
 * Frees an exception buffer.
 * If the pointer has been freed already or is not the result of__allocate_exception_buffer, the behavior is undefined.
 * Otherwise, if the refcount is 0 then calls the destructor of the object then frees the buffer.
 * Otherwise, decrements the refcount by 1.
 */
_CDECL void __free_exception_buffer(struct exception_info* buff)_NOEXCEPT;
/**
 * Counts the total number of uncaught exceptions.
 * Returns the number of types that __throw is called and a matching call to __unwind_end has not been made be the code.
 */
_CDECL int __uncaught_exceptions()_NOEXCEPT;

/**
 * Throws an exception given by info at the address specified by addr.
 * If pcaddr is not some address during the statement which calls __throw, the behavior is undefined.
 *
 * Except that if throw is tailcalled, then it shall be the return address of the invocation that makes the tailcall.
 *
 * The statement:
 * throw e;
 *
 * Is the same as the following C++ Code
 * _Throw:{
 * 	struct exception_info* info = __allocate_exception_buffer(*address-of*(e),&typeid(*correct-type*(e)),__builtin_copy_constructor(*correct-type*(e)),__builtin_destructor(*correct-type*(e)))
 * 	__throw(info,&&_Throw);
 * }
 *
 * Where, *address-of*(e) is defined as std::addressof(e) if e is an lvalue, otherwise std::addressof(__expn) if e is an x-value or pr-value where __expn is defined as const auto&&, and is initialized with e.
 * and *correct-type*(e) is std::decay_t<decltype(e)>
 *
 * Except that The declaration of the label _Throw is only visible to the block scope, and previous and subsequent declarations of _Throw are ignored.
 */
_CDECL _Noreturn _Noreturn_t __throw(struct exception_info*,pcaddr)_NOEXCEPT;
_CDECL void __do_unwind()_NOEXCEPT;
_CDECL void __unwind_end(pcaddr)_NOEXCEPT;
_CDECL void __set_uncaught_exception_sentinal(pcaddr)_NOEXCEPT;

#endif /* INCLUDE_ABI_EXCEPTIONS_H__2018_12_362_13_29_15 */
