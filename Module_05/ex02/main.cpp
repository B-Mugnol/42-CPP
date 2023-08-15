/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:59:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/15 16:27:24 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void printBlueColored(std::string text);
static void printCyanColored(std::string text);

int main(void)
{
	printBlueColored("Forms tests");
	{
		printCyanColored("ShrubberyCreationForm (valid values) tests");
		ShrubberyCreationForm form1("home");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << form1 << std::endl;
		bigBoss.signForm(form1);
		std::cout << form1 << std::endl;
		bigBoss.executeForm(form1);
		std::cout << form1 << std::endl;
	}
	{
		printCyanColored("RobotomyRequestForm (valid values) tests");
		RobotomyRequestForm form1("joão");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << form1 << std::endl;
		bigBoss.signForm(form1);
		std::cout << form1 << std::endl;
		bigBoss.executeForm(form1);
		bigBoss.executeForm(form1);
		bigBoss.executeForm(form1);
		bigBoss.executeForm(form1);
		std::cout << form1 << std::endl;
	}
	{
		printCyanColored("PresidentialPardonForm (valid values) tests");
		PresidentialPardonForm form1("joão");
		Bureaucrat bigBoss("bigBoss", 1);

		std::cout << form1 << std::endl;
		bigBoss.signForm(form1);
		std::cout << form1 << std::endl;
		bigBoss.executeForm(form1);
		std::cout << form1 << std::endl;
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
