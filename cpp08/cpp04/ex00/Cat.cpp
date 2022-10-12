/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"


Cat::Cat(){
    this->setType("Cat");
    std::cout << "[CAT]Default constructor called\n\n\n";
}

Cat::Cat(Cat &obj) : Animal(obj){
    this->_type = obj.getType();
    std::cout << "[CAT]Copy constructor called.\n\n\n";
}

Cat::~Cat(){
    std::cout << "[CAT]Destructor called.\n\n\n";
    return;
}

Cat& Cat::operator=(Cat &obj){
    this->setType(obj.getType()); 
    return (*this);
}

void Cat::makeSound(void){
    std::cout << "MIAU! MIAU!\n\n";
}
