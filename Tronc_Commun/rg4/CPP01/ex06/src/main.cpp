/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:47:12 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/27 22:37:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cout << "Usage: ./harl <level>" << std::endl;
        return (1);
    }
    else if (std::string(argv[1]) != "DEBUG" && std::string(argv[1]) != "INFO" && std::string(argv[1]) != "WARNING" && std::string(argv[1]) != "ERROR") {
        std::cout << "Level is inexistant." << std::endl;
        return (1);
    }
    harl.complain(std::string(argv[1]));
    return (0);
}