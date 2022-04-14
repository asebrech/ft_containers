/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:51:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/04/14 13:01:26 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public :

			typedef	T	value_type;
			typedef	Alloc	allocator_type;

			explicit vector(const allocator_type & alloc = allocator_type()) : _alloc(alloc) {};
			~vector() {};

		private :

			Alloc	_alloc;
			T	* _type;

	};
};

#endif
