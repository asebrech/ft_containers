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
# include <sstream>

namespace	ft
{
	template<class T>
	std::string	to_string(T const & i)
	{
		std::stringstream	ss;
		ss << i;

		return ss.str();
	}
};

#endif
