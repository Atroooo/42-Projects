/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:40:36 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 01:40:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN::~RPN() {}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return (*this);
}

void RPN::push(int value) {
    this->_stack.push(value);
}

void RPN::add() {
    if (this->_stack.size() < 2) {
        std::cout << "Not enough values in stack to add" << std::endl;
        return ;
    }
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a + b);
}

void RPN::subtract() {
    if (this->_stack.size() < 2) {
        std::cout << "Not enough values in stack to subtract" << std::endl;
        return ;
    }
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a - b);
}

void RPN::multiply() {
    if (this->_stack.size() < 2) {
        std::cout << "Not enough values in stack to multiply" << std::endl;
        return ;
    }
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    this->_stack.push(a * b);
}

void RPN::divide() {
    if (this->_stack.size() < 2) {
        std::cout << "Not enough values in stack to divide" << std::endl;
        return ;
    }
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    if (b == 0) {
        std::cout << "Cannot divide by zero" << std::endl;
        return ;
    }
    this->_stack.push(a / b);
}

void RPN::modulo() {
    if (this->_stack.size() < 2) {
        std::cout << "Not enough values in stack to modulo" << std::endl;
        return ;
    }
    int b = this->_stack.top();
    this->_stack.pop();
    int a = this->_stack.top();
    this->_stack.pop();
    if (b == 0) {
        std::cout << "Cannot modulo by zero" << std::endl;
        return ;
    }
    this->_stack.push(a % b);
}

void RPN::printResult() const {
    if (this->_stack.size() != 1) {
        std::cout << "Invalid expression" << std::endl;
        return ;
    }
    std::cout << this->_stack.top() << std::endl;
}
