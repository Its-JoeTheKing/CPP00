/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:09:59 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/06 11:10:01 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void readline(std::string read_msg, std::string *inp)
{
	std::cout << read_msg;
	std::getline(std::cin, *inp);
	if (std::cin.eof())
		exit(1);
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
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return 1;
		if (cmd == "ADD")
		{
			readline("firstName: ", &j);
			cont.setFirstName(j);

			readline("lastName: ", &j);
			cont.setLastName(j);

			readline("nickname: ", &j);
			cont.setNickname(j);

			readline("phoneNumber: ", &j);
			cont.setPhoneNumber(j);

			readline("secret: ", &j);
			cont.setSecret(j);

			phone.addNewContact(cont);
		}
		else if (cmd == "SEARCH")
		{
			size_t i = 0;
			int	err = 0;
			readline("index of phone : ", &j);
			if (j[0] == '+')
				i++;
			for (;i < j.length(); i++)
			{
				if (!std::isdigit(j[i]))
					err++;
			}
			if (err < 1)
				phone.findPhone(atoi(j.c_str()));
			else
				std::cout << "INVALID ID" << std::endl;
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "COMMAND NOT FOUND\n";
	}
}
