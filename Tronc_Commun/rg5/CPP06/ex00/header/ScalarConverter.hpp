/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:18 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 15:24:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdlib.h>
# include <cfloat>
# include <climits>

class ScalarConverter {
    
    public:
        ScalarConverter();
        ScalarConverter(std::string const &input);
        ScalarConverter(ScalarConverter const &src);
        ~ScalarConverter();

        ScalarConverter &operator=(ScalarConverter const &src);

        void            convert(std::string const &input);
};

int isfloat(std::string str);
int isint(std::string str);
int ischar(std::string str);
int isdouble(std::string str);
int specialCases(std::string str);

#endif