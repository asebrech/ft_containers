/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:15:50 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/15 19:40:44 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>

#include <iostream>

#include "utility.hpp"
#include "srcs/iterator_traits.hpp"

namespace	ft
{

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
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type	size_type;

		private :

			key_compare	compare;
			allocator_type	alloc;

			struct Node
			{
				value_type	* data;
				Node 	* parent;
				Node	* left;
				Node	* right;
				int	color;
			};

			typedef Node *	NodePtr;

			NodePtr	root;
			NodePtr	TNULL;	

		public :
			explicit map (const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) : compare(comp), alloc(alloc)
			{
				TNULL = new Node;
				TNULL->data = this->alloc.allocate(1);
				TNULL->color = 0;
				TNULL->left = nullptr;
				TNULL->right = nullptr;
				root = TNULL;
			}
			~map() {};

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
				NodePtr x = this->root;

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
			}

			void	printTree()
			{
				if (root)
					printHelper(this->root, "", true);
			}

		private :
			
		void printHelper(NodePtr root, std::string indent, bool last) {
			if (root != TNULL) {
				std::cout << indent;
				if (last) {
					std::cout << "R----";
					indent += "   ";
				} else {
					std::cout << "L----";
					indent += "|  ";
				}

				std::string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data->second << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);

			}
		}
		//	void	initializeNULLNode(NodePtr node, NodePtr parent);
	};

};

#endif
