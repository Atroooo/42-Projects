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

Span::Span() : _size(0), _arr(NULL) {}

Span::Span(unsigned int n) : _size(n), _arr(new int[n]) {
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = 0;
}

Span::Span(Span const &other) : _size(other._size), _arr(new int[_size]) {
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

Span::~Span() {
    delete [] _arr;
}

Span &Span::operator=(Span const &other) {
    delete [] _arr;
    this->_size = other._size;
    this->_arr = new int[_size];
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
    return *this;
}

void Span::addNumber(int n) {
    if (_size == 0)
        throw std::exception();
    for (unsigned int i = 0; i < _size; i++) {
        if (_arr[i] == 0) {
            _arr[i] = n;
            return ;
        }
    }
    throw Span::FullSpanException();
}

int Span::shortestSpan(void) {
    if (_size < 2)
        throw Span::NotEnoughNumbersException();

    std::vector<int> v(_size);
    std::copy(_arr, _arr + _size, v.begin());
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
    int min = *std::min_element(_arr, _arr + _size);
    int max = *std::max_element(_arr, _arr + _size);
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
