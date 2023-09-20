/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:28:23 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 14:44:42 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    Zombie *horde = zombieHorde(N, "Zombie");
    
    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}