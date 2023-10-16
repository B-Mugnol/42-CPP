/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:14:57 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

const std::string Animal::_DEFAULT_TYPE = "Animal";

Animal::Animal(void) : type(_DEFAULT_TYPE)
{
	std::cout << "An " + this->type + " has been created." << std::endl;
	return;
}

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << "An " + this->type + " has been copied." << std::endl;
	return;
}

Animal::~Animal(void)
{
	std::cout << "An animal has been deleted." << std::endl;
	return;
}

Animal &Animal::operator=(Animal const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}

	std::cout << "An " + rhs.type + " has been attributed to another " + this->type + "." << std::endl;

	return *this;
}

std::string Animal::getType(void) const { return this->type; }
