/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:40:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 17:46:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base *generate(void);
static void identify(Base *p);
static void identify(Base &p);

int main(void)
{
	Base *basePointer = generate();

	identify(basePointer);
	identify(*basePointer);

	delete basePointer;
	return 0;
}

static Base *generate(void)
{
	std::srand(std::time(NULL));
	int randomNumber = std::rand() % 3;

	switch (randomNumber)
	{
	case 0:
		std::cout << "Class A instanciated." << std::endl;
		return new A;
	case 1:
		std::cout << "Class B instanciated." << std::endl;
		return new B;
	case 2:
		std::cout << "Class C instanciated." << std::endl;
		return new C;
	default:
		return NULL;
	}
}

static void identify(Base *p)
{
	std::cout << "[identify by pointer] ";
	if (dynamic_cast<A *>(p))
		std::cout << "Object is of type: "
				  << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Object is of type: "
				  << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Object is of type: "
				  << "C" << std::endl;
	else
		std::cout << "Object is not of type A, B or C" << std::endl;
}

static void identify(Base &p)
{
	// {
	// 	std::cout << "[identify by reference] ";
	// 	if (dynamic_cast<A *>(&p))
	// 		std::cout << "Object is of type: "
	// 				  << "A" << std::endl;
	// 	else if (dynamic_cast<B *>(&p))
	// 		std::cout << "Object is of type: "
	// 				  << "B" << std::endl;
	// 	else if (dynamic_cast<C *>(&p))
	// 		std::cout << "Object is of type: "
	// 				  << "C" << std::endl;
	// 	else
	// 		std::cout << "Object is not of type A, B or C" << std::endl;
	// }
	{
		std::cout << "[identify by reference]:" << std::endl;

		try
		{
			A &reference = dynamic_cast<A &>(p);
			std::cout << "Object is of type: "
					  << "A" << std::endl;
			(void)reference;
			return;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << " — ";
			std::cout << "Object is not of type: "
					  << "A" << std::endl;
		}

		try
		{
			B &reference = dynamic_cast<B &>(p);
			std::cout << "Object is of type: "
					  << "B" << std::endl;
			(void)reference;
			return;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << " — ";
			std::cout << "Object is not of type: "
					  << "B" << std::endl;
		}

		try
		{
			C &reference = dynamic_cast<C &>(p);
			std::cout << "Object is of type: "
					  << "C" << std::endl;
			(void)reference;
			return;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << " — ";
			std::cout << "Object is not of type: "
					  << "C" << std::endl;
		}

		std::cout << "Object is not of type A, B or C" << std::endl;
	}
}
