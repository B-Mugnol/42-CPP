/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:21:04 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/25 19:54:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl complainer;

	complainer.complain("DEBUG");
	complainer.complain("INFO");
	complainer.complain("WARNING");
	complainer.complain("ERROR");
	complainer.complain("Something else");

	return 0;
}
