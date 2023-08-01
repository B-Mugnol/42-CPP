/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:53:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/01 16:35:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

static void printTrap(ScavTrap &trap)
{
	std::cout << "[" << trap << "]" << std::endl;
	return;
}

int main(void)
{
	{
		// Orthodox Canonical Class Form tests
		ScavTrap bob;
		bob.guardGate();
		printTrap(bob);

		ScavTrap novoBob(bob);
		printTrap(novoBob);

		ScavTrap jimmy("Jimmy");
		printTrap(jimmy);

		bob = jimmy;
		printTrap(bob);
	}
	{
		// Actions tests
		ScavTrap admiralAckbar("Admiral Ackbar");
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(9);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(8);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Joãozinho");
		printTrap(admiralAckbar);

		admiralAckbar.guardGate();
		printTrap(admiralAckbar);

		admiralAckbar.guardGate();
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

		admiralAckbar.takeDamage(2000);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(91);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Maria");
		printTrap(admiralAckbar);

		admiralAckbar.guardGate();
		printTrap(admiralAckbar);
	}
	return 0;
}

