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
    ScavTrap b("Evander Holyfield");
    b.showData();
    a.showData();
    fighters[0] = &a;
    fighters[1] = &b;
    ClapTrap::ring = fighters;
    b.attack(a.getName());
    b.showData();
    a.showData();
    b.guardGate();
    
    return 0;
}