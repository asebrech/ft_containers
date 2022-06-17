/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:54:25 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/17 17:03:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <iostream>

namespace ft
{

	template <class T1, class T2>
		struct	pair
		{
			typedef T1	first_type;
			typedef T2	second_type;

			pair() {}

			template <class U, class V>
				pair(const pair<U, V> & pr) { *this = pr; }

			pair	const & operator=(const pair & pr)
			{
				if (this != &pr)
				{
					first = pr.first;
					second = pr.second;
				}
				return (*this);
			}

			operator pair<const T1, T2>() const { pair<const T1, T2> tmp(this->first, this->second); return (tmp); }

			pair (const first_type & a, const second_type & b) : first(a), second(b) {}

			first_type	first;
			second_type	second;
		};

	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs==rhs); }

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(rhs<lhs); }

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return rhs<lhs; }

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
		{ return !(lhs<rhs); }


	template <class T1,class T2>
		ft::pair<T1,T2>	make_pair(T1 x, T2 y)
		{
			return ( ft::pair<T1,T2>(x,y) );
		}	
};

#endif
