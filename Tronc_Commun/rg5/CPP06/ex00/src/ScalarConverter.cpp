/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:24:09 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 15:24:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(std::string const &input) {
    this->convert(input);
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    *this = src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src) {
    if (this != &src) {
        *this = src;
    }
    return *this;
}

void    convertToChar(std::string const &input) {
    if (specialCases(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (isint(input)) {
        int i = std::atoi(input.c_str());
        if (i >= 32 && i <= 126) {
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        }
        else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    else if (ischar(input)) {
        std::cout << "'" << input << "'" << std::endl;
    }
    else if (isfloat(input)) {
        float f = std::atof(input.c_str());
        if (f >= 32 && f <= 126) {
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        }
        else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    else if (isdouble(input)) {
        double d = strtod(input.c_str(), NULL);
        if (d >= 32 && d <= 126) {
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        }
        else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    convertToInt(std::string const &input) {
    if (specialCases(input)) {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (ischar(input)) {
        std::cout << static_cast<int>(input[0]) << std::endl;
    }
    else if (isint(input)) {
        long i = std::atol(input.c_str());
        if (i >= INT_MIN && i <= INT_MAX) {
            std::cout << static_cast<int>(i) << std::endl;
        }
        else {
            std::cout << "Overflow" << std::endl;
        }
    }
    else if (isfloat(input)) {
        float f = std::atof(input.c_str());
        if (f >= (float)INT_MIN && f <= (float)INT_MAX) {
            std::cout << static_cast<int>(f) << std::endl;
        }
        else {
            std::cout << "Overflow" << std::endl;
        }
    }
    else if (isdouble(input)) {
        double d = strtod(input.c_str(), NULL);
        if (d >= INT_MIN && d <= INT_MAX) {
            std::cout << static_cast<int>(d) << std::endl;
        }
        else {
            std::cout << "Overflow" << std::endl;
        }
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    printSpecialCasesF(std::string const & input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "nanf" << std::endl;
    }
    else if (input == "inf" || input == "inff") {
        std::cout << "+inff" << std::endl;
    }
    else if (input == "+inf" || input == "+inff") {
        std::cout << "+inff" << std::endl;
    }
    else if (input == "-inf" || input == "-inff") {
        std::cout << "-inff" << std::endl;
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    convertToFloat(std::string const &input) {
    if (specialCases(input)) {
        printSpecialCasesF(input);
        return ;
    }
    if (ischar(input)) {
        std::cout << static_cast<float>(input[0]) << "f" << std::endl;
    }
    else if (isint(input)) {
        std::cout << static_cast<float>(std::atoi(input.c_str())) << ".0f" << std::endl;
    }
    else if (isfloat(input)) {
        double f = strtod(input.c_str(), NULL);
        if (f >= -FLT_MAX && f <= FLT_MAX) {
            std::cout << static_cast<float>(f) << "f" << std::endl;
        }
        else {
            std::cout << "overflow" << std::endl;
        }
    }
    else if (isdouble(input)) {
        double d = strtod(input.c_str(), NULL);
        if (d >= -FLT_MAX && d <= FLT_MAX) {
            std::cout << static_cast<float>(d) << "f" << std::endl;
        }
        else {
            std::cout << "impossible" << std::endl;
        }
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    printSpecialCasesD(std::string const & input) {
    if (input == "nan" || input == "nanf") {
        std::cout << "nan" << std::endl;
    }
    else if (input == "inf" || input == "inff") {
        std::cout << "+inf" << std::endl;
    }
    else if (input == "+inf" || input == "+inff") {
        std::cout << "+inf" << std::endl;
    }
    else if (input == "-inf" || input == "-inff") {
        std::cout << "-inf" << std::endl;
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    convertToDouble(std::string const &input) {
    if (specialCases(input)) {
        printSpecialCasesD(input);
        return ;
    }
    if (ischar(input)) {
        std::cout << static_cast<double>(input[0]) << std::endl;
    }
    else if (isint(input)) {
        std::cout << static_cast<double>(std::atoi(input.c_str())) << ".0" << std::endl;
    }
    else if (isfloat(input)) {
        std::cout << static_cast<double>(std::atof(input.c_str())) << std::endl;
    }
    else if (isdouble(input)) {
        double long d = strtod(input.c_str(), NULL);
        if (d >= -DBL_MAX && d <= DBL_MAX) {
            std::cout << static_cast<double>(d) << std::endl;
        }
        else {
            std::cout << "overflow" << std::endl;
        }
    }
    else {
        std::cout << "impossible" << std::endl;
    }
}

void    ScalarConverter::convert(std::string const &input) {
    std::cout << "char: ";
    convertToChar(input);
    std::cout << "int: ";
    convertToInt(input);
    std::cout << "float: ";
    convertToFloat(input);
    std::cout << "double: ";
    convertToDouble(input);
}

int isfloat(std::string str) {
    int i = 0;
    int dot = 0;
    int f = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (str[i] == '.') {
            if (dot == 1)
                return (0);
            dot = 1;
        }
        else if (str[i] == 'f') {
            if (f == 1)
                return (0);
            f = 1;
        }
        else if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    if (f == 0 || dot == 0)
        return (0);
    return (1);
}

int isint(std::string str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ischar(std::string str) {
    if (str.length() != 1)
        return (0);
    if (str[0] < 32 || str[0] > 126)
        return (0);
    return (1);
}

int isdouble(std::string str) {
    int i = 0;
    int dot = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (str[i] == '.') {
            if (dot == 1)
                return (0);
            dot = 1;
        }
        else if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int specialCases(std::string str) {
    if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
        return (1);
    return (0);
}
