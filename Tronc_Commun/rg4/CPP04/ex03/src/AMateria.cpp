/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:36 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 14:09:10 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) {
    std::cout << "AMateria constructor called" << std::endl;
    this->type = type;
}

AMateria::AMateria(const AMateria &src) {
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria(void) {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src) {
    std::cout << "AMateria assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

std::string const &AMateria::getType(void) const {
    return (this->type);
}

void AMateria::use(ICharacter &target) {
    std::cout << this->type << " use on " << target.getName() << std::endl;
}
