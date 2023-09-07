/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:58:42 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/07 13:46:32 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon weapon) {
    this->_name = name;
    this->_weapon = &weapon;
}

HumanB::HumanB(std::string name) {
    this->_name = name;
    this->_weapon = NULL;
}

HumanB::~HumanB(void) {
    return ;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void HumanB::attack(void) {
    if (this->_weapon == NULL)
        std::cout << this->_name << " attacks with their fists" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
