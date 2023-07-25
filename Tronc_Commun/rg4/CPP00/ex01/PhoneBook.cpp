/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:14 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_nbContacts = 0;
	this->_index = 0;
	this->_book[0].id = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::addContact(void) {
	Contact			contact;
	std::string		firstName;
	std::string		lastName;
	std::string		nickname;
	std::string		phoneNumber;
	std::string		darkestSecret;

	if (this->_index == 8)
		this->_index = 0;
	std::cout << "Enter First Name: ";
	std::cin >> firstName;
	std::cout << "Enter Last Name: ";
	std::cin >> lastName;
	std::cout << "Enter Nickname: ";
	std::cin >> nickname;
	std::cout << "Enter Phone Number: ";
	std::cin >> phoneNumber;
	std::cout << "Enter Darkest Secret: ";
	std::cin >> darkestSecret;
	contact.setContactinfo(firstName, lastName, nickname, phoneNumber, darkestSecret, this->_index);
	this->_book[this->_index] = contact;
	this->_index++;
	if (this->_nbContacts != 8)
		this->_nbContacts++;
}

void	PhoneBook::printContact(int	index)
{
	if (index > this->_nbContacts || index < 0)
	{
		std::cout << "This contact does not exist." << std::endl;
		return ;
	}
	std::cout << "First name: " << this->_book[index].firstName << std::endl;
	std::cout << "Last name: " << this->_book[index].lastName << std::endl;
	std::cout << "Nickname: " << this->_book[index].nickname << std::endl;
	std::cout << "Phone number: " << this->_book[index].phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_book[index].darkestSecret << std::endl;
}

void	PhoneBook::print_contact_info(std::string str)
{
	if (str.size() > 10)
		std::cout << std::right << std::setw(10) << str.substr(0, 10) << ".";
	else
		std::cout << std::right << std::setw(10) << str;
}

int	PhoneBook::printAllContacts(void)
{
	int i;

	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	std::cout << "|Id        |First Name|Last Name |Phone Num.|" << std::endl;
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	i = -1;
	if (this->_nbContacts == 0)
	{
		std::cout << "No contacts to display." << std::endl << std::endl;
		return (0);
	}
	while (++i <= this->_nbContacts)
	{
		std::cout << "|" << this->_book[i].id << "         |";
		print_contact_info(this->_book[i].firstName);
		std::cout << "|";
		print_contact_info(this->_book[i].lastName);
		std::cout << "|";
		print_contact_info(this->_book[i].phoneNumber);
		std::cout << "|";
		std::cout << std::endl << " ---------- ---------- ---------- ---------- " << std::endl;
	}
	std::cout << std::endl << std::endl;
	return (1);
}