/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:16:05 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 16:59:48 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie(std::string zombieName);
	Zombie(void);
	~Zombie(void);

	void announce(void);
	void setName(std::string zombieName);
	std::string getName(void) const;

private:
	std::string name;
};

Zombie *zombieHorde(int N, std::string name);

#endif
