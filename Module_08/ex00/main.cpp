/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:33:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/25 16:18:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(95 + i);
	}

	for (int i = 0; i < 10; i++)
	{
		try
		{
			std::cout << i << ": ";
			it = easyfind(v, 100 + i);
			std::cout << *it << " | " << *(std::find(v.begin(), v.end(), 100 + i)) << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
