/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:14:39 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 15:57:37 by bmugnol-         ###   ########.fr       */
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
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed &operator=(Fixed const &rhs);

private:
};

#endif
