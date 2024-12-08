/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:36 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/08 16:55:36 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	size_t 	size;
	size_t 	curr_index;
	public:
	 	PhoneBook();
		int getsize();
		int getIndx();
		void printContact(std::string str);
		void setIndx(int n);
		void setSize(int n);
		void addNewContact(Contact c);
		std::string replaceTabs(std::string &str);
		void showAll();
		void findPhone(size_t n);
};
