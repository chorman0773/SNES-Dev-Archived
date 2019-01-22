/*
 * Ops65816.hpp
 *
 *  Created on: Jan 17, 2019
 *      Author: chorm
 */

#ifndef CODEGEN_OPS65816_HPP__2019_01_17_02_10_21
#define CODEGEN_OPS65816_HPP__2019_01_17_02_10_21

#include <cstdint>

enum class Opcodes:std::uint8_t{

};

enum class MemoryMappedRegisters: std::uintptr_t{
	 SCRN_DISP = 0x2100,
	 OAM_SZDT_DESG = 0x2101,
	 OAM_ADDR = 0x2102,
	 OAM_DTWR = 0x2104,
	 BG_TLSZ_MD = 0x2105,
	 MOSSZ_BGEN = 0x2106,
	 BG1_ADDR = 0x2107,
	 BG2_ADDR 0x2108,
	 BG3_ADDR = 0x2109,
	 BG4_ADDR = 0x210A
};



#endif /* CODEGEN_OPS65816_HPP__2019_01_17_02_10_21 */
