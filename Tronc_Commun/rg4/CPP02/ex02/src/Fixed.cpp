/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:58:36 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/14 15:07:24 by marvin           ###   ########.fr       */
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a._value < b._value)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a._value > b._value)
        return (a);
    return (b);
}

Fixed &Fixed::operator=(Fixed const &src) {
    std::cout << "Copy assigment operator called" << std::endl;
    this->_value = src.getRawBits();
    return (*this);
}

Fixed Fixed::operator+(Fixed const &src) const {
    Fixed tmp;

    tmp.setRawBits(this->_value + src._value);
    return (tmp);
}

Fixed Fixed::operator-(Fixed const &src) const {
    Fixed tmp;

    tmp.setRawBits(this->_value - src._value);
    return (tmp);
}

Fixed Fixed::operator*(Fixed const &src) const {
    Fixed tmp;

    tmp.setRawBits(this->_value * src._value >> this->_bits);
    return (tmp);
}

Fixed Fixed::operator/(Fixed const &src) const {
    Fixed tmp;
    
    if (src._value == 0)
    {
        std::cout << "You cannot divide something by 0." << std::endl;
        return (0);        
    }
    tmp.setRawBits((this->_value << this->_bits) / src._value);
    return (tmp);
}

bool Fixed::operator>(Fixed const &src) const {
    return (this->_value > src._value);
}

bool Fixed::operator<(Fixed const &src) const {
    return (this->_value < src._value);
}

bool Fixed::operator>=(Fixed const &src) const {
    return (this->_value >= src._value);
}

bool Fixed::operator<=(Fixed const &src) const {
    return (this->_value <= src._value);
}

bool Fixed::operator==(Fixed const &src) const {
    return (this->_value == src._value);
}

bool Fixed::operator!=(Fixed const &src) const {
    return (this->_value != src._value);
}

Fixed &Fixed::operator++() {
    this->_value++;
    return (*this);
}

Fixed &Fixed::operator--() {
    this->_value--;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;

    this->_value++;
    return (tmp);
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;

    this->_value--;
    return (tmp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &src) {
    out << src.toFloat();
    return (out);
}
