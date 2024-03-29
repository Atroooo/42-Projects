/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:07:31 by marvin            #+#    #+#             */
/*   Updated: 2023/09/17 22:07:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main (void) {

    Data *data = new Data;

    data->info = "Ceci est classifie";
    
    std::cout << "Information: " << data->info << std::endl;

    
    uintptr_t serialized = Serializer::serialize(data);

    std::cout << "Serialized: " << serialized << std::endl;
    
    Data *deserialized = Serializer::deserialize(serialized);
    
    std::cout << "Info deserialized: " << deserialized->info << std::endl;

    delete data;
}