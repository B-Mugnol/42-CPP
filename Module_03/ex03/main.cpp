/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:53:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 09:34:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

static void printTrap(DiamondTrap &trap)
{
	std::cout << "[" << trap << "]" << std::endl;
	return;
}

int main(void)
{
	{
		// Orthodox Canonical Class Form tests
		DiamondTrap bob;
		bob.whoAmI();
		printTrap(bob);

		DiamondTrap novoBob(bob);
		novoBob.whoAmI();
		printTrap(novoBob);

		DiamondTrap jimmy("Jimmy");
		jimmy.whoAmI();
		printTrap(jimmy);

		bob = jimmy;
		bob.whoAmI();
		printTrap(bob);

		novoBob.guardGate();
		printTrap(novoBob);
		novoBob.highFivesGuys();
		printTrap(novoBob);
		novoBob.attack("Joaninha");
		printTrap(novoBob);
	}
	{
		// Actions tests
		DiamondTrap admiralAckbar("Admiral Ackbar");
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(9);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(8);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Joãozinho");
		printTrap(admiralAckbar);

		admiralAckbar.guardGate();
		printTrap(admiralAckbar);

		admiralAckbar.highFivesGuys();
		printTrap(admiralAckbar);

		admiralAckbar.whoAmI();
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

		admiralAckbar.guardGate();
		printTrap(admiralAckbar);

		admiralAckbar.highFivesGuys();
		printTrap(admiralAckbar);

		admiralAckbar.whoAmI();
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(5);
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(2000);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(91);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Maria");
		printTrap(admiralAckbar);

		admiralAckbar.highFivesGuys();
		printTrap(admiralAckbar);
	}
	return 0;
}
