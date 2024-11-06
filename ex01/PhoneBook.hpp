#pragma once
#include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	size_t 	size;
	public:
	 	PhoneBook();
		int getsize();
		void printContact(std::string str);
		void setSize(int n);
		void addNewContact(Contact c);
		void findPhone(size_t n);
};
