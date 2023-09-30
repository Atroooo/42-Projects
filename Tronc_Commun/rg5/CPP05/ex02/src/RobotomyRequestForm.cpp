/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:03:36 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 22:03:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    AForm::operator=(src);
    this->_target = src._target;
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if (this->getSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException("Grade too low to execute form");
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->_target << " robotomization failed" << std::endl;
}