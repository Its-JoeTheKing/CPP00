/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerrfig <aerrfig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:09:43 by aerrfig           #+#    #+#             */
/*   Updated: 2024/12/08 16:58:24 by aerrfig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{

}

void Contact::setId(int newId) {
    id = newId;
}

void Contact::setFirstName(const std::string& newFirstName) {
    firstName = newFirstName;
}

void Contact::setLastName(const std::string& newLastName) {
    lastName = newLastName;
}

void Contact::setNickname(const std::string& newNickname) {
    nickname = newNickname;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setSecret(const std::string& newSecret) {
    secret = newSecret;
}

int Contact::getId() const {
    return id;
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getSecret() const {
    return secret;
}
