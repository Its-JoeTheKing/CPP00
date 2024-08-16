#include "PhoneBook.hpp"

int PhoneBook::getsize()
{
	return this->size;
};

void PhoneBook::setSize(int n)
{
	this->size = n;
}

void PhoneBook::addNewContact(string fName, string lName, string Nick, string PN, string sec)
{
	if (fName.length() && lName.length() && Nick.length() && PN.length() && sec.length())
	{
		this->contacts[size].id = size;
		this->contacts[size].firstName = fName;
		this->contacts[size].lastName = lName;
		this->contacts[size].nickname = Nick;
		this->contacts[size].phoneNumber = PN;
		this->contacts[size].secret = sec;
		this->size++;
		cout << "CONTACT ADDED SUCCESSFULLY\n";
	}
	else
		cout << "PLEASE FULL FILL ALL FORM\n";
}

void PhoneBook::printContact(string str)
{
	if (str.length() > 10)
		cout << str.substr(0, 9) << ".";
	else
	{
		cout << str;
		for (size_t i = str.length(); i < 10; i++)
		{
			cout << " ";
		}
	}
}

void PhoneBook::findPhone(size_t n)
{
	if (n < 0 || n > 7)
		cout << "INDEX OUT OF RANGE\n";
	else if (n > size - 1)
		cout << "CONTACT NOT FOUND\n";
	else
	{
		cout << "| " << contacts[n].id << " | ";
		printContact(contacts[n].firstName);
		cout << "|";
		printContact(contacts[n].lastName);
		cout << "|";
		printContact(contacts[n].nickname);
		cout << "|";
		printContact(contacts[n].phoneNumber);
		cout << "|";
		printContact(contacts[n].secret);
		cout << "|\n";
	}
}
