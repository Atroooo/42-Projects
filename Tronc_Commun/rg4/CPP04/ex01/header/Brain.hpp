/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:59:45 by lcompieg          #+#    #+#             */
/*   Updated: 2023/10/12 14:39:40 by lcompieg         ###   ########.fr       */
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

        void setIdea(int i, std::string idea);
        std::string getIdea(int i) const;
};

#endif