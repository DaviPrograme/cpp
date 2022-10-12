/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"


Dog::Dog(){
    this->setType("Dog");
    std::cout << "[DOG]Default constructor called\n\n\n";
}

Dog::Dog(Dog &obj) : Animal(obj){
    this->_type = obj.getType();
    std::cout << "[DOG]Copy constructor called.\n\n\n";
}

Dog::~Dog(){
    std::cout << "[DOG]Destructor called.\n\n\n";
    return;
}

Dog& Dog::operator=(Dog &obj){
    this->setType(obj.getType()); 
    return (*this);
}

void Dog::makeSound(void){
    std::cout << "AU! AU!\n\n";
}
