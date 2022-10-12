/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->setType("WrongAnimal");
    std::cout << "[WRONG_ANIMAL]Default constructor called\n\n\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &obj){
    this->_type = obj.getType();
    std::cout << "[WRONG_ANIMAL]Copy constructor called.\n\n\n";
}

WrongAnimal::~WrongAnimal(){
    std::cout << "[WRONG_ANIMAL]Destructor called.\n\n\n";
    return;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal &obj){
    this->setType(obj.getType()); 
    return (*this);
}

void WrongAnimal::setType(std::string tp){
    this->_type = tp;
}

std::string WrongAnimal::getType(void){
    return this->_type;
}

void WrongAnimal::makeSound(void){
    std::cout << "WRONG CRI! WRONG CRI!\n\n";
}
