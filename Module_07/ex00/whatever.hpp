/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:42:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/20 16:50:29 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b)
{
	T copy = a;

	a = b;
	b = copy;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	return b;
}

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return a;
	return b;
}

#endif
