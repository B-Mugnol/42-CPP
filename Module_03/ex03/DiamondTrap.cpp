/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:19:14 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 09:29:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap(), _name(this->ClapTrap::getName())
{
	this->ClapTrap::setName(this->ClapTrap::getName() + "_clap_name");
	std::cout << "ClapTrap '" << this->getDiamondName() << "' has evolved to DiamondTrap!" << std::endl;
	this->setHitPoints(this->FragTrap::baseHitPoints);
	this->setEnergyPoints(this->ScavTrap::baseEnergyPoints);
	this->setAttackDamage(this->FragTrap::baseAttackDamage);
	return;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	this->ClapTrap::setName(this->ClapTrap::getName() + "_clap_name");
	std::cout << "ClapTrap '" << this->getDiamondName() << "' has evolved to DiamondTrap!" << std::endl;
	this->setHitPoints(this->FragTrap::baseHitPoints);
	this->setEnergyPoints(this->ScavTrap::baseEnergyPoints);
	this->setAttackDamage(this->FragTrap::baseAttackDamage);
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = src.getDiamondName();
	std::cout << "('" << this->getDiamondName() << "' is of the type DiamondTrap)" << std::endl;
	return;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap '" << this->getDiamondName() << "' is reverting back to ClapTrap!" << std::endl;
	return;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs)
{
	if (this == &rhs)
		return *this;

	std::cout << "DiamondTrap '" << this->getDiamondName() << "' is now '" << rhs.getDiamondName() << "'." << std::endl;

	this->setName(rhs.getName());
	this->setHitPoints(rhs.getHitPoints());
	this->setEnergyPoints(rhs.getEnergyPoints());
	this->setAttackDamage(rhs.getAttackDamage());
	this->_name = rhs.getDiamondName();

	return *this;
}

std::ostream &operator<<(std::ostream &o, DiamondTrap const &i)
{
	o << "DiamondTrap '" << i.getDiamondName() << "' has " << i.getHitPoints() << " HP, " << i.getEnergyPoints() << " EP and does " << i.getAttackDamage() << " damage per attack.";
	return o;
}

std::string DiamondTrap::getDiamondName(void) const { return this->_name; }

void DiamondTrap::whoAmI(void)
{
	std::cout << "I AM THE DIAMOND TRAP '" << this->getDiamondName() << "' AND NONE SHALL PASS!!";
	std::cout << " Also, follow me on instagram @" << this->ClapTrap::getName() << " :)" << std::endl;
	return;
}
