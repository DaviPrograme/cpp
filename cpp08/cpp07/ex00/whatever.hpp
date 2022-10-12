/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/23 06:22:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

template<typename T>
void swap(T &a, T &b){
	T c = a;
	a = b;
	b = c;
}

template<typename T>
T min(T const a, T const b){
	return (a < b ? a : b);
}

template<typename T>
T max(T const a, T const b){
	return (a > b ? a : b);
}
#endif