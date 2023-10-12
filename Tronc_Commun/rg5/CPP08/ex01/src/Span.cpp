/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:10:02 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 20:10:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(Span const &other) : _size(other._size) {
    _numbers = other._numbers;
}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
    _size = other._size;
    _numbers = other._numbers;
    return (*this);
}

void Span::addNumber(int n) {
    if (_size == 0)
        throw std::exception();
    if (_numbers.size() == _size)
        throw Span::FullSpanException();
    _numbers.push_back(n);
}

int Span::shortestSpan(void) {
    if (_size < 2 || _numbers.size() < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> v(_size);
    std::copy(_numbers.begin(), _numbers.end(), v.begin());
    std::sort(v.begin(), v.end());

    for (size_t i = 0; i < _size - 1; i++) {
        v[i] = v[i + 1] - v[i];
    }
    
    int res = *std::min_element(v.begin(), v.end());
    return (res);
}

int Span::longestSpan(void) {
    if (_size < 2)
        throw Span::NotEnoughNumbersException();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return (max - min);
}

void Span::addMultipleNumbers(unsigned int n) {
    if (n > _size || _size == 0)
        throw Span::FullSpanException();
    for (unsigned int i = 0; i < n; i++) {
        addNumber(rand() % (n * 10));
    }
}

const char *Span::NoSpanException::what() const throw() {
    return "No span to find";
}

const char *Span::FullSpanException::what() const throw() {
    return "Span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw() {
    return "Not enough numbers to find a span";
}
