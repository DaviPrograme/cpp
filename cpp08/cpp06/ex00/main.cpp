/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/10 23:08:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main( int argc, char **argv){
   Conversor t;
   if (argc > 2 || argc == 1){
	   std::cout << "THIS PROGRAM NEEDS TO RECEIVE A PARAMETER!\n\n";
	   return 1;
   }
   t.convertToTypes(static_cast<std::string>(argv[1]));
   return 0;
}