/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:36:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/17 18:24:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

std::string const Intern::formTypes[] = {
	"shrubbery creation", "robotomy request", "presidential pardon"};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern(void)
{
	return;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

e_formType Intern::resolveFormType(std::string form)
{
	int i = SHRUBBERY_CREATION;
	while (i != INVALID && formTypes[i].compare(form) != 0)
		i++;
	return (e_formType)i;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form;

	switch (resolveFormType(name))
	{
	case SHRUBBERY_CREATION:
		form = new ShrubberyCreationForm(target);
		break;
	case ROBOTOMY_REQUEST:
		form = new RobotomyRequestForm(target);
		break;
	case PRESIDENTIAL_PARDON:
		form = new PresidentialPardonForm(target);
		break;
	default:
		std::cout << name << " is not a valid form." << std::endl;
		return NULL;
	}
	std::cout << "Intern creates: " << *form << std::endl;
	return form;
}

/* ************************************************************************** */
