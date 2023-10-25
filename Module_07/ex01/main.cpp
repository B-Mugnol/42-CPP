/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:41:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/20 17:02:44 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

void intTest(int n);
void floatTest(float n);
void stringTest(std::string n);

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	float floatArray[] = {1.1f, 2.6, 3.7, 4.5, 5.6, 6, 7, 8, 9};
	std::string stringArray[] = {"dog", "cat", "bird"};

	iter(intArray, 9, intTest);
	iter(floatArray, 9, floatTest);
	iter(stringArray, 3, stringTest);

	return (0);
}

void intTest(int n)
{
	std::cout << n << std::endl;
}

void floatTest(float n)
{
	std::cout << n << std::endl;
}

void stringTest(std::string n)
{
	std::cout << n << std::endl;
}

