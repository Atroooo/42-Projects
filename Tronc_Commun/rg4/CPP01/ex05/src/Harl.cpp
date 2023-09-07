/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:29:22 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/07 17:52:38 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level) {
    switch (level) {
        case "debug":
            this->debug();
            break;
        case "info":
            this->info();
            break;
        case "warning":
            this->warning();
            break;
        case "error":
            this->error();
            break;
        default:
            std::cout << "Wrong level" << std::endl;
            break;
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
