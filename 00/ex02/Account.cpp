/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:46:22 by bmugnol-          #+#    #+#             */
/*   Updated: 2023/07/21 14:49:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

// Non-member variables initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Non-member variables getters:
int Account::getNbAccounts(void) { return Account::_nbAccounts; }
int Account::getTotalAmount(void) { return Account::_totalAmount; }
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

// Global display
void Account::displayAccountsInfos(void)
{
	if (Account::getNbAccounts() == 0)
		return;
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

// Constructors
Account::Account(int initial_deposit)
	: _accountIndex(Account::getNbAccounts()), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	return;
}

Account::Account(void)
	: _accountIndex(Account::getNbAccounts()), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";created" << std::endl;
	return;
}

// Destructor
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

// Operations:
void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit;

	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;

	std::cout << ";amount:" << this->checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;

	std::cout << withdrawal << ";amount:" << this->checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return this->_amount;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->checkAmount() << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	struct tm *localTimeInfo;
	char buffer[18];

	time_t now = time(NULL);
	localTimeInfo = localtime(&now);

	if (strftime(buffer, 18, "[%Y%m%d_%H%M%S]", localTimeInfo) == 0)
		return ;
	std::cout << buffer;
	return;
}
