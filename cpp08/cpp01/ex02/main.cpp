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

#include <iostream>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string str2 = "BRAAAAAAAAAAAIN";

    std::string *ptr = &str;
    std::string &ref = str;

    std::cout << "ADDRES: " << &str << "\n";
    std::cout << "PTR=" << *ptr << "   ADDRES-PTR=" << ptr << "\n" << "REF=" << ref << "   ADDRES-REF=" << &ref << "\n\n";

    ptr = &str2;
    ref = str;

    std::cout << "ADDRES: " << &str2 << "\n";
    std::cout << "PTR=" << *ptr << "   ADDRES-PTR=" << ptr << "\n" << "REF=" << ref << "   ADDRES-REF=" << &ref << "\n\n";
    return 0;
}