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
#include "Brain.hpp"


Dog::Dog(){
    this->setType("Dog");
    this->_brain = new Brain();
    std::cout << "[DOG]Default constructor called\n\n\n";
}

Dog::Dog(Dog &obj) : Animal(obj){
    this->_type = obj.getType();
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*(obj.getBrain()));
    std::cout << "[DOG]Copy constructor called.\n\n\n";
}

Dog::~Dog(){
    delete this->_brain;
    std::cout << "[DOG]Destructor called.\n\n\n";
    return;
}

Dog& Dog::operator=(Dog &obj){
    this->setType(obj.getType());
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*(obj.getBrain()));
    return (*this);
}

void Dog::makeSound(void){
    std::cout << "AU! AU!\n\n";
}

void Dog::insertIdea(std::string str){
    this->_brain->setIdea(str);
}

std::string *Dog::getIdeas(void){
    return this->_brain->getIdeas();
}

std::string Dog::getIdea(unsigned int index){
    return this->_brain->getIdea(index);
}

Brain *Dog::getBrain(void){
    return this->_brain;
}
