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
        
        Bureaucrat bureaucrat("Lucas", 1);
        Form form("Documents secrets", 10, 1);
        Form form2 = form;

        bureaucrat.signForm(form2);

        std::cout << form2 << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    try {
        
        Bureaucrat bureaucrat("Lucas", 150);
        Form form("Documents secrets", 10, 1);
        Form form2 = form;

        bureaucrat.signForm(form2);

        std::cout << form2 << std::endl;
    } 
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
}