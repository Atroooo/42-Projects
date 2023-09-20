/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:47:38 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 16:09:11 by lcompieg         ###   ########.fr       */
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
        std::string type;
};

#endif
