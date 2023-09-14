/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:58:18 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/14 15:05:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int _value;
        static const int _bits = 8;
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        Fixed(int const x);
        Fixed(float const x);
        ~Fixed(void);
        
        bool operator>(Fixed const &src) const;
        bool operator<(Fixed const &src) const;
        bool operator>=(Fixed const &src) const;
        bool operator<=(Fixed const &src) const;
        bool operator==(Fixed const &src) const;
        bool operator!=(Fixed const &src) const;
        
        Fixed &operator=(Fixed const &src);
        Fixed operator+(Fixed const &src) const;
        Fixed operator-(Fixed const &src) const;
        Fixed operator*(Fixed const &src) const;
        Fixed operator/(Fixed const &src) const;

        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif