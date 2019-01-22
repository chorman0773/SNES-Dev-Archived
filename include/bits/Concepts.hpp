/*
 * Concepts.hpp
 *
 *  Created on: Jan 8, 2019
 *      Author: chorm
 */

#ifndef INCLUDE_BITS_CONCEPTS_HPP_
#define INCLUDE_BITS_CONCEPTS_HPP_

#include <type_traits>

namespace std{
	struct __nonesuch{};
	namespace __detail{
		template<typename Default,typename AlwaysVoid,template<typename...> class Op,
			class... Args> struct detector{
			using value_t = std::false_type;
			using type = Default;
		};
		template<typename Default,template<typename...> class Op,class... Args> struct
			detector<Default,std::void_t<Op<Args...>>,Op,Args...>{
			using value_t = std::true_type;
			using type = Op<Args...>;
		};
	}

	template<template<typename...> class _Op,class... _Args> using __is_detected = typename __detail::detector<__nonesuch,void,_Op,_Args...>::value_t;
	template<template<typename...> class _Op,class... _Args> using __detected_t = typename __detail::detector<__nonesuch,void,_Op,_Args...>::type;
	template<typename _Default,template<typename...> class _Op,class... _Args> struct __detected_or: __detail::detector<_Default,void,_Op,_Args...>{};

	template<template<typename...> class Op,class... Args> constexpr const bool __is_detected_v = __is_detected<Op,Args...>::value;
	template<typename Default,template<typename...> class Op,class... Args> using __detected_or_t = typename __detected_or<Default,Op,Args...>::type;
	template<typename Expected,template<typename...> class Op,class... Args> using __is_detected_exact = typename std::is_same<Expected,__detected_t<Op,Args...>>::type;
	template<typename Expected,template<typename...> class Op,class... Args> using __is_detected_convertible = typename std::is_convertible<Expected,__detected_t<Op,Args...>>::type;

	template<typename Expected,template<typename...> class Op,class... Args> constexpr const bool __is_detected_exact_v = __is_detected_exact<Expected,Op,Args...>::value;
	template<typename Expected,template<typename...> class Op,class... Args> constexpr const bool __is_detected_convertible_v = __is_detected_convertible<Expected,Op,Args...>::value;

}

#define __v(type) std::declval<type>()

#endif /* INCLUDE_BITS_CONCEPTS_HPP_ */
