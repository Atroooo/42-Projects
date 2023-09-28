/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:50:29 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/28 22:43:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure(void);
        Cure(Cure const &src);
        ~Cure(void);

        Cure &operator=(Cure const &src);

        void use(ICharacter &target);
        Cure *clone() const;
};

#endif