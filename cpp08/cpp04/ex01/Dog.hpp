/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "includes.hpp"
# include "Animal.hpp"
# include "Brain.hpp"


class Dog : public Animal {
    public:
        Dog();
        Dog(Dog &obj);
        Dog& operator=(Dog &obj);
        virtual ~Dog();
        void makeSound(void);
        void insertIdea(std::string str);
        std::string *getIdeas(void);
        std::string getIdea(unsigned int index);
        Brain *getBrain(void);
    private:
        Brain *_brain;
};

#endif