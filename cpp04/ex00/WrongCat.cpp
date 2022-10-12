/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"


WrongCat::WrongCat(){
    this->setType("WrongCat");
    std::cout << "[WRONG_CAT]Default constructor called\n\n\n";
}

WrongCat::WrongCat(WrongCat &obj) : WrongAnimal(obj){
    this->_type = obj.getType();
    std::cout << "[WRONG_CAT]Copy constructor called.\n\n\n";
}

WrongCat::~WrongCat(){
    std::cout << "[WRONG_CAT]Destructor called.\n\n\n";
    return;
}

WrongCat& WrongCat::operator=(WrongCat &obj){
    this->setType(obj.getType()); 
    return (*this);
}

void WrongCat::makeSound(void){
    std::cout << "WRONG MIAU! WRONG MIAU!\n\n";
}
