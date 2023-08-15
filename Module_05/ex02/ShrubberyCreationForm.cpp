/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 18:54:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_FORM_NAME = "ShrubberyCreationForm";
const int ShrubberyCreationForm::_SIGN_GRADE = 145;
const int ShrubberyCreationForm::_EXEC_GRADE = 137;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm(), _target("<missing target>")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm(this->_FORM_NAME, this->_SIGN_GRADE, this->_EXEC_GRADE), _target(target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src._target)
{
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		throw AForm::UnassignableException();
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::action(void) const
{
	std::ofstream outputFile;
	outputFile.open((this->_target + "_shrubbery").c_str());
	if (outputFile.fail())
	{
		std::cout << "Shrubbery creation for " << this->_target << " has failed." << std::endl;
		return;
	}
	std::string forest = "\
	 ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n\
	/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n\
	/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n\
	/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\";
	outputFile
		<< forest;
	return;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget(void) const { return this->_target; }

/* ************************************************************************** */
