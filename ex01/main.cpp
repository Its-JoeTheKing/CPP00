#include "PhoneBook.hpp"

void readline(string read_msg, string *inp)
{
	cout << read_msg;
	getline(cin, *inp);
	if (cin.eof())
		exit(0);
}


int main()
{
	PhoneBook phone;
	Contact cont;
	string cmd;
	string j;
	phone.setSize(0);
	while (cmd != "EXIT")
	{
		getline(cin, cmd);
		if (cin.eof())
			return 0;
		if (cmd == "ADD")
		{
			readline("firstName : ", &cont.firstName);
			readline("lastName : ", &cont.lastName);
			readline("nickname : ", &cont.nickname);
			readline("phoneNumber : ", &cont.phoneNumber);
			readline("secret : ", &cont.secret);
			phone.addNewContact(cont.firstName, cont.lastName, cont.nickname, cont.phoneNumber, cont.secret);
		}
		else if (cmd == "SEARCH")
		{
			readline("index of phone : ", &j);
			phone.findPhone(atoi(j.c_str()));
		}
		else
			cout << "COMMAND NOT FOUND\n";
	}
}
