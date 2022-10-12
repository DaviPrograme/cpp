/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/05/01 17:34:05 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(int, char**)
{
	{
		MutantStack<int>teste;
		std::cout << "__________________________________________\n";
		std::cout << "1. [MutantStack]CHECKING AN EMPTY CONTAINER\n";
		std::cout << "__________________________________________\n\n";
		std::cout << "empty: " << (teste.empty() ? "TRUE\n": "FALSE\n");
		std::cout << "size: " << teste.size() << "\n";

		std::cout << "__________________________________________\n";
		std::cout << "2. [MutantStack]INSERTING ELEMENTS INTO A CONTAINER\n";
		std::cout << "__________________________________________\n\n";
		for(int index = 0; index < 10; ++index)
			teste.push(index);
		MutantStack<int>::iterator it = teste.begin();
		MutantStack<int>::iterator ite = teste.end();
		std::cout << "  2.1 from beginning to end: \n\n";
		while(it != ite){
			std::cout << "element: " << *it << "\n";
			++it;
		}
		std::cout << "\n";
		it = teste.begin();
		std::cout << "  2.2 from the end to the beginning: \n\n";
		while(it != ite)
			std::cout << "element: " << *(--ite) << "\n";

		std::cout << "\n";
		std::cout << "empty: " << (teste.empty() ? "TRUE\n": "FALSE\n");
		std::cout << "size: " << teste.size() << "\n";
		std::cout << "top: " << teste.top() << "\n";

		std::cout << "__________________________________________\n";
		std::cout << "3. [MutantStack]DELETING CONTAINER ELEMENTS\n";
		std::cout << "__________________________________________\n\n";
		for(int index = 0; index <= 5; ++index){
			teste.pop();
		}
		it = teste.begin();
		ite = teste.end();
		std::cout << "  3.1 list of elements: \n\n";
		while(it != ite){
			std::cout << "element: " << *it << "\n";
			++it;
		}
		std::cout << "\n\n";
		std::cout << "size: " << teste.size() << "\n";
		std::cout << "top: " << teste.top() << "\n";
	}


	/* {
		std::list<int>teste;
		std::cout << "__________________________________________\n";
		std::cout << "1. [list]CHECKING AN EMPTY CONTAINER\n";
		std::cout << "__________________________________________\n\n";
		std::cout << "empty: " << (teste.empty() ? "TRUE\n": "FALSE\n");
		std::cout << "size: " << teste.size() << "\n";

		std::cout << "__________________________________________\n";
		std::cout << "2. [list]INSERTING ELEMENTS INTO A CONTAINER\n";
		std::cout << "__________________________________________\n\n";
		for(int index = 0; index < 10; ++index)
			teste.push_back(index);
		std::list<int>::iterator it = teste.begin();
		std::list<int>::iterator ite = teste.end();
		std::cout << "  2.1 from beginning to end: \n\n";
		while(it != ite){
			std::cout << "element: " << *it << "\n";
			++it;
		}
		std::cout << "\n";
		it = teste.begin();
		std::cout << "  2.2 from the end to the beginning: \n\n";
		while(it != ite)
			std::cout << "element: " << *(--ite) << "\n";

		std::cout << "\n";
		std::cout << "empty: " << (teste.empty() ? "TRUE\n": "FALSE\n");
		std::cout << "size: " << teste.size() << "\n";

		std::cout << "__________________________________________\n";
		std::cout << "3. [list]DELETING CONTAINER ELEMENTS\n";
		std::cout << "__________________________________________\n\n";
		for(int index = 0; index <= 5; ++index){
			teste.pop_back();
		}
		it = teste.begin();
		ite = teste.end();
		std::cout << "  3.1 list of elements: \n\n";
		while(it != ite){
			std::cout << "element: " << *it << "\n";
			++it;
		}
		std::cout << "\n\n";
		std::cout << "size: " << teste.size() << "\n";
	} */
	return 0;
}