/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:17 by marvin            #+#    #+#             */
/*   Updated: 2023/10/08 19:25:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>
# include <stdlib.h>
//Check si algo bien respecte
template <typename T>
T getMiddle(T cont, size_t middle) {
    for (size_t i = 0; i < middle; i++)
        ++cont;
    return cont;
};

template <typename T>
void merge_sort(T &cont, T &contLeft, T &contRight) {
    typename T::iterator it = cont.begin();
    typename T::iterator itLeft = contLeft.begin();
    typename T::iterator itRight = contRight.begin();

    while (itLeft != contLeft.end() && itRight != contRight.end()) {
        if (*itLeft < *itRight) {
            *it = *itLeft;
            itLeft++;
        } else {
            *it = *itRight;
            itRight++;
        }
        it++;
    }

    while (itLeft != contLeft.end()) {
        *it = *itLeft;
        itLeft++;
        it++;
    }

    while (itRight != contRight.end()) {
        *it = *itRight;
        itRight++;
        it++;
    }
};

template <typename T>
void merge_insertion_sort(T &cont) {
    if (cont.size() <= 1)
        return ;

    size_t middle = cont.size() / 2;
    T contLeft(cont.begin(), getMiddle(cont.begin(), middle));
    T contRight(getMiddle(cont.begin(), middle), cont.end());

    merge_insertion_sort(contLeft);
    merge_insertion_sort(contRight);

    merge_sort(cont, contLeft, contRight);
};

template <typename T>
void printCont(T &cont) {
    for (typename T::iterator it = cont.begin(); it != cont.end(); it++) {
        std::cout << *it;
        if (it + 1 != cont.end())
            std::cout << " ";
    }
    std::cout << std::endl;
};

#endif