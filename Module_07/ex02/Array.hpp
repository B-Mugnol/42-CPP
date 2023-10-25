/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:28:03 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:27 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
private:
	unsigned int _size;
	T *_element;

public:
	Array(void);
	Array(unsigned int n);
	Array(Array const &src);
	~Array(void);

	unsigned int size(void) const;

	Array &operator=(Array const &rhs);
	T &operator[](const unsigned int) const;

private:
};

#include "Array.tpp"

#endif
