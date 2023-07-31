/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:50:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/28 20:53:16 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << "----Testing ++ and -- operators----" << std::endl;
		std::cout << "Value of a: " << a << std::endl;
		std::cout << "Value of a pre++: " << ++a << std::endl;
		std::cout << "Value of a pos++: " << a++ << std::endl;
		std::cout << "Value of a: " << a << std::endl;

		std::cout << "Value of b: " << b << std::endl;

		std::cout << "max(a,b): " << Fixed::max(a, b) << std::endl;
		std::cout << "min(a,b): " << Fixed::min(a, b) << std::endl;
	}
	{
		Fixed a(Fixed(10.05f) + Fixed(2));
		Fixed b(Fixed(5.05f) - Fixed(2));
		Fixed c(Fixed(14.22f) / Fixed(2));
		Fixed d(Fixed(14.22f) * Fixed(5));

		std::cout << "\n---Testing arithmetics----" << std::endl;
		std::cout << "Value of a: " << a << std::endl;
		std::cout << "Value of b: " << b << std::endl;
		std::cout << "Value of c: " << c << std::endl;
		std::cout << "Value of d: " << d << std::endl;

		std::cout << "\n----Making comparisons----" << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a != c: " << (a != c) << std::endl;
		std::cout << "b >= c: " << (b >= c) << std::endl;
		std::cout << "b == b: " << (b == b) << std::endl;
	}
	return (0);
}
