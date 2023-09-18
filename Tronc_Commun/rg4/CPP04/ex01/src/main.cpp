/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:28 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 16:21:53 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Animal *Animal[4];
    
    for (int i = 0; i < 4; i++) {
        if (i % 2 == 0)
            Animal[i] = new Dog();
        else
            Animal[i] = new Cat();
    }

    for (int i = 0; i < 4; i++)
        Animal[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete Animal[i];
    return (0);
}