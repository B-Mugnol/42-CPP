/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:24:55 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/24 16:44:59 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << &stringVAR << " -> The memory address of the string variable." << std::endl;
	std::cout << &stringPTR << " -> The memory address held by stringPTR." << std::endl;
	std::cout << &stringREF << " -> The memory address held by stringREF." << std::endl;

	std::cout << stringVAR << " -> The value of the string variable." << std::endl;
	std::cout << *stringPTR << " -> The value pointed to by stringPTR." << std::endl;
	std::cout << stringREF << " -> The value pointed to by stringREF." << std::endl;

	return 0;
}
