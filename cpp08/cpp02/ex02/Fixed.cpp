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
    this->_rawBits = 0;
}

Fixed::Fixed(int num){
    this->_rawBits = num << this->_fractionalBits;
}

Fixed::Fixed(float num){
    this->_rawBits = roundf(num * (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void)const{
    return this->_rawBits;
}

void Fixed::setRawBits(Fixed const &obj){
    this->_rawBits = obj.getRawBits();
}

Fixed& Fixed::operator=(Fixed const &obj){
    this->_rawBits = obj._rawBits;
    return (*this);
}

Fixed::Fixed(Fixed const &obj){
    Fixed::operator=(obj);
}

Fixed::~Fixed(void){
    return ;
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

bool Fixed::operator<(Fixed const &obj)const{
    if (this->_rawBits < obj._rawBits)
        return true;
    return false;
}

bool Fixed::operator<=(Fixed const &obj)const{
    if (this->_rawBits <= obj._rawBits)
        return true;
    return false;
}

bool Fixed::operator>(Fixed const &obj)const{
    if (this->_rawBits > obj._rawBits)
        return true;
    return false;
}

bool Fixed::operator>=(Fixed const &obj)const{
    if (this->_rawBits >= obj._rawBits)
        return true;
    return false;
}

bool Fixed::operator!=(Fixed const &obj)const{
    if (this->_rawBits != obj._rawBits)
        return true;
    return false;
}

bool Fixed::operator==(Fixed const &obj)const{
    if (this->_rawBits == obj._rawBits)
        return true;
    return false;
}

Fixed Fixed::operator+(Fixed const &obj)const{
    Fixed ret(this->toFloat() + obj.toFloat());
    return (ret);
}

Fixed Fixed::operator-(Fixed const &obj)const{
    Fixed ret(this->toFloat() - obj.toFloat());
    return (ret);
}

Fixed Fixed::operator*(Fixed const &obj)const{
    Fixed ret(this->toFloat() * obj.toFloat());
    return (ret);
}

Fixed Fixed::operator/(Fixed const &obj)const{
    Fixed ret(this->toFloat() / obj.toFloat());
    return (ret);
}

Fixed& Fixed::operator++(void){
    this->_rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int){
    Fixed ret = *this;
    this->_rawBits++;
    return (ret);
}

Fixed& Fixed::operator--(void){
    this->_rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int){
    Fixed ret = *this;
    this->_rawBits--;
    return (ret);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2){
    return obj1 > obj2 ? obj1 : obj2;
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2){
    return obj1 > obj2 ? obj1 : obj2;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2){
    return obj1 < obj2 ? obj1 : obj2;
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2){
    return obj1 < obj2 ? obj1 : obj2;
}

