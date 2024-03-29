/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:40:32 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:31:08 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(FragTrap const &src);
        ~FragTrap(void);

        FragTrap &operator=(FragTrap const &src);

        void highFivesGuys(void);
        void attack(const std::string &target);
};


#endif