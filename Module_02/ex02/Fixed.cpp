/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 20:54:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// CONSTRUCTOR
Fixed::Fixed(void) : _rawBits(0) { return; }
Fixed::Fixed(const Fixed &src) : _rawBits(src.getRawBits()) { return; }
Fixed::Fixed(const int i) : _rawBits(i << _fractionalBits) { return; }
Fixed::Fixed(const float f) : _rawBits(0.5 + f * (1 << this->_fractionalBits)) { return; }

// DESTRUCTOR
Fixed::~Fixed(void) { return; }

// GETTER & SETTER
int Fixed::getRawBits(void) const { return this->_rawBits; }

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return;
}

// OTHER METHOD
int Fixed::toInt(void) const { return this->getRawBits() >> this->_fractionalBits; }
float Fixed::toFloat(void) const { return this->getRawBits() / (float)(1 << this->_fractionalBits); }

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
const Fixed &Fixed::min(Fixed const &a, Fixed const &b) { return a < b ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed &Fixed::max(Fixed const &a, Fixed const &b) { return a > b ? a : b; }

// OPERATOR OVERLOAD
// Assignment
Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}

// Insertion
std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return o;
}

// Comparison operator
bool Fixed::operator>(Fixed const &rhs) const { return this->getRawBits() > rhs.getRawBits(); }
bool Fixed::operator>=(Fixed const &rhs) const { return this->getRawBits() >= rhs.getRawBits(); }
bool Fixed::operator<(Fixed const &rhs) const { return this->getRawBits() < rhs.getRawBits(); }
bool Fixed::operator<=(Fixed const &rhs) const { return this->getRawBits() <= rhs.getRawBits(); }
bool Fixed::operator==(Fixed const &rhs) const { return this->getRawBits() == rhs.getRawBits(); }
bool Fixed::operator!=(Fixed const &rhs) const { return this->getRawBits() != rhs.getRawBits(); }

// Arithmetic operator
Fixed Fixed::operator+(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Increment/Decrement operator
// fixedInstance++
Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->setRawBits(this->getRawBits() + 1);
	return copy;
}

// fixedInstance--
Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->setRawBits(this->getRawBits() - 1);
	return copy;
}

// ++fixedInstance
Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

// --fixedInstance
Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}
