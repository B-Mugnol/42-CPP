/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:13:20 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/25 18:53:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) { return; }
Harl::~Harl(void) { return; }

void Harl::complain(std::string level)
{
	std::string levelString[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*function[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::invalid};

	int i;
	for (i = DEBUG; level != levelString[i] && i != INVALID; i++)
		;

	(this->*function[i])();
	return;
}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "A debug message" << std::endl;
	return;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "An informational message" << std::endl;
	return;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "A warning message" << std::endl;
	return;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "An error message" << std::endl;
	return;
}

void Harl::invalid(void)
{
	std::cout << "[ INVALID ]" << std::endl
			  << "Valid levels are 'DEBUG', 'INFO', 'WARNING' and 'ERROR'" << std::endl;
	return;
}
