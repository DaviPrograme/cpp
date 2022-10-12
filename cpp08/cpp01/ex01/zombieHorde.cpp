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

static std::string invert_string(std::string str){
    int end = str.length();
    std::string invert;

    while (--end >= 0)
        invert.append(str.substr(end, 1));
    return invert;
}

static std::string _itoa(int num){
    std::string num_str;
    int mult = 0;
    std::string let;
    while (num || !mult){
        ++mult;
        let = '0' + (num % 10);
        num_str.append(let);
        num /= 10; 
    }
    return invert_string(num_str);
}

Zombie *Zombie::zombieHorde(int N, std::string name){
    if (N <= 0)
        return NULL;
    Zombie *horde = new Zombie[N];

    while (--N >= 0)
        horde[N].setName(name + "-" + _itoa(N));
    return horde;
}