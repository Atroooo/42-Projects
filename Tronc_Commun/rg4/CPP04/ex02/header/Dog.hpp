/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:28:18 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:49:26 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog(void);

        Dog &operator=(const Dog &src);
        
        void makeSound(void) const;
    
    private:
        Brain *brain;
};

#endif