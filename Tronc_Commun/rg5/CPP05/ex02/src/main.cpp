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
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void ) {
    Bureaucrat bureaucrat("Lucas", 1);
    Bureaucrat bureaucrat1("Pierre", 150);
    ShrubberyCreationForm shrubbery("home");
    PresidentialPardonForm presidential("Jack");
    RobotomyRequestForm robotomy("Lucas");

    std::cout << bureaucrat << std::endl;
    
    //Sign and execute all forms with try and catch
    try {
        bureaucrat.signForm(shrubbery);
        shrubbery.execute(bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        bureaucrat.signForm(presidential);
        presidential.execute(bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        bureaucrat.signForm(robotomy);
        robotomy.execute(bureaucrat);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        bureaucrat1.signForm(presidential);
        presidential.execute(bureaucrat1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}