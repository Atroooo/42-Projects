/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 21:01:53 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 21:01:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToExecute, int gradeToSign) : _name(name), _signed(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign) {
    if (gradeToExecute < 1)
        throw AForm::GradeTooHighException("Grade too high to execute");
    if (gradeToSign < 1)
        throw AForm::GradeTooHighException("Grade too high to sign");
    if (gradeToExecute > 150)
        throw AForm::GradeTooLowException("Grade too low to execute");
    if (gradeToSign > 150)
        throw AForm::GradeTooLowException("Grade too low to sign");
}

AForm::AForm(const AForm &inst) : _name(inst.getName()), _signed(inst.getSigned()), _gradeToExecute(inst.getGradeToExecute()), _gradeToSign(inst.getGradeToSign()) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &src) {
    this->_signed = src.getSigned();
    return (*this);
}

std::string const AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_signed);
}

int AForm::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

int AForm::getGradeToSign() const {
    return (this->_gradeToSign);
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException("Grade too low to sign");
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &o, const AForm &src) {
    o << src.getName() << " is a AForm " << " that requires a grade " << src.getGradeToSign() << " to be signed and a grade " << src.getGradeToExecute() << " to be executed." << std::endl;
    return (o);
}