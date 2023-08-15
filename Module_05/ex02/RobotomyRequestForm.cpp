/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/14 14:58:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::_FORM_NAME = "RobotomyRequestForm";
const int RobotomyRequestForm::_SIGN_GRADE = 72;
const int RobotomyRequestForm::_EXEC_GRADE = 45;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm(), _target("<missing target>")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm(this->_FORM_NAME, this->_SIGN_GRADE, this->_EXEC_GRADE), _target(target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src._target)
{
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
		throw AForm::UnassignableException();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::action(void) const
{
	std::cout << "[LOUD DRILLING NOISES]" << std::endl;

	timespec ts;
	timespec_get(&ts, TIME_UTC);
	srand((unsigned)ts.tv_nsec);

	if (rand() % 2)
	{
		std::cout << "[SUCCESS] " << this->_target
				  << " has been successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << "[FAILURE] " << this->_target << "'"
				  << (*this->_target.rbegin() == 's' ? " " : "s ")
				  << "robotomy has failed." << std::endl;
	}
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RobotomyRequestForm::getTarget(void) const { return this->_target; }

/* ************************************************************************** */
