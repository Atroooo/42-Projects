/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:16 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/12 14:23:13 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
    public:
        Cat(void);
        Cat(const Cat &src);
        ~Cat(void);

        Cat &operator=(const Cat &src);

        void makeSound(void) const;
        Brain *getBrain(void) const;
        
    private:
        Brain *brain;
};

#endif