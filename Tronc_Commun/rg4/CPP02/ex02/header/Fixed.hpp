/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcompieg <lcompieg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:58:18 by lcompieg          #+#    #+#             */
/*   Updated: 2023/09/08 16:50:12 by lcompieg         ###   ########.fr       */
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
        Fixed &operator=(Fixed const &op);
        Fixed &operator>(Fixed const &op);
        Fixed &operator<(Fixed const &op);
        Fixed &operator>=(Fixed const &op);
        Fixed &operator<=(Fixed const &op);
        Fixed &operator==(Fixed const &op);
        Fixed &operator!=(Fixed const &op);
        Fixed &operator+(Fixed const &op);
        Fixed &operator-(Fixed const &op);
        Fixed &operator*(Fixed const &op);
        Fixed &operator/(Fixed const &op);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        float min(Fixed &a, Fixed &b);
        float max(Fixed &a, Fixed &b);
        float min(Fixed const &a, Fixed const &b);
        float man(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &src);

#endif