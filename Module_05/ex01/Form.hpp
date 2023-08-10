/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 15:28:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	Form(void);

	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

	Form &operator=(Form const &rhs);

public:
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(Form const &src);
	~Form(void);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;

	void beSigned(const Bureaucrat& bureaucrat);

	// EXCEPTIONS //
private:
	class UnassignableException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
