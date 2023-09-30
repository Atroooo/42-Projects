/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 22:37:01 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 22:37:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {

    public:
        Intern();
        Intern(const Intern &src);
        ~Intern();

        Intern &operator=(const Intern &src);

        AForm *makeShrubberyCreationForm(std::string const & target);
        AForm *makePresidentialPardonForm(std::string const & target);
        AForm *makeRobotomyRequestForm(std::string const & target);

        AForm *makeForm(std::string const & formName, std::string const & target);

        class FormNotFoundException : public std::exception {

            public:
                virtual const char* what() const throw() { return ("Form not found"); }
        };
};

#endif