/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:08:12 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/12 14:48:31 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "default";
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
    std::cout << "Brain assignation operator called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    return (*this);
}

void Brain::setIdea(int index, std::string idea) {
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
    std::cout << "index out of range" << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return (this->ideas[index]);
    return ("index out of range");
}