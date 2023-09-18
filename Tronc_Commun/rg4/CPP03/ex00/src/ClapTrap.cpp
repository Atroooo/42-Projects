/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:29 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "Default constructor called." << std::endl;
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
    std::cout << "Constructor called." << std::endl;
    this->_Name = name;
    this->_HitPoints = 10;
    this->_EnergyPoints = 10;
    this->_AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "Copy constructor called." << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &op) {
    std::cout << "Copy assigment operator called" << std::endl;
    this->_Name = op._Name;
    this->_HitPoints = op._HitPoints;
    this->_EnergyPoints = op._EnergyPoints;
    this->_AttackDamage = op._AttackDamage;
    return (*this);
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor for ClapTrap " << std::endl;
}

void ClapTrap::attack(const std::string &target) {
    if (this->_HitPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    if (this->_EnergyPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " has no energy left." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
    this->_EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    
    if (this->_HitPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_Name << " is taking " << amount << " points of damage !" << std::endl;
    this->_HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_HitPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    if (this->_EnergyPoints <= 0) {
        std::cout << "ClapTrap " << this->_Name << " has no energy left." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_Name << " is repairing himself and regains " << amount << " health point(s)" << std::endl;
    this->_HitPoints += amount;
    this->_EnergyPoints--;
}
