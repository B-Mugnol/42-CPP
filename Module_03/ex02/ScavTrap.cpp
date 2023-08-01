/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:24:26 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/01 16:36:02 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap(), _isGatekeeping(false)
{
	std::cout << "ClapTrap '" << this->getName() << "' has evolved to ScavTrap!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _isGatekeeping(false)
{
	std::cout << "ClapTrap '" << this->getName() << "' has evolved to ScavTrap!" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	return;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	this->_isGatekeeping = src.getIsGatekeeping();
	std::cout << "('" << this->getName() << "' is of the type ScavTrap)" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap '" << this->getName() << "' is reverting back to ClapTrap!" << std::endl;
	return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this == &rhs)
		return *this;

	std::cout << "ScavTrap '" << this->getName() << "' is now '" << rhs.getName() << "'." << std::endl;

	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	this->_isGatekeeping = rhs.getIsGatekeeping();

	return *this;
}

std::ostream &operator<<(std::ostream &o, ScavTrap const &i)
{
	o << "ScavTrap '" << i.getName() << "' has " << i.getHitPoints() << " HP, " << i.getEnergyPoints() << " EP and does " << i.getAttackDamage() << " damage per attack. Gatekeeping mode is " << (i.getIsGatekeeping() ? "ON" : "OFF") << ".";
	return o;
}

bool ScavTrap::getIsGatekeeping(void) const { return this->_isGatekeeping; }

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
		return this->displayLackHitPointsMessage("attack " + target);
	else if (this->getEnergyPoints() == 0)
		return this->displayLackEnergyPointsMessage("attack " + target);

	this->decreaseEnergyPoints(1);
	std::cout << "ScavTrap '" << this->getName() << "' attacks '" << target << "' for " << this->getAttackDamage() << " points of damage!" << std::endl;
	return;
}

void ScavTrap::guardGate(void)
{
	if (this->getHitPoints() == 0)
		return this->displayLackHitPointsMessage("enter Gatekeeper mode");
	else if (this->getEnergyPoints() == 0)
		return this->displayLackEnergyPointsMessage("enter Gatekeeper mode");

	if (this->_isGatekeeping)
	{
		std::cout << "ScavTrap '" << this->getName() << "' is already in Gatekeeper mode." << std::endl;
		return;
	}
	this->_isGatekeeping = true;
	this->decreaseEnergyPoints(1);
	std::cout << "ScavTrap '" << this->getName() << "' is now in Gatekeeper mode." << std::endl;
	return;
}
