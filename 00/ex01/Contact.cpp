/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:45 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/18 18:26:53 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(
	std::string const firstNameInput, std::string const lastNameInput,
	std::string const nicknameInput, std::string const phoneNumberInput,
	std::string const darkestSecretInput) : _firstName(firstNameInput),
											_lastName(lastNameInput),
											_nickname(nicknameInput),
											_phoneNumber(phoneNumberInput),
											_darkestSecret(darkestSecretInput)
{
	return;
}

Contact::~Contact(void) { return; }

int Contact::hasEmptyField(void) const
{
	if (
		this->getFirstName().empty() || this->getLastName().empty() || this->getNickname().empty() || this->getPhoneNumber().empty() || this->getDarkestSecret().empty())
		return 1;
	return 0;
}

void Contact::clearContact(void)
{
	this->setFirstName("");
	this->setLastName("");
	this->setNickname("");
	this->setPhoneNumber("");
	this->setDarkestSecret("");
}

std::string Contact::getFirstName(void) const { return this->_firstName; }
std::string Contact::getLastName(void) const { return this->_lastName; }
std::string Contact::getNickname(void) const { return this->_nickname; }
std::string Contact::getPhoneNumber(void) const { return this->_phoneNumber; }
std::string Contact::getDarkestSecret(void) const { return this->_darkestSecret; }

void Contact::setFirstName(std::string newFirstName) { this->_firstName = newFirstName; }
void Contact::setLastName(std::string newLastName) { this->_lastName = newLastName; }
void Contact::setNickname(std::string newNickname) { this->_nickname = newNickname; }
void Contact::setPhoneNumber(std::string newPhoneNumber) { this->_phoneNumber = newPhoneNumber; }
void Contact::setDarkestSecret(std::string newDarkestSecret) { this->_darkestSecret = newDarkestSecret; }
