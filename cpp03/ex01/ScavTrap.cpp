/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    this->setName("Default Name");
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDemage(20);
    std::cout << "[SCAVTRAP]Default constructor called\n\n\n";
}

ScavTrap::ScavTrap(std::string name){
    this->setName(name);
    this->setHitPoint(100);
    this->setEnergyPoint(50);
    this->setAttackDemage(20);
    std::cout << "[SCAVTRAP]String constructor called.\n\n\n";
}

ScavTrap::ScavTrap(ScavTrap &obj): ClapTrap(obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    std::cout << "[SCAVTRAP]Copy constructor called.\n\n\n";
}

ScavTrap::~ScavTrap(){
    std::cout << "[SCAVTRAP]Destructor called.\n\n\n";
    return;
}

ScavTrap& ScavTrap::operator=(ScavTrap &obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    return (*this);
}

void ScavTrap::attack(const std::string& target){
        int index = 0;
    if (this->getEnergyPoint() > 0)
    {
        while(ScavTrap::ring && ScavTrap::ring[index] && ScavTrap::ring[index]->getName() != target)
            ++index;
        if(ScavTrap::ring && ScavTrap::ring[index])
        {
            if (ScavTrap::ring[index]->getHitPoint())
            {
                ScavTrap::ring[index]->takeDamage(this->getAttackDemage());
                this->setEnergyPoint(this->getEnergyPoint() - 1);
                std::cout << "ScavTrap " << this->getName() << " attacks " << target;
                std::cout << ", causing " << this->getAttackDemage() << " points of damage!\n\n\n";
            }
            else
                std::cout << "The ScavTrap " << ScavTrap::ring[index]->getName() << " was knocked out!!!\n\n\n";
        }
        else
            std::cout << "ScavTrap " << target << " not found!!!\n\n\n";
    }
    else 
        std::cout << "ScavTrap " << this->getName() << " is out of energy to attack!\n\n\n";
}

void ScavTrap::showData(void){
    std::cout << "=============================================\n";
    std::cout << "           [SCAVTRAP]FIGHTER DATA            \n";
    std::cout << "=============================================\n";
    std::cout << "NAME: " << this->getName() << "\n";
    std::cout << "HP: " << this->getHitPoint() << "\n";
    std::cout << "ENERGY: " << this->getEnergyPoint() << "\n";
    std::cout << "ATTACK DAMAGE: " << this->getAttackDemage() << "\n";
    std::cout << "=============================================\n";
    std::cout << "=============================================\n\n\n\n";
}

void ScavTrap::guardGate(){
    std::cout << "[SCAVTRAP] " << this->getName() << " is now is in gate keeper mode!\n\n\n";
}
