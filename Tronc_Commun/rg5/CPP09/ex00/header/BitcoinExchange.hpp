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
# include <stdlib.h>
# include <string>
# include <fstream>
# include <climits>
# include <map>

class BitcoinExchange {
    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &src);
        ~BitcoinExchange(void);

        BitcoinExchange &operator=(BitcoinExchange const &src);

        int   parsePriceFile(std::string filename);
        int   printRes(std::string filename);
        
    private:
        std::map<std::string, double>  _priceMap;
};

#endif