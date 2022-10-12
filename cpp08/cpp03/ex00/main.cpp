/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ClapTrap *fighters[2];

int main(void){
    ClapTrap a("Mike Tyson");
    ClapTrap b("Evander Holyfield");
    a.setAttackDemage(1);
    b.setAttackDemage(1);

    fighters[0] = &a;
    fighters[1] = &b;

    ClapTrap::ring = fighters;

    std::cout << "What happens if one of the ClapTraps attacks until they run out of energy?\n\n";
    b.setHitPoint(15);
    a.showData();
    b.showData();
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.attack("Evander Holyfield");
    a.showData();
    b.showData();

    std::cout << "What happens if a fighter uses energy to repair himself?\n\n";
    b.showData();
    b.beRepaired(1);
    b.beRepaired(1);
    b.beRepaired(1);
    b.beRepaired(1);
    b.beRepaired(1);
    b.showData();

    std::cout << "What happens if one fighter attacks other until he knocks him out?\n\n";
    b.setAttackDemage(5);
    a.showData();
    b.showData();
    b.attack("Mike Tyson");
    b.attack("Mike Tyson");
    b.attack("Mike Tyson");
    b.attack("Mike Tyson");
    a.showData();
    b.showData();

    std::cout << "What happens if a fighter tries to attack an opponent that doesn't exist?\n\n";
    b.showData();
    b.attack("Muhammad Ali");
    b.showData();
    
    return 0;
}