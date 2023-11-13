// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Array.hpp                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/10/02 13:39:17 by marvin            #+#    #+#             */
// /*   Updated: 2023/10/02 13:39:17 by marvin           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
    public:

        Array(void) : _array(NULL), _size(0) {};
        Array(unsigned int n) : _array(new T[n]), _size(n) {};
        Array(Array const &src) : _array(NULL), _size(0) {
            *this = src;
        };
        ~Array(void) {
            if (this->_array)
                delete [] this->_array;
        };

        Array &operator=(Array const &src) {
            if (this->_array)
                delete [] this->_array;
            this->_array = new T[src._size];
            this->_size = src._size;
            for (unsigned int i = 0; i < this->_size; i++)
                this->_array[i] = src._array[i];
            return (*this);
        };

        T &operator[](unsigned int i) const {
            if (i >= this->_size)
                throw Array::OutOfLimitsException();
            return (this->_array[i]);
        };

        int size(void) const {
            return (this->_size);
        };

        class OutOfLimitsException : public std::exception {
            public:
                virtual const char *what() const throw() {
                    return ("Out of Range");
                };
        };

    private:
        T *_array;
        unsigned int _size;
};

#endif
