/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void) {
    ClapTrap ClapTrap("Bob");
    ScavTrap ScavTrap("John");
    FragTrap FragTrap("Jack");

    ClapTrap.attack("John");
    ScavTrap.takeDamage(5);
    ScavTrap.beRepaired(5);

    ScavTrap.attack("Bob");
    ClapTrap.takeDamage(20);
    ClapTrap.beRepaired(5);
    ScavTrap.guardGate();

    FragTrap.highFivesGuys();
    FragTrap.attack("John");
    ScavTrap.takeDamage(30);
    ScavTrap.beRepaired(20);

    return (1);
}