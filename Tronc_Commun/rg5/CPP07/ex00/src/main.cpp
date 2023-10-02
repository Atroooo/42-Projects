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

#include "whatever.hpp"


int main(void) {
    int a = 1;
    int b = 2;

    std::cout << "Before swap : a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap a = " << a << ", b = " << b << std::endl;

    std::cout << "Min of " << a << " and " << b << " is " << min(a, b) << std::endl;
    std::cout << "Max of " << a << " and " << b << " is " << max(a, b) << std::endl;

    char c = 'a';
    char d = 'z';

    std::cout << "Before swap : c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "After swap c = " << c << ", d = " << d << std::endl;
    
    std::cout << "Min of " << c << " and " << d << " is " << min(c, d) << std::endl;
    std::cout << "Max of " << c << " and " << d << " is " << max(c, d) << std::endl;

    std::string e = "chaine1"; 
    std::string f = "chaine2"; 
    ::swap(e, f); 
    std::cout << "e = " << e << ", f = " << f << std::endl; 
    std::cout << "min(e, f) = " << ::min(e, f) <<std::endl; 
    std::cout <<"max(e, f) = " << ::max(e, f) <<std::endl; 
    
    return (0);
}
