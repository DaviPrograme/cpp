/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/05/01 07:18:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <algorithm>

Span::Span(): maxElements(0){};
		
Span::Span(unsigned int n): maxElements(n){};
		
Span::Span(Span &obj) {
	*this = obj;
};
		  
Span &Span::operator=(Span &obj){
	this->maxElements = obj.maxElements;
	this->array = obj.array;
	return(*this);
};
		
Span::~Span(){};
		
const char *Span::MaxElements::what() const throw(){
		return "Error: maximum number of elements reached.\n";
};

const char *Span::InsufficientAmountElements::what() const throw(){
		return "Error: insufficient amount of elements.\n";
};

unsigned int Span::getMaxElements(void){
	return (this->maxElements);
}

void Span::addNumber(int n){
	if (this->array.size() == this->maxElements)
		throw Span::MaxElements();
	this->array.push_back(n);
	std::sort(this->array.begin(), this->array.end());
}

void Span::addNumber(std::vector<int> vec){
	if (vec.size() + this->array.size() > this->maxElements)
		throw Span::MaxElements();
	this->array.insert(this->array.end(), vec.begin(), vec.end());
	std::sort(this->array.begin(), this->array.end());
}

unsigned int Span::shortestSpan(void){
	if (this->array.size() <= 1)
		throw Span::InsufficientAmountElements();
	std::vector<int>::iterator it = this->array.begin();
	std::vector<int>::iterator itDelimiter = this->array.end() - 1;
	int result = *(it + 1) - *it;
	while(it != itDelimiter){
		if((*(it + 1) - *it) < result)
			result = *(it + 1) - *it;
		std::advance(it, 1);
	}
	return result;
}

unsigned int Span::longestSpan(void){
	if (this->array.size() <= 1)
		throw Span::InsufficientAmountElements();
	return (*(this->array.end() - 1) - *(this->array.begin()));
}

bool Span::findSpan(int src){
	std::vector<int>::iterator it = std::find(this->array.begin(), this->array.end(), src);
	return (it == this->array.end() ? true : false);
}

unsigned int Span::sizeSpan(void){
	return this->array.size();
}