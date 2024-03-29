/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:51:57 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/07 13:29:19 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {
    return ;
}

Weapon::Weapon(std::string type) {
    this->_type = type;
}

Weapon::~Weapon(void) {
    return ;
}

std::string const &Weapon::getType(void) {
    return (this->_type);
}

void Weapon::setType(std::string type) {
    this->_type = type;
}
