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

int main(void){
    PhoneBook *agenda = new PhoneBook();
    std::string command = "";

    while (true){
        system("clear");
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, command);
        if (!(command.compare("EXIT")))
            break;
        else if (!(command.compare("ADD")))
            agenda->add();
        else if (!(command.compare("SEARCH")))
            agenda->search();
        else
            std::cout << "Command not found!\n";
        std::cout << "\nPRESS ENTER!\n";
        std::getline(std::cin, command);
    }
    return 0;
}