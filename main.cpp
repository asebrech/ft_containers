/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/05/03 12:21:10 by asebrech         ###   ########.fr       */
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

	std::vector<int>::iterator	it = vector.begin();
	std::vector<int>::iterator	ite = vector.end();

	it++;
	1 + it;
	int i = it - ite;
	std::cout<< "i " << i << std::endl;

	std::cout<< "vec " << *it << std::endl;


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


	std::cout << &(*toto) << std::endl;
	std::cout << tata << std::endl;
	std::cout << halo[1] << std::endl;

	return 0;	
}
