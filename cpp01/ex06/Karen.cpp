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
    std::cout << "[DEBUG]\nI love to get extra baconfor my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!\n\n";
}

void Karen::info(void){
    std::cout << "[INFO]\nI cannot believe adding extrabacon cost more money. You don’t put enough! If you did I would not have to askfor it!\n\n";
}

void Karen::warning(void){
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. I’ve beencoming here for years and you just started working here last month.\n\n";
}

void Karen::error(void){
    std::cout << "[ERROR]\nThis is unacceptable, I want to speak to the manager now.\n\n";
}

void Karen::case_default(void){
    std::cout << "[ Probably complaining about insignificant problems ]\n";
}

void Karen::complain(std::string level){

    int x = 0;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Karen::*func[5])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::case_default};
    while(x < 4 && levels[x] != level)
        ++x;
    switch (x)
    {
    case 0:
        (this->*(func[0]))();
    case 1:
        (this->*(func[1]))();
    case 2:
        (this->*(func[2]))();
    case 3:
        (this->*(func[3]))();
        break;
    default:
        (this->*(func[4]))();
        break;
    }
}