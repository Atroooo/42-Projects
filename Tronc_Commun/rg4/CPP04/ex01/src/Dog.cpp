/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/13 15:44:12 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src){
    std::cout << "Dog copy constructor called" << std::endl;
    this->type = src.getType();
    this->brain = new Brain(*src.getBrain());
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &src) {
    std::cout << "Dog assignation operator called" << std::endl;
    this->type = src.getType();
    delete this->brain;
    this->brain = new Brain(*src.getBrain());
    return (*this);
}

void Dog::makeSound(void) const {
    std::cout << "Bark Bark" << std::endl;
}

Brain *Dog::getBrain(void) const {
    return (this->brain);
}
