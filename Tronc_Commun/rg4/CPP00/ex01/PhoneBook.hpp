/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:17 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <cstring>

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(void);
		void	printContact(int index);
		int	printAllContacts(void);
		void	print_contact_info(std::string str);
	
	private:
		Contact		_book[8];
		int			_nbContacts;
		int			_index;
};

#endif