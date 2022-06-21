/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:00:00 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/21 17:59:49 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace	ft
{
	/*
	* This class reverses the direction in which a bidirectional or
	* random-access iterator iterates through a range.
	*/

	template <class Iterator>
	class	reverse_iterator
	{
		public :

			/* typedefs */

			typedef	Iterator	iterator_type;
			typedef	typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename ft::iterator_traits<Iterator>::value_type	value_type;
			typedef	typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef	typename ft::iterator_traits<Iterator>::pointer	pointer;
			typedef	typename ft::iterator_traits<Iterator>::reference	reference;

			/* constructor */

			reverse_iterator() {}
			reverse_iterator(iterator_type it) : _current(it) {}
			reverse_iterator(reverse_iterator<Iterator> const & src) { *this = src; }
			reverse_iterator const & operator=(reverse_iterator<Iterator> const & rhs)
				{ if (this != &rhs) { this->_current = rhs._current;} return (*this);}
			virtual ~reverse_iterator() {}

			iterator_type	base() const { return (this->_current); }

			template < template < class > class It , class T>
			operator reverse_iterator< It<const T> >() const {reverse_iterator< It<const T> > temp(_current); return (temp);}			

			/* operators */

			reference	operator*() const { Iterator tmp = _current; return (*(--tmp)); }
			pointer		operator->() const { Iterator tmp = _current; return (&(*(--tmp))); }
			reference	operator[](difference_type n) const { return (this->_current[-n-1]); }		

			/* arithmetic */

			reverse_iterator	operator+(difference_type n) const { return (reverse_iterator(this->_current - n)); }
			reverse_iterator	operator-(difference_type n) const { return (reverse_iterator(this->_current + n)); }
			reverse_iterator	& operator++() { --this->_current; return (*this); }
			reverse_iterator	& operator--() { ++this->_current; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator tmp = *this; --this->_current; return (tmp); }
			reverse_iterator	operator--(int) { reverse_iterator tmp = *this; ++this->_current; return (tmp); }
			reverse_iterator	& operator+=(difference_type n) { this->_current -= n; return (*this); }
			reverse_iterator	& operator-=(difference_type n) { this->_current += n; return (*this); }

		protected :

			Iterator	_current;			
	};

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> & rev_it)
		{ return (reverse_iterator<Iterator>(rev_it.base() - n)); }
	template <class L, class R>
	typename reverse_iterator<L>::difference_type	operator-(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs)
		{ return (rhs.base() - lhs.base()); }

	/* relational operators */

	template <class L, class R>
	bool	operator==(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() == rhs.base()); } 
	template <class L, class R>
	bool	operator!=(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() != rhs.base()); } 
	template <class L, class R>
	bool	operator<(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() > rhs.base()); } 
	template <class L, class R>
	bool	operator>(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() < rhs.base()); } 
	template <class L, class R>
	bool	operator>=(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() <= rhs.base()); } 
	template <class L, class R>
	bool	operator<=(reverse_iterator<L> const & lhs, reverse_iterator<R> const & rhs) { return (lhs.base() >= rhs.base()); } 
}

#endif
