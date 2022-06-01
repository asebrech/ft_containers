/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:51:49 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/01 11:48:14 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iterator>
# include <iostream>

# include "vector/random_access_iterator.hpp"
# include "srcs/type_traits.hpp"
# include "srcs/reverse_iterator.hpp"
# include "srcs/iterator.hpp"
# include "srcs/algorithm.hpp"


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

			void	resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					for(size_type i = _size; i > n; i--)
						_alloc.destroy(_data + i);
					_size = n;
				}
				else if (n > _size)
				{
					reserve(n);
					for (size_type i = _size; i < n; i++)
						_alloc.construct(_data + i, val);
					_size = n;
				}
			}

			size_type	capacity() const { return (_capacity); }

			bool	empty() const { return (_size == 0); }

			void	reserve(size_type n)
			{
				if (n > _capacity)
				{
					if (n > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(n); 
					for(size_type i = 0; i < _size; i++)
					{
						_alloc.construct(tmp + i, _data[i]);
						_alloc.destroy(_data + i);
					}
					_alloc.deallocate(_data, _capacity);	
					_capacity = n;
					_data = tmp;
				}
			}

			/*	Elements access		*/

			reference	operator[](size_type n) { return(_data[n]); }
			const_reference	operator[](size_type n) const { return(_data[n]); }

			reference	at(size_type n)
			{
				if (n >= _size)
					throw	std::out_of_range("vector");
				return(_data[n]);
			}
			const_reference	at(size_type n) const
			{
				if (n >= _size)
					throw	std::out_of_range("vector");
				return(_data[n]);
			}

			reference	front() { return(*_data); }
			const_reference	front() const { return(*_data); }

			reference	back() { return(_data[_size - 1]); }
			const_reference	back() const { return(_data[_size - 1]); }

			/*	Modifiers	*/

			// range
			template <class InputIterator>			
			void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{
				size_type	n = 0;
				n = ft::distance(first, last);

				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), *first++);
			}
			// fill
			void	assign(size_type n, value_type const & val)
			{
				clear();
				reserve(n);
				_size = n;
				for (size_type i = 0; i < _size; i++)
					_alloc.construct((_data + i), val);
			}

			void	push_back(value_type const & val) { insert(end(), 1, val); } 

			void	pop_back() { erase(end() - 1); }
			
			// single element
			iterator	insert(iterator position, value_type const & val)
			{
				size_type	i = 0;
				i = ft::distance(begin(), position);

				insert(position, 1, val);
				return (begin() + i);
			}

			// fill	
			void	insert(iterator position, size_type n, value_type const & val)
			{
				if((_size + n) > _capacity)
				{
					size_type	rsize = _capacity * 2;
					if (rsize < (_size + n))
						rsize = (_size + n);
					if (rsize > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(rsize); 
					iterator	it;
					size_type i = 0;
					for (it = begin(); it != position; it++)
						_alloc.construct(tmp + i++, *it);
					for (size_type j = 0; j < n; j++)
						_alloc.construct(tmp + i++, val);
					while (it != end())
						_alloc.construct(tmp + i++, *it++);
					for (i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_alloc.deallocate(_data, _capacity);
					_capacity = rsize;
					_size += n;
					_data = tmp;
				}
				else
				{
					size_type	i = 0, k = 0, tmp = _size - 1;
					i = ft::distance(begin(), position);	

					for (size_type j = i; j < _size; j++)
					{
						_alloc.construct(_data + (tmp + n) - k, _data[tmp - k]);
						k++;
					}
					for (size_type j = 0; j < n; j++)
					{
						_alloc.destroy(_data + i);
						_alloc.construct(_data + i++, val);
					}
					_size += n;
				}
			}

			template <class InputIterator>
			void	insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = false)
			{
				size_type	n = ft::distance(first, last);
				if((_size + n) > _capacity)
				{
					size_type	rsize = _capacity * 2;
					if (rsize < (_size + n))
						rsize = (_size + n);
					if (rsize > max_size())
						throw	std::length_error("vector");
					pointer	tmp = _alloc.allocate(rsize); 
					iterator	it;
					size_type i = 0;
					for (it = begin(); it != position; it++)
						_alloc.construct(tmp + i++, *it);
					while (first != last)
						_alloc.construct(tmp + i++, *first++);
					while (it != end())
						_alloc.construct(tmp + i++, *it++);
					for (i = 0; i < _size; i++)
						_alloc.destroy(_data + i);
					_alloc.deallocate(_data, _capacity);
					_capacity = rsize;
					_size += n;
					_data = tmp;
				}
				else
				{
					size_type	i = 0, k = 0, tmp = _size - 1;
					i = ft::distance(begin(), position);	

					for (size_type j = i; j < _size; j++)
					{
						_alloc.construct(_data + (tmp + n) - k, _data[tmp - k]);
						k++;
					}
					while (first != last)
					{
						_alloc.destroy(_data + i);
						_alloc.construct(_data + i++, *first++);
					}
					_size += n;
				}
			}

			iterator	erase (iterator position) { return (erase(position, position + 1)); }

			iterator	erase (iterator first, iterator last)
			{
				size_type	n = ft::distance(first, last);
				iterator	it;
				for(it = first; it != last; it++)
					_alloc.destroy(&(*it));
				for(it = last; it != end(); it++)
				{
					_alloc.construct(&(*(it - n)), *it);  
					_alloc.destroy(&(*it));
				}
				_size -= n;
				return (first);
			}

			void	swap(vector & x)
			{
				pointer		tmp_data = x._data;
				size_type	tmp_size = x._size;
				size_type	tmp_capacity = x._capacity;

				x._data = _data;
				x._size = _size;
				x._capacity = _capacity;

				_data = tmp_data;
				_size = tmp_size;
				_capacity = tmp_capacity;
			}

			void	clear()
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_data + i);
				_size = 0;
			}

	};

	/*	relational operators	*/

	template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(rhs < lhs)); }

	template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }

};

#endif
