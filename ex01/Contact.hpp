/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:09:51 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/07 15:10:10 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iomanip>
#include <cctype>

class Contact
{
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string secret;

public:
    Contact();
    Contact(int newId, const std::string& newFirstName, const std::string& newLastName,
            const std::string& newNickname, const std::string& newPhoneNumber,
            const std::string& newSecret);

    void setId(int newId);
    void setFirstName(const std::string& newFirstName);
    void setLastName(const std::string& newLastName);
    void setNickname(const std::string& newNickname);
    void setPhoneNumber(const std::string& newPhoneNumber);
    void setSecret(const std::string& newSecret);

    int getId() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getSecret() const;

    void addNewContact();
};
