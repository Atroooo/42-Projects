/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:01:53 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 21:01:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToExecute(150), _gradeToSign(150) {}

Form::Form(std::string name, int gradeToExecute, int gradeToSign) : _name(name), _signed(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign) {
    if (gradeToExecute < 1)
        throw Form::GradeTooHighException("Grade too high to execute");
    if (gradeToSign < 1)
        throw Form::GradeTooHighException("Grade too high to sign");
    if (gradeToExecute > 150)
        throw Form::GradeTooLowException("Grade too low to execute");
    if (gradeToSign > 150)
        throw Form::GradeTooLowException("Grade too low to sign");
}

Form::Form(const Form &inst) : _name(inst.getName()), _signed(inst.getSigned()), _gradeToExecute(inst.getGradeToExecute()), _gradeToSign(inst.getGradeToSign()) {}

Form::~Form(void) {}

Form &Form::operator=(const Form &src) {
    this->_signed = src.getSigned();
    return (*this);
}

std::string const Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
    return (this->_signed);
}

int Form::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

int Form::getGradeToSign() const {
    return (this->_gradeToSign);
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException("Grade too low to sign");
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, const Form &src) {
    o << src.getName() << " is a form " << " that requires a grade " << src.getGradeToSign() << " to be signed and a grade " << src.getGradeToExecute() << " to be executed." << std::endl;
    return (o);
}