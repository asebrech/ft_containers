/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:51:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/12 19:13:31 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <limits>

# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

# include <iostream>

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public :

			/*	Member types	*/

			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef	random_access_iterator<value_type>	iterator;
			typedef	random_access_iterator<const value_type>	const_iterator;
			typedef	ft::reverse_iterator<iterator>	reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename allocator_type::size_type	size_type;

			/*	Member functions	*/

			// default
			vector(const allocator_type & alloc = allocator_type())
				: _data(NULL), _alloc(alloc), _capacity(0), _size(0) {}
			
			// fill
			vector(size_type n, const value_type & val = value_type(),
					const allocator_type & alloc = allocator_type())
					: _data(NULL), _alloc(alloc), _capacity(0), _size(0)
			{ assign(n, val); }
			
			// range
			template <class	InputIterator > 
			vector(InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
				: _data(NULL), _alloc(alloc), _capacity(0), _size(0)
			{ assign(first, last); }

			// copy
			vector(vector const & x) : _data(NULL), _capacity(0), _size(0)
			{ *this = x; }

			vector	& operator=(vector const & x)
			{
				if (this != &x)
					assign(x.begin(), x.end());
				return (*this);
			}

			// destructor
			~vector() { clear(); _alloc.deallocate(_data, _capacity); }

			/*	Iterators	*/

			iterator	begin() { return (iterator(_data)); }
			const_iterator	begin() const { return (const_iterator(_data)); }

			iterator	end() { return (iterator(_data + _size)); }
			const_iterator	end() const { return (const_iterator(_data + _size)); }

			reverse_iterator	rbegin() { return (reverse_iterator(end())); }	
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(end())); }	

			reverse_iterator	rend() { return (reverse_iterator(begin())); }	
			const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }	

			/*	Capacity	*/

			size_type	size() const { return (_size); }

			size_type	max_size() const { return (_alloc.max_size()); }

			size_type	capacity() const { return (_capacity); }

			bool	empty() const { return (_size == 0); }

			/*	Elements access		*/

			pointer	data(void) { return (this->_data); }
			const_pointer	data(void) const { return (static_cast<const_pointer>(this->_data)); }

			/*	Modifiers	*/

			// range
			template <class InputIterator>			
			void	assign(InputIterator first, InputIterator last)
			{
				clear();
				for (InputIterator it = first; it != last; it++)
					_size++;
				if (_size > _capacity)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = _size;
					if (_capacity > max_size())
						throw	std::length_error("vector");
					_data = _alloc.allocate(_capacity);
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct((_data + i), *first++);
				}
			}
			// fill
			void	assign(size_type n, value_type const & val)
			{
				clear();
				_size = n;
				if (_size > _capacity)
				{
					_alloc.deallocate(_data, _capacity);
					_capacity = _size;
					if (_capacity > max_size())
						throw	std::length_error("vector");
					_data = _alloc.allocate(_capacity);
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct((_data + i), val);
				}	
			}

			void	swap(vector & x)
			{
				vector	tmp = x;
				x = *this;
				*this = tmp;
			}

			void	clear()
			{
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_data + i);
				}
				_size = 0;
			}

		private :

			pointer	_data;
			allocator_type	_alloc;
			size_type	_capacity;
			size_type	_size;

	};
};

#endif
