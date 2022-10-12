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
        int getRawBits(void)const;
        void setRawBits(int const raw);
    private:
        int _rawBits;
        static const int _fractionalBits;
};
std::ostream& operator<<(std::ostream &o, const Fixed &fixed); 

#endif