/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/17 18:11:42 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

#include <iostream>
#include <string>


void	test()
{
	ft::vector<int>	vector(5, 117);
	std::vector<int>	vec(5, 119);

	ft::vector<int>::iterator	it;

	//vector.reserve(11);	

	//std::cout << "pos " << *vector.insert(vector.begin() + 2, 118) << std::endl;
	vector.insert((vector.begin() + 2), 2, 118);
	//vector.insert((vector.begin() + 2), vec.begin(), vec.end());
	std::cout << "cap " << vector.capacity() << std::endl;
	std::cout << "siz " << vector.size() << std::endl;

	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << "ft " << *it << std::endl;
}

void	test2()
{
	std::vector<int>	vector(5, 117);
	std::vector<int>	vec(5, 119);

	std::vector<int>::iterator	it;

	//vector.reserve(11);	

	//std::cout << "pos " << *vector.insert((vector.begin() + 2), 8) << std::endl;
	vector.insert((vector.begin() + 2), 2, 118);
	//vector.insert((vector.begin() + 2), vec.begin(), vec.end());
	std::cout << "cap " << vector.capacity() << std::endl;
	std::cout << "siz " << vector.size() << std::endl;

	for (it = vector.begin(); it != vector.end(); it++)
		std::cout << "std " << *it << std::endl;
}

int	main()
{
	test();
	std::cout << std::endl;
	test2();

	return 0;	
}
