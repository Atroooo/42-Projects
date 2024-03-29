/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:58:36 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/14 14:40:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = x * ( 1 << this->_bits);
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called " << std::endl;
    this->_value = roundf(x * (1 << this->_bits));
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &op) {
    std::cout << "Copy assigment operator called" << std::endl;
    this->_value = op.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const {
    return ((int)(this->_value / (1 << this->_bits)));
}

std::ostream &operator<<(std::ostream &out, const Fixed &src) {
    out << src.toFloat();
    return (out);
}