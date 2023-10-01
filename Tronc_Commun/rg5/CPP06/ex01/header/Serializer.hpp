/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:56:42 by marvin            #+#    #+#             */
/*   Updated: 2023/10/01 16:56:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

class Data {
    public:
        std::string info;
};

class Serializer {

    public:

        Serializer();
        Serializer(Serializer const & src);
        ~Serializer();

        Serializer &		operator=(Serializer const & src);


        static uintptr_t           serialize(Data * ptr);
        static Data                *deserialize(uintptr_t raw);

};

#endif