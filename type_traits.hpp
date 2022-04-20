/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:55:25 by asebrech          #+#    #+#             */
/*   Updated: 2022/04/20 11:46:23 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace	ft
{
	/*
	* std::integral_constant wraps a static constant of specified type.
	* It is the base class for the C++ type traits.
	*/

	template <class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
	};	

	/* Instantiation of integral_constant to represent the bool value true. */

	typedef integral_constant<bool,true> true_type;	

	/* Instantitation of integral_constant to represent the bool value false. */

	typedef integral_constant<bool,false> false_type;


	/*
	* Trait class that identifies whether T is an integral type.
	* It inherits from integral_constant as being either true_type or false_type,
	* depending on whether T is an integral type
	*/

	template<typename>
	struct is_integral : public ft::false_type {};

	template<>
	struct is_integral <bool>: public ft::true_type {};

	template<>
	struct is_integral <char>: public ft::true_type {};

	template<>
	struct is_integral <wchar_t>: public ft::true_type {};

	template<>
	struct is_integral <signed char>: public ft::true_type {};

	template<>
	struct is_integral <short int>: public ft::true_type {};

	template<>
	struct is_integral <int>: public ft::true_type {};

	template<>
	struct is_integral <long int>: public ft::true_type {};

	template<>
	struct is_integral <long long int>: public ft::true_type {};

	template<>
	struct is_integral <unsigned char>: public ft::true_type {};

	template<>
	struct is_integral <unsigned short int>: public ft::true_type {};

	template<>
	struct is_integral <unsigned int>: public ft::true_type {};

	template<>
	struct is_integral <unsigned long int>: public ft::true_type {};

	template<>
	struct is_integral <unsigned long long int>: public ft::true_type {};


	/*
	* The type T is enabled as member type enable_if::type if Cond is true.
	* Otherwise, enable_if::type is not defined.
	* This is useful to hide signatures on compile time when a particular condition is not met,
	* since in this case,
	* the member enable_if::type will not be defined and attempting to compile using it should fail.
	*/

	template <bool Condition, typename T = void>
	struct	enable_if {};

	template <typename T>
	struct	enable_if<true, T>
	{
		typedef T	type;
	};
};

#endif
