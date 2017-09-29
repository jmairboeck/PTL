
//          Copyright Michael Florian Hava.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../../../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <cstdint>

#ifdef _MSC_VER
	#define PTL_PACK_BEGIN __pragma(pack(push, 1))
	#define PTL_PACK_END   __pragma(pack(pop))
#elif __GNUC__
	#define PTL_PACK_BEGIN _Pragma("pack(push, 1)")
	#define PTL_PACK_END   _Pragma("pack(pop)")
#else
	#error unknown compiler
#endif

#if UINTPTR_MAX == 0xFFFFFFFF
	#define PTL_TARGET_BITNESS_IS_32 1
	#define PTL_TARGET_BITNESS_IS_64 0
#elif UINTPTR_MAX == 0xFFFFFFFFFFFFFFFF
	#define PTL_TARGET_BITNESS_IS_32 0
	#define PTL_TARGET_BITNESS_IS_64 1
#else
	#error Unknown bitness detected
#endif