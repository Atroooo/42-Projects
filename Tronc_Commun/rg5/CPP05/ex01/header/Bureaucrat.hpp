/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:42:00 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 00:42:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:

        std::string const   _name;
        int                 _grade;

    public:

        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &ref);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &ref);

        std::string const   getName() const;
        int                 getGrade() const;

        void                incrementGrade();
        void                decrementGrade();

        class GradeTooHighException : public std::exception {
            private:
                const char *_error;

            public:
                GradeTooHighException(const char *error) : _error(error) {};
                virtual const char* what() const throw() { return _error; }
        };

        class GradeTooLowException : public std::exception {
            private:
                const char *_error;

            public:
                GradeTooLowException(const char *error) : _error(error) {};
                virtual const char* what() const throw() { return _error; }
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif