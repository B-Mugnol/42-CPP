/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:30:12 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/08/09 16:25:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	Bureaucrat(void);

	const std::string _name;
	int _grade;

	Bureaucrat &operator=(Bureaucrat const &rhs);

protected:
	static const int MIN_GRADE;
	static const int MAX_GRADE;

public:
	Bureaucrat(const std::string, const int);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat(void);

	std::string getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);

	// EXCEPTIONS //
private:
	class UnassignableException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
