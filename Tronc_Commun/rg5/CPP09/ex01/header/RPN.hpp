/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 01:38:52 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 01:38:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<int> _stack;

    public:
        RPN();
        RPN(const RPN& other);
        ~RPN();

        RPN& operator=(const RPN& other);

        void push(int value);
        void add();
        void subtract();
        void multiply();
        void divide();
        void modulo();
        void printResult() const;
};

#endif
