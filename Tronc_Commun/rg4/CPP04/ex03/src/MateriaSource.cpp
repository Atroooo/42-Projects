/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:30:37 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/28 23:17:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
    // std::cout << "MateriaSource constructor called" << std::endl;
    this->count = 0;
    for (int i = 0; i < 4; i++)
        this->_Inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    // std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource::~MateriaSource(void) {
    // std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i])
            delete this->_Inventory[i];
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    // std::cout << "MateriaSource assignation operator called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i])
            delete this->_Inventory[i];
        if (src._Inventory[i])
            this->_Inventory[i] = src._Inventory[i]->clone();
        else
            this->_Inventory[i] = NULL;
    }
    this->count = src.getCount();
    return (*this);
}

int MateriaSource::getCount(void) const {
    return (this->count);
}

void MateriaSource::learnMateria(AMateria *m) {
    this->count += 1;
    if (this->count > 4)
        this->count = 1;
    this->_Inventory[this->count] = m;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (this->_Inventory[i] && this->_Inventory[i]->getType() == type)
            return (this->_Inventory[i]->clone());
    }
    return (NULL);
}
