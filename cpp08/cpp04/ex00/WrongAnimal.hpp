/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include "includes.hpp"

class WrongAnimal {
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal &obj);
        WrongAnimal& operator=(WrongAnimal &obj);
        virtual ~WrongAnimal();
        void makeSound(void);
        void setType(std::string tp);
        std::string getType(void);
    protected:
        std::string _type;
};

#endif