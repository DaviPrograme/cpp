/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/31 04:49:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void){
    AForm *teste;
    Intern mano;

    teste = mano.makeForm("robotomy request", "TEST1");
    std::cout << *teste;
    teste = mano.makeForm("shrubbery creation", "TEST2");
    std::cout << *teste;
    teste = mano.makeForm("presidential pardon", "TEST3");
    std::cout << *teste;
    teste = mano.makeForm("shurumelas", "TEST4");
    return 0;
}