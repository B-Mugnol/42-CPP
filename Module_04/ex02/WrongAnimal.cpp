/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:14:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 16:30:12 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

const std::string WrongAnimal::_DEFAULT_TYPE = "WrongAnimal";

WrongAnimal::WrongAnimal(void) : type(_DEFAULT_TYPE)
{
	std::cout << "An " + this->type + " has been created." << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
	std::cout << "An " + this->type + " has been copied." << std::endl;
	return;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "An animal has been deleted." << std::endl;
	return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}

	std::cout << "An " + rhs.type + " has been attributed to another " + this->type + "." << std::endl;

	return *this;
}

std::string WrongAnimal::getType(void) const { return this->type; }

void WrongAnimal::makeSound(void) const
{
	std::cout << "You hear a generic animal noise" << std::endl;
	return;
}
