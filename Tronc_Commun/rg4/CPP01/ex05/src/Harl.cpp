/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:29:22 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/08 13:44:45 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
    std::string     levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    void            (Harl::*function[4])(void) = 
    {  
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    int i = 0;
    while (level[i])
    {
        if (level == levels[i])
            (this->*function[i])();
        i++;
    }
}

void Harl::debug(void) {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}


