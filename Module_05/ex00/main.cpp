/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:59:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 15:06:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

static void printBlueColored(std::string text);
static void printCyanColored(std::string text);

int main(void)
{
	printBlueColored("Bureaucrat Class basic tests");
	{
		// printCyanColored("Orthodox Canonical Class Form");

		// std::cout << "Bob: ";
		// Bureaucrat bob; // <- Default constructor is private

		// std::cout << "Bob = Jimmy: ";
		// bob = jimmy; // <- Assignment operator is private
	} {
		printCyanColored("Parameterized Constructor (valid values) tests");
		try
		{
			std::cout << "Bob: ";
			Bureaucrat bob("bob", 149);

			std::cout << "novoBob: ";
			Bureaucrat novoBob(bob);

			std::cout << "Jimmy: ";
			Bureaucrat jimmy("jimmy", 1);

			std::cout << "Tabatata: ";
			Bureaucrat tabatata("tabatata", 78);

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
			std::cout << "Bob grade 0: ";
			Bureaucrat bob("bob", 0);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Jimmy grade 151: ";
			Bureaucrat jimmy("jimmy", 151);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Tabatata grade -42: ";
			Bureaucrat tabatata("tabatata", -42);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("Increment/Decrement member function (valid values) tests");
		try
		{
			std::cout << "Bob grade 1: ";
			Bureaucrat bob("bob", 1);
			std::cout << bob << std::endl;
			bob.decrementGrade();
			std::cout << "Bob after decrement: ";
			std::cout << bob << std::endl;

			std::cout << "Jimmy grade 150: ";
			Bureaucrat jimmy("jimmy", 150);
			std::cout << jimmy << std::endl;
			jimmy.incrementGrade();
			std::cout << "Jimmy after increment: ";
			std::cout << jimmy << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printCyanColored("Increment/Decrement member function (invalid values) tests");
		// Nested try/catch for fun:
		try
		{
			std::cout << "Bob grade 1: ";
			Bureaucrat bob("bob", 1);
			std::cout << bob << std::endl;
			try
			{
				std::cout << "Incrementing Bob: ";
				bob.incrementGrade();
				std::cout << bob << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
			std::cout << "Jimmy grade 150: ";
			Bureaucrat jimmy("jimmy", 150);
			std::cout << jimmy << std::endl;
			try
			{
				std::cout << "Decrementing Jimmy: ";
				jimmy.decrementGrade();
				std::cout << jimmy << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "Bob grade 1: ";
		Bureaucrat bob("bob", 1);
		std::cout << bob << std::endl;
		try
		{
			std::cout << "Incrementing Bob: ";
			bob.incrementGrade();
			std::cout << bob << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Jimmy grade 150: ";
		Bureaucrat jimmy("jimmy", 150);
		std::cout << jimmy << std::endl;
		try
		{
			std::cout << "Decrementing Jimmy: ";
			jimmy.decrementGrade();
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
