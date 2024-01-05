/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/04 15:22:39 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>
#include <set>

class BitcoinExchange
{
public:
	BitcoinExchange(std::string const databaseFilename);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	void getResultingValue(std::string filename);
	void printResultingValue(const std::string &line) const;

private:
	BitcoinExchange(void);
	std::set<std::string> _database;

	std::string getDate(const std::string &line) const;
	float getBitcoinQuantity(const std::string &line) const;
	float getExchangeRate(const std::string &date) const;

	void valitadeDateFormat(const std::string &line) const;
	void validateDigits(const std::string &line, const int &start, const int &length) const;
	void validateDate(const std::string &line) const;

	// EXCEPTIONS
private:
	class InvalidDatabaseFile : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInputFile : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidDate : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInput : public std::exception
	{
		virtual const char *what() const throw();
	};

	class BitcoinNegative : public std::exception
	{
		virtual const char *what() const throw();
	};

	class BitcoinTooLarge : public std::exception
	{
		virtual const char *what() const throw();
	};
};

#endif
