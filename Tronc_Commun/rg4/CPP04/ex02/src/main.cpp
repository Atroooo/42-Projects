/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:28 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/12 14:47:57 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    Cat Cat1;
    Cat Cat2;
    Cat1.getBrain()->setIdea(0, "Idea 1");
    Cat1 = Cat2;

    std::cout << Cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << Cat2.getBrain()->getIdea(0) << std::endl;
    
    Cat1.getBrain()->setIdea(0, "Idea 2");
    
    std::cout << Cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << Cat2.getBrain()->getIdea(0) << std::endl;
    return (0);
}