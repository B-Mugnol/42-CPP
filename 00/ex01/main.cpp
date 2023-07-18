/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:54:30 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/17 14:52:15 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static int addContact(PhoneBook *phonebook);
static int searchContact(PhoneBook phonebook);

int main(void)
{
	PhoneBook phonebook;

	std::cout << "Welcome to PhoneBook9000! You can navigate with the commands ADD, SEARCH and EXIT" << std::endl;
	std::string line;
	std::cout << ">";
	while (std::getline(std::cin, line))
	{
		if (line == "ADD")
			addContact(&phonebook);
		else if (line == "SEARCH")
			searchContact(phonebook);
		else if (line == "EXIT")
			break;
		else
			std::cout << "Insert one of the following commands: ADD, SEARCH and EXIT" << std::endl;
		std::cin.clear();
		std::cout << ">";
	}
	std::cout << std::endl
			  << "Goodbye!" << std::endl;
}

static int addContact(PhoneBook *phonebook)
{
	if (phonebook->createContact() == SUCCESS)
		return SUCCESS;
	std::cout << "Contact creation failed. Please make sure all fields are inputted correctly" << std::endl;
	return FAILURE;
}

static int searchContact(PhoneBook phonebook)
{
	if (phonebook.displayAllContacts() == FAILURE)
		return FAILURE;

	int index;

	std::cout << "Insert the index of the contact you want detailed, or 0 (zero) to return." << std::endl;
	std::cout << ": ";
	std::cin >> index;
	while (std::cin.fail() || (index != 0 && phonebook.displayContact(index) == FAILURE))
	{
		std::cout << "Please insert a valid index or 0 (zero) to return." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << ": ";
		std::cin >> index;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return SUCCESS;
}
