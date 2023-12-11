/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:26:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/12/10 23:56:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
	MutantStack(void) { return; }
	MutantStack(const MutantStack &src) : std::stack<T, Container>(src) { return; };
	~MutantStack(void) { return; }

	MutantStack &operator=(MutantStack const &rhs)
	{
		std::stack<T, Container>::operator=(rhs);
		return *this;
	}

	typedef typename Container::iterator iterator;

	iterator begin(void) { return this->c.begin(); }
	iterator end(void) { return this->c.end(); }
};

#endif
