/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alois <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:26:29 by alois             #+#    #+#             */
/*   Updated: 2022/06/01 11:27:54 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORIYHM_HPP
# define ALGORIYHM_HPP

namespace ft
{
	template<class InputIt1, class InputIt2>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
				InputIt2 first2, InputIt2 last2)
		{
			for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
				if (*first1 < *first2) return true;
				if (*first2 < *first1) return false;
			}
			return (first1 == last1) && (first2 != last2);
		}


	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}
};

#endif
