/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:12:38 by marvin            #+#    #+#             */
/*   Updated: 2023/10/04 20:12:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange();

        BitcoinExchange &operator=(BitcoinExchange const &src);

        void    parseFile();
        void    printMap(); 

    private:
        std::map<std::string, float> _map;
        std::ifstream               _pricesFile;
        std::ifstream                _exchangeRateFile;
};

#endif