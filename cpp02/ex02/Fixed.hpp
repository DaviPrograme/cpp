/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include "includes.hpp"

class Fixed{
    public:
        Fixed();
        Fixed(Fixed const &obj);
        ~Fixed();
        Fixed& operator=(Fixed const &obj);
        Fixed(int num);
        Fixed(float num);
        float toFloat(void) const;
        int toInt(void) const;
        bool operator>(Fixed const &obj) const;
        bool operator<(Fixed const &obj) const;
        bool operator>=(Fixed const &obj) const;
        bool operator<=(Fixed const &obj) const;
        bool operator==(Fixed const &obj) const;
        bool operator!=(Fixed const &obj) const;
        Fixed operator+(Fixed const &obj) const;
        Fixed operator-(Fixed const &obj) const;
        Fixed operator*(Fixed const &obj) const;
        Fixed operator/(Fixed const &obj) const;
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        static Fixed& max(Fixed& obj1, Fixed& obj2);
        static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
        static Fixed& min(Fixed& obj1, Fixed& obj2);
        static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
        int getRawBits(void)const;
        void setRawBits(Fixed const &obj);
    private:
        int _rawBits;
        static const int _fractionalBits;
};
std::ostream& operator<<(std::ostream &o, const Fixed &fixed); 

#endif