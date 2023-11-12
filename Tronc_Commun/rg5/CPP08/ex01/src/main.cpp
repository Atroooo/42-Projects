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

#include "Span.hpp"

int main(void) { 
    Span sp = Span(5); 
    
    sp.addNumber(6); 
    sp.addNumber(3); 
    sp.addNumber(17); 
    sp.addNumber(9); 
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl; 
    std::cout << sp.longestSpan() << std::endl; 
    

    Span sp2 = Span(10000);
    sp2.addMultipleNumbers(10000);

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    


    try {
        Span sp3 = Span(1);
        sp3.addNumber(1);
        sp3.addNumber(2);
    } catch (std::exception &e) { 
        std::cout << e.what() << std::endl;
    }

    
    Span sp4 = Span(10000);
    std::vector<int> v(10000);
    for (int i = 0; i < 10000; i++) {
        v[i] = i;
    }

    sp4.addMultipleNumbers(v.begin(), v.end());

    std::cout << sp4.shortestSpan() << std::endl;
    std::cout << sp4.longestSpan() << std::endl;

    return (0);
}