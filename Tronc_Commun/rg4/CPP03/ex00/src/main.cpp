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

#include "ClapTrap.hpp"

int main(void) {
    ClapTrap ClapTrap("Bob");

    ClapTrap.attack("John");
    ClapTrap.takeDamage(5);
    ClapTrap.beRepaired(5);

    ClapTrap.takeDamage(5);
    ClapTrap.takeDamage(5);
    ClapTrap.attack("John");
    return (1);
}