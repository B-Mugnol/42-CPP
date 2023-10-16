/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:12:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 16:08:42 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : virtual public Animal
{
private:
	static const std::string _DEFAULT_TYPE;
	Brain *_brain;

public:
	Cat(void);
	Cat(Cat const &src);
	~Cat(void);

	Cat &operator=(Cat const &rhs);

	void makeSound(void) const;
};

#endif
