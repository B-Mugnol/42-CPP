/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:11 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/09 16:24:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form(void) : _name("<missing name>"), _signGrade(Bureaucrat::HIGHEST_GRADE), _execGrade(Bureaucrat::HIGHEST_GRADE), _isSigned(false)
{
	std::cout << "Form " + this->_name + " created with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < Bureaucrat::HIGHEST_GRADE || execGrade < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (signGrade > Bureaucrat::LOWEST_GRADE || execGrade > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();

	std::cout << "Form " + this->_name + " created with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

Form::Form(const Form &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	if (src._signGrade < Bureaucrat::HIGHEST_GRADE || src._execGrade < Bureaucrat::HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (src._signGrade > Bureaucrat::LOWEST_GRADE || src._execGrade > Bureaucrat::LOWEST_GRADE)
		throw Form::GradeTooLowException();

	std::cout << "Form " + this->_name + " copied with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form(void)
{
	std::cout << "Form " + this->_name + " destroyed" << std::endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		throw Form::UnassignableException();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << (i.getIsSigned() ? "[Signed]" : "[Pending signature]")
	  << " Form " << i.getName() << ", grade requirements: "
	  << i.getSignGrade() << " (to be signed), "
	  << i.getExecGrade() << " (to be executed)";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signGrade < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName(void) const { return this->_name; }
int Form::getSignGrade(void) const { return this->_signGrade; }
int Form::getExecGrade(void) const { return this->_execGrade; }
bool Form::getIsSigned(void) const { return this->_isSigned; }

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Form::UnassignableException::what() const throw()
{
	return "Forms are unassignable.";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

/* ************************************************************************** */
