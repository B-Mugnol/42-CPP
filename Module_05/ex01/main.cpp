/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:59:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 16:34:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void printBlueColored(std::string text);
static void printCyanColored(std::string text);

int main(void)
{
	printBlueColored("Form Class basic tests");
	// {
	// printCyanColored("Orthodox Canonical Class Form");

	// std::cout << "Bob: ";
	// Form bob; // <- Default constructor is private

	// std::cout << "Bob = Jimmy: ";
	// bob = jimmy; // <- Assignment operator is private
	// }
	{
		printCyanColored("Parameterized Constructor (valid values) tests");
		try
		{
			std::cout << "Bob: ";
			Form bob("bob", 149, 150);

			std::cout << "novoBob: ";
			Form novoBob(bob);

			std::cout << "Jimmy: ";
			Form jimmy("jimmy", 2, 1);

			std::cout << "Tabatata: ";
			Form tabatata("tabatata", 78, 42);

			printCyanColored("Insertion operator overload tests");
			std::cout << bob << std::endl;
			std::cout << novoBob << std::endl;
			std::cout << jimmy << std::endl;
			std::cout << tabatata << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("Parameterized Constructor (invalid values) tests");
		try
		{
			std::cout << "Bob sign grade 0: ";
			Form bob("bob", 0, 1);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Jimmy sign grade 151: ";
			Form jimmy("jimmy", 151, 150);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Tabatata exec grade -42: ";
			Form tabatata("tabatata", 5, -42);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Batababa exec grade 151: ";
			Form batababa("batababa", 5, 151);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("beSigned member function (valid values) tests");
		try
		{
			Bureaucrat bigBoss("Big Boss", 1);

			std::cout << "Bob sign grade 1: ";
			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;
			bob.beSigned(bigBoss);
			std::cout << "Bob after being signed by " << bigBoss << ":" << std::endl;
			std::cout << bob << std::endl;

			std::cout << "Jimmy sign grade 150: ";
			Form jimmy("jimmy", 150, 1);
			std::cout << jimmy << std::endl;
			jimmy.beSigned(bigBoss);
			std::cout << "Jimmy after being signed by " << bigBoss << ":" << std::endl;
			std::cout << jimmy << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("beSigned member function (invalid values) tests");
		// Nested try/catch for fun:
		try
		{
			std::cout << "Bob sign grade 1: ";
			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;

			Bureaucrat lilBoss("Lil Boss", 2);
			try
			{

				std::cout << "Signing Bob (sign grade 1) with Lil Boss (grade 2): ";
				bob.beSigned(lilBoss);
				std::cout << bob << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}

			std::cout << "Jimmy sign grade 149: ";
			Form jimmy("jimmy", 149, 1);
			std::cout << jimmy << std::endl;

			Bureaucrat intern("Intern", 150);
			try
			{

				std::cout << "Signing Jimmy (sign grade 149) with Intern (grade 150): ";
				jimmy.beSigned(intern);
				std::cout << jimmy << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	printBlueColored("Bureaucrat Class advanced tests");
	{
		printCyanColored("signForm member function (valid values) tests");
		try
		{
			Bureaucrat bigBoss("Big Boss", 1);

			std::cout << "Bob sign grade 1: ";
			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;
			bigBoss.signForm(bob);
			std::cout << "Bob after being signed by " << bigBoss << ":" << std::endl;
			std::cout << bob << std::endl;

			std::cout << "Jimmy sign grade 150: ";
			Form jimmy("jimmy", 150, 1);
			std::cout << jimmy << std::endl;
			bigBoss.signForm(jimmy);
			std::cout << "Jimmy after being signed by " << bigBoss << ":" << std::endl;
			std::cout << jimmy << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("signForm member function (invalid values) tests");
		// Nested try/catch for fun:
		try
		{
			Bureaucrat lilBoss("Lil Boss", 2);
			std::cout << "Bob sign grade 1: ";
			Form bob("bob", 1, 1);
			std::cout << bob << std::endl;

			std::cout << "Signing Bob (sign grade 1) with Lil Boss (grade 2): ";
			lilBoss.signForm(bob);
			std::cout << bob << std::endl;

			Bureaucrat intern("Intern", 150);
			std::cout << "Jimmy sign grade 149: ";
			Form jimmy("jimmy", 149, 1);
			std::cout << jimmy << std::endl;

			std::cout << "Signing Jimmy (sign grade 149) with Intern (grade 150): ";
			intern.signForm(jimmy);
			std::cout << jimmy << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
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
