/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 15:57:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define NUM_IDEAS 100

class Brain
{
public:
	Brain(void);
	Brain(Brain const &src);
	~Brain(void);

	Brain &operator=(Brain const &rhs);

	std::string ideas[NUM_IDEAS];
};

#endif
