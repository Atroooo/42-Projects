/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:36 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 02:31:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
    // std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
    // std::cout << "AMateria constructor called" << std::endl;
    this->_Type = type;
}

AMateria::AMateria(const AMateria &src) {
    // std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria(void) {
    // std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src) {
    // std::cout << "AMateria assignation operator called" << std::endl;
    if (this != &src) {
        this->_Type = src.getType();
    }
    return (*this);
}

std::string const &AMateria::getType(void) const {
    return (this->_Type);
}

void AMateria::use(ICharacter &target) {
    std::cout << this->_Type << " use on " << target.getName() << std::endl;
}
