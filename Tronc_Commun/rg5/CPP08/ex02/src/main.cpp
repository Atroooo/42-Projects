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

#include "MutantStack.hpp"

int main(void) {
    MutantStack<int> mstack; 
    
    mstack.push(5); 
    mstack.push(17); 
    
    std::cout << "top " << mstack.top() << std::endl; 
    mstack.pop(); 
    
    std::cout << "size " << mstack.size() << std::endl; 
    mstack.push(3); 
    mstack.push(5);
    mstack.push(737); 
    
    //[...] 
    mstack.push(0); 
    
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end(); 
    ++it;
    --it; 
    
    while(it != ite) { 
        std::cout << "nb " << *it << std::endl; 
        ++it; 
    } 
    
    std::stack<int> s(mstack); 
    return (0);
}
