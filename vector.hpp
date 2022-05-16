/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:51:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/16 11:03:17 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <limits>
# include <sstream>

# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utile.hpp"

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

		private :

			pointer	_data;
			allocator_type	_alloc;
			size_type	_capacity;
			size_type	_size;

		public :

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

			reference	operator[](size_type n) { return(_data[n]); }
			const_reference	operator[](size_type n) const { return(_data[n]); }

			reference	at(size_type n)
			{
				if (n >= _size)
					_out_of_range(n);
				return(_data[n]);
			}
			const_reference	at(size_type n) const
			{
				if (n >= _size)
					_out_of_range(n);
				return(_data[n]);
			}

			reference	front() { return(_data); }
			const_reference	front() const { return(_data); }

			reference	back() { return(_data[_size - 1]); }
			const_reference	back() const { return(_data[_size - 1]); }

			/*	Modifiers	*/

			// range
			template <class InputIterator>			
			void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{
				clear();
				for (InputIterator it = first; it != last; it++)
					_size++;
				if (_size > _capacity)
					_new_allocate();
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), *first++);
			}
			// fill
			void	assign(size_type n, value_type const & val)
			{
				clear();
				_size = n;
				if (_size > _capacity)
					_new_allocate();
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), val);
			}

			void	push_back(value_type const & val) { insert(end(), val); } 
			
			// single element
			iterator	insert(iterator position, value_type const & val)
			{
				size_type i = 0;
				size_type rtn = 0;
				if(_size + 1 > _capacity)
				{
					_size++;
					if (_size > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(_size); 
					iterator	it = begin();
					while(it != position)
					{
						tmp[i] = *it;
						i++;
						it++;
					}
					rtn = i;
					tmp[i] = val;
					i++;
					while(it != end())
					{
						tmp[i] = *it;
						i++;
						it++;
					}
					clear();
					_alloc.deallocate(_data, _capacity);
					_capacity++;
					_size = _capacity;
					_data = tmp;
				}
				else
				{
					for (iterator it = begin(); it != position; it++)
						i++;
					value_type	tmp = _data[i];
					value_type	tmp2;
					_data[i] = val;
					rtn = i;
					i++;
					while(i < _size)
					{
						tmp2 = _data[i];
						_data[i] = tmp;
						tmp = tmp2;
						i++;
					}
					_data[i] = tmp;
					_size++;
				}
				return (begin() + rtn);
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
					_alloc.destroy(_data + i);
				_size = 0;
			}

		private :
						
			/*	utiles functions	*/

			void	_out_of_range(size_type n)
			{
				std::string	error(" vector::_M_range_check: __n (which is ");
				error.append(ft::to_string(n));
				error.append(") >= this->size() (which is ");
				error.append(ft::to_string(_size));
				error.push_back(')');
				throw	std::out_of_range(error);
			}

			void	_new_allocate()
			{
				_alloc.deallocate(_data, _capacity);
				_capacity = _size;
				if (_capacity > max_size())
					throw	std::length_error("vector");
				_data = _alloc.allocate(_capacity);
			}
	};
};

#endif
