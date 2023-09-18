/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:59:45 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/18 15:53:49 by lcompieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
    private:
        std::string ideas[100];
    
    public:
        Brain(void);
        Brain(const Brain &src);
        ~Brain(void);

        Brain &operator=(const Brain &src);
};

#endif