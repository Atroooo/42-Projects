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
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void ) {
    try  {
        Bureaucrat bureaucrat("Lucas", 1);
        Intern intern;

        AForm *form = intern.makeForm("ShrubberyCreationForm", "home");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

        try  {
        Bureaucrat bureaucrat("Lucas", 1);
        Intern intern;

        AForm *form = intern.makeForm("shrubbery creation", "home");
        bureaucrat.signForm(*form);
        form->execute(bureaucrat);
        std::cout << *form << std::endl;
        delete form;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}