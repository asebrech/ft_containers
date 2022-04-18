/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:00:22 by asebrech          #+#    #+#             */
/*   Updated: 2022/04/18 17:40:33 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

#include <iostream>
#include <vector>
#include <string>

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
}
