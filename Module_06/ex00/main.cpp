/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:08:21 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 16:23:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid number of parameters" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	// // Tests:
	// {
	// 	std::cout << "\nConvert 0:\n";
	// 	ScalarConverter::convert("0");

	// 	std::cout << "\nConvert -1:\n";
	// 	ScalarConverter::convert("-1");

	// 	std::cout << "\nConvert 42:\n";
	// 	ScalarConverter::convert("42");

	// 	std::cout << "\nConvert 300:\n";
	// 	ScalarConverter::convert("300");

	// 	std::cout << "\nConvert abobrinha:\n";
	// 	ScalarConverter::convert("abobrinha");

	// 	std::cout << "\nConvert +inf:\n";
	// 	ScalarConverter::convert("+inf");

	// 	std::cout << "\nConvert +inff:\n";
	// 	ScalarConverter::convert("+inff");

	// 	std::cout << "\nConvert -inf:\n";
	// 	ScalarConverter::convert("-inf");

	// 	std::cout << "\nConvert -inff:\n";
	// 	ScalarConverter::convert("-inff");

	// 	std::cout << "\nConvert nan:\n";
	// 	ScalarConverter::convert("nan");

	// 	std::cout << "\nConvert nanf:\n";
	// 	ScalarConverter::convert("nanf");

	// }

	return 0;
}
