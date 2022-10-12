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
    std::cout << "1) Attempt to instantiate a bureaucrat with a higher grade than allowed: \n\n";
    Bureaucrat a(0);
    std::cout << a;


    std::cout << "\n\n2) Attempt to instantiate a bureaucrat with a lower grade than allowed: \n\n";
    Bureaucrat b(151);
    std::cout << b;


    std::cout << "\n\n3) Check behavior of up and down grade methods: \n\n";
    Bureaucrat c(75);
    std::cout << c;
    c.upGrade();
    std::cout << c;
    c.downGrade();
    std::cout << c;
    c.setGrade(1);
    c.upGrade();
    std::cout << c;
    c.setGrade(150);
    c.downGrade();
    std::cout << c;

    return 0;
}