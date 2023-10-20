/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/16 16:54:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
public:
	Data(void);
	Data(int value);
	Data(Data const &src);
	~Data(void);

	int value;

	Data &operator=(Data const &rhs);
};

#endif
