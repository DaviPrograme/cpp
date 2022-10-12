/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/31 01:16:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "includes.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm& operator=(ShrubberyCreationForm &obj);
        ~ShrubberyCreationForm();
        void action(void) const;
        void _createFile(void) const;
		std::string treeASCII(void) const;
    private:
        ShrubberyCreationForm();
};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm &obj);


#endif