/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:13:41 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/16 19:06:23 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "srcs/iterator_traits.hpp"

# include "map.hpp"

namespace	ft
{
	template<class T>
	struct	Node;

	template <class T>
	class	bidirectional_iterator
	{
		public :

			/* typedefs */

			typedef T	value_type;
			typedef ptrdiff_t	difference_type;
			typedef T	* pointer;
			typedef T	& reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		private :

			typedef bidirectional_iterator	iterator;
			typedef	Node<value_type>	Node;
			typedef	Node *	NodePtr;

			NodePtr	root;
			NodePtr	TNULL;	

		public :

			/* Lifecyle */

			bidirectional_iterator(void) : root(NULL), TNULL(NULL) {}
			bidirectional_iterator(NodePtr root, NodePtr TNULL) : root(root), TNULL(TNULL) {}
			bidirectional_iterator(iterator const & src) { *this = src; }
			virtual ~bidirectional_iterator() {}

			iterator const & operator=(iterator const & rhs) {if (this != &rhs) {root = rhs.root; TNULL = rhs.TNULL;} return (*this);}
			
			operator bidirectional_iterator<const T>() const {bidirectional_iterator<const T> temp(this->_ptr); return (temp);}			

			reference	operator*() const {return (*root->data);}
			pointer		operator->() const {return (root->data);}

			iterator	& operator++() {root = successor(root); return (*this);}
			iterator	operator++(int) { iterator tmp(*this); ++*this; return (tmp);}
			iterator	& operator--() {root = predecessor(root); return (*this);}
			iterator	operator--(int) {iterator tmp(*this); --*this; return (tmp);}

			
			template <class It>
			bool	operator==(It const & rhs) const {return (root->data == &(*rhs));}
			template <class It>
			bool	operator!=(It const & rhs) const {return (root->data != &(*rhs));}

		private :

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

			NodePtr	successor(NodePtr x)
			{
				if (x->right != TNULL)
					return (minimum(x->right));

				NodePtr	y = x->parent;
				while (y != TNULL && x == y->right)
				{
					x = y;
					y = y->parent;
				}
				return (y);
			}

			NodePtr	predecessor(NodePtr x)
			{
				if (x->left != TNULL)
					return (maximum(x->left));

				NodePtr	y = x->parent;
				while (y != TNULL && x == y->left)
				{
					x = y;
					y = y->parent;
				}
				return (y);
			}
	};
};

#endif
