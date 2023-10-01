/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int checkArgv(std::string argv) {
    if (isfloat(argv) || isint(argv) || ischar(argv) || isdouble(argv) || specialCases(argv))
        return (1);
    return (0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert [input]" << std::endl;
        return (1);
    }
    if (checkArgv(std::string(argv[1])) == 0)
        return (1);
    std::string str = std::string(argv[1]);
    ScalarConverter converter(str);
    return (0);
}