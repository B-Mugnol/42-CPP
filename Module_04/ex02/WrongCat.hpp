/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:12:42 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/02 16:47:57 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
private:
	static const std::string _DEFAULT_TYPE;

public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	~WrongCat(void);

	WrongCat &operator=(WrongCat const &rhs);

	void makeSound(void) const;
};

#endif
