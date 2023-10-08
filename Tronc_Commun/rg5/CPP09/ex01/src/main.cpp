/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }
    RPN rpn;
    std::string expression = argv[1];
    for (size_t i = 0; i < expression.length(); i++) {
        
        if (expression[i] == ' ')
            continue ;
        if (expression[i] >= '0' && expression[i] <= '9') {
            rpn.push(expression[i] - '0');
            continue ;
        }
        if (expression[i] == '+') {
            rpn.add();
            continue ;
        }
        if (expression[i] == '-') {
            rpn.subtract();
            continue ;
        }
        if (expression[i] == '*') {
            rpn.multiply();
            continue ;
        }
        if (expression[i] == '/') {
            rpn.divide();
            continue ;
        }
        if (expression[i] == '%') {
            rpn.modulo();
            continue ;
        }
        std::cout << "Invalid character: " << expression[i] << std::endl;
        return (1);
    }
    rpn.printResult();
}
