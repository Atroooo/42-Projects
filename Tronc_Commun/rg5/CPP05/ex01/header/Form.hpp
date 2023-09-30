/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:55:13 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 20:55:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToExecute;
        const int           _gradeToSign;
    public:
        Form();
        Form(std::string name, int gradeToExecute, int gradeToSign);
        Form(const Form &src);
        ~Form();

        Form &operator=(const Form &rhs);

        std::string const   getName() const;
        bool                getSigned() const;
        int                 getGradeToExecute() const;
        int                 getGradeToSign() const;

        void                beSigned(const Bureaucrat &bureaucrat);

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

std::ostream &operator<<(std::ostream &o, const Form &rhs);

#endif