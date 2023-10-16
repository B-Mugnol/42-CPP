/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:12:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:58:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : virtual public Animal
{
private:
	static const std::string _DEFAULT_TYPE;
	Brain *_brain;

public:
	Dog(void);
	Dog(Dog const &src);
	~Dog(void);

	Dog &operator=(Dog const &rhs);

	void makeSound(void) const;
};

#endif
