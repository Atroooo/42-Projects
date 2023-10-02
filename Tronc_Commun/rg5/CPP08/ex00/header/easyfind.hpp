/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:19:07 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 14:19:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template <typename T>
bool easyfind(T &container, int n) {
    typename T::iterator occur = std::find(container.begin(), container.end(), n);
    if (occur == container.end())
        throw std::exception();
    else
        return (1);
}

#endif
