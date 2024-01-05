/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/05 13:47:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const std::string RPN::operators("+-*/");

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN(void)
{
	return;
}

RPN::RPN(RPN const &src)
{
	this->_stack = src._stack;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
		this->_stack = rhs._stack;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RPN::executeOperation(const std::string input)
{
	if (input.empty())
		throw InvalidInput();
	else if (isOperator(input[0]))
		throw InvalidInput();

	for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
			continue;

		if (isOperand(input[i]))
		{
			if (i > 0 && std::isdigit(input[i - 1]))
				throw InvalidInput();
			this->_stack.push(input[i] - '0');
		}
		else if (isOperator(input[i]))
		{
			if (this->_stack.size() < 2)
				throw InvalidOperator();
			pushResult(input[i]);
		}
	}

	if (this->_stack.size() != 1)
		throw InvalidOperands();

	std::cout << "Result: " << this->_stack.top() << "\n";
	this->_stack.pop();
}

void RPN::pushResult(const char c)
{
	int a = this->_stack.top();
	this->_stack.pop();

	int b = this->_stack.top();
	this->_stack.pop();

	this->_stack.push(getResult(b, a, c));
}

int RPN::getResult(const int a, const int b, const char op) const
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	default:
		throw InvalidInput();
	}
}

bool RPN::isOperand(const char c) const
{
	return std::isdigit(c) ? true : false;
}

bool RPN::isOperator(const char c) const
{
	if (this->operators.find_first_of(c) != std::string::npos)
		return true;
	return false;
}

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *RPN::InvalidInput::what() const throw()
{
	return "Invalid input";
}

const char *RPN::InvalidOperator::what() const throw()
{
	return "Invalid operator usage";
}

const char *RPN::InvalidOperands::what() const throw()
{
	return "There are not enough operators";
}

/* ************************************************************************** */
