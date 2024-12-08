/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:31 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/08 12:29:35 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}
int PhoneBook::getsize()
{
	return this->size;
};

int PhoneBook::getIndx()
{
	return this->curr_index;
};

bool PhoneBook::is_printable(std::string str)
{
	if (!str.length())
		return (0);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isprint(str[i]) && str[i] != '\t')
			return (0);
	}
	return (1);
}

void PhoneBook::setSize(int n)
{
	this->size = n;
}

void PhoneBook::setIndx(int n)
{
	this->curr_index = n;
}

void PhoneBook::addNewContact(Contact c)
{
	const char *spaces = " \t\n\r\f\v";
	std::string fName = c.getFirstName();
	fName.erase(0, fName.find_first_not_of(spaces));
	std::string lName = c.getLastName();
	lName.erase(0, lName.find_first_not_of(spaces));
	std::string Nick = c.getNickname();
	Nick.erase(0, Nick.find_first_not_of(spaces));
	std::string PN = c.getPhoneNumber();
	PN.erase(0, PN.find_first_not_of(spaces));
	std::string sec = c.getSecret();
	sec.erase(0, sec.find_first_not_of(spaces));
	if (curr_index > 7)
		curr_index = 0;
	if (is_printable(fName) && is_printable(lName) && is_printable(Nick) && is_printable(PN) && is_printable(sec))
	{
		this->contacts[curr_index].setId(curr_index);
		this->contacts[curr_index].setFirstName(fName);
		this->contacts[curr_index].setLastName(lName);
		this->contacts[curr_index].setNickname(Nick);
		this->contacts[curr_index].setPhoneNumber(PN);
		this->contacts[curr_index].setSecret(sec);
		this->curr_index++;
		this->size += this->size < 8;
		std::cout << "CONTACT ADDED SUCCESSFULLY\n";
	}
	else
		std::cout << "PLEASE FULL FILL ALL FORM\n";
}

std::string PhoneBook::replaceTabs(std::string &str)
{
	std::string new_str = str;
	size_t pos = 0;
	while ((pos = str.find('\t', pos)) != std::string::npos)
	{
		new_str = str.replace(pos, 1, 4, ' ');
		pos += 4;
	}
	return (new_str);
}

void PhoneBook::printContact(std::string str)
{
	str = replaceTabs(str);
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::right << str;
}

void PhoneBook::findPhone(size_t n)
{
	if (n < 0 || n > 7)
		std::cout << "INDEX OUT OF RANGE\n";
	else if (n >= this->size)
		std::cout << "CONTACT NOT FOUND\n";
	else
	{
		std::cout << "------------------------------------------------------------------\n";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "id";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "First Name";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "Last Name";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "Nickname";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "Phone Num";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << "Secret";
		std::cout << "|\n------------------------------------------------------------------\n";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << contacts[n].getId();
		std::cout << "|";
		printContact(contacts[n].getFirstName());
		std::cout << "|";
		printContact(contacts[n].getLastName());
		std::cout << "|";
		printContact(contacts[n].getNickname());
		std::cout << "|";
		printContact(contacts[n].getPhoneNumber());
		std::cout << "|";
		printContact(contacts[n].getSecret());
		std::cout << "|" << std::endl;
	}
}

void PhoneBook::showAll()
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "id";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "First Name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "Last Name";
	std::cout << "|";
	std::cout << std::setw(10) << std::right << "Nickname";
	std::cout << "|" << std::endl;
	for (size_t n = 0; n < this->size; n++)
	{
		std::cout << "---------------------------------------------\n";
		std::cout << "|";
		std::cout << std::setw(10) << std::right << contacts[n].getId();
		std::cout << "|";
		printContact(contacts[n].getFirstName());
		std::cout << "|";
		printContact(contacts[n].getLastName());
		std::cout << "|";
		printContact(contacts[n].getNickname());
		std::cout << "|" << std::endl;
	}
}