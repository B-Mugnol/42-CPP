/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:07 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:38 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain(void)
{
	std::cout << "A brain has been created." << std::endl;
	return;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = src.ideas[i];

	std::cout << "A brain has been copied." << std::endl;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain(void)
{
	std::cout << "A brain has been deleted." << std::endl;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &Brain::operator=(Brain const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < NUM_IDEAS; i++)
			this->ideas[i] = rhs.ideas[i];
	}

	std::cout << "A brain has been attributed to another." << std::endl;
	return *this;
}

/* ************************************************************************** */
