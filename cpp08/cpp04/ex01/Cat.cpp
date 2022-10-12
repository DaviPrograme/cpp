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
#include "Brain.hpp"


Cat::Cat(){
    this->setType("Cat");
    this->_brain = new Brain();
    std::cout << "[CAT]Default constructor called\n\n\n";
}

Cat::Cat(Cat &obj) : Animal(obj){
    this->_type = obj.getType();
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*(obj.getBrain()));
    std::cout << "[CAT]Copy constructor called.\n\n\n";
}

Cat::~Cat(){
    delete this->_brain;
    std::cout << "[CAT]Destructor called.\n\n\n";
    return;
}

Cat& Cat::operator=(Cat &obj){
    this->setType(obj.getType());
    if (this->_brain)
        delete this->_brain;
    this->_brain = new Brain(*(obj.getBrain()));
    return (*this);
}

void Cat::makeSound(void){
    std::cout << "MIAU! MIAU!\n\n";
}

void Cat::insertIdea(std::string str){
    this->_brain->setIdea(str);
}

std::string *Cat::getIdeas(void){
    return this->_brain->getIdeas();
}

std::string Cat::getIdea(unsigned int index){
    return this->_brain->getIdea(index);
}

Brain *Cat::getBrain(void){
    return this->_brain;
}