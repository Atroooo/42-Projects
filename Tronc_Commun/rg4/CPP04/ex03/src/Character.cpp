/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:37:49 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 03:06:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
    for (int i = 0; i < 4; i++) {
        this->_Inventory[i] = NULL;
        this->_Unequiped[i] = NULL;    
    }
}

Character::Character(std::string name) {
    this->_Name = name;
    for (int i = 0; i < 4; i++) {
        this->_Inventory[i] = NULL;
        this->_Unequiped[i] = NULL;    
    }
}

Character::Character(Character const &src) {
    for (int i = 0; i < 4; i++){
        if (this->_Inventory[i])
            this->_Inventory[i] = src._Inventory[i]->clone();
        else
            this->_Inventory[i] = NULL;
    }
    this->_Name = src._Name;
}

Character::~Character(void) {
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i] != NULL)
            delete this->_Inventory[i];
        if (this->_Unequiped[i] != NULL)
            delete this->_Unequiped[i];
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

void Character::equip( AMateria* m ) {
    if (m == NULL)
        return ;
    int i = -1;
    while (++i < 4) {
        if (this->_Unequiped[i] == NULL)
            break;
        if (this->_Unequiped[i] == m)
            return ;
    }
    if (i == 4)
        this->deleteUnequiped();
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i] == m) {
            std::cout << "Already equipped" << std::endl;
            return ;
        }
        if (this->_Inventory[i] == NULL) {
            std::cout << "Equipping..." << std::endl;
            this->_Inventory[i] = m;
            return;
        }
    }
    if (i != 4)
        this->_Unequiped[i] = m;
    else
        this->_Unequiped[0] = m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++) {
        if (this->_Unequiped[i] == NULL) {
            std::cout << "Unequipping..." << std::endl;
            this->_Unequiped[i] = _Inventory[idx];
            this->_Inventory[idx] = NULL;
            return ;
        }
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
    delete this->_Inventory[idx];
    this->_Inventory[idx] = NULL;
    this->deleteUnequiped();
}


void Character::deleteUnequiped(void) {
    for (int i = 0; i < 4; i++) {
        if (this->_Unequiped[i] != NULL) {
            delete this->_Unequiped[i];
            this->_Unequiped[i] = NULL;
        }
    }
}