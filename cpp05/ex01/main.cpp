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
    std::cout << "1) Creating a Form with valid data: \n\n";
    Form form1("Teste 1", 75, 75);
    std::cout << form1;

    std::cout << "2) Creating a Form with Grid Sign larger than allowed: \n\n";
    Form form2("Teste 2", 0, 75);
    std::cout << form2;

    std::cout << "3) Creating a Form with Execute Grid smaller than allowed: \n\n";
    Form form3("Teste 3", 75, 151);
    std::cout << form3;

    std::cout << "4) Getting a bureaucrat to sign an invalid form: \n\n";
    Bureaucrat bureaucrat1("Chico Alves", 75);
    bureaucrat1.signForm(form3);
    std::cout << form3;

    std::cout << "5) Getting a bureaucrat to sign a Form where his grade is lower than required: \n\n";
    bureaucrat1.setGrade(76);
    bureaucrat1.signForm(form1);
    std::cout << form1;

    std::cout << "6) Put a bureaucrat to sign a Form where his grade is enough: \n\n";
    bureaucrat1.setGrade(75);
    bureaucrat1.signForm(form1);
    std::cout << form1;

    return 0;
}