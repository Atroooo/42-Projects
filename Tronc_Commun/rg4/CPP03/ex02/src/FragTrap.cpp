/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:40:45 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:33:37 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << "Default constructor FragTrap called" << std::endl;
    this->_Name = "Default";
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "Constructor FragTrap called" << std::endl;
    this->_Name = name;
    this->_HitPoints = 100;
    this->_EnergyPoints = 100;
    this->_AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {
    std::cout << "Copy constructor FragTrap called" << std::endl;
    *this = src;
}

FragTrap::~FragTrap(void) {
    std::cout << "Deconstructor FragTrap called" << std::endl;   
}

FragTrap &FragTrap::operator=(FragTrap const &op) {
    std::cout << "Assignation operator FragTrap called" << std::endl;
    this->_Name = op._Name;
    this->_HitPoints = op._HitPoints;
    this->_EnergyPoints = op._EnergyPoints;
    this->_AttackDamage = op._AttackDamage;
    return (*this);
}

void FragTrap::attack(const std::string &target) {
    if (this->_HitPoints <= 0) {
        std::cout << "FragTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    if (this->_EnergyPoints <= 0) {
        std::cout << "FragTrap " << this->_Name << " has no energy left." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage !" << std::endl;
    this->_EnergyPoints--;
}

void FragTrap::highFivesGuys(void) {
    if (this->_HitPoints <= 0) {
        std::cout << "FragTrap " << this->_Name << " is dead." << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_Name << " is asking for a high five !" << std::endl;
}
