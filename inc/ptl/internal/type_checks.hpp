
//          Copyright Michael Florian Hava.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file ../../../LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once
#include <type_traits>

namespace ptl::internal {
	template<typename Type>
	struct is_abi_compatible final : std::bool_constant<
		std::is_standard_layout_v<std::remove_cv_t<Type>> &&
		std::is_default_constructible_v<std::remove_cv_t<Type>> &&
		std::is_copy_constructible_v<std::remove_cv_t<Type>> &&
		std::is_nothrow_move_constructible_v<std::remove_cv_t<Type>> &&
		std::is_copy_assignable_v<std::remove_cv_t<Type>> &&
		std::is_nothrow_move_assignable_v<std::remove_cv_t<Type>> &&
		std::is_nothrow_destructible_v<std::remove_cv_t<Type>> &&
		std::is_nothrow_swappable_v<std::remove_cv_t<Type>>
	> {};

	template<typename Type>
	inline
	constexpr
	auto is_abi_compatible_v{is_abi_compatible<Type>::value};


	template<typename...>
	struct are_abi_compatible;

	template<typename... Types>
	inline
	constexpr
	auto are_abi_compatible_v{are_abi_compatible<Types...>::value};

	template<>
	struct are_abi_compatible<> final : std::true_type {};

	template<typename Type, typename... Types>
	struct are_abi_compatible<Type, Types...> final : std::bool_constant<
		is_abi_compatible_v<Type> &&
		are_abi_compatible_v<Types...>
	> {};


	template<typename...>
	struct are_integral;

	template<typename... Types>
	inline
	constexpr
	auto are_integral_v{are_integral<Types...>::value};

	template<>
	struct are_integral<> final : std::true_type {};

	template<typename Type, typename... Types>
	struct are_integral<Type, Types...> final : std::bool_constant<
		std::is_integral_v<Type> &&
		are_integral_v<Types...>
	> {};
}
