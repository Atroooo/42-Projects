/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:22:50 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 16:26:07 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat(void);
        WrongCat(const WrongCat &src);
        ~WrongCat(void);

        WrongCat &operator=(const WrongCat &src);
        
        void makeSound(void) const;
};

#endif