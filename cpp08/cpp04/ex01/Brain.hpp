/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include "includes.hpp"


class Brain {
    public:
        Brain();
        Brain(Brain &obj);
        Brain& operator=(Brain &obj);
        ~Brain();
        void setIdea(std::string str);
        std::string *getIdeas(void);
        std::string getIdea(unsigned int index);
        void setIndex(unsigned int index);
        unsigned int getIndex(void);
    private:
        std::string _ideas[100];
        unsigned int _index;
};

#endif