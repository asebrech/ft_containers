/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/13 12:12:12 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

#include <iostream>
#include <string>


void	test()
{
	ft::vector<int>	vector(4, 117);
	ft::vector<int>	vector2(4, 118);


	ft::vector<int>	ftvector(vector);

	ftvector.swap(vector2);

	ft::vector<int>::iterator	it;

	for (it = ftvector.begin(); it != ftvector.end(); it++)
		std::cout << "ft " << *it << std::endl;

	std::cout << vector.max_size() << std::endl;

	ft::vector<int>::reference a = vector.at(3);

//	a = 12;

	std::cout << "operator [] " << a << std::endl;
	std::cout << " " << vector.back() << std::endl;

}

void	test2()
{
	std::vector<int>	vector(4, 117);
	std::vector<int>	vector2(4, 118);


	std::vector<int>	ftvector(vector);

	ftvector.swap(vector2);

	std::vector<int>::iterator	it;

	for (it = ftvector.begin(); it != ftvector.end(); it++)
		std::cout << "ft " << *it << std::endl;

	std::cout << vector.max_size() << std::endl;

	std::vector<int>::reference a = vector.at(3);

//	a = 12;

	std::cout << "operator [] " << a << std::endl;
	std::cout << " " << vector.back() << std::endl;

}

int	main()
{
	test();
	test2();

	return 0;	
}
