/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:53:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/31 17:15:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

static void printTrap(ClapTrap &trap)
{
	std::cout << "[" << trap << "]" << std::endl;
	return;
}

int main(void)
{
	{
		// Orthodox Canonical Class Form tests
		ClapTrap bob;
		printTrap(bob);

		ClapTrap novoBob(bob);
		printTrap(novoBob);

		ClapTrap jimmy("Jimmy");
		printTrap(jimmy);

		bob = jimmy;
		printTrap(bob);
	}
	{
		// Actions tests
		ClapTrap admiralAckbar("Admiral Ackbar");
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(9);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(8);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Joãozinho");
		printTrap(admiralAckbar);

		while (admiralAckbar.getEnergyPoints())
		{
			admiralAckbar.attack("Jusicreuda");
			printTrap(admiralAckbar);
		}

		admiralAckbar.beRepaired(91);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Maria");
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(5);
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(20);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(91);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Maria");
		printTrap(admiralAckbar);
	}
	return 0;
}
