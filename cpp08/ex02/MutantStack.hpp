/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/29 05:54:45 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <deque>

template <class T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container> {
    public:
		MutantStack(){};
		
      	MutantStack(MutantStack &obj): std::stack< T, Container >(obj) {} 
		
        MutantStack& operator=(MutantStack &obj){
			this->c = obj.c;
			return(*this);
		};
		
        ~MutantStack(){};
		
		typedef typename Container::iterator iterator;
		iterator end(void){
			iterator it = this->c.end();
			return (it);
		}

		iterator begin(void){
			iterator it = this->c.begin();
			return (it);
		}		
};
#endif