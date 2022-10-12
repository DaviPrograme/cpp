/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "includes.hpp"
# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal {
    public:
        Cat();
        Cat(Cat &obj);
        Cat& operator=(Cat &obj);
        virtual ~Cat();
        void makeSound(void);
        void insertIdea(std::string str);
        Brain *getBrain(void);
        std::string *getIdeas(void);
        std::string getIdea(unsigned int index);
    private:
        Brain *_brain;

};

#endif