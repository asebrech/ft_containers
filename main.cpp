/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/12 19:33:00 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

#include <iostream>
#include <string>


void	test(bool ft)
{
	if (!ft)
		namespace ft = std;

	ft::vector<int>	vector(4, 117);
	ft::vector<int>	vector2(4, 118);


	ft::vector<int>	ftvector(vector);

	ftvector.swap(vector2);

	ft::vector<int>::iterator	it;

	for (it = ftvector.begin(); it != ftvector.end(); it++)
		std::cout << "ft " << *it << std::endl;

	std::cout << vector.max_size() << std::endl;

}

int	main()
{
	test(true);
	test(false);

	return 0;	
}
