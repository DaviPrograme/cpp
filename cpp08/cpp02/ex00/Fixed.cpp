/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    this->_rawBits = 0;
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

int Fixed::setRawBits(int const raw){
    return this->_rawBits = raw;
}

Fixed& Fixed::operator=(Fixed &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = obj.getRawBits();
    return (*this);
}

Fixed::Fixed(Fixed &obj){
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(obj);
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}