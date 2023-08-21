/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:59:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/17 18:21:48 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void printBlueColored(std::string text);
static void printCyanColored(std::string text);

int main(void)
{
	printBlueColored("Intern makeForm() tests");
	{
		printCyanColored("ShrubberyCreationForm test");
		Intern intern;
		AForm *form1 = intern.makeForm(intern.formTypes[0], "home");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << *form1 << std::endl;
		bigBoss.signForm(*form1);
		std::cout << *form1 << std::endl;
		bigBoss.executeForm(*form1);
		std::cout << *form1 << std::endl;

		delete form1;
	}
	{
		printCyanColored("RobotomyRequestForm test");
		Intern intern;
		AForm *form2 = intern.makeForm(intern.formTypes[1], "joão");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << *form2 << std::endl;
		bigBoss.signForm(*form2);
		std::cout << *form2 << std::endl;
		bigBoss.executeForm(*form2);
		bigBoss.executeForm(*form2);
		bigBoss.executeForm(*form2);
		bigBoss.executeForm(*form2);
		std::cout << *form2 << std::endl;

		delete form2;
	}
	{
		printCyanColored("PresidentialPardonForm test");
		Intern intern;
		AForm *form3 = intern.makeForm(intern.formTypes[2], "maria");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << *form3 << std::endl;
		bigBoss.signForm(*form3);
		std::cout << *form3 << std::endl;
		bigBoss.executeForm(*form3);
		std::cout << *form3 << std::endl;

		delete form3;
	}
	{
		printCyanColored("Invalid form name test");
		Intern intern;
		AForm *form3 = intern.makeForm("A_Invalid_Form_Name", "nobody");

		delete form3;
	}

	return 0;
}

static void printBlueColored(std::string text)
{
	std::cout << "\033[1m"
			  << "\033[94m" << text << "\033[0m" << std::endl;
	return;
}

static void printCyanColored(std::string text)
{
	std::cout << "\033[96m"
			  << text << "\033[0m" << std::endl;
	return;
}
