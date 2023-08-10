/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:11 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 14:44:23 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const int Bureaucrat::HIGHEST_GRADE = 1;
const int Bureaucrat::LOWEST_GRADE = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat(void) : _name("<missing name>"), _grade(Bureaucrat::LOWEST_GRADE)
{
	std::cout << "Bureaucrat " + this->_name + " created with grade " << this->_grade
			  << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name), _grade(Bureaucrat::LOWEST_GRADE)
{
	if (grade < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > Bureaucrat::LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat " + this->_name + " created with grade " << this->_grade
			  << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
	if (src._grade < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooHighException();
	if (src._grade > Bureaucrat::LOWEST_GRADE)
		throw GradeTooLowException();
	std::cout << "Bureaucrat " + this->_name + " copied with grade " << this->_grade
			  << std::endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " + this->_name + " destroyed" << std::endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		throw Bureaucrat::UnassignableException();
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < Bureaucrat::HIGHEST_GRADE)
		throw GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > Bureaucrat::LOWEST_GRADE)
		throw GradeTooLowException();
	this->_grade += 1;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName(void) const { return this->_name; }
int Bureaucrat::getGrade(void) const { return this->_grade; }

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Bureaucrat::UnassignableException::what() const throw()
{
	return "Bureaucrats are unassignable.";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low.";
}

/* ************************************************************************** */
