/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 17:45:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTOR
// Default
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

// Copy
Fixed::Fixed(const Fixed &src) : _rawBits(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
	return;
}

// Int
Fixed::Fixed(const int i) : _rawBits(i << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

// Float
Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(0.5 + f * (1 << this->_fractionalBits));
}

// DESTRUCTOR
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

// GETTER
int Fixed::getRawBits(void) const
{
	return this->_rawBits;
}

// SETTER
void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return;
}

// OTHER METHODS
int Fixed::toInt(void) const
{
	return this->getRawBits() >> this->_fractionalBits;
}

float Fixed::toFloat(void) const
{
	return this->getRawBits() / (float)(1 << this->_fractionalBits);
}

// OPERATOR OVERLOAD
// Assignment
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

// Insertion
std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
