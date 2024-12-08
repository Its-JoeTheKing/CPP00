/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:09:59 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/08 17:18:54 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool is_printable(std::string str)
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

void readline(std::string read_msg, std::string *inp, bool nums_check)
{
	int err = 0;
	std::cout << read_msg;
	std::getline(std::cin, *inp);
	if (std::cin.eof())
		exit(1);
	inp->erase(0, inp->find_first_not_of(" \t\n\r\f\v"));
	if (!(inp->length() > 0 && is_printable(*inp)))
	{
		std::cout << "input must be printable and non empty" << std::endl;
		readline(read_msg, inp, nums_check);
	}
	if (nums_check)
	{
		size_t i = 0;
		if ((*inp)[0] == '+')
			i++;
		for (; i < inp->length(); i++)
		{
			if (!std::isdigit((*inp)[i]))
				err++;
		}
		if (err > 0)
		{
			std::cout << "phone number and index must contains numbers only" << std::endl;
			readline(read_msg, inp, nums_check);
		}
	}
}

int main()
{
	PhoneBook phone;
	Contact cont;
	std::string cmd;
	std::string j;
	phone.setSize(0);
	while (1)
	{
		std::cout << ":> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return 1;
		if (cmd == "ADD")
		{
			readline("firstName: ", &j, 0);
			cont.setFirstName(j);
			readline("lastName: ", &j, 0);
			cont.setLastName(j);
			readline("nickname: ", &j, 0);
			cont.setNickname(j);
			readline("phoneNumber: ", &j, 1);
			cont.setPhoneNumber(j);
			readline("secret: ", &j, 0);
			cont.setSecret(j);
			phone.addNewContact(cont);
		}
		else if (cmd == "SEARCH")
		{
			phone.showAll();
			readline("index of phone : ", &j, 1);
			if (j.length() < 3)
				phone.findPhone(atoi(j.c_str()));
			else
				std::cout << "INVALID OUT OF RANGE" << std::endl;
		}
		else if (cmd == "EXIT")
			break;
	}
}
