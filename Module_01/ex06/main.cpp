/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:21:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/26 14:10:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	std::string level = argv[1];

	int i = DEBUG;
	for (; level != Harl::levelString[i] && i != RANDOM; i++)
		;

	Harl complainer;
	if (i == RANDOM)
	{
		complainer.complain(Harl::levelString[i]);
		return 0;
	}
	for (; i != RANDOM; i++)
	{
		complainer.complain(Harl::levelString[i]);
		std::cout << std::endl;
	}

	return 0;
}
