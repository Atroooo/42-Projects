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

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    *this = src;
}

BitcoinExchange::~BitcoinExchange() {
    return;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
    if (this != &src) {
        this->_priceMap = src._priceMap;
    }
    return (*this);
}

int BitcoinExchange::parsePriceFile(std::string filename) {
    std::ifstream   pricesFile(filename.c_str());
    std::string     line;

    if (!pricesFile.is_open()) {
        std::cout << "Unable to open data.csv file." << std::endl;
        return (0);
    }
    std::getline(pricesFile, line);
    while (std::getline(pricesFile, line)) {
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1);
        this->_priceMap[date] = std::atof(price.c_str());
    }
    pricesFile.close();
    return (1);
}

bool checkDate(std::string date) {
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return (false);
    }
	int month = std::atof(date.substr(5).c_str());
	int day = std::atof(date.substr(8).c_str());
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    return (true);
}
// Gerer annee bisextile, fevrier , 30 ou 31 jours 
double get_value_from_data(std::map<std::string, double>& data, std::string &str)
{	
	int yearInputFile = std::atof(str.substr(0).c_str());
	int	monthInputFile = std::atof(str.substr(5).c_str());
	int	dayInputFile = std::atof(str.substr(8).c_str());

	std::map<std::string, double>::const_iterator it;
    for (it = data.begin(); it != data.end(); ++it) {
		int Year_Data = std::atof(it->first.substr(0).c_str());
		int Month_Data = std::atof(it->first.substr(5).c_str());
		int Day_Data = std::atof(it->first.substr(8).c_str());
		if (Year_Data >= yearInputFile && Month_Data >= monthInputFile && \
            Day_Data >= dayInputFile){	
			break;
		}
    }
	return ((it)->second);
}

int BitcoinExchange::printRes(std::string filename) {
    std::ifstream exchgRateFile(filename.c_str());
    std::string line;

    if (!exchgRateFile.is_open()) {
        std::cout << "Unable to open " << filename << " file." << std::endl;
        return (0);
    }
    std::getline(exchgRateFile, line);
    while (std::getline(exchgRateFile, line)) {
        std::string date = line.substr(0, line.find('|') - 1);
        if (!checkDate(date)) {
            std::cout << "Error: bad input => " + date << std::endl;
            continue;
        }
        double exchgRate = strtod(line.substr(line.find('|') + 1).c_str(), NULL);
        if (exchgRate < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (exchgRate >= 1000) {
            std::cout << "Error: too large number" << std::endl;
            continue;
        }
        double price = get_value_from_data(this->_priceMap, date);
        std::cout << date << " => " << exchgRate << " = " << exchgRate * price << std::endl;
    }
    exchgRateFile.close();
    return (1);
}