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

#include "Bureaucrat.hpp"

int main( void ) {
    try {
    
        Bureaucrat Lucas = Bureaucrat("Lucas", 1);
        Lucas.decrementGrade();
        Lucas.decrementGrade();
    }
    
    catch (std::exception & e) {
        
        std::cout << e.what() << std::endl;
    }

    try {
    
        Bureaucrat Edouard = Bureaucrat("Edouard", 1);
        Edouard.incrementGrade();
        std::cout << Edouard.getGrade() << std::endl;
        std::cout << Edouard << std::endl;
    }
    
    catch (std::exception & e) {
        
        std::cout << e.what() << std::endl;
    }

    try {
    
        Bureaucrat Pierre = Bureaucrat("Pierre", -1);
        std::cout << Pierre << std::endl;
    }
    
    catch (std::exception & e) {
        
        std::cout << e.what() << std::endl;
    }
}