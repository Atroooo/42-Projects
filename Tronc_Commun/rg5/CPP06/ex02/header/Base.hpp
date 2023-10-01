/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 22:22:27 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 22:22:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>

class Base {

    public:
        virtual ~Base( void ) {};
}; 

class A : public Base {};
class B : public Base {};
class C : public Base {};

#endif