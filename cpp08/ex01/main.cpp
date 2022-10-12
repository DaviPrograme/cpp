/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/05/01 07:48:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <stdlib.h>
#include<time.h>

void CreateTenThousandElements(void){
	Span sp(10000);
	int		r;
	while(sp.sizeSpan() < sp.getMaxElements()){
		srand((unsigned)time(NULL));
		r =  std::rand() % 100000;
		sp.addNumber(r);
	}
	std::cout << "shortestSpan(10.000): " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan(10.000): " << sp.longestSpan() << "\n";
	
}

int main(int, char**)
{
	Span sp(5);
	std::cout << "______________________________________________\n";
	std::cout << "1. checking the shortestSpan and longestSpan \n";
	std::cout << "	with no elements in the container\n";
	std::cout << "______________________________________________\n\n";
	try{
		std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	} catch(std::exception &e){
		std::cout << e.what();
	}
	try{
		std::cout << "longestSpan: " << sp.longestSpan() << "\n"; 
	}catch(std::exception &e){
		std::cout << e.what();
	}
	std::cout << "______________________________________________\n";
	std::cout << "2. checking shortestSpan and longestSpan with\n";
	std::cout << "	only one element in container\n";
	std::cout << "______________________________________________\n\n";
	sp.addNumber(6);
	try{
		std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	} catch(std::exception &e){
		std::cout << e.what();
	}
	try{
		std::cout << "longestSpan: " << sp.longestSpan() << "\n"; 
	}catch(std::exception &e){
		std::cout << e.what();
	}
	std::cout << "______________________________________________\n";
	std::cout << "3. checking shortestSpan and longestSpan \n";
	std::cout << "	with full container\n";
	std::cout << "______________________________________________\n\n";
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);
	sp.addNumber(vec);
	std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
	std::cout << "longestSpan: " << sp.longestSpan() << "\n";
	
	std::cout << "______________________________________________\n";
	std::cout << "4. Trying to add one more element to the one\n";
	std::cout << "	 with full container\n";
	std::cout << "______________________________________________\n\n";
	try{
		sp.addNumber(42);
	}catch(std::exception &e){
		std::cout << e.what();
	}
	return 0;
}