/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:50 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/18 15:37:07 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>

#include <iostream>

#include "srcs/iterator_traits.hpp"
#include "srcs/reverse_iterator.hpp"
#include "utility.hpp"
#include "bidirectional_iterator.hpp"

namespace	ft
{
	template <class T>	
	struct Node
	{
		T	* data;
		Node 	* parent;
		Node	* left;
		Node	* right;
		int	color;
	};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::pair <const Key, T> > >
	class	map
	{
		public:

	 		typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;		
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef ft::bidirectional_iterator<value_type>	iterator;
			typedef ft::bidirectional_iterator<const value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type	size_type;

		private :

			key_compare	compare;
			allocator_type	alloc;

			typedef Node<value_type>	Node;
			typedef	Node	* NodePtr;
			NodePtr	root;
			NodePtr	TNULL;	

		public :

			/*	Membrer functions	*/

			explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : compare(comp), alloc(alloc)
			{
				TNULL = new Node;
				TNULL->parent = nullptr;
				TNULL->data = this->alloc.allocate(1);
				TNULL->color = 0;
				TNULL->left = nullptr;
				TNULL->right = nullptr;
				root = TNULL;
			}
			virtual ~map() {};

			/*	Iterartors	*/			

			iterator	begin() { return (iterator(minimum(root), maximum(root), TNULL)); }
			const_iterator	begin() const  { return (const_iterator(minimum(root), maximum(root), TNULL)); }

			iterator	end() { return (iterator(TNULL, maximum(root), TNULL)); }
			const_iterator	end() const { return (const_iterator(TNULL, maximum(root), TNULL)); }

			reverse_iterator	rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const  { return (const_reverse_iterator(end())); }

			reverse_iterator	rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const  { return (const_reverse_iterator(begin())); }

			void	insert(const value_type & val)
			{
				NodePtr	node = new Node;
				node->parent = nullptr;
				node->data = this->alloc.allocate(1);
				alloc.construct(&node->data->first, val.first);
				alloc.construct(&node->data->second, val.second);
				node->left = TNULL;
				node->right = TNULL;
				node->color = 1;

				NodePtr	y = nullptr;
				NodePtr	x = this->root;

				while (x != TNULL)
				{
					y = x;
					if (compare(node->data->first, x->data->first))
						x = x->left;
					else
						x = x->right;
				}

				node->parent = y;
				if (y == nullptr)
					root = node;
				else if (  compare(node->data->first, y->data->first))
					y->left = node;
				else
					y->right = node;

				if (node->parent == nullptr)
				{
					node->color = 0;
					return;
				}

				if (node->parent->parent == nullptr)
					return;

				insertFix(node);
			}

			void	erase(const key_type & key)
			{
				NodePtr	node = this->root;
				NodePtr	z = TNULL;
				NodePtr	x;
				NodePtr	y;
				while (node != TNULL)
				{
					if (node->data->first == key)
						z = node;
					if (compare(key, node->data->first))
						node = node->left;
					else
						node = node->right;
				}

				if (z == TNULL)
				{
					std::cout << "key not found in the tree" << std::endl;
					return;
				}

				y = z;
				int	y_original_color = y->color;
				if (z->left == TNULL)
				{
					x = z->right;
					rbTransplant(z, z->right);
				}
				else if (z->right == TNULL)
				{
					x = z->left;
					rbTransplant(z, z->left);
				}
				else
				{
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else
					{
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				alloc.destroy(z->data);
				alloc.deallocate(z->data, 1);
				delete z;
				if (y_original_color == 0)
					deleteFix(x);
			}

			iterator	find(const key_type & k) { return (iterator(searchTree(root, k), maximum(root), TNULL));}
			const_iterator	find(const key_type & k) const { return (const_iterator(searchTree(root, k), maximum(root), TNULL)); }

			size_type	count(const key_type & k) const { return ((searchTree(root, k) == TNULL) ? 0 : 1); }

			iterator	lower_bound(const key_type & k)
			{
				iterator	it;

				for (it = begin(); it != end(); it++)
					if (!compare(it->first, k))
						return (it);
				return (it);
			}
			const_iterator	lower_bound(const key_type & k) const
			{
				const_iterator	it;

				for (it = begin(); it != end(); it++)
					if (!compare(it->first, k))
						return (it);
				return (it);
			}
			
			iterator	upper_bound(const key_type & k)
			{
				iterator	it;

				for (it = begin(); it != end(); it++)
					if (compare(k, it->first))
						return (it);
				return (it);
			}
			const_iterator	upper_bound(const key_type & k) const
			{
				const_iterator	it;

				for (it = begin(); it != end(); it++)
					if (compare(k, it->first))
						return (it);
				return (it);
			}

			ft::pair<iterator, iterator>	equal_range(const key_type & k)
				{ return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k))); }
			ft::pair<const_iterator, const_iterator>	equal_range(const key_type & k) const
				{ return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k))); }

		private :

			void	rightRotate(NodePtr x)
			{
				NodePtr	y = x->left;
				x->left = y->right;
				if (y->right != TNULL)
					y->right->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					this->root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			}

			void	leftRotate(NodePtr x)
			{
				NodePtr	y = x->right;
				x->right = y->left;
				if (y->left != TNULL)
					y->left->parent = x;
				y->parent = x->parent;
				if (x->parent == nullptr)
					this->root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			}

			void	rbTransplant (NodePtr u, NodePtr v)
			{
				if (u->parent == nullptr)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}

			NodePtr	minimum(NodePtr node)
			{
				while (node->left != TNULL)
					node = node->left;
				return (node);
			}

			NodePtr	maximum(NodePtr node)
			{
				while (node->right != TNULL)
					node = node->right;
				return (node);
			}

			void	insertFix(NodePtr k)
			{
				NodePtr	u;
				while (k->parent->color == 1)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						if (u->color == 1)
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->left)
							{
								k = k->parent;
								rightRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					}
					else
					{
						u = k->parent->parent->right;
						if (u->color == 1)
						{
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						}
						else
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								leftRotate(k);
							}
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == root)
						break;
				}
				root->color = 0;
			}

			void deleteFix(NodePtr x)
			{
				NodePtr	s;
				while (x != root && x->color == 0)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == 0 && s->right->color == 0)
						{
							s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->right->color == 0)
							{
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							}
							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = root;
						}
					}
					else
					{
						s = x->parent->left;
						if (s->color == 1)
						{
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == 0 && s->left->color == 0)
						{
							s->color = 1;
							x = x->parent;
						}
						else
						{
							if (s->left->color == 0)
							{
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = root;

						}
					}
				}
				x->color = 0;
			}

			NodePtr	searchTree(NodePtr node, const key_type & key) const
			{
				if (node == TNULL || key == node->data->first)
					return (node);
				if (compare(key, node->data->first))
					return (searchTree(node->left, key));
				return (searchTree(node->right, key));
			}
	};

};

#endif
