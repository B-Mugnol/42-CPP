/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:45:49 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 22:58:28 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(void) : _maxSize(0)
{
	return;
}

Span::Span(unsigned int N) : _maxSize(N)
{
	return;
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _data(src._data)
{
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_data = rhs._data;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(int n)
{
	if (this->_data.size() < this->_maxSize)
		this->_data.push_back(n);
	else
		throw Span::SpanFullException();
}

void Span::addNumbers(std::vector<int> numbers)
{
	if (numbers.size() + this->_data.size() > this->_maxSize)
		throw Span::SpanFullException();

	for (size_t i = 0; i < numbers.size(); i++)
	{
		this->_data.push_back(numbers[i]);
	}
}

int Span::longestSpan(void) const
{
	if (this->_data.size() < 2)
		throw Span::SpanEmptyException();

	int max = *std::max_element(this->_data.begin(), this->_data.end());
	int min = *std::min_element(this->_data.begin(), this->_data.end());
	return (max - min);
}

int Span::shortestSpan(void) const
{
	if (_data.size() < 2)
		throw Span::SpanEmptyException();

	std::vector<int> copy = _data;
	std::sort(copy.begin(), copy.end());

	int shortestSpan = std::abs(copy[1] - copy[0]);
	for (size_t i = 1; i < copy.size() - 1; i++)
	{
		if (std::abs(copy[i + 1] - copy[i]) < shortestSpan)
			shortestSpan = std::abs(copy[i + 1] - copy[i]);
	}
	return shortestSpan;
}

void Span::fillWithRandom(void)
{
	std::srand(time(0));
	if (_data.size() >= _maxSize)
		throw SpanFullException();
	for (size_t i = 0; i < _maxSize; i++)
	{
		_data.push_back(rand());
	}
}

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *Span::SpanFullException::what() const throw()
{
	return "The Span is full";
}

const char *Span::SpanEmptyException::what() const throw()
{
	return "The Span is empty";
}

/* ************************************************************************** */
