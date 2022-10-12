/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include "includes.hpp"

class Animal {
    public:
        Animal();
        Animal(Animal &obj);
        Animal& operator=(Animal &obj);
        virtual ~Animal();
        virtual void makeSound(void) = 0;
        void setType(std::string tp);
        std::string getType(void);
    protected:
        std::string _type;
};

#endif