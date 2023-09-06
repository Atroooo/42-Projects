/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:27:42 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/06 17:53:30 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void    announce(void);
        void    setName(std::string name);
        
    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif