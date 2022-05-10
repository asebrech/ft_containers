/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/10 11:09:29 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <iostream>
#include <vector>
#include <string>


#include <iterator>     // std::iterator_traits
#include <typeinfo>     // typeid
#include "iterator_traits.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

int	main()
{
	std::vector<int>	vector(2, 117);

	vector.push_back(10);
	vector.push_back(117);
	vector.push_back(66);

	ft::vector<int>	ft_vector(vector.begin(), vector.end());
	ft::vector<int>	ft_vector1(2, 100);

	std::cout << ft_vector.data()[1] << std::endl;
	std::cout << ft_vector1.data()[1] << std::endl;

	std::cout << vector.max_size() << std::endl;
	std::cout << ft_vector.max_size() << std::endl;

	std::vector<int>::reverse_iterator	it(vector.begin());
	std::vector<int>::reverse_iterator	ite = vector.rend();

	if(it >= ite)
		std::cout << "okay \n";

	ite - it;

	if (it.base() == vector.begin())
		std::cout << "okay " << it[-5] << std::endl;
	std::cout<< "vec " << *it << std::endl;
	std::cout<< "vec " << *(vector.begin() - 1) << std::endl;

	typedef std::iterator_traits<int*> traits;

	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator" << std::endl;
		std::cout << typeid(traits).name() << std::endl;

	typedef ft::iterator_traits<int*> traits1;
	if (typeid(traits1::iterator_category)==typeid(ft::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator" << std::endl;
		std::cout << typeid(traits1).name() << std::endl;


	int	tata[] = {1, 2, 3};

	ft::vector<int>::iterator	toto(tata);
	ft::vector<int>::iterator	halo(toto);

	ft::vector<int>::reverse_iterator	test(tata);
	ft::vector<int>::reverse_iterator	test2(toto);

	if(test == test)
		std::cout << "okay \n";
	test2 - test;

	if (test.base() == tata)
		std::cout << "ttttetttstst :    "  << *test  << std::endl;;

	halo = 1 + halo;
	toto - halo;
	std::cout << &(*toto) << std::endl;
	std::cout << tata << std::endl;
	std::cout << *halo << std::endl;

	return 0;	
}
