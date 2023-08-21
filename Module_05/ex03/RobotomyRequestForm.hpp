/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:21:40 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 18:53:36 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

class RobotomyRequestForm : virtual public AForm
{
private:
	static const std::string _FORM_NAME;
	static const int _SIGN_GRADE;
	static const int _EXEC_GRADE;

private:
	std::string _target;

	RobotomyRequestForm(void);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);
	void action(void) const;

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm(void);

	std::string getTarget(void) const;
};

#endif
