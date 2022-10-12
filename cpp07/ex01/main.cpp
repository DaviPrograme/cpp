/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/23 07:05:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include<iostream>

int main(void){
	//int array[5] = {1, 2, 3, 4, 5};
	//char array[5] = {'P','A','U','L','O'};
	//double array[5] = {0.42,1.42,2.42,3.42,4.42};
	float array[5] = {10.42f,11.42f,12.42f,13.42f,14.42f};
	int index = -1;

	std::cout << "beforeArray[5]: {";
	while(++index < 5)
		std::cout << array[index] << ", ";
	std::cout << "}\n";
	
	::iter(array, 5, ::zero);

	index = -1;
	std::cout << " afterArray[5]: {";
	while(++index < 5)
		std::cout << array[index] << ", ";
	std::cout << "}\n\n";
	return 0;
}