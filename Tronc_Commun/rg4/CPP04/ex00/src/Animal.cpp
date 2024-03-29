/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:25 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:46:40 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
    std::cout << "Animal assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

std::string Animal::getType(void) const {
    return (this->type);
}

void Animal::makeSound(void) const {
    std::cout << "Animal sound" << std::endl;
}
