/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:09:38 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 17:09:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("training sword") { return; }
Weapon::Weapon(std::string type) : _type(type) { return; }
Weapon::~Weapon(void) { return; }

std::string const &Weapon::getType(void) const { return this->_type; }

void Weapon::setType(std::string type) { this->_type = type; }
