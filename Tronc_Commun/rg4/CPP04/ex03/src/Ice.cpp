/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:30:59 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 00:50:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    // std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria(src) {
    // std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice(void) {
    // std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &src) {
    // std::cout << "Ice assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice *Ice::clone() const {
    return (new Ice());
}
