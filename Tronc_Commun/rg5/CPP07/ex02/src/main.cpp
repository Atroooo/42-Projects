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

#include "Array.hpp"


int main(void) {
    Array<int> a(5);
    Array<int> b(5);
    Array<int> c;

    try {
        for (int i = 0; i < 5; i++) {
            a[i] = i;
            b[i] = i + 5;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "a: ";
    try {
        for (int i = 0; i < 5; i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "b: ";
    try {
        for (int i = 0; i < 7; i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "c: ";
    try {
        for (int i = 0; i < 7; i++)
            std::cout << c[i] << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
