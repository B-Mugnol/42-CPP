/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/05 13:35:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <exception>
#include <stack>
#include <string>
#include <iostream>

class RPN
{
public:
	RPN(void);
	RPN(RPN const &src);
	~RPN(void);

	RPN &operator=(RPN const &rhs);

	void executeOperation(const std::string input);

private:
	static const std::string operators;

	std::stack<int> _stack;

	void pushResult(const char c);
	int getResult(const int a, const int b, const char op) const;
	bool isOperand(const char c) const;
	bool isOperator(const char c) const;

	// EXCEPTIONS
private:
	class InvalidInput : public std::exception
	{
		virtual const char *what() const throw();
	};
	class InvalidOperator : public std::exception
	{
		virtual const char *what() const throw();
	};
	class InvalidOperands : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif
