/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:55:13 by marvin            #+#    #+#             */
/*   Updated: 2023/09/30 20:55:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

    private:
        const std::string   _name;
        bool                _signed;
        const int           _gradeToExecute;
        const int           _gradeToSign;
    
    public:
        AForm(std::string name, int gradeToExecute, int gradeToSign);
        AForm(const AForm &src);
        virtual ~AForm();

        AForm &operator=(const AForm &src);

        std::string const   getName() const;
        bool                getSigned() const;
        int                 getGradeToExecute() const;
        int                 getGradeToSign() const;

        void                beSigned(const Bureaucrat &bureaucrat);
        virtual void        execute(const Bureaucrat &executor) const = 0;

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

        class FormNotSignedException : public std::exception {
            
            public:
                virtual const char* what() const throw() { return "Form is not signed by accredited Bureaucrat"; }
        };
        
        class FormNotExecutable: public std::exception {
            
            public:
                virtual const char* what() const throw() { return "Form is not executable by Bureaucrat"; }
        };
};

std::ostream &operator<<(std::ostream &o, const AForm &src);

#endif