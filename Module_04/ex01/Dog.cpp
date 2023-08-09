/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:31:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 16:31:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

const std::string Dog::_DEFAULT_TYPE = "Dog";

Dog::Dog(void) : Animal()
{
	std::cout << "The creation is a " + this->_DEFAULT_TYPE + "." << std::endl;
	this->type = this->_DEFAULT_TYPE;
	return;
}

Dog::Dog(const Dog &src) : Animal()
{
	this->type = src.type;
	std::cout << "The copy is of a " + src.type + "." << std::endl;
	return;
}

Dog::~Dog(void)
{
	std::cout << "A " + this->type + " has been deleted." << std::endl;
	return;
}

Dog &Dog::operator=(Dog const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}

	std::cout << "A " + rhs.type + " has been attributed to another " + this->type + "." << std::endl;

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark bark" << std::endl;
	return;
}
