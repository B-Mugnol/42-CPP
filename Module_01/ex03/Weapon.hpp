/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:59:31 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 17:22:43 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	std::string const &getType(void) const;
	void setType(std::string type);
};

#endif
