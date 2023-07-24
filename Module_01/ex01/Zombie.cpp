/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:18:29 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/21 16:53:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName) { return; }

Zombie::Zombie(void) : name("The Unnamed Undead") { return; }

Zombie::~Zombie(void)
{
	std::cout << this->getName() << " has died (once more!)" << std::endl;
	return;
}

void Zombie::announce(void)
{
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void Zombie::setName(std::string zombieName)
{
	this->name = zombieName;
	return;
}

std::string Zombie::getName(void) const
{
	return this->name;
}
