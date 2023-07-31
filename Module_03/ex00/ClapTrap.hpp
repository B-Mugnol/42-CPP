/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:54:34 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/31 18:18:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <limits>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

	void _increaseHitPoints(unsigned int amount);
	void _decreaseHitPoints(unsigned int amount);
	void _decreaseEnergyPoints(unsigned int amount);

	void _displayLackEnergyPointsMessage(std::string attemptedAction) const;
	void _displayLackHitPointsMessage(std::string attemptedAction) const;

protected:
	void setName(std::string newValue);
	void setHitPoints(unsigned int newValue);
	void setEnergyPoints(unsigned int newValue);
	void setAttackDamage(unsigned int newValue);

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap(void);
	ClapTrap &operator=(ClapTrap const &rhs);

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream &operator<<(std::ostream &o, ClapTrap const &i);

#endif
