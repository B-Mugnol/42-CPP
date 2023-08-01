/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:24:22 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/01 16:34:52 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	bool _isGatekeeping;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap(void);

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(const std::string &target);
	void guardGate(void);
	bool getIsGatekeeping(void) const;
};

std::ostream &operator<<(std::ostream &o, ScavTrap const &i);

#endif
