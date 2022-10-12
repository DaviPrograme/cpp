/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/05/01 06:32:28 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	//create array without parameters
	Array <int>test1;
	try{
		test1[0];
	}catch(std::exception &e){
		std::cout << "test result 1:\n" << e.what() << "\n";
	}
	
	//create array with parameters
	std::cout << "test result 2:\n";
	unsigned int elements = 5;
	unsigned int index;
	Array <int>test2(elements);
	while(elements){
		index = elements - 1;
		test2[index] = index;
		std::cout << "Array[" << index << "] = "<< test2[index] << "\n";
		--elements;
	}
	std::cout << "\n";

	//access a position in the array that does not exist
	try {
		test2[test2.size() + 1];
	}catch(std::exception &e){
		std::cout << "test result 3:\n" << e.what() << "\n";
	}

	//Demonstrating that a copy created using the 
	//equality operator or using the copy constructor 
	//in both cases is deep copy
	std::cout << "test result 4:\n";
	Array <int>test3(test2);
	
	test3[2] = 42;
	std::cout << "copy constructor: newArray[2]=" << test3[2] << " & oldArray[2]=" << test2[2] << "\n";
	
	Array <int>test4 = test2;
	test4[2] = 84;
	std::cout << "equality operator: newArray[2]=" << test4[2] << " & oldArray[2]=" << test2[2] << "\n";
	return 0;
}