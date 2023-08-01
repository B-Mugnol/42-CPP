/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:24:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/01 16:00:56 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "ClapTrap '" << this->getName() << "' has evolved to FragTrap!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ClapTrap '" << this->getName() << "' has evolved to FragTrap!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "('" << this->getName() << "' is of the type FragTrap)" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap '" << this->getName() << "' is reverting back to ClapTrap!" << std::endl;
	return;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this == &rhs)
		return *this;

	std::cout << "FragTrap '" << this->getName() << "' is now '" << rhs.getName() << "'." << std::endl;

	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());

	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
		return this->displayLackHitPointsMessage("attack " + target);
	else if (this->getEnergyPoints() == 0)
		return this->displayLackEnergyPointsMessage("attack " + target);

	this->decreaseEnergyPoints(1);
	std::cout << "FragTrap '" << this->getName() << "' attacks '" << target << "' for " << this->getAttackDamage() << " points of damage!" << std::endl;
	return;
}

void FragTrap::highFivesGuys(void){
	if (this->getHitPoints() == 0)
		return this->displayLackHitPointsMessage("request a high five");
	else if (this->getEnergyPoints() == 0)
		return this->displayLackEnergyPointsMessage("request a high five");

	this->decreaseEnergyPoints(1);
	std::cout << "FragTrap '" << this->getName() << "' is energetically requesting a high five!" << std::endl;
	return ;
}
