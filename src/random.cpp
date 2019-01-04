/*
 * random.cpp
 *
 *  Created on: Jan 3, 2019
 *      Author: chorm
 */

#include <random>
#include <cstdint>
#include <string>
extern "C"{
#include <stdlib.h>
};

struct _LFSR{
private:
	std::uint16_t bits:15;
public:
	explicit _LFSR(std::uint16_t val):bits{val}{}
	explicit operator std::uint16_t(){
		__builtin_atomic_start();
		std::uint16_t out{bits};
		bits >>=1;
		std::uint16_t bit{(out&0x1)^(bits&0x1)};
		std::uint16_t pattern{bit<<7|bit<<15};
		bits = (bits&0x3f7f)|pattern;
		__builtin_atomic_end();
		return out;
	}
};

static std::uint16_t genPeusdoRandomBits(){
	static _LFSR lfsr{0x3f7f^__builtin_joypad1()};
	return static_cast<std::uint16_t>(lfsr);
}

static unsigned int hash(const std::string& s){
	unsigned int hash{};
	for(char c:s)
		hash *=93438271, hash +=(static_cast<unsigned int>(c)*37233473);
	return hash;
}

std::random_device::random_device():_M_khash(hash("SNES-DEV")){}
std::random_device::random_device(const std::string& s):_M_khash(hash(s)){}

unsigned int std::random_device::operator()(){
	_M_khash ^= genPeusdoRandomBits();
	_M_khash = _M_khash>>7|_M_khash<<(32-7);
	_M_khash += __builtin_rtc_nanos();
	return _M_khash;
}

double std::random_device::enthropy()const noexcept{
	return 0;
}

static std::linear_congruential_engine<unsigned long long,0x5DEECE66DuLL,0xBuLL,0xFFFFFFFFFFFFuLL>& _GetRandGenerator(){
	static std::linear_congruential_engine<unsigned long long,0x5DEECE66DuLL,0xBuLL,0xFFFFFFFFFFFFuLL> generator{};
	return generator;
}

extern"C"{
	void srand(unsigned __seed){
		__builtin_atomic_begin();
		_GetRandGenerator().seed(__seed);
		__builtin_atomic_end();
	}

	int rand(){
		__builtin_atomic_begin();
		int val = static_cast<int>((_GetRandGenerator()())>>17);
		__builtin_atomic_end();
		return val;
	}
};


