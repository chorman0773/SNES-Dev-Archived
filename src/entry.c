/*
 * main.c
 *
 *  Created on: Nov 13, 2018
 *      Author: chorm
 */

#include <stddef.h>
#include <setjmp.h>

extern volatile unsigned short _FrameCount;

extern unsigned char __stackHead[];
extern unsigned char __stackTail[];

typedef void(init_func)(void);
typedef void(__attribute__((convention(this))) finalizer)(void*);

extern init_func* const __initTabBegin[];
extern init_func* const __initTabEnd[];

void __cxa_finalize(void*);
void __cxa_at_exit(finalizer*,void*,void*);

void main();
void vblank();
void hblank();
void raise(unsigned short);

void debug();

void debug() __attribute__((weak)){

}



#pragma section .text.sys rx $00:8000
void __reset() __attribute__((naked)){
	__builtin_hint_emulation();
	__builtin_disable_interupts();
	__builtin_native();
	__builtin_index16();
	__builtin_acc16();
	__builtin_set_stack_address(__stackTail);
	__builtin_enable_interupts();
	__reset_start();
}
static void __reset_start() __attribute__((noreturn)){
	{
		init_func** _begin = __initTabBegin;
		init_func** _end = __initTabEnd;
		for(init_func** _curr = _begin;_curr!=_end;_curr++)
			(*_curr)();
	}
	main();
	__cxa_finalize(NULL);
	__builtin_stop();
}
void __vblank()__attribute__((convention(interrupt))){
	_FrameCount++;
	vblank();
}

void __abort()__attribute__((convention(interrupt))){
	__cxa_finalize(NULL);
}

void __brk()__attribute__((convention(interrupt))){
	raise(__builtin_accumulator());
}
void __irq()__attribute__((convention(interrupt))){
	if(__builtin_fault_code()==0)
		hblank();
	raise(__builtin_fault_code());
}

void __dbg()__attribute__((convention(interrupt))){
	debug();
}

typedef void(interrupt)(void);

struct __interrupts{
	unsigned __unused;
	__short_pointer(interrupt*) cop;
	__short_pointer(interrupt*) brk;
	__short_pointer(interrupt*) abort;
	__short_pointer(interrupt*) nmi;
	__short_pointer(interrupt*) reset;
	__short_pointer(interrupt*) irq;
}__attribute__((packed));

struct __header_base{
	char name[21];
	unsigned char makeup;
	unsigned char type;
	unsigned char romSz;
	unsigned char sramSz;
	unsigned short license;
	unsigned char version;
}__attribute__((packed));

struct __snes_dev_cartridge_header{
	struct __header_base base;
	unsigned short chksmCmpl;
	unsigned short chksm;
	struct __interrupts native;
	struct __interrupts emulation;
} __attribute__((packed));

#define _NOINT (__short_pointer(interrupt*))(0xFFFF)

#define _SHORT(x) (__builtin_low((&x)))
#pragma section .rodata.init $00:ffc0 force

extern const struct __snes_dev_cartridge_header __head;

const struct __snes_dev_cartridge_header __head = {
		{"",0,0,0,0},~__builtin_checksum(&__head,sizeof(struct __header_base)),__builtin_checksum(&__head,sizeof(struct __header_base)),
		{0,_SHORT(__dbg),_SHORT(__brk),_SHORT(__abort),_SHORT(__vblank),_NOINT,_SHORT(__irq)},
		{0,_NOINT,_NOINT,_NOINT,_NOINT,_SHORT(__reset),_NOINT}
};

