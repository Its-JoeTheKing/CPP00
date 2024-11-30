#include "Contact.hpp"

Contact::Contact()
{

}
Contact::Contact(int newId, const std::string& newFirstName, const std::string& newLastName,
                 const std::string& newNickname, const std::string& newPhoneNumber,
                 const std::string& newSecret)
    : id(newId), firstName(newFirstName), lastName(newLastName),
      nickname(newNickname), phoneNumber(newPhoneNumber), secret(newSecret) {}

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
