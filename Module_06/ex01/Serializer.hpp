/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:37:05 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 16:42:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	Serializer(void);
	Serializer(Serializer const &src);
	~Serializer(void);

	Serializer &operator=(Serializer const &rhs);
};

#endif
