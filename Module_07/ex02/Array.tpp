/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:13:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 22:26:35 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::Array(void) : _size(0), _element(NULL)
{
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _element(NULL)
{
	if (this->_size == 0)
		return;

	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_element[i] = T();
	}
	return;
}

template <typename T>
Array<T>::Array(const Array<T> &src) : _size(src._size), _element(NULL)
{
	if (this->_size == 0)
		return;

	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_element[i] = src._element[i];
	}
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

template <typename T>
Array<T>::~Array<T>(void)
{
	delete[] this->_element;
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

template <typename T>
T &Array<T>::operator[](const unsigned int index) const
{
	if (index >= this->_size)
		throw std::invalid_argument("Invalid array index.");

	return *(this->_element + index);
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this == &rhs)
		return *this;

	this->_size = rhs._size;
	delete[] this->_element;

	if (rhs._size == 0)
	{
		this->_element = rhs._element;
		return *this;
	}

	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_element[i] = rhs._element[i];
	}

	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

template <typename T>
unsigned int Array<T>::size(void) const { return this->_size; }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */

#endif
