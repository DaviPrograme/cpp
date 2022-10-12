/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap **ClapTrap::ring = {NULL};


ClapTrap::ClapTrap(){
    this->setName("Default Name");
    this->setHitPoint(10);
    this->setEnergyPoint(10);
    this->setAttackDemage(0);
    std::cout << "[CLAPTRAP]Default constructor called\n\n\n";
}

ClapTrap::ClapTrap(std::string name){
    this->setName(name);
    this->setHitPoint(10);
    this->setEnergyPoint(10);
    this->setAttackDemage(0);
    std::cout << "[CLAPTRAP]String constructor called.\n\n\n";
}

ClapTrap::ClapTrap(ClapTrap &obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    std::cout << "[CLAPTRAP]Copy constructor called.\n\n\n";
}

ClapTrap::~ClapTrap(){
    std::cout << "[CLAPTRAP]Destructor called.\n\n\n";
    return;
}

ClapTrap& ClapTrap::operator=(ClapTrap &obj){
    this->setName(obj.getName());
    this->setHitPoint(obj.getHitPoint());
    this->setEnergyPoint(obj.getEnergyPoint());
    this->setAttackDemage(obj.getAttackDemage());
    return (*this);
}

void ClapTrap::attack(const std::string& target){
        int index = 0;
    if (this->getEnergyPoint() > 0)
    {
        while(ClapTrap::ring && ClapTrap::ring[index] && ClapTrap::ring[index]->getName() != target)
            ++index;
        if(ClapTrap::ring && ClapTrap::ring[index])
        {
            if (ClapTrap::ring[index]->getHitPoint())
            {
                ClapTrap::ring[index]->takeDamage(this->getAttackDemage());
                this->setEnergyPoint(this->getEnergyPoint() - 1);
                std::cout << "ClapTrap " << this->getName() << " attacks " << target;
                std::cout << ", causing " << this->getAttackDemage() << " points of damage!\n\n\n";
            }
            else
                std::cout << "The ClapTrap " << ClapTrap::ring[index]->getName() << " was knocked out!!!\n\n\n";
        }
        else
            std::cout << "ClapTrap " << target << " not found!!!\n\n\n";
    }
    else 
        std::cout << "ClapTrap " << this->getName() << " is out of energy to attack!\n\n\n";
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->getEnergyPoint() > 0)
    {
        this->setEnergyPoint(this->getEnergyPoint() - 1);
        this->setHitPoint(this->getHitPoint() + amount);
        std::cout << "ClapTrap " << this->getName() << " repaired " << amount << " hit points!\n\n\n";
    } else
        std::cout << "ClapTrap " <<  this->getName() << " is out of energy!\n\n\n";
}

void ClapTrap::setName(std::string name) {
    this->_name = name; 
}

std::string ClapTrap::getName(void) {
    return this->_name; 
}

void ClapTrap::setHitPoint(int hp) {
    this->_hit_point = hp;
}

int ClapTrap::getHitPoint(void) {
    return this->_hit_point; 
}

void ClapTrap::setEnergyPoint(int ep){
    this->_energy_point = ep;
}

int ClapTrap::getEnergyPoint(void){
    return this->_energy_point;
}

void ClapTrap::setAttackDemage(int ad){
    this->_attack_damage = ad;
}

int ClapTrap::getAttackDemage(void){
    return this->_attack_damage;
}

void ClapTrap::takeDamage(unsigned int amount){
    int hitPoint = this->getHitPoint();
    if (hitPoint - (int)amount >= 0)
        this->setHitPoint(hitPoint - amount);
    else
        this->setHitPoint(0);
}

void ClapTrap::showData(void){
    std::cout << "=============================================\n";
    std::cout << "           [CLAPTRAP]FIGHTER DATA            \n";
    std::cout << "=============================================\n";
    std::cout << "NAME: " << this->getName() << "\n";
    std::cout << "HP: " << this->getHitPoint() << "\n";
    std::cout << "ENERGY: " << this->getEnergyPoint() << "\n";
    std::cout << "ATTACK DAMAGE: " << this->getAttackDemage() << "\n";
    std::cout << "=============================================\n";
    std::cout << "=============================================\n\n\n\n";
}
