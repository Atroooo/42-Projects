/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:52:13 by marvin            #+#    #+#             */
/*   Updated: 2023/10/02 12:52:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T &a, T &b) {
    if (a == b)
        return (b);
    else if (a < b)
        return (a);
    return (b);
}

template <typename T>
T max(T &a, T &b) {
    if (a == b)
        return (b);
    else if (a < b)
        return (b);
    return (a);
}

#endif