/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:50:42 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/28 22:43:08 by marvin           ###   ########.fr       */
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
        Ice *clone() const;
};

#endif
