/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:18 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/16 19:19:54 by asebrech         ###   ########.fr       */
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

	map.printTree();

	std::cout << "\n Afeter deletion\n";

	map.erase(40);

	map.printTree();

	ft::map<int, int>::iterator	it = map.begin();
	//ft::map<int, int>::iterator	ite = map.end();

	it++;
	//ite--;

	//std::cout << ite->second << std::endl;

//	for (; it != map.end(); it++)
//		std::cout << it->second << std::endl;


	std::map<int, int>	mymap;

	mymap.insert(std::pair<int, int>(50, 50));
	mymap.insert(std::pair<int, int>(60, 60));

	//std::pair<int, int>	*c;

	std::map<int, int>::iterator	itt = mymap.end();

	itt--;
	std::cout << itt->second  << std::endl;;

  return 0;
}
