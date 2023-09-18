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

#include "ScavTrap.hpp"

int main(void) {
    ClapTrap ClapTrap("Bob");
    ScavTrap ScavTrap("John");

    ClapTrap.attack("John");
    ScavTrap.takeDamage(5);
    ScavTrap.beRepaired(5);

    ScavTrap.attack("Bob");
    ClapTrap.takeDamage(20);
    ClapTrap.beRepaired(5);
    return (1);
}