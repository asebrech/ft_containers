/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/06/01 10:28:02 by alois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <vector>

#include <iostream>
#include <string>

template <class T, class Alloc>
void	cmpstd(const std::vector<T, Alloc> &lhs, const std::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template <class T, class Alloc>
void	cmp(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	ft::vector<int> vct(4);
	ft::vector<int> vct2(4);

	cmp(vct, vct);  // 0
	cmp(vct, vct2); // 1

	vct2.resize(10);

	cmp(vct, vct2); // 2
	cmp(vct2, vct); // 3

	vct[2] = 42;

	cmp(vct, vct2); // 4
	cmp(vct2, vct); // 5

	swap(vct, vct2);

	cmp(vct, vct2); // 6
	cmp(vct2, vct); // 7


	std::cout << "\n\n------------------------------------------------\n\n";


	std::vector<int> vctstd(4);
	std::vector<int> vct2std(4);

	cmpstd(vctstd, vctstd);  // 0
	cmpstd(vctstd, vct2std); // 1

	vct2std.resize(10);

	cmpstd(vctstd, vct2std); // 2
	cmpstd(vct2std, vctstd); // 3

	vctstd[2] = 42;

	cmpstd(vctstd, vct2std); // 4
	cmpstd(vct2std, vctstd); // 5

	swap(vctstd, vct2std);

	cmpstd(vctstd, vct2std); // 6
	cmpstd(vct2std, vctstd); // 7

	return (0);
}


/*
void	test()
{
	ft::vector<int>	vector(3, 117);
	ft::vector<int>	vec(3, 117);

	ft::vector<int>::iterator	it;
	ft::vector<int>::const_iterator v = it;;
	if (vector != vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector == vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector < vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector > vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector <= vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector >= vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	vector.push_back(117);
	vector.push_back(118);
	vector.push_back(119);
	vector.push_back(120);
	vector.push_back(121);
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
	std::vector<int>	vec(3, 117);
	if (vector != vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector == vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector < vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector > vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector <= vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	if (vector >= vec)
		std::cout << "vrais \n";
	else
		std::cout << "faux \n";
	vector.push_back(117);
	vector.push_back(118);
	vector.push_back(119);
	vector.push_back(120);
	vector.push_back(121);

	std::vector<int>::iterator	it;
	std::vector<int>::reverse_iterator	re;



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
*/
