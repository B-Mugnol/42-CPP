/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/10 15:28:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
protected:
	AForm(void);

private:
	const std::string _name;
	const int _signGrade;
	const int _execGrade;
	bool _isSigned;

	AForm &operator=(AForm const &rhs);

public:
	AForm(const std::string name, const int signGrade, const int execGrade);
	AForm(AForm const &src);
	virtual ~AForm(void);

	std::string getName(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	bool getIsSigned(void) const;

	void beSigned(const Bureaucrat &bureaucrat);
	virtual void action(void) const = 0;
	void execute(Bureaucrat const &executor) const;

	// EXCEPTIONS //
public:
	class UnsignedFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class UnassignableException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
