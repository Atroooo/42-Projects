/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:27:31 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/06 18:04:13 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
    return ;
}

Zombie::Zombie(std::string name) {
    this->_name = name;
}

Zombie::~Zombie(void) {
    std::cout << "Deconstructor called, " << this->_name << " is dead." << std::endl;
    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
