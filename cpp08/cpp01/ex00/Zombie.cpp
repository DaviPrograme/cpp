/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string name){
    this->_name = name;
}

std::string Zombie::getName(void){
    return this->_name;
}

Zombie::Zombie(std::string name){
    this->setName(name);
}

Zombie::Zombie(){
    return;
}

Zombie::~Zombie(void){
    std::cout << "The " << this->getName() << " zombie died.\n";
}

void Zombie::annouce(void){
    std::cout << this->getName() << " BraiiiiiiinnnzzzZ...\n";
}