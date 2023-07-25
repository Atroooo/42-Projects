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

class PhoneBook {

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact(Contact contact);
		void	printContact(int index);
		void	printAllContacts(void);
	
	private:
		Contact		_book[8];
		int			_nbContacts;
		int			_index;
};

#endif