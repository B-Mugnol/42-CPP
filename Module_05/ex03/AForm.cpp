/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:11 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/09 16:24:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(void) : _name("<missing name>"), _signGrade(Bureaucrat::HIGHEST_GRADE), _execGrade(Bureaucrat::HIGHEST_GRADE), _isSigned(false)
{
	std::cout << this->_name + " created with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < Bureaucrat::HIGHEST_GRADE || execGrade < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooHighException();
	if (signGrade > Bureaucrat::LOWEST_GRADE || execGrade > Bureaucrat::LOWEST_GRADE)
		throw GradeTooLowException();

	std::cout << this->_name + " created with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

AForm::AForm(const AForm &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	if (src._signGrade < Bureaucrat::HIGHEST_GRADE || src._execGrade < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooHighException();
	if (src._signGrade > Bureaucrat::LOWEST_GRADE || src._execGrade > Bureaucrat::LOWEST_GRADE)
		throw GradeTooLowException();

	std::cout << this->_name + " copied with sign grade " << this->_signGrade
			  << " and execute grade " << this->_execGrade << "." << std::endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm(void)
{
	std::cout << this->_name + " destroyed" << std::endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		throw AForm::UnassignableException();
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << (i.getIsSigned() ? "[Signed]" : "[Pending signature]")
	  << " " << i.getName() << ", grade requirements: "
	  << i.getSignGrade() << " (to be signed), "
	  << i.getExecGrade() << " (to be executed)";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signGrade < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->_isSigned == false)
		throw AForm::UnsignedFormException();

	if (executor.getGrade() > this->_execGrade)
		throw AForm::GradeTooLowException();

	this->action();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string AForm::getName(void) const { return this->_name; }
int AForm::getSignGrade(void) const { return this->_signGrade; }
int AForm::getExecGrade(void) const { return this->_execGrade; }
bool AForm::getIsSigned(void) const { return this->_isSigned; }

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *AForm::UnsignedFormException::what() const throw()
{
	return "Form isn't signed.";
}

const char *AForm::UnassignableException::what() const throw()
{
	return "Forms are unassignable.";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low.";
}

/* ************************************************************************** */
