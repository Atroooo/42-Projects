/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:37:49 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 19:26:05 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
    this->_inventory = new AMateria*[4];
}

Character::Character(std::string name) {
    this->_inventory = new AMateria*[4];
    this->_Name = name;
}

Character::Character(Character const &src) {
    *this = src;
}

Character::~Character(void) {
    delete [] this->_inventory;
}

Character &Character::operator=(Character const &src) {
    this->_Name = src.getName();
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = src._inventory[i];
    }
    return (*this);
}

std::string const &Character::getName(void) const {
    return (this->_Name);
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i] == NULL) {
            this->_inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    if (this->_inventory[idx] == NULL) {
        std::cout << "No materia at this index" << std::endl;
        return ;
    }
    this->_inventory[idx].use(target);
}
