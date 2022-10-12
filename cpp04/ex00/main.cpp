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
    std::cout << "___[START] CREATION OF OBJECTS___\n\n";
    Animal *ptr1 = new Animal();
    Animal *ptr2 = new Dog();
    Animal *ptr3 = new Cat();
    std::cout << "____[END] CREATION OF OBJECTS____\n\n";
    std::cout << "____[START] GET TYPES___\n\n";
    std::cout << ptr1->getType() << "\n\n";
    std::cout << ptr2->getType() << "\n\n";
    std::cout << ptr3->getType() << "\n\n";
    std::cout << "____[END] GET TYPES____\n\n";
    std::cout << "____[START] MAKE SOUNDS___\n\n";
    ptr1->makeSound();
    ptr2->makeSound();
    ptr3->makeSound();
    std::cout << "____[END] MAKE SOUNDS____\n\n";
    std::cout << "____[START] DELETE OF OBJECTS___\n\n";
    delete ptr1;
    delete ptr2;
    delete ptr3;
    std::cout << "____[END] DELETE OF OBJECTS___\n\n";
    std::cout << "____[START] CREATION THE WRONG OBJECTS____\n\n";
    WrongAnimal *ptr4 = new WrongAnimal();
    WrongAnimal *ptr5 = new WrongCat();
    std::cout << "____[END] CREATION THE WRONG OBJECTS____\n\n";
    std::cout << "____[START] MAKE SOUNDS___\n\n";
    ptr4->makeSound();
    ptr5->makeSound();
    std::cout << "____[END] MAKE SOUNDS____\n\n";
    std::cout << "____[START] DELETE OF OBJECTS___\n\n";
    delete ptr4;
    delete ptr5;
    std::cout << "____[END] DELETE OF OBJECTS___\n\n";

    return 0;
}