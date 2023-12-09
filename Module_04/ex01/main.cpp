/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:28:31 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/09 14:07:32 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

static void printBlueColored(std::string text);
static void printCyanColored(std::string text);

int main(void)
{
	printBlueColored("Orthodox Canonical Class Form tests");
	{
		printCyanColored("Brain Class");
		std::cout << "Bob: ";
		Brain bob;

		std::cout << "novoBob: ";
		Brain novoBob(bob);

		std::cout << "Jimmy: ";
		Brain jimmy;

		std::cout << "Bob = Jimmy: ";
		bob = jimmy;
	}

	printBlueColored("Basic 42 subject tests");
	{
		printCyanColored("Basic test (leak)");
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		printCyanColored("Basic test (array)");

		Animal *animalArray[10];
		for (size_t i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animalArray[i] = new Dog();
			else
				animalArray[i] = new Cat();
		}

		Animal *justAnAnimal;
		for (size_t i = 0; i < 10; i++)
		{
			justAnAnimal = animalArray[i];
			delete justAnAnimal;
		}
	}
	{
		printCyanColored("Deep copy test (Dog)");
		std::cout << "Bob: ";
		Dog *bob = new Dog();

		std::cout << "novoBob: ";
		Dog novoBob(*bob);

		delete bob;
		novoBob.makeSound();
	}
	{
		printCyanColored("Deep copy test (Cat)");
		std::cout << "Bob: ";
		Cat *bob = new Cat();

		std::cout << "novoBob: ";
		Cat novoBob(*bob);

		delete bob;
		novoBob.makeSound();
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
