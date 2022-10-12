/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

char *upper_string(char *str){
    int count;

    count = -1;
    while (str[++count]){
        str[count] = toupper(str[count]);
    }
    return str;
}

int main(int argc, char **argv){
    int x = 0;

    if (argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else {
        while (++x < argc){
            std::cout << upper_string(argv[x]);
        }
        std::cout << "\n";
    }
    return (0);
}