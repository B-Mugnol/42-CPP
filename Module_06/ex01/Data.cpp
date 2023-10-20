/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:07 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data(void) : value(42)
{
	std::cout << "Data has been created." << std::endl;
	return;
}

Data::Data(int value) : value(value)
{
	std::cout << "Data has been created." << std::endl;
	return;
}

Data::Data(const Data &src) : value(src.value)
{
	std::cout << "Data has been copied." << std::endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data(void)
{
	std::cout << "Data has been deleted." << std::endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &Data::operator=(Data const &rhs)
{
	if (this != &rhs)
	{
		this->value = rhs.value;
	}

	std::cout << "Data has been attributed." << std::endl;
	return *this;
}

/* ************************************************************************** */
