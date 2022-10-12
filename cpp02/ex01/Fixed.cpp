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

Fixed::Fixed(int num){
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = num << this->_fractionalBits;
}

Fixed::Fixed(float num){
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = roundf(num * (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw){
    this->_rawBits = raw;
}

Fixed& Fixed::operator=(Fixed const &obj){
    std::cout << "Copy assignment operator called" << std::endl;
    this->_rawBits = obj._rawBits;
    return (*this);
}

Fixed::Fixed(Fixed const &obj){
    std::cout << "Copy constructor called" << std::endl;
    Fixed::operator=(obj);
}

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt(void)const{
    return this->_rawBits >> this->_fractionalBits;
}

float Fixed::toFloat(void)const{
    return this->_rawBits / (float)(1 << this->_fractionalBits);
}

std::ostream& operator<<(std::ostream &o, const Fixed &fixed){
    o << fixed.toFloat();
    return o;
}
