/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:57 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/06 11:11:58 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() 
{
	return _nbAccounts;
}

int Account::getTotalAmount() 
{
	return _totalAmount;
}

int Account::getNbDeposits() 
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() 
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	int am = _amount;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << am << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	int am = _amount;
	if (withdrawal <= _amount)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << am << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return (1);
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << am << ";withdrawal:refused\n";
		return (0);
	}
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::_displayTimestamp()
{
	char date[20];
	time_t t;
	struct tm *s;

	time(&t);
	s = localtime(&t);
	strftime(date, 20, "[%Y%m%d_%H%M%S] ", s);
	std::cout << date;
}