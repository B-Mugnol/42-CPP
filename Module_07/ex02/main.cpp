/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:41:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/24 18:14:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
	{
		Array<int> numbers(42);
		std::cout << "Should be default (0): " << numbers[0] << std::endl;
		numbers[0] = 3;
		std::cout << "Should be new value (3): " << numbers[0] << std::endl;
		std::cout << "Should fail:" << std::endl;
		try
		{
			numbers[42];
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{

		Array<int> numbers(MAX_VAL);
		int *mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		// SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}

		std::cout << "Should fail:" << std::endl;
		try
		{
			numbers[-2] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "Should fail:" << std::endl;
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		delete[] mirror;
	}

	{
		Array<std::string> name(4);
		int index;

		name[0] = "Bruno";
		name[1] = "Wilk";
		name[2] = "Lucas";
		name[3] = "Eloi";

		index = rand() % 3;

		std::cout << "Random name: " << name[index] << std::endl;
		std::cout << "Should be 4: "  << name.size() << std::endl;

		std::cout << "Should fail:" << std::endl;
		try
		{
			std::cout << name[4] << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}
