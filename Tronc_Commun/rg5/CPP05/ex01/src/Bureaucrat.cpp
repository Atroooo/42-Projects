/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:47:53 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 00:47:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name), _grade(grade){

    if (_grade < 1)
        throw Bureaucrat::GradeTooLowException("The maximum Grade is 1, cannot attribute grade to 0 or lower.");
    if (_grade > 150)
        throw Bureaucrat::GradeTooHighException("The minimum Grade is 150, cannot attribute grade to 151 or higher.");
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat( ) {

    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& cpy ) : _name(cpy._name), _grade(cpy._grade) {

    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
        
        if (this == &other) {
            return *this;
        }
        std::cout << "Copy assignment operator called" << std::endl;
        this->_grade = other.getGrade();
        return *this;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

std::string const Bureaucrat::getName() const {
    return this->_name;
}


void Bureaucrat::decrementGrade( void ) {

    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooLowException("The maximum Grade is 1, cannot attribute grade to 0 or lower.");
    _grade--;
}

void Bureaucrat::incrementGrade( void ) {

    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooHighException("The minimum Grade is 150, cannot attribute grade to 151 or higher.");
    _grade++;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    
        os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
        return os;
}