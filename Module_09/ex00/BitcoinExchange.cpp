/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 01:02:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2024/01/04 16:35:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange(void)
{
	throw InvalidDatabaseFile();
	return;
}

BitcoinExchange::BitcoinExchange(std::string databaseFilename)
{
	std::ifstream databaseFile(databaseFilename.c_str());
	if (databaseFile.is_open() == false)
		throw InvalidDatabaseFile();

	std::string line;
	std::getline(databaseFile, line); // Skips column title line
	while (std::getline(databaseFile, line))
		this->_database.insert(line);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange(void)
{
	return;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
		this->_database = rhs._database;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void BitcoinExchange::getResultingValue(std::string filename)
{
	std::ifstream inputFile(filename.c_str());
	if (inputFile.is_open() == false)
		throw InvalidInputFile();

	std::string line;
	std::getline(inputFile, line);	// Skip column title line
	while (std::getline(inputFile, line))
		printResultingValue(line);
	return;
}

void BitcoinExchange::printResultingValue(const std::string &line) const
{
	try
	{
		std::string date = getDate(line);
		float bitcoin = getBitcoinQuantity(line);
		float exchangeRate = getExchangeRate(date);
		std::cout << date << " => " << bitcoin << " = " << bitcoin * exchangeRate
				  << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
		return;
	}
	return;
}

std::string BitcoinExchange::getDate(const std::string &line) const
{
	if (line.empty())
		throw InvalidInput();

	valitadeDateFormat(line);
	validateDate(line);

	if (line.substr(10, 3) != " | ")
		throw InvalidInput();

	return line.substr(0, 10);
}

void BitcoinExchange::valitadeDateFormat(const std::string &line) const
{
	validateDigits(line, 0, 4); // Year (YYYY)
	if (line[4] != '-')			// Separator (-)
		throw InvalidDate();

	validateDigits(line, 5, 2); // Month (MM)
	if (line[7] != '-')			// Separator (-)
		throw InvalidDate();

	validateDigits(line, 8, 2); // Day (DD)
	return;
}

void BitcoinExchange::validateDigits(const std::string &line, const int &start, const int &length) const
{
	for (int i = start; i < length; i++)
	{
		if (!line[i])
			throw InvalidDate();
		else if (std::isdigit(line[i]) == false)
			throw InvalidDate();
	}
	return;
}

void BitcoinExchange::validateDate(const std::string &line) const
{
	std::string month(line.substr(5, 2));
	if (std::atoi(month.c_str()) > 12)
		throw InvalidDate();

	std::string day(line.substr(8, 2));
	if (std::atoi(day.c_str()) > 31)
		throw InvalidDate();

	return;
}

float BitcoinExchange::getBitcoinQuantity(const std::string &line) const
{
	std::string bitcoinString(line.substr(13, line.length() - 13));
	float bitcoinQuantity = std::strtof(bitcoinString.c_str(), NULL);

	if (bitcoinQuantity == 0)
		throw InvalidInput();
	else if (bitcoinQuantity < 0)
		throw BitcoinNegative();
	else if (bitcoinQuantity > 1000)
		throw BitcoinTooLarge();

	return bitcoinQuantity;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::set<std::string>::iterator it = this->_database.lower_bound(date);

	if (it == this->_database.end())
		--it;
	else if (it != this->_database.begin() && (*it).substr(0, 10) != date)
		--it;

	std::string line(*it);
	std::string exchangeRateString(line.substr(11, line.length() - 11));
	return std::strtof(exchangeRateString.c_str(), NULL);
}

/*
** --------------------------------- EXCEPTIONS -------------------------------
*/

const char *BitcoinExchange::InvalidDatabaseFile::what() const throw()
{
	return "Error: Can't open the database file";
}

const char *BitcoinExchange::InvalidInputFile::what() const throw()
{
	return "Error: Can't open the input file";
}

const char *BitcoinExchange::InvalidDate::what() const throw()
{
	return "Error: Invalid date provided in input file";
}

const char *BitcoinExchange::InvalidInput::what() const throw()
{
	return "Error: Invalid input";
}

const char *BitcoinExchange::BitcoinNegative::what() const throw()
{
	return "Error: The number is not positive";
};
const char *BitcoinExchange::BitcoinTooLarge::what() const throw()
{
	return "Error: The number is too large";
};

/* ************************************************************************** */
