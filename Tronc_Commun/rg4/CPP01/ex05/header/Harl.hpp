/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:27:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/08 13:24:16 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        std::string _level[4];
    public:
        void complain(std::string level);
};

#endif