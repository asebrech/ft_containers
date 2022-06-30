/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:18:38 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/30 15:51:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include "vector.hpp"
# include "../srcs/algorithm.hpp"

/*
* The std::stack class is a container adaptor that gives the programmer the functionality of a stack
* specifically, a LIFO (last-in, first-out) data structure.*
*/

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class	stack
	{
		public :
			typedef Container	container_type;
			typedef typename  container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;

			explicit stack(const container_type & c = container_type()) : c(c) {}

			~stack() {}

			bool	empty() const { return (c.empty()); }

			size_type	size() const { return (c.size()); }

			value_type & top() { return (c.back()); }
			const value_type & top() const { return (c.back()); }

			void	push(const value_type & val) { c.push_back(val); }

			void	pop() { c.pop_back(); }
		

			template <class Tf, class Containerf>
  			friend bool	operator== (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

			template <class Tf, class Containerf>
  			friend bool	operator!= (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

			template <class Tf, class Containerf>
  			friend bool	operator< (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

			template <class Tf, class Containerf>
  			friend bool	operator<= (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

			template <class Tf, class Containerf>
  			friend bool	operator> (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

			template <class Tf, class Containerf>
  			friend bool	operator>= (const ft::stack<Tf,Containerf>& lhs, const ft::stack<Tf,Containerf>& rhs);

		protected :
			container_type	c;
	};

	template <class T, class Container>
  	bool	operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c == rhs.c); }

	template <class T, class Container>
  	bool	operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c != rhs.c); }

	template <class T, class Container>
  	bool	operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c < rhs.c); }

	template <class T, class Container>
  	bool	operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c <= rhs.c); }

	template <class T, class Container>
  	bool	operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c > rhs.c); }

	template <class T, class Container>
  	bool	operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.c >= rhs.c); }
};

#endif
