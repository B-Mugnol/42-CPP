/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:13:20 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/26 14:18:22 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string const Harl::levelString[INVALID] = {"DEBUG", "INFO", "WARNING", "ERROR", "RANDOM"};

Harl::Harl(void) { return; }
Harl::~Harl(void) { return; }

void Harl::complain(std::string level)
{
	void (Harl::*function[INVALID + 1])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::random, &Harl::invalid};

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

void Harl::random(void)
{
	std::cout << "[ Random complaint ]" << std::endl;
	return;
}
