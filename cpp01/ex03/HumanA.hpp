/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "includes.hpp"

class HumanA {
    public:
        HumanA(std::string named, Weapon &wpn);
        ~HumanA(void);
        void setName(std::string named);
        std::string getName(void);
        std::string getWeapon(void);
        void attack(void);
    private:
        std::string name;
        Weapon &weapon;
};

#endif