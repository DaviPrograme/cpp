/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/23 06:41:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP
# include <iostream>
# include <typeinfo>

template<typename T>
void iter(T *array, unsigned int length, void (*f)(T*)){
	while (length > 0)
		f(&array[--length]);
}

template<typename T>
void zero(T *test){
	std::string identifierInt = "i";
	std::string identifierChar = "c";
	std::string identifierDouble = "d";
	std::string identifierFloat = "f";
	
	if (typeid(*test).name() == identifierInt)
		*test = 0;
	else if (typeid(*test).name() == identifierDouble)
		*test = 0;
	else if (typeid(*test).name() == identifierFloat)
		*test = 0;
	else if (typeid(*test).name() == identifierChar)
		*test = (char)48;
}
#endif