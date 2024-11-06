#include "PhoneBook.hpp"

void readline(std::string read_msg, std::string *inp)
{
	std::cout << read_msg;
	std::getline(std::cin, *inp);
	if (std::cin.eof())
		exit(0);
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
			return 0;
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
			readline("index of phone : ", &j);
			phone.findPhone(atoi(j.c_str()));
		}
		else if (cmd == "EXIT")
			break ;
		else
			std::cout << "COMMAND NOT FOUND\n";
	}
}
