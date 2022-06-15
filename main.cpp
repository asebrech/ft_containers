/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:57:18 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/15 19:43:22 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.hpp"
#include "map.hpp"

# include <string>
# include <iostream>
# include <map>

int main()
{
	ft::pair<std::string, int>	test;
	ft::pair<std::string, int>	a("hello there", 117);
	ft::pair<std::string, int>	b;

	b = ft::make_pair<std::string, int>("hello there", 117);

	if (a == b)
		std::cout << "okay\n";


	std::map<char, int>	hello;
	hello['a'] = 117;
	hello['b'] = 118;
	hello['c'] = 119;
	hello['d'] = 120;

	hello.erase('c');

	std::cout << hello.size() << std::endl;



	ft::pair<std::string, int>	* c;
	std::allocator<ft::pair<std::string, int> >	alloc;
	c = alloc.allocate(1);
	alloc.construct(&c->first, "hello");
	alloc.construct(&c->second, 117);
	

	//c->first = "hello";

	std::cout << "c " << c->first << std::endl;
	std::cout << "c " << c->second << std::endl;

	alloc.destroy(c);
	//alloc.deallocate(c, 1);

	std::cout << "c " << c->first << std::endl;


	ft::map<char, int>		map;

	map.insert(ft::pair<char, int>('z', 117));
	map.insert(ft::pair<char, int>('r', 18));
	map.insert(ft::pair<char, int>('g', 119));
	map.insert(ft::pair<char, int>('w', 20));

	map.printTree();
}
