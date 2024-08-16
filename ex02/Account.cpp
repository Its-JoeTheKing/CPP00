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
	std::cout << "[19920104_091532] " << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << "\n";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "[19920104_091532] " << "index:" << _accountIndex <<";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= _amount;
	std::cout << "[19920104_091532] " << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::makeDeposit(int deposit)
{
	int am = _amount;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount += deposit;
	std::cout << "[19920104_091532] " << "index:" << _accountIndex << ";p_amount:" << am << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
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
		std::cout << "[19920104_091532] " << "index:" << _accountIndex << ";p_amount:" << am << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return (1);
	}
	else
	{
		std::cout << "[19920104_091532] " << "index:" << _accountIndex << ";p_amount:" << am << ";withdrawal:refused\n";
		return (0);
	}
}

void Account::displayStatus() const
{
	std::cout << "[19920104_091532] " << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}

Account::Account( void )
{
	
}
// create : [19920104_091532] index:7;amount:16576;created

// displayAccounts: [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0

// displayStatus: [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0

// makeDeposit: [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1

// makeWithdrawal fail: [19920104_091532] index:0;p_amount:47;withdrawal:refused
// makeWithdrawal: [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

// closed: [19920104_091532] index:0;amount:47;closed