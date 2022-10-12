/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/22 19:41:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class Array {
    public:
		Array(){
			this->countElements = 0;
			this->array = new T[0];
		};
		Array(int n){
			this->countElements = n;
			this->array = new T[n];
		};
      	Array(Array &obj){
			*this = obj;
		};
        Array& operator=(Array &obj){
			if (this == &obj)
				return (*this);
			unsigned int n = obj.size();
			unsigned int count = 0;
			this->countElements = n;
			this->array = new T[this->countElements];
			while (count < n){
				this->array[count] = obj[count];
				++count;
			}
			return (*this);
		};
        ~Array(){
			delete [] this->array;
    		return;
		};
		class InvalidIndex : public std::exception{
			virtual const char *what() const throw() {
				return "Error: INVALID INDEX!\n";
			}
		};
		T &operator[]( unsigned int i ) const {
			if ( i >= this->size() ) throw Array::InvalidIndex();
			return this->array[i];
		}
		unsigned int size(void) const{
			return this->countElements;
		};
    private:
		T *array;
		unsigned int countElements;
};
#endif