/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:37:49 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 01:17:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
    for (int i = 0; i < 4; i++) {
        this->_Inventory[i] = NULL;    
    }
}

Character::Character(std::string name) {
    this->_Name = name;
}

Character::Character(Character const &src) {
    *this = src;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i]  != NULL)
            delete this->_Inventory[i];
    }
}

Character &Character::operator=(Character const &src) {
    this->_Name = src.getName();
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i])
            delete this->_Inventory[i];
        if (src._Inventory[i])
            this->_Inventory[i] = src._Inventory[i];
        else
            this->_Inventory[i] = NULL;
    }
    return (*this);
}

std::string const &Character::getName(void) const {
    return (this->_Name);
}

void Character::equip(AMateria *m) {
    if (m == NULL) {
        std::cout << "Invalid materia" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i] == NULL) {
            std::cout << "Equipping..." << std::endl;
            this->_Inventory[i] = m;
            return ;
        }
    }
    std::cout << "Inventory full" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i] && this->_Inventory[i] == m) {
            std::cout << "Already equipped" << std::endl;
            return ;
        }
    }
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    if (this->_Inventory[idx])
    {
        std::cout << "Unequipping..." << std::endl;
        delete this->_Inventory[idx];
        this->_Inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    if (this->_Inventory[idx] == NULL) {
        std::cout << "No materia at this index" << std::endl;
        return ;
    }
    this->_Inventory[idx]->use(target);
}
