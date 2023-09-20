/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:50:42 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 15:20:05 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice(void);
        Ice(Ice const &src);
        ~Ice(void);

        Ice &operator=(Ice const &src);

        void use(ICharacter &target);
        AMateria *clone() const;
};

#endif
