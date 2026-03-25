#include "Contact.hpp"

void Contact::setContact(std::string firstName, std::string lastName,
                        std::string nickname, std::string phoneNumber,
                        std::string darkestSecret)
{
    // this->firstname aponta para o atributo firstName da classe Contact, enquanto firstName é o parametro
    // passado na função setContact
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}
//std::string é o tipo de retorno da função
//Contact:: é o escopo da função, ou seja, a classe Contact
//const é um modificador que indica que a função não modifica o objeto
//não preciso colocar this-> porque o this é implicito, pois a função é membro da classe Contact
std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}