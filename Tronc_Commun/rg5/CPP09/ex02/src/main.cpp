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

#include "PmergeMe.hpp"

bool checkNb(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false)
            return (false);
    }
    return (true);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Usage: ./a.out [list of numbers]" << std::endl;
        return 1;
    }
    std::vector<int> v;
    std::list<int> l;

    size_t i = 1;
    while (argv[i]) {
        if (checkNb(argv[i]) == false) {
            std::cout << "Error" << std::endl;
            return (1);
        }
        int number = atoi(argv[i]);
        if (number < 0) {
            std::cout << "Error" << std::endl;
            return (1);
        }
        v.push_back(number);
        l.push_back(number);
        i++;
    }
    std::cout << "Before: ";
    printCont(v);

    clock_t start = clock();
    merge_insertion_sort(v);
    clock_t end = clock();
    double time_vector = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    merge_insertion_sort(l);
    end = clock();
    double time_list = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "After: ";
    printCont(v);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << time_vector << "us" << std::endl;
    std::cout << "Time to process a range of " << l.size() << " elements with std::list : " << time_list << "us" << std::endl;
    return (0);
}
