/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/05/01 07:08:59 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include <vector>
#include "easyfind.hpp"

int main(void){
	std::vector<int>vct;
	std::cout << "ARRAY = [";
	for(int i = 12; i < 100; i+=10){
		vct.push_back(i);
		std::cout << i << ", ";
	}
	std::cout << "]\n";
	
	std::vector<int>::iterator it =  easyfind(vct, 43);
	if (it != vct.end())
		std::cout << "element: "<< *it << "\n";
	else	
		std::cout << "element: not found\n";

	it =  easyfind(vct, 42);
	if (it != vct.end())
		std::cout << "element: "<< *it << "\n";
	else	
		std::cout << "element: not found\n";
	return 0;
}