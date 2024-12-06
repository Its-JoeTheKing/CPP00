/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:31 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/06 11:11:32 by aerrfig          ###   ########.fr       */
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

void PhoneBook::setSize(int n)
{
	this->size = n;
}

void PhoneBook::addNewContact(Contact c)
{
	const char *spaces = " \t\n\r\f\v";
	size_t size = PhoneBook::getsize();
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
	if (size > 7)
		size = 7;
	if (fName.length() && lName.length() && Nick.length() && PN.length() && sec.length())
	{
		this->contacts[size].setId(size);
		this->contacts[size].setFirstName(fName);
		this->contacts[size].setLastName(lName);
		this->contacts[size].setNickname(Nick);
		this->contacts[size].setPhoneNumber(PN);
		this->contacts[size].setSecret(sec);
		this->size++;
		std::cout << "CONTACT ADDED SUCCESSFULLY\n";
	}
	else
		std::cout << "PLEASE FULL FILL ALL FORM\n";
}

void PhoneBook::printContact(std::string str)
{
	if (str.length() > 10)
		str = str.substr(0, 9) + ".";
	std::cout << std::setw(10) << std::left << str;
}

void PhoneBook::findPhone(size_t n)
{
	if (n < 0 || n > 7)
		std::cout << "INDEX OUT OF RANGE\n";
	else if (n >= this->size)
		std::cout << "CONTACT NOT FOUND\n";
	else
	{
		std::cout << "|";
		std::cout << std::setw(10) << std::left << contacts[n].getId();
		std::cout << "|";
		printContact(contacts[n].getFirstName());
		std::cout << "|";
		printContact(contacts[n].getLastName());
		std::cout << "|";
		printContact(contacts[n].getNickname());
		std::cout << "|" << std::endl;
	}
}
