/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:18:18 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:18:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << "Default Constructor ScavTrap called" << std::endl;
    this->_Name = "Default";
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor ScavTrap called" << std::endl;
    this->_Name = name;
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {
    std::cout << "Copy Constructor ScavTrap called" << std::endl;
    *this = src;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &op) {
    std::cout << "Assignation operator ScavTrap called" << std::endl;
    this->_Name = op._Name;
    this->_HitPoints = op._HitPoints;
    this->_EnergyPoints = op._EnergyPoints;
    this->_AttackDamage = op._AttackDamage;
    return (*this);
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Deconstructor ScavTrap called" << std::endl;   
}

void ScavTrap::attack(const std::string &target) {
    if (this->_HitPoints <= 0) {
        std::cout << "ScavTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    if (this->_EnergyPoints <= 0) {
        std::cout << "ScavTrap " << this->_Name << " has no energy left." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
    this->_EnergyPoints--;
}

void ScavTrap::guardGate(void) {
    if (this->_HitPoints <= 0) {
        std::cout << "ScavTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_Name << " has entered Gate Keeper mode !" << std::endl;
}
