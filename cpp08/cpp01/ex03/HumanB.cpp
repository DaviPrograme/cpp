/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name){
    this->setName(name);
}

HumanB::~HumanB(void){}

void HumanB::setName(std::string named){
    this->name = named;
}

std::string HumanB::getName(void){
    return this->name;
}

std::string HumanB::getWeapon(void){
    return this->weapon->getType();
}

void HumanB::attack(void){
    std::cout << this->getName() << " attacks withs his " << this->getWeapon() << "\n";
}

void HumanB::setWeapon(Weapon &wpn){
    this->weapon = &wpn;
}


