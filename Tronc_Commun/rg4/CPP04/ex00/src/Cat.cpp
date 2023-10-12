/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:46 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/12 19:37:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
    std::cout << "Cat assignation operator called" << std::endl;
    this->type = src.getType();
    return (*this);
}

void Cat::makeSound(void) const {
    std::cout << "Miaou Miaou" << std::endl;
}
