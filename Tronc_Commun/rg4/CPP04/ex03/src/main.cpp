/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:34 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 19:16:42 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->unequip(0);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    
    delete bob;
    delete me;
    delete src;
    return (0);
}