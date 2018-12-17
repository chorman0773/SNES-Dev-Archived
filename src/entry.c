/*
 * main.c
 *
 *  Created on: Nov 13, 2018
 *      Author: chorm
 */

#include <stddef.h>
#include <registers.h>
void* ebp =0;

extern unsigned char stackHead[];
extern unsigned char stackTail[];

typedef void(init_func)(void);
typedef void(__attribute__((convention(this))) finalizer)(void*);

extern init_func* const initTabBegin[];
extern init_func* const initTabEnd[];

void __cxa_finalize(void*);
void __cxa_at_exit(finalizer*,void*,void*);

void main();
void vblank();
void hblank();
void sig(unsigned short);

struct reg{
	unsigned short A;
	unsigned short X;
	unsigned short Y;
};


#pragma section .sys rx $00:8000
void __reset() __attribute__((naked)){
	__builtin_hint_emulation();
	__builtin_disable_interupts();
	__builtin_native();
	__builtin_index16();
	__builtin_acc16();
	__builtin_set_stack_address(stackTail);
	__builtin_enable_interupts();
	{
		init_func** _begin = initTabBegin;
		init_func** _end = initTabEnd;
		for(init_func** _curr = _begin;_curr!=_end;_curr++)
			(*_curr)();
	}
	main();
	__cxa_finalize(NULL);
	__builtin_stop();
}
void __vblank()__attribute__((convention(interrupt))){
	vblank();
}

void __abort()__attribute__((convention(interrupt))){
	__cxa_finalize(NULL);
}

void __brk()__attribute__((convention(interrupt))){
	sig(__builtin_accumulator());
}
void __irq()__attribute__((convention(interrupt))){
	if(__builtin_fault_code()==0)
		hblank();
	sig(__builtin_fault_code());
}

void __dbg()__attribute__((convention(interrupt))){

}

#pragma section .header r $00:f000
#pragma comment "Cartridge Header"
#pragma position set $00:ffc0 force
#pragma pack on
const char name[21] = "SNES Homebrew Test";
const unsigned char makeup = 0;
const unsigned char type = 0;
const unsigned char romSize = __builtin_size("rom");
const unsigned char sramSize = __builtin_size("pram");
#pragma position set $00:ffe4 force
#pragma comment "Header Interrupt Vectors (Native)"
const unsigned short cop_n = __builtin_short(&__dbg);
const unsigned short brk_n = __builtin_short(&__brk);
const unsigned short abort_n = __builtin_short(&__abort);
const unsigned short nmi_n = __builtin_short(&__vblank);
const unsigned short reset_n = 0xffff;
const unsigned short irq_n = __builtin_short(&__irq);
#pragma position set $00:fff4 force
const unsigned short cop_e = 0xffff;
const unsigned short abort_e = 0xffff;
const unsigned short nmi_e = 0xffff;
const unsigned short reset_e = __builtin_short(&__reset);
const unsigned short brk_e = 0xffff;
const unsigned short irq_e = 0xffff;
