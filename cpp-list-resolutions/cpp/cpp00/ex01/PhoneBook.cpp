#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook()
{
    count = 0;
    oldestIndex = 0;
}

static std::string formatField(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

static bool isEmptyField(std::string str)
{
    return str.empty();
}

static bool isValidIndex(std::string str, int max)
{
    if (str.length() != 1)
        return false;
    if (str[0] < '0' || str[0] > '7')
        return false;
    if ((str[0] - '0') >= max)
        return false;
    return true;
}

void PhoneBook::addContact()
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "First name: ";
    if (!std::getline(std::cin, firstName))
        return;
    std::cout << "Last name: ";
    if (!std::getline(std::cin, lastName))
        return;
    std::cout << "Nickname: ";
    if (!std::getline(std::cin, nickname))
        return;
    std::cout << "Phone number: ";
    if (!std::getline(std::cin, phoneNumber))
        return;
    std::cout << "Darkest secret: ";
    if (!std::getline(std::cin, darkestSecret))
        return;

    if (isEmptyField(firstName) || isEmptyField(lastName) || isEmptyField(nickname)
        || isEmptyField(phoneNumber) || isEmptyField(darkestSecret))
    {
        std::cout << "Error: empty fields are not allowed." << std::endl;
        return;
    }

    contacts[oldestIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    oldestIndex = (oldestIndex + 1) % 8;
    if (count < 8)
        count++;
}

void PhoneBook::searchContact() const
{
    std::string index;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index: ";
    if (!std::getline(std::cin, index))
        return;

    if (!isValidIndex(index, count))
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    int i = index[0] - '0';

    std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
}