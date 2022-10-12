/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "includes.hpp"

class HumanB {
    public:
        HumanB(std::string named);
        HumanB();
        ~HumanB(void);
        void setName(std::string named);
        std::string getName(void);
        std::string getWeapon(void);
        void setWeapon(Weapon &wpn);
        void attack(void);
    private:
        std::string name;
        Weapon *weapon;
};

#endif