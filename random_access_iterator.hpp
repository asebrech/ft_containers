/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:13:41 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/03 12:30:54 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft
{
	/*
	* Random-access iterators are iterators that can be used to access elements
	* at an arbitrary offset position relative to the element they point to,
	* offering the same functionality as pointers.
	*/
	
	template <class T>
	class	random_access_iterator
	{
		public :

			/* typedefs */

			typedef T	value_type;
			typedef ptrdiff_t	difference_type;
			typedef T	* pointer;
			typedef T	& reference;
			typedef ft::random_access_iterator_tag	iterator_category;

		private :

			typedef random_access_iterator iterator;

		public :

			/* Lifecyle */

			random_access_iterator(void) : _ptr(nullptr) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(iterator const & src) { *this = src; }
			virtual ~random_access_iterator() {}
			iterator const & operator=(iterator const & rhs) {if (this != &rhs){_ptr = rhs._ptr;} return (*this);}

			/* Operators : misc */

			iterator	& operator+=(difference_type rhs) {_ptr += rhs; return (*this);}
			iterator	& operator-=(difference_type rhs) {_ptr -= rhs; return (*this);}
			reference	operator*() const {return (*_ptr);}
			pointer		operator->() const {return (_ptr);}
			reference	operator[](difference_type index) const {return (_ptr[index]);}

			/* Operators : arithmetic */

			iterator	& operator++() {_ptr++; return (*this);}
			iterator	operator++(int) { iterator tmp(*this); ++*this; return (tmp);}
			iterator	& operator--() {_ptr--; return (*this);}
			iterator	operator--(int) {iterator tmp(*this); --*this; return (tmp);}
			difference_type	operator-(iterator const & rhs) const { return (_ptr - rhs._ptr);}

			/* Operators : comparison */

			bool	operator==(iterator const & rhs) const {return (_ptr == rhs.p);}
			bool	operator!=(iterator const & rhs) const {return (_ptr != rhs.p);}
			bool	operator>(iterator const & rhs) const {return (_ptr > rhs.p);}
			bool	operator<(iterator const & rhs) const {return (_ptr < rhs.p);}
			bool	operator>=(iterator const & rhs) const {return (_ptr >= rhs.p);}
			bool	operator<=(iterator const & rhs) const {return (_ptr <= rhs.p);}

		protected :

			/* Data member */

			pointer	_ptr;
	};

	template <class T>
	random_access_iterator<T>	operator+(ptrdiff_t lhs, random_access_iterator<T> const & rhs) {return (random_access_iterator<T>(lhs + rhs->get()));}
	template <class T>
	random_access_iterator<T>	operator-(ptrdiff_t lhs, random_access_iterator<T> const & rhs) {return (random_access_iterator<T>(lhs - rhs->get()));}
};

#endif
