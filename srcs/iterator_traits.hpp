/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:39:08 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/12 10:24:14 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <stddef.h>

namespace	ft
{
	/* The iterator category. It can be one of these */

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};


	/* Traits class defining properties of iterators. */

	template <class Iterator>
		struct iterator_traits {
			typedef typename Iterator::iterator_category iterator_category;
			typedef typename Iterator::value_type        value_type;
			typedef typename Iterator::difference_type   difference_type;
			typedef typename Iterator::pointer           pointer;
			typedef typename Iterator::reference         reference;
		};

	template <class T>
		struct iterator_traits<T*> {
			typedef ft::random_access_iterator_tag iterator_category;
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef T*                         pointer;
			typedef T&                         reference;
		};

	template <class T>
		struct iterator_traits<const T*> {
			typedef ft::random_access_iterator_tag iterator_category;
			typedef T                          value_type;
			typedef ptrdiff_t                  difference_type;
			typedef const T*                         pointer;
			typedef const T&                         reference;
		};
};

#endif
