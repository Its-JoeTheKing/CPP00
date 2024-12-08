/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:31 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/08 17:19:21 by aerrfig          ###   ########.fr       */
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
	if (curr_index > 7)
		curr_index = 0;
	this->contacts[curr_index] = c;
	this->contacts[curr_index].setId(curr_index);
	this->curr_index++;
	this->size += this->size < 8;
	std::cout << "CONTACT ADDED SUCCESSFULLY\n";
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
		std::cout << "Id ==> " << contacts[n].getId() << std::endl;
		std::cout << "FirstName ==> " << contacts[n].getFirstName() << std::endl;
		std::cout << "LastName ==> " << contacts[n].getLastName() << std::endl;
		std::cout << "Nickname ==> " << contacts[n].getNickname() << std::endl;
		std::cout << "PhoneNumber ==> " << contacts[n].getPhoneNumber() << std::endl;
		std::cout << "Secret ==> " << contacts[n].getSecret() << std::endl;
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