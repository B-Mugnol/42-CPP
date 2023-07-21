/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:06:17 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/07 16:37:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[]){
	if (argc == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string message;

	for (int i = 1; i < argc; i++)
		message += argv[i];
	for (std::string::iterator it = message.begin(); it != message.end(); it++)
		*it = std::toupper(*it);
	std::cout << message << std::endl;
	return (0);
}
