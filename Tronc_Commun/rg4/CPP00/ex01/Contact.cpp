/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:01:05 by marvin            #+#    #+#             */
/*   Updated: 2023/07/10 18:01:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
    return ;
}

Contact::~Contact(void) {
    return ;
}

void	Contact::setContactinfo(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret, int id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    this->id = id;
}
