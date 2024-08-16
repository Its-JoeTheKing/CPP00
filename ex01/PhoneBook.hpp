#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contact.hpp"


using std::cout;
using std::cin;
using std::string;
using std::getline;

class PhoneBook
{
	private:
		Contact contacts[8];
		size_t size;
	public:
		int getsize();
		void printContact(string str);
		void setSize(int n);
		void addNewContact(string fName, string lName, string Nick, string PN, string sec);
		void findPhone(size_t n);
};


#endif