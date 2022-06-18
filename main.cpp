/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:18 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/18 15:50:58 by asebrech         ###   ########.fr       */
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


//	std::cout << "\n Afeter deletion\n";

//	map.erase(40);

//	map.printTree();

	ft::map<int, int>::iterator	it = map.begin();
	ft::map<int, int>::iterator	ite = map.end();

	//it--;
//	std::cout  << "end "<< ite->second << std::endl;

	ite--;
	for (; ite != it; ite--)
		std::cout << ite->second << std::endl;

	ft::map<int, int>::const_iterator	cit;

	cit = map.find(65);

	std::cout << "find "  << cit->second << std::endl;

	std::cout << "count " << map.count(40) << std::endl;

	it = map.upper_bound(58);

	std::cout << "lower " << it->second << std::endl;

	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator>	ip;

	ip = map.equal_range(60);

	std::cout << ip.first->second << ip.second->first << std::endl;

	std::cout << "\n mymap \n "  << std::endl;

	std::map<int, int>	mymap;

	mymap.insert(std::pair<int, int>(55, 55));
	mymap.insert(std::pair<int, int>(40, 40));
	mymap.insert(std::pair<int, int>(65, 65));
	mymap.insert(std::pair<int, int>(60, 60));
	mymap.insert(std::pair<int, int>(75, 75));
	mymap.insert(std::pair<int, int>(57, 57));

	std::map<int, int>::iterator	mit = mymap.begin();
	std::map<int, int>::iterator	mite = mymap.end();

//	mit--;
	mite--;
	for (; mite != mit; mite--)
		std::cout << mite->second << std::endl;

	std::map<int, int>::const_iterator	mitt;
	mitt = mymap.find(65);


	std::cout << "find "  << mitt->second << std::endl;

	std::cout << "count " << mymap.count(40) << std::endl;

	mit = mymap.upper_bound(58);

	std::cout << "lower " << mit->second << std::endl;

	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>	p;

	p = mymap.equal_range(60);

	std::cout << p.first->second << p.second->first  << std::endl;


  return 0;
}
