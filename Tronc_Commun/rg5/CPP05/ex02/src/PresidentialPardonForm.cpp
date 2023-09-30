/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:03:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 22:03:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const {
    return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException("Grade too low to execute PresidentialPardon");
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
