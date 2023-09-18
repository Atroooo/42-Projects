/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:08:12 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:54:05 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
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