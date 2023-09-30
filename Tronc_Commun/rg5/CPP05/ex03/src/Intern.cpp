/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:36:56 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 22:36:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src) {
    (void) src;
    return (*this);
}

AForm *Intern::makeShrubberyCreationForm(std::string const &  target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &  target) {
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const & target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target) {
    std::string Forms[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    AForm *(Intern::*member[3])(std::string const & target) = {
        &Intern::makeShrubberyCreationForm, 
        &Intern::makePresidentialPardonForm, 
        &Intern::makeRobotomyRequestForm
    };

    for (int i = 0; i < 3; i++) {
        if (Forms[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*member[i])(target));
        }
    }
    throw FormNotFoundException();
}
