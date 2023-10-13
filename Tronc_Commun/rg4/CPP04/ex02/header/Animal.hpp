/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:27:21 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/13 15:43:13 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
    protected:
        std::string type;
    
    public:
        Animal(void);
        Animal(std::string type);
        Animal(const Animal &src);
        virtual ~Animal(void);

        Animal &operator=(const Animal &src);

        std::string getType(void) const;
        virtual void makeSound(void) const = 0;
};
#endif