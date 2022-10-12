/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(){
    return;
}

Karen::~Karen(){
    return;
}

void Karen::debug(void){
    std::cout << "I love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n";
}
void Karen::info(void){
    std::cout << "I cannot believe adding extrabacon cost more money. You don’t put enough! If you did I would not have to askfor it!\n";
}

void Karen::warning(void){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve beencoming here for years and you just started working here last month.\n";
}

void Karen::error(void){
    std::cout << "This is unacceptable, I want to speak to the manager now.\n";
}

void Karen::complain(std::string level){

    int x = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Karen::*func[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
    while(x < 3 && levels[x] != level)
        ++x;
    (this->*(func[x]))();
}