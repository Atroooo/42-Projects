/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:38 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 02:30:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
    public:
        AMateria(void);
        AMateria(std::string const &type);
        AMateria(const AMateria &src);
        virtual ~AMateria(void);

        AMateria &operator=(const AMateria &src);

        std::string const &getType(void) const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
    
    protected:
        std::string _Type;
};

#endif
