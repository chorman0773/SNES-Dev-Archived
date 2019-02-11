/*
 * exception.cpp
 *
 *  Created on: Jan 7, 2019
 *      Author: chorm
 */

#include <abi/exceptions.h>
#include <exception>
#include <cstddef>
#include <typeinfo>
#include <new>

unsigned char __bad_alloc_exception_buffer[sizeof(struct exception_info)+sizeof(std::bad_alloc)];

void* _CurrentExceptionSentinal[30];
std::ptrdiff_t _CurrentExceptionSentinalPtr;

struct exception_info* _CurrentUncaughtException{};
int _UncaughtExceptionCount{};

exception_info* __uncaught_exception()noexcept{
	return _CurrentUncaughtException;
}

int __uncaught_exceptions()noexcept{
	return _UncaughtExceptionCount;
}

struct exception_info* __allocate_bad_alloc(){
	struct exception_info* ebuff = new(__bad_alloc_exception_buffer) exception_info;
	ebuff->except = ebuff->buffer;
	ebuff->__copyctor = __builtin_copy_constructor(std::bad_alloc);
	ebuff->__dtor = __builtin_destructor(std::bad_alloc);
	ebuff->refcount = 0;
	ebuff->rtti = &typeid(std::bad_alloc);
	new(ebuff->buffer) std::bad_alloc{};
	return ebuff;
}

struct exception_info* __allocate_exception_buffer(const void* obj,const void* rtti,copyctor* _copyctor,dtor* _dtor)noexcept{
	__set_uncaught_exception_sentinal((pcaddr)&&_UncaughtSential);
	const std::size_t sz = sizeof(struct exception_info)+static_cast<std::size_t>(reinterpret_cast<const std::type_info*>(rtti)->__size());
	struct exception_info* ebuff = (struct exception_info*) operator new(sz);
	new(ebuff) exception_info{};
	ebuff->__copyctor = _copyctor;
	ebuff->__dtor = _dtor;
	ebuff->refcount = 0;
	ebuff->rtti = rtti;
	ebuff->except = ebuff->buffer;
	if(_copyctor)
		_copyctor(ebuff->buffer,obj);
	else
		__builtin_memcpy(ebuff->buffer,obj,sz);
	return ebuff;
	_UncaughtSential:
	{
		if(__uncaught_exception()->rtti->hash_code()==typeid(std::bad_alloc).hash_code())
			return __uncaught_exception();
		std::bad_exception b{};
		return __allocate_exception_buffer(&b,&typeid(std::bad_exception),__builtin_copy_constructor(std::bad_exception),__builtin_destructor(std::bad_exception));
	}
}

void __dup_exception_buffer(struct exception_info* ebuff)noexcept{
	__builtin_atomic_start();
	ebuff->refcount++;
	__builtin_atomic_end();
}

void __free_exception_buffer(struct exception_info* ebuff)noexcept{
	__builtin_atomic_start();
	if(ebuff->refcount)
		ebuff->refcount--;
	else{
		if(ebuff->__dtor)
			ebuff->__dtor(ebuff->except);
		operator delete(ebuff);
	}
	__builtin_atomic_start();
}

using namespace std;

int std::uncaught_exceptions()noexcept{
	return __uncaught_exceptions();
}

__exception_ptr::__exception_ptr(const __exception_ptr& p):_M_buff{p._M_buff}{
	if(_M_buff)
		__dup_exception_buffer(_M_buff);
}
__exception_ptr::__exception_ptr(__exception_ptr&& p):_M_buff{std::exchange(p._M_buff,nullptr)}{}

__exception_ptr::~__exception_ptr(){
	if(_M_buff)
		__free_exception_buffer(_M_buff);
}

[[noreturn]] void __exception_ptr::__rethrow(){
	 __builtin_tailcall(__throw,_M_buff,__builtin_return_address());
}


void __throw(struct __exception_info* __buff,pcaddr __addr){

}
