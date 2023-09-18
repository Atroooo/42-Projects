/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:48:18 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Bark Bark" << std::endl;
}
