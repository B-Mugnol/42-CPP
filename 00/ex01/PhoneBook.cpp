/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:52 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/17 15:06:07 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string getNonEmptyLine(void);
static void formattedPrint(std::string s1, std::string s2, std::string s3, std::string s4);
static void formattedPrintWithNumber(int n1, std::string s1, std::string s2, std::string s3);

PhoneBook::PhoneBook(void) : numberOfContacts(0) { return; }

PhoneBook::~PhoneBook(void) { return; }

int PhoneBook::saveContact(Contact newContact)
{
	if (newContact.hasEmptyField() || MAX_CONTACTS <= 0)
		return FAILURE;
	this->contact[this->numberOfContacts % MAX_CONTACTS] = newContact;
	this->numberOfContacts++;
	return SUCCESS;
}

int PhoneBook::createContact(void)
{
	std::string line;
	Contact newContact;

	std::cout << "Please fill out the following fields:" << std::endl;
	std::cout << "First name: ";
	newContact.setFirstName(getNonEmptyLine());
	std::cout << "Last name: ";
	newContact.setLastName(getNonEmptyLine());
	std::cout << "Nickname: ";
	newContact.setNickname(getNonEmptyLine());
	std::cout << "Phone number: ";
	newContact.setPhoneNumber(getNonEmptyLine());
	std::cout << "Darkest secret: ";
	newContact.setDarkestSecret(getNonEmptyLine());

	return this->saveContact(newContact);
}

int PhoneBook::displayAllContacts(void) const
{
	formattedPrint("Index", "First Name", "Last name", "Nickname");
	for (int i = 0; (i < MAX_CONTACTS) && (i < this->numberOfContacts); i++)
		formattedPrintWithNumber(i + 1, this->contact[i].getFirstName(), this->contact[i].getLastName(), this->contact[i].getNickname());
	return this->numberOfContacts != 0 ? SUCCESS : FAILURE;
}

int PhoneBook::displayContact(int contactIndex) const
{
	if (contactIndex < 1 || contactIndex > MAX_CONTACTS || contactIndex > this->numberOfContacts)
	{
		std::cout << "There's no contact indexed as " << contactIndex << "." << std::endl;
		return FAILURE;
	}
	std::cout << "First name: " << this->contact[contactIndex - 1].getFirstName() << std::endl;
	std::cout << "Last name: " << this->contact[contactIndex - 1].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contact[contactIndex - 1].getNickname() << std::endl;
	std::cout << "Phone number: " << this->contact[contactIndex - 1].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->contact[contactIndex - 1].getDarkestSecret() << std::endl;
	return SUCCESS;
}

static std::string getNonEmptyLine(void)
{
	std::string line;

	while (getline(std::cin, line))
	{
		if (!line.empty())
			break;
	}
	return line;
}

static void formattedPrint(std::string s1, std::string s2, std::string s3, std::string s4)
{

	std::cout << std::setiosflags(std::ios_base::left);
	std::cout << std::setw(10) << s1 << "|";
	std::cout << std::setw(10) << s2 << "|";
	std::cout << std::setw(10) << s3 << "|";
	std::cout << std::setw(10) << s4 << "|";
	std::cout << std::endl;
}

static void formattedPrintWithNumber(int n1, std::string s1, std::string s2, std::string s3)
{
	std::string temp;

	if (s1.length() > 10)
		s1 = s1.substr(0, 9) + ".";
	if (s2.length() > 10)
		s2 = s2.substr(0, 9) + ".";
	if (s3.length() > 10)
		s3 = s3.substr(0, 9) + ".";
	std::cout << std::setiosflags(std::ios_base::right);
	std::cout << std::setw(10) << n1 << "|";
	std::cout << std::setw(10) << s1 << "|";
	std::cout << std::setw(10) << s2 << "|";
	std::cout << std::setw(10) << s3 << "|";
	std::cout << std::endl;
}
