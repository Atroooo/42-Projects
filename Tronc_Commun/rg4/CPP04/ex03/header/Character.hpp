/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:37:55 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 02:41:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character(void);
        Character(std::string name);
        Character(Character const &src);
        ~Character(void);

        Character &operator=(Character const &src);

        std::string const &getName(void) const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        void deleteUnequiped(void);
        
    private:
        std::string _Name;
        AMateria *_Inventory[4];
        AMateria *_Unequiped[4];
};

#endif