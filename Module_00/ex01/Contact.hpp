/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:49 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/21 14:28:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact(
		std::string const firstNameInput = "",
		std::string const lastNameInput = "",
		std::string const nicknameInput = "",
		std::string const phoneNumberInput = "",
		std::string const darkestSecretInput = "");
	~Contact(void);

	int hasEmptyField(void) const;
	void clearContact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

	void setFirstName(std::string newFirstName);
	void setLastName(std::string newLastName);
	void setNickname(std::string newNickname);
	void setPhoneNumber(std::string newPhoneNumber);
	void setDarkestSecret(std::string newDarkestSecret);
};

#endif
