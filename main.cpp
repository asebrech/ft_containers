/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/18 12:37:12 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

#include <iostream>
#include <string>


void	test()
{
	ft::vector<int>	vector(3, 117);
	vector.push_back(117);
	vector.push_back(118);
	vector.push_back(119);
	vector.push_back(120);
	vector.push_back(121);

	ft::vector<int>::iterator	it;

	ft::vector<int>::const_iterator v = it;;

	v++;

	//vector.erase(vector.end() - 1);

	//vector.reserve(20);

	std::cout << "insert : " << *vector.insert(vector.end() - 3, 400) << std::endl;
	vector.insert(vector.begin() + 3, 5, 300);

	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << "ft " << *it << std::endl;

	std::cout << "cap " << vector.capacity() << std::endl;
	std::cout << "siz " << vector.size() << std::endl;
}

void	test2()
{
	std::vector<int>	vector(3, 117);
	vector.push_back(117);
	vector.push_back(118);
	vector.push_back(119);
	vector.push_back(120);
	vector.push_back(121);

	std::vector<int>::iterator	it;

	std::vector<int>::const_iterator v = it;

	v++;

	//vector.erase(vector.end() - 1);

	//vector.reserve(20);

	std::cout << "insert : " << *vector.insert(vector.end() - 3, 400) << std::endl;
	vector.insert(vector.begin() + 3, 5, 300);


	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << "std " << *it << std::endl;

	std::cout << "cap " << vector.capacity() << std::endl;
	std::cout << "siz " << vector.size() << std::endl;
}

int	main()
{
	test();
	std::cout << std::endl;
	test2();

	return 0;	
}
