/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
    this->setName("Default Name");
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDemage(30);
    std::cout << "[FRAGTRAP]Default constructor called\n\n\n";
}

FragTrap::FragTrap(std::string name){
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(100);
    this->setAttackDemage(30);
    std::cout << "[FRAGTRAP]String constructor called.\n\n\n";
}

FragTrap::FragTrap(FragTrap &obj): ClapTrap(obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    std::cout << "[FRAGTRAP]Copy constructor called.\n\n\n";
}

FragTrap::~FragTrap(){
    std::cout << "[FRAGTRAP]Destructor called.\n\n\n";
    return;
}

FragTrap& FragTrap::operator=(FragTrap &obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    return (*this);
}

void FragTrap::attack(const std::string& target){
        int index = 0;
    if (this->getEnergyPoint() > 0)
    {
        while(FragTrap::ring && FragTrap::ring[index] && FragTrap::ring[index]->getName() != target)
            ++index;
        if(FragTrap::ring && FragTrap::ring[index])
        {
            if (FragTrap::ring[index]->getHitPoint())
            {
                FragTrap::ring[index]->takeDamage(this->getAttackDemage());
                this->setEnergyPoint(this->getEnergyPoint() - 1);
                std::cout << "FragTrap " << this->getName() << " attacks " << target;
                std::cout << ", causing " << this->getAttackDemage() << " points of damage!\n\n\n";
            }
            else
                std::cout << "The FragTrap " << FragTrap::ring[index]->getName() << " was knocked out!!!\n\n\n";
        }
        else
            std::cout << "FragTrap " << target << " not found!!!\n\n\n";
    }
    else 
        std::cout << "FragTrap " << this->getName() << " is out of energy to attack!\n\n\n";
}

void FragTrap::showData(void){
    std::cout << "=============================================\n";
    std::cout << "           [FRAGTRAP]FIGHTER DATA            \n";
    std::cout << "=============================================\n";
    std::cout << "NAME: " << this->getName() << "\n";
    std::cout << "HP: " << this->getHitPoint() << "\n";
    std::cout << "ENERGY: " << this->getEnergyPoint() << "\n";
    std::cout << "ATTACK DAMAGE: " << this->getAttackDemage() << "\n";
    std::cout << "=============================================\n";
    std::cout << "=============================================\n\n\n\n";
}

void FragTrap::highFiveGuys(void){
    std::cout << "[FRAGTRAP] " << this->getName() << " Hi five folks! Very teamwork! So wow!\n\n\n";
}
