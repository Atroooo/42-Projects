/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:59:08 by marvin            #+#    #+#             */
/*   Updated: 2023/10/03 16:59:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack(void) {};
        MutantStack(const MutantStack<T> &other) { *this = other; }
        ~MutantStack(void) {};

        MutantStack &operator=(MutantStack const &other) {
            if (this != &other)
                std::stack<T>::operator=(other);
            return (*this);
        }

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() {
            return (this->c.begin());
        }

        iterator end() {
            return (this->c.end());
        }
};

#endif