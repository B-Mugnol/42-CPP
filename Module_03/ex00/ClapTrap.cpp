/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:54:32 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/31 17:29:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Bob"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap '" << this->_name << "' created" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap '" << this->_name << "' created" << std::endl;
	return;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src.getName()), _hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()), _attackDamage(src.getAttackDamage())
{
	std::cout << "ClapTrap '" << this->_name << "' copied" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap '" << this->_name << "' destroyed" << std::endl;
	return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this == &rhs)
		return *this;

	std::cout << "ClapTrap '" << this->_name << "' is now '" << rhs.getName() << "'." << std::endl;

	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return *this;
}

std::ostream &operator<<(std::ostream &o, ClapTrap const &i)
{
	o << "ClapTrap '" << i.getName() << "' has " << i.getHitPoints() << " HP, " << i.getEnergyPoints() << " EP and does " << i.getAttackDamage() << " damage per attack.";
	return o;
}

std::string ClapTrap::getName(void) const { return this->_name; }
unsigned int ClapTrap::getHitPoints(void) const { return this->_hitPoints; }
unsigned int ClapTrap::getEnergyPoints(void) const { return this->_energyPoints; }
unsigned int ClapTrap::getAttackDamage(void) const { return this->_attackDamage; }

void ClapTrap::setName(std::string newValue)
{
	this->_name = newValue;
	return;
}
void ClapTrap::setHitPoints(unsigned int newValue)
{
	this->_hitPoints = newValue;
	return;
}
void ClapTrap::setEnergyPoints(unsigned int newValue)
{
	this->_energyPoints = newValue;
	return;
}
void ClapTrap::setAttackDamage(unsigned int newValue)
{
	this->_attackDamage = newValue;
	return;
}

void ClapTrap::increaseHitPoints(unsigned int amount)
{
	if (this->_hitPoints == std::numeric_limits<unsigned int>::max())
		return;

	if (this->_hitPoints >= this->_hitPoints + amount)
		this->_hitPoints = std::numeric_limits<unsigned int>::max();
	else
		this->_hitPoints += amount;
	return;
}

void ClapTrap::decreaseHitPoints(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return;

	if (this->_hitPoints < this->_hitPoints - amount)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	return;
}

void ClapTrap::decreaseEnergyPoints(unsigned int amount)
{
	if (this->_energyPoints == 0)
		return;

	if (this->_energyPoints < this->_energyPoints - amount)
		this->_energyPoints = 0;
	else
		this->_energyPoints -= amount;
	return;
}

void ClapTrap::displayLackEnergyPointsMessage(std::string attemptedAction) const
{
	std::cout << "ClapTrap '" << this->_name << "' does not have enough energy to " << attemptedAction << "." << std::endl;
	return;
}

void ClapTrap::displayLackHitPointsMessage(std::string attemptedAction) const
{
	std::cout << "ClapTrap '" << this->_name << "' is dead and cannot " << attemptedAction << "." << std::endl;
	return;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		return this->displayLackHitPointsMessage("attack " + target);
	else if (this->_energyPoints == 0)
		return this->displayLackEnergyPointsMessage("attack " + target);

	this->decreaseEnergyPoints(1);
	std::cout << "ClapTrap '" << this->_name << "' attacks '" << target << "' for " << this->_attackDamage << " points of damage!" << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap '" << this->_name << "' is already dead and takes no more damage." << std::endl;
		return;
	}

	this->decreaseHitPoints(amount);
	std::cout << "ClapTrap '" << this->_name << "' takes " << amount << " points of damage." << std::endl;
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap '" << this->_name << "' has been destroyed!" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		return this->displayLackHitPointsMessage("be repaired");
	else if (this->_energyPoints == 0)
		return this->displayLackEnergyPointsMessage("be repaired");

	this->decreaseEnergyPoints(1);
	this->increaseHitPoints(amount);
	std::cout << "ClapTrap '" << this->_name << "' is repaired, recovering " << amount << " hitpoints." << std::endl;
	return;
}
