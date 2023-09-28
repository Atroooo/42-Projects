/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:30:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 00:50:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    // std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria(src) {
    // std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void) {
    // std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &src) {
    // std::cout << "Cure assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure *Cure::clone() const {
    return (new Cure());
}