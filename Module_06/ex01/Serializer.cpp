/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:37:28 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 16:57:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Serializer::Serializer(void) { return; }

Serializer::Serializer(const Serializer &src)
{
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer(void) { return; }

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Serializer &Serializer::operator=(Serializer const &rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data *dataPointer)
{
	return reinterpret_cast<uintptr_t>(dataPointer);
}

Data *Serializer::deserialize(uintptr_t rawAddress)
{
	return reinterpret_cast<Data *>(rawAddress);
}

/* ************************************************************************** */
