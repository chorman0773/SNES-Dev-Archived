/*
 * qc-float.cpp
 *
 *  Created on: Nov 26, 2018
 *      Author: chorm
 */

#include <snes-dev/qc/qc-floats.hpp>

/*
 * float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}
 */

extern const __qcfloat fINF;
extern const __qcfloat fNaN;
const  __qcfloat fINF{0x7f000000};
const __qcfloat fNaN{0x7f000001};
extern const __qcdouble dINF;
extern const __qcdouble dNaN;
const __qcdouble dINF{0x7ff0000000000000};
const __qcdouble dNaN{0x7ff0000000000001};

const static unsigned ffactTab[]{1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
const static unsigned long long dfactTab[]{1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,
		6227020800,87178291200
};

inline static __qcfloat exp2(int i){
	__qcfloat ret{};
	if(i>127)

	return ret;
}

inline static float powOverFact(float f,unsigned c){
	if(c==0)
		return 1.f;
	else if(c==1)
		return f;
	else
		return powOverFact(f,c-1)*f/c;
}

__qcdouble __qc_minvsqrt(__qcdouble d){
	const double threehalfs = 1.5;
	const unsigned long long magic = 0x5FE6EB50C7B537A9;
	double x2 = d.val*0.5;
	if(d.val<0)
		return dNaN;
	d.bits = magic - (d.bits >> 1);
	d.val = d.val*(threehalfs - (x2 * d.val * d.val));
	return d;
}

bool __qc_isNaNf(__qcfloat f){
	return !(f.rep.exp^0x7f);//
}

__qcfloat __qc_minvsqrtf(__qcfloat f){
	const float threehalfs = 1.5f;
	const unsigned magic = 0x5f3759df;
	float x2 = f.val*0.5f;
	if(f.val<0)
		return fNaN;
	f.bits = magic - (f.bits >> 1);
	f.val = f.val*(threehalfs - (x2 * f.val * f.val));
	return f;
}

__qcfloat __qc_msqrtf(__qcfloat f){
	f = __qc_minvsqrtf(f);
	f.val = 1/f.val;
	return f;
}

__qcfloat __qc_mexpf(__qcfloat e){
	float f = 0;
}



