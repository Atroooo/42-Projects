/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:04:27 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/20 16:07:30 by lcompieg         ###   ########.fr       */
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

        int getCount(void) const;
        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);

    protected:
        AMateria *_Inventory[4];
        int count;
    
};

#endif