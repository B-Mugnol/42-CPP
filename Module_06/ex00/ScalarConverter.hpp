/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 15:29:14 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
public:
	static void convert(const std::string &src);

private:
	static const std::string _pseudoLiterals[3];
	static const std::string _pseudoLiteralsF[3];

	static char _char;
	static long _int;
	static float _float;
	static double _double;
	static bool _isPseudoLiteral;
	static bool _isPseudoLiteralF;

	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &literal);
	~ScalarConverter(void);

	ScalarConverter &operator=(ScalarConverter const &rhs);

	static void convertFromChar(const std::string &literal);
	static void convertFromFloat(const std::string &literal);
	static void convertFromInt(const std::string &literal);
	static void convertFromDouble(const std::string &literal);

	static bool isChar(const std::string &literal);
	static bool isFloat(const std::string &literal);
	static bool isInt(const std::string &literal);
	static bool isDouble(const std::string &literal);
	static bool isPseudoLiteral(const std::string &literal);
	static bool isPseudoLiteralF(const std::string &literal);

	static void printValues(const std::string &literal);

	static void printChar(void);
	static void printInt(void);
	static void printFloat(const std::string &literal);
	static void printDouble(const std::string &literal);
};

#endif
