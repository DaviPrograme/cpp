/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include "includes.hpp"


class ClapTrap{
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap &obj);
        ClapTrap& operator=(ClapTrap &obj);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setName(std::string name);
        std::string getName(void);
        void setHitPoint(int hp);
        int getHitPoint(void);
        void setEnergyPoint(int ep);
        int getEnergyPoint(void);
        void setAttackDemage(int ad);
        int getAttackDemage(void);
        void showData(void);
        static ClapTrap **ring;
    private:
        std::string _name;
        int _hit_point;
        int _energy_point;
        int _attack_damage;
};

#endif