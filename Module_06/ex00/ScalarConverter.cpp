/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/19 16:43:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <cstdlib>
#include <climits>
#include <string>
#include <iomanip>

char ScalarConverter::_char = 0;
long int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;
int ScalarConverter::_type = -1;
double ScalarConverter::_rangerChecker = 0;

const std::string ScalarConverter::_pseudoLiterals[6] = {
	"-inff", "-inf", "+inff", "+inf", "nanf", "nan"};

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
		return *this;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool ScalarConverter::isPseudo(std::string str)
{
	for (int i = 0; i < 6; i++)
	{
		if (_pseudoLiterals[i].compare(str) == 0)
		{
			_type = i;
			return (true);
		}
	}
	return (false);
}

bool ScalarConverter::isNumber(const std::string s)
{
	std::string::const_iterator it = s.begin();

	if (*it == '-' || *it == '+')
		it++;
	while (it != s.end() && std::isdigit(*it))
		++it;
	return !s.empty() && it == s.end();
}

bool ScalarConverter::isFloat(const std::string s)
{
	int point = 0;
	size_t i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;
	while (i < s.length())
	{
		if (!std::isdigit(s[i]))
		{
			if (s[i] == '.')
				point++;
			else
				return (false);
		}
		i++;
	}
	if (point == 0 || point > 1)
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string s)
{
	int point = 0;

	std::string::const_iterator it = s.begin();

	if (s[s.length() - 1] != 'f')
		return (false);
	if (*it == '-' || *it == '+')
		it++;
	while (it != s.end() - 1)
	{
		if (!std::isdigit(*it))
		{
			if (*it == '.')
				point++;
			else
				return (false);
		}
		++it;
	}
	if (point == 0 || point > 1)
		return (false);
	return (true);
}

void ScalarConverter::getType(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		setChar(str);
	else if (ScalarConverter::isNumber(str))
		setInt(str);
	else if (ScalarConverter::isFloat(str))
		setFloat(str);
	else if (ScalarConverter::isDouble(str))
		setDouble(str);
	else if (ScalarConverter::isPseudo(str))
	{
		;
	}
	else
	{
		std::cout << "invalid arg type" << std::endl;
		return;
	}
	printValues();
}

void ScalarConverter::printInt(void)
{
	if (_type == 0 || _type == 1)
		std::cout << "int: -inf" << std::endl;
	else if (_rangerChecker < INT_MIN || _rangerChecker > INT_MAX || _type >= 0)
		std::cout << "int: Imposible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
}

void ScalarConverter::printChar(void)
{
	if (_rangerChecker < CHAR_MIN || _rangerChecker >= CHAR_MAX || _type >= 0)
		std::cout << "char: Imposible" << std::endl;
	else if (!isprint(_char))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << _char << std::endl;
}

void ScalarConverter::printFloat(void)
{
	std::cout << "Float: ";
	if (_type == 0 || _type == 1)
		std::cout << "-inff" << std::endl;
	else if (_type == 2 || _type == 3)
		std::cout << "+inff" << std::endl;
	else if (_type > 3)
		std::cout << "nanf" << std::endl;
	else if (_type >= 0)
		std::cout << "Imposible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << _float << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(void)
{
	std::cout << "Double: ";
	if (_type == 0 || _type == 1)
		std::cout << "-inf" << std::endl;
	else if (_type == 2 || _type == 3)
		std::cout << "+inf" << std::endl;
	else if (_type > 3)
		std::cout << "nan" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1);
		std::cout << _double << std::endl;
	}
}

void ScalarConverter::printValues(void)
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void ScalarConverter::convert(std::string const str)
{
	getType(str);
}

/*
** --------------------------------- SETTERS ----------------------------------
*/

void ScalarConverter::setInt(std::string s)
{
	_rangerChecker = strtof(s.c_str(), NULL);
	_int = atoi(s.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::setChar(std::string s)
{
	_rangerChecker = strtof(s.c_str(), NULL);
	_int = static_cast<int>(s[0]);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::setDouble(std::string s)
{
	_rangerChecker = strtof(s.c_str(), NULL);
	_double = strtod(s.c_str(), NULL);
	_char = static_cast<char>(_double);
	_int = static_cast<float>(_double);
	_float = static_cast<double>(_double);
}

void ScalarConverter::setFloat(std::string s)
{
	_rangerChecker = strtof(s.c_str(), NULL);
	_float = strtof(s.c_str(), NULL);
	_char = static_cast<char>(_float);
	_int = static_cast<float>(_float);
	_double = static_cast<double>(_float);
}

/* ************************************************************************** */
