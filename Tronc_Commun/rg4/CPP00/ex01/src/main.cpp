/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:00 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	checkIndex(std::string index) {
	if (index.length() > 1)
		return (0);
	if (index[0] > '8' || index[0] < '0')
		return (0);
	return (1);
}

int	main(int argc, char **argv) {
	PhoneBook		phoneBook;
	std::string		command;
	std::string		searchIndex;

	(void) argv;
	if (argc != 1)
	{
		std::cout << "Usage ./phonebook" << std::endl;
		return (1);
	}
	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::cin >> command;
		if (std::cin.eof() || command == "EXIT")
		{
			std::cout << "Exiting..." << std::endl;
			return (0);
		}
		else if (command == "SEARCH")
		{
			if (phoneBook.printAllContacts() == 1)
			{
				std::cout << "Enter an index: ";
				std::cin >> searchIndex;
				if (checkIndex(searchIndex))
					phoneBook.printContact(searchIndex[0] - '0');
				else
					std::cout << "Invalid index." << std::endl;
			}
		}
		else if (command == "ADD")
			phoneBook.addContact();
		else
			std::cout << "Invalid command." << std::endl;
	}
}