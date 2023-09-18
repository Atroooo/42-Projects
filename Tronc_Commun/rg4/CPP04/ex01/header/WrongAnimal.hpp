/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:22:52 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 16:25:42 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
    protected:
        std::string type;
    
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal &src);
        virtual ~WrongAnimal(void);

        WrongAnimal &operator=(const WrongAnimal &src);

        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif