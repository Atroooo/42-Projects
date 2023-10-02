/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

int main(void) {
    int tab[] = { 0, 1, 2, 3, 4 };
    char tab2[5] = { 'a', 'b', 'c', 'd', 'e' };

    iter(tab, 5, print);
    iter(tab2, 5, print);
}
