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
        Fixed(Fixed &obj);
        Fixed& operator=(Fixed &obj);
        ~Fixed();
        int getRawBits(void) const;
        int setRawBits(int const raw);
    private:
        int _rawBits;
        static const int _fractionalBits;
};

#endif