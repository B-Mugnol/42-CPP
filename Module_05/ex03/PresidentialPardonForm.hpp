/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:40 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/15 16:00:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#include <iostream>
#include <string>

class PresidentialPardonForm : virtual public AForm
{
private:
	static const std::string _FORM_NAME;
	static const int _SIGN_GRADE;
	static const int _EXEC_GRADE;

private:
	std::string _target;

	PresidentialPardonForm(void);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);
	void action(void) const;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm(void);

	std::string getTarget(void) const;
};

#endif
