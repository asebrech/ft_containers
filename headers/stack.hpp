/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:18:38 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/23 17:34:21 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include "vector.hpp"
# include "../srcs/algorithm.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class	stack
	{
		public :
			typedef Container	container_type;
			typedef typename  container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;

			explicit stack(const container_type & ctnr = container_type()) : ctnr(ctnr) {}

			~stack() {}

			bool	empty() const { return (ctnr.empty()); }

			size_type	size() const { return (ctnr.size()); }

			value_type & top() { return (ctnr.back()); }
			const value_type & top() const { return (ctnr.back()); }

			void	push(const value_type & val) { ctnr.push_back(val); }

			void	pop() { ctnr.pop_back(); }
		

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
			container_type	ctnr;
	};

	template <class T, class Container>
  	bool	operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr == rhs.ctnr); }

	template <class T, class Container>
  	bool	operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr != rhs.ctnr); }

	template <class T, class Container>
  	bool	operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr < rhs.ctnr); }

	template <class T, class Container>
  	bool	operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr <= rhs.ctnr); }

	template <class T, class Container>
  	bool	operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr > rhs.ctnr); }

	template <class T, class Container>
  	bool	operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
		{ return (lhs.ctnr >= rhs.ctnr); }
};

#endif
