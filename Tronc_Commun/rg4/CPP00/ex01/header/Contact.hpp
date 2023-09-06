/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:08 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

	public:
		Contact(void);
		~Contact(void);	

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		int			id;

		void	setContactinfo(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret, int id);
};

#endif