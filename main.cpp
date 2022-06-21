/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:18 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/21 15:45:04 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.hpp"
#include "map.hpp"

# include <string>
# include <iostream>
# include <map>

int main()
{
	ft::map<int, int>		map;

	map.insert(ft::pair<int, int>(55, 55));
	map.insert(ft::pair<int, int>(40, 40));
	map.insert(ft::pair<int, int>(65, 65));
	map.insert(ft::pair<int, int>(60, 60));
	map.insert(ft::pair<int, int>(75, 75));
	map.insert(ft::pair<int, int>(57, 57));

	ft::map<int, int>::iterator	it;

	ft::map<int, int>	test;
	test = map;

	for (it = test.begin(); it != test.end(); it++)
		std::cout << it ->first << std::endl;

	map[33] = 33;
	std::cout << map[33] << "  " << map.size() << std::endl;

	std::cout << "\n mymap \n "  << std::endl;

	std::map<int, int>	mymap;

	mymap.insert(std::pair<int, int>(55, 55));
	mymap.insert(std::pair<int, int>(40, 40));
	mymap.insert(std::pair<int, int>(65, 65));
	mymap.insert(std::pair<int, int>(60, 60));
	mymap.insert(std::pair<int, int>(75, 75));
	mymap.insert(std::pair<int, int>(57, 57));

	std::cout << mymap[33] << "  " << mymap.size() << std::endl;

  return 0;
}
