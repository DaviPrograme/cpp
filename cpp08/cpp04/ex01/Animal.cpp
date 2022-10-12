/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
    this->setType("No Animal");
    std::cout << "[ANIMAL]Default constructor called\n\n\n";
}

Animal::Animal(Animal &obj){
    this->_type = obj.getType();
    std::cout << "[ANIMAL]Copy constructor called.\n\n\n";
}

Animal::~Animal(){
    std::cout << "[ANIMAL]Destructor called.\n\n\n";
    return;
}

Animal& Animal::operator=(Animal &obj){
    this->setType(obj.getType()); 
    return (*this);
}

void Animal::setType(std::string tp){
    this->_type = tp;
}

std::string Animal::getType(void){
    return this->_type;
}

void Animal::makeSound(void){
    std::cout << "CRI! CRI!\n\n";
}
