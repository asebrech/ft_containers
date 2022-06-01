/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:56:58 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/13 11:21:31 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILE_HPP
# define UTILE_HPP
# include "iterator_traits.hpp"

namespace	ft
{

	template<class It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, ft::input_iterator_tag)
	{
    		typename ft::iterator_traits<It>::difference_type result = 0;
    		while (first != last)
		{
        		++first;
        		++result;
    		}
    		return result;
	}
 
	template<class It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, ft::random_access_iterator_tag)
	{
    		return last - first;
	}

	template<class It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, std::input_iterator_tag)
	{
    		typename ft::iterator_traits<It>::difference_type result = 0;
    		while (first != last)
		{
        		++first;
        		++result;
    		}
    		return result;
	}
 
	template<class It>
	typename ft::iterator_traits<It>::difference_type do_distance(It first, It last, std::random_access_iterator_tag)
	{
    		return last - first;
	}
 
 
	template<class It>
	typename ft::iterator_traits<It>::difference_type 
    	distance(It first, It last)
	{
    		return ft::do_distance(first, last, typename ft::iterator_traits<It>::iterator_category());
	}

/*
	template<class T>
	std::string	to_string(T const & i)
	{
		std::stringstream	ss;
		ss << i;

		return ss.str();
	}*/
};

#endif
