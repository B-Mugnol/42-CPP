/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:17:32 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/21 16:53:58 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *ZomBob;

	ZomBob = newZombie("Bob");
	ZomBob->announce();
	delete ZomBob;

	randomChump("Billy");

	Zombie theUnnamedUndead;

	return 0;
}
