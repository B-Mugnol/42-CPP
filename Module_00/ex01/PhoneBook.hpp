/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:56 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/13 15:57:16 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#ifndef MAX_CONTACTS
#define MAX_CONTACTS 8
#endif

#include <limits>
#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

enum status
{
	FAILURE = 0,
	SUCCESS = 1
};

class PhoneBook
{
private:
	Contact contact[MAX_CONTACTS];
	int numberOfContacts;
	int saveContact(Contact newContact);

public:
	PhoneBook(void);
	~PhoneBook(void);
	int createContact(void);
	int displayAllContacts(void) const;
	int displayContact(int contactIndex) const;
};

#endif
