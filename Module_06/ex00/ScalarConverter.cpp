/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 16:22:07 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <limits.h>

#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>

const std::string ScalarConverter::_pseudoLiterals[3] = {"-inf", "+inf", "nan"};
const std::string ScalarConverter::_pseudoLiteralsF[3] = {"-inff", "+inff", "nanf"};
char ScalarConverter::_char = 0;
long ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
bool ScalarConverter::_isPseudoLiteral = false;
bool ScalarConverter::_isPseudoLiteralF = false;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter(void) { return; }

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter(void) { return; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	if (this != &rhs)
	{
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cout << "Invalid Argument\n";
		return;
	}

	if (isPseudoLiteral(literal))
		_isPseudoLiteral = true;
	else if (isPseudoLiteralF(literal))
	{
		_isPseudoLiteral = true;
		_isPseudoLiteralF = true;
	}
	else if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
	{
		std::cout << "Invalid Argument\n";
		return;
	}

	if (_isPseudoLiteralF)
		printValues(literal.substr(0, literal.length() - 1));
	else
		printValues(literal);

	_isPseudoLiteral = false;
	_isPseudoLiteralF = false;
}

bool ScalarConverter::isChar(const std::string &literal)
{
	if (literal.length() == 1 && std::isdigit(literal[0]) == false)
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
	size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]) == false)
			return false;
	}
	return true;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	bool hasDot = false;

	size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (std::isdigit(literal[i]) == false)
		{
			if (literal[i] == '.' && hasDot == false)
				hasDot = true;
			else
				return false;
		}
	}
	return hasDot;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	bool hasDot = false;

	if (literal[literal.length() - 1] != 'f')
		return false;

	size_t start = literal[0] == '-' || literal[0] == '+' ? 1 : 0;
	for (size_t i = start; i < literal.length() - 1; i++)
	{
		if (std::isdigit(literal[i]) == false)
		{
			if (literal[i] == '.' && hasDot == false)
				hasDot = true;
			else
				return false;
		}
	}
	return hasDot;
}

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
	for (int i = 0; i < 3; i++)
	{
		if (literal == _pseudoLiterals[i])
			return true;
	}
	return false;
}

bool ScalarConverter::isPseudoLiteralF(const std::string &literal)
{
	for (int i = 0; i < 3; i++)
	{
		// if (literal == _pseudoLiteralsF[i])
		if (_pseudoLiteralsF[i].compare(literal) == 0)
			return true;
	}
	return false;
}

void ScalarConverter::convertFromChar(const std::string &literal)
{
	_int = static_cast<int>(literal[0]);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
	_int = std::atoi(literal.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::convertFromFloat(const std::string &literal)
{
	_float = std::strtof(literal.c_str(), NULL);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void ScalarConverter::convertFromDouble(const std::string &literal)
{
	_double = std::strtod(literal.c_str(), NULL);
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_double);
	_float = static_cast<float>(_double);
}

void ScalarConverter::printValues(const std::string &literal)
{
	printChar();
	printInt();
	printFloat(literal);
	printDouble(literal);
}

void ScalarConverter::printChar(void)
{
	std::cout << "char: ";
	if (_int < CHAR_MIN || _int > CHAR_MAX || _isPseudoLiteral)
		std::cout << "Impossible\n";
	else if (isprint(_char) == false)
		std::cout << "Non Displayable\n";
	else
		std::cout << _char << "\n";
}

void ScalarConverter::printInt(void)
{
	std::cout << "int: ";
	if (_int < INT_MIN || _int > INT_MAX || _isPseudoLiteral)
		std::cout << "Impossible\n";
	else
		std::cout << _int << "\n";
}

void ScalarConverter::printFloat(const std::string &literal)
{
	std::cout << "float: ";
	if (_isPseudoLiteral)
		std::cout << literal << "f\n";
	else
		std::cout << std::fixed << std::setprecision(1) << _float << "f\n";
};

void ScalarConverter::printDouble(const std::string &literal)
{
	std::cout << "double: ";
	if (_isPseudoLiteral)
		std::cout << literal << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << _double << "\n";
}

/* ************************************************************************** */
