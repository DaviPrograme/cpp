/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn): weapon(wpn) {
    this->setName(name);
}

HumanA::~HumanA(void){}

void HumanA::setName(std::string named){
    this->name = named;
}

std::string HumanA::getName(void){
    return this->name;
}

std::string HumanA::getWeapon(void){
    return this->weapon.getType();
}

void HumanA::attack(void){
    std::cout << this->getName() << " attacks withs his " << this->getWeapon() << "\n";
}
