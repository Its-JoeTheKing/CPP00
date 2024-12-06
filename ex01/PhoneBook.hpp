/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:11:36 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/06 11:11:37 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
