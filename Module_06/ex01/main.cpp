/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:40:32 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 16:56:00 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data originalData(666);

	uintptr_t serializedData = Serializer::serialize(&originalData);

	Data *deserializedData = Serializer::deserialize(serializedData);

	std::cout << "Original data value: "
			  << originalData.value << std::endl;
	std::cout << "Deserialized data value: "
			  << deserializedData->value << std::endl;
	std::cout << "Serialized data value: "
			  << serializedData << std::endl;

	std::cout << "Original data address: "
			  << &originalData << std::endl;
	std::cout << "Deserialized data address pointed: "
			  << deserializedData << std::endl;

	return 0;
}
