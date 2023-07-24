/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:17:32 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 14:57:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *myHorde;
	int N = 10;

	myHorde = zombieHorde(N, "Bartholomew");

	for (int i = 0; i < N; i++)
		myHorde[i].announce();

	delete[] myHorde;

	return 0;
}
