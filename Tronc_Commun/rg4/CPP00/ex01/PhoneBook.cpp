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
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::addContact(Contact contact) {
	if (this->_index == 8)
		this->_index = 0;
	else
		this->_index++;
	this->_book[this->_index] = contact;

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

void	PhoneBook::printAllContacts(void)
{
	int i;

	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	std::cout << "|Id        |First Name|Last Name |Phone Num.|" << std::endl;
	std::cout << " ---------- ---------- ---------- ---------- " << std::endl;
	i = -1;
	while (++i < this->_nbContacts)
	{
		std::cout << "|" << this->_book[i].id << "         |";
		// Affichage des 10 prems chars (this->_book[i].firstName);
		std::cout << "|";
		// Affichage des 10 prems chars (this->_book[i].lastName);
		std::cout << "|";
		// Affichage des 10 prems chars (this->_book[i].phoneNumber);
		std::cout << "|";
		std::cout << std::endl << " ---------- ---------- ---------- ---------- " << std::endl;
	}
	std::cout << std::endl << std::endl;
}