/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:40:20 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 21:40:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    return;
}

BitcoinExchange::BitcoinExchange(std::string filename) {
    this->_pricesFile.open("data.csv");
    if (!this->_pricesFile.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        exit(1);
    }
    this->_exchangeRateFile.open("exchangeRate.csv");
    if (!this->_exchangeRateFile.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        exit(1);
    }
}