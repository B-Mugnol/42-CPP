/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:14:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:42:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
private:
	static const std::string _DEFAULT_TYPE;

protected:
	std::string type;

public:
	Animal(void);
	Animal(Animal const &src);
	virtual ~Animal(void);

	std::string getType(void) const;
	virtual void makeSound(void) const = 0;

	Animal &operator=(Animal const &rhs);
};

#endif
