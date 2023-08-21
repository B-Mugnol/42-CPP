/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:36:32 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/17 17:51:55 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef enum e_formType
{
	SHRUBBERY_CREATION,
	ROBOTOMY_REQUEST,
	PRESIDENTIAL_PARDON,
	INVALID
} formType;

class Intern
{
private:
	e_formType resolveFormType(std::string form);

public:
	Intern(void);
	Intern(Intern const &src);
	~Intern(void);

	static const std::string formTypes[];

	AForm *makeForm(std::string name, std::string target);

	Intern &operator=(Intern const &rhs);
};

#endif
