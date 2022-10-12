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
    unsigned int qtd = 10;
    unsigned int index = -1;
    Animal *animals[qtd];
    std::cout << "___[START] CREATION OF OBJECTS___\n\n";
    while (++index < qtd)
    {
        if (index % 2 == 0)
            animals[index] = new Dog();
        else
            animals[index] = new Cat();
    }
    std::cout << "____[END] CREATION OF OBJECTS____\n\n";
    index  = -1;
    std::cout << "____[START] DELETE OF OBJECTS___\n\n";
    while (++index < qtd)
        delete animals[index];
    std::cout << "_____[END] DELETE OF OBJECTS____\n\n";
    std::cout << "____[START] PROVING THEY ARE DEEP COPIES___\n\n";
    Cat beforeCat;
    beforeCat.insertIdea("CATZEIRA 1\n");
    Cat afterCat = beforeCat;
    std::cout << "FIRST MOMENT: \n";
    std::cout << "BEFORE_CAT: " << beforeCat.getIdea(0) << "AFTER_CAT: " << afterCat.getIdea(0) << "\n";
    std::string *ptr = afterCat.getIdeas();
    ptr[0] = "CATZEIRA 2\n";
    std::cout << "SECOND MOMENT: \n";
    std::cout << "BEFORE_CAT: " << beforeCat.getIdea(0) << "AFTER_CAT: " << afterCat.getIdea(0) << "\n";
    std::cout << "_____[END] PROVING THEY ARE DEEP COPIES____\n\n";
    return 0;
}