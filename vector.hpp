/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:51:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/04/20 15:45:11 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
//# include <iterator>

# include "type_traits.hpp"

# include <iostream>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public :

			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef typename std::iterator<std::random_access_iterator_tag, value_type>	iterator;
			typedef typename allocator_type::size_type	size_type;

			explicit vector(const allocator_type & alloc = allocator_type()) : _alloc(alloc) {};
			
			explicit vector(size_type n, const value_type & val = value_type(),
					const allocator_type & alloc = allocator_type()) : _alloc(alloc), _capacity(n), _size(n)
			{
				if (n > this->max_size())
					throw	std::length_error("vector");
				this->_data = this->_alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct((this->_data + i), val);
				}
			}
			
			template <class	InputIterator > 
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, std::nullptr_t>::type = nullptr) : _alloc(alloc)
			{
				this->_capacity = std::distance(first, last);
				this->_size = this->_capacity;
				if (this->_capacity > this->max_size())
					throw	std::length_error("vector");
				this->_data = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_capacity; i++)
				{
					this->_alloc.construct((this->_data + i), *first);
					first++;
				}
			}

			~vector() {};


			pointer	data(void)
			{
				return (this->_data);
			}

			const_pointer	data(void) const
			{
				return (static_cast<const_pointer>(this->_data));
			}

			size_type	max_size() const
			{
				size_type tmp = sizeof(value_type);
				tmp = (tmp == 1) ? 2 : tmp;

				return (std::numeric_limits<size_type>::max() / tmp);
			}

			size_type	size() const
			{
				return (this->_size);
			}

			size_type	capacity() const
			{
				return (this->_capacity);
			}

		private :

			pointer	_data;
			allocator_type	_alloc;
			size_type	_capacity;
			size_type	_size;

	};
};

#endif
