/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:42:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/10/20 16:58:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <typename T>
void iter(T *array, std::size_t length, void (*f)(T))
{
	if (!array || !f)
        return ;

	for (std::size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

#endif
