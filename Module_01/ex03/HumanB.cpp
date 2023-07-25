/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:16:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 17:51:50 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name) { return; }

HumanB::~HumanB(void) { return; }

void HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return;
}
