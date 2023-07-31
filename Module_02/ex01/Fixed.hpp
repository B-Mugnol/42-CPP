/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 18:26:54 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	int toInt(void) const;
	float toFloat(void) const;

	Fixed &operator=(Fixed const &rhs);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);

#endif
