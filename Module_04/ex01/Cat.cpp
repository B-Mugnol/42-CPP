/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:31:23 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 16:41:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

const std::string Cat::_DEFAULT_TYPE = "Cat";

Cat::Cat(void) : Animal()
{
	std::cout << "The creation is a " + this->_DEFAULT_TYPE + "." << std::endl;
	this->type = this->_DEFAULT_TYPE;
	return;
}

Cat::Cat(const Cat &src) : Animal()
{
	this->type = src.type;
	std::cout << "The copy is of a " + src.type + "." << std::endl;
	return;
}

Cat::~Cat(void)
{
	std::cout << "A " + this->type + " has been deleted." << std::endl;
	return;
}

Cat &Cat::operator=(Cat const &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
	}

	std::cout << "A " + rhs.type + " has been attributed to another " + this->type + "." << std::endl;

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
	return;
}
