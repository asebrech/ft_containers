/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:33:02 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/30 16:35:48 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
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
};

#endif
