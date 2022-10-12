/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/10 20:39:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

class Base{public: virtual ~Base(void){};};
class A: public Base{};
class B: public Base{};
class C: public Base{};

Base *generate(void){
	std::srand((unsigned int)time(NULL));
	unsigned int random_number = rand() % 99;
	unsigned int count = 0;

	if (random_number % 3 == 0){
		std::cout << "\ngenerate(void){return *A}\n";
		return new A();
	}
	count = 1;
	while(count <= random_number){
		if (count == random_number){
			std::cout << "\ngenerate(void){return *B}\n";
			return new B();
		}
		count += 3;
	}
	std::cout << "\ngenerate(void){return *C}\n";
	return new C();
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "identify(Base* p) {return Type A}\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "identify(Base* p) {return Type B}\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "identify(Base* p) {return Type C}\n";
}

void identify(Base& p){
	try{
		A type_a = dynamic_cast<A&>(p);
		std::cout << "identify(Base& p) {return Type A}\n";
		return;
	}catch(const std::exception &e){
		
	}
	try{
		B type_b = dynamic_cast<B&>(p);
		std::cout << "identify(Base& p) {return Type B}\n";
		return;
	}catch(const std::exception &e){
		
	}
	try{
		C type_a = dynamic_cast<C&>(p);
		std::cout << "identify(Base& p) {return Type C}\n";
		return;
	}catch(const std::exception &e){
		
	}
}

int main(){
	int count = 5;
	while(--count >= 0){
		usleep(7000000 + count * 20000);
		Base *ptr = generate();
		Base &ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
	}
	return 0;
}