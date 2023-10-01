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

#include "Base.hpp"

Base *generate( void ) {
    int i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify( Base *p ) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify( Base &p ) {
    if (dynamic_cast<A *>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(&p))
        std::cout << "C" << std::endl;
}   

int main( void ) {
    Base *base0 = generate();
    identify(base0);
    identify(*base0);
    delete base0;
    Base *base1 = generate();
    identify(base1);
    identify(*base1);
    delete base1;
    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
    Base *base2 = generate();
    identify(base2);
    identify(*base2);
    delete base2;
    Base *base3 = generate();
    identify(base3);
    identify(*base3);
    delete base3;
    Base *base4 = generate();
    identify(base4);
    identify(*base4);
    delete base4;
    Base *base5 = generate();
    identify(base5);
    identify(*base5);
    delete base5;
    Base *base6 = generate();
    identify(base6);
    identify(*base6);
    delete base6;
    Base *base7 = generate();
    identify(base7);
    identify(*base7);
    delete base7;
    Base *base8 = generate();
    identify(base8);
    identify(*base8);
    delete base8;
    Base *base9 = generate();
    identify(base9);
    identify(*base9);
    delete base9;
}