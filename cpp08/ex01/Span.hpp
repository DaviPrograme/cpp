/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/29 18:08:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <vector>
# include <algorithm>

class Span {
    public:
		Span();
		Span(unsigned int n);
      	Span(Span &obj);  
        Span &operator=(Span &obj);
        ~Span();
		class MaxElements : public std::exception{
			virtual const char *what() const throw();
		};
		class  InsufficientAmountElements: public std::exception{
			virtual const char *what() const throw();
		};
		unsigned int getMaxElements(void);
		void addNumber(int n);
		void addNumber(std::vector<int> vec);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		bool findSpan(int src);
		unsigned int sizeSpan(void);
    private:
		std::vector<int> array;
		unsigned int maxElements;
};
#endif