/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:28:33 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 14:44:19 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie *zombieHorde = new Zombie[N];

    for (int i = 0; i < N; i++)
        zombieHorde[i].setName(name);
    return (zombieHorde);
}
