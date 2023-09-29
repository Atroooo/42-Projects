/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:04:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/29 02:29:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        ~MateriaSource(void);

        MateriaSource &operator=(MateriaSource const &src);

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);

    protected:
        AMateria *_Inventory[4];
};

#endif