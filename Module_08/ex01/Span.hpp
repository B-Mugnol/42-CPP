/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 19:45:46 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 21:43:12 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _data;

public:
	Span(void);
	Span(unsigned int maxSize);
	Span(Span const &src);
	~Span(void);

	void addNumber(int n);
	int longestSpan(void) const;
	int shortestSpan(void) const;
	void fillWithRandom(void);

	Span &operator=(Span const &rhs);

	// EXCEPTIONS //
private:
	class SpanFullException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class SpanEmptyException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

#endif /* ************************************************************ SPAN_H */
