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

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor ScavTrap called";
    this->_Name = name;
    this->_HitPoints = 100;
    this->_EnergyPoints = 50;
    this->_AttackDamage = 20;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Deconstructor ScavTrap called";   
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
    std::cout << "ScavTrap " << this->_name << " has entered Gate Keeper mode !" << std::endl;
}
