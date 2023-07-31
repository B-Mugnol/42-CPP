/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 20:53:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	// Constructor
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int i);
	Fixed(const float f);

	// Destructor
	~Fixed(void);

	// Getter & Setter
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Other method
	int toInt(void) const;
	float toFloat(void) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

	// Assignment operator
	Fixed &operator=(Fixed const &rhs);

	// Comparison operator
	bool operator>(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

	// Arithmetic operator
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

	// Increment/Decrement operator
	Fixed operator++(int);	 // fixedInstance++
	Fixed operator--(int);	 // fixedInstance--
	Fixed &operator++(void); // ++fixedInstance
	Fixed &operator--(void); // --fixedInstance
};

// Insertion operator
std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
