/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:53:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/01 16:00:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

static void printTrap(FragTrap &trap)
{
	std::cout << "[" << trap << "]" << std::endl;
	return;
}

int main(void)
{
	{
		// Orthodox Canonical Class Form tests
		FragTrap bob;
		printTrap(bob);

		FragTrap novoBob(bob);
		printTrap(novoBob);

		FragTrap jimmy("Jimmy");
		printTrap(jimmy);

		bob = jimmy;
		printTrap(bob);
	}
	{
		// Actions tests
		FragTrap admiralAckbar("Admiral Ackbar");
		printTrap(admiralAckbar);

		admiralAckbar.takeDamage(9);
		printTrap(admiralAckbar);

		admiralAckbar.beRepaired(8);
		printTrap(admiralAckbar);

		admiralAckbar.attack("Joãozinho");
		printTrap(admiralAckbar);

		admiralAckbar.highFivesGuys();
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

		admiralAckbar.highFivesGuys();
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

