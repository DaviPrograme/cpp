/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
    this->_index = 0;
    std::cout << "[BRAIN]Default constructor called\n\n\n";
}

Brain::Brain(Brain &obj) {
    unsigned int index = 0;
    while (index < 100){
        this->_ideas[index] = obj._ideas[index];
        ++index;
    }
    this->setIndex(obj.getIndex());
    std::cout << "[BRAIN]Copy constructor called.\n\n\n";
}

Brain::~Brain(){
    std::cout << "[BRAIN]Destructor called.\n\n\n";
    return;
}

Brain& Brain::operator=(Brain &obj){
    unsigned int index = 0;
    while (index < 100){
        this->_ideas[index] = obj._ideas[index];
        ++index;
    }
    this->setIndex(obj.getIndex());
    return (*this);
}

void Brain::setIdea(std::string str){
    this->_ideas[this->_index] = str;
    this->_index = this->_index + 1 == 100 ? 0 : this->_index + 1; 
}

std::string *Brain::getIdeas(void){
    return this->_ideas;
}

std::string Brain::getIdea(unsigned int index){
    return this->_ideas[index];
}

void Brain::setIndex(unsigned int index){
    this->_index = index;
}

unsigned int Brain::getIndex(void){
    return this->_index;
}
