/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:29:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/04 15:08:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of parameters." << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc(std::string("./data.csv"));
		btc.getResultingValue(std::string(argv[1]));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	return 0;
}
