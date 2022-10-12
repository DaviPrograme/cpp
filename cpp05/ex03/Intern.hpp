/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "includes.hpp"
# include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(Intern &obj);
        Intern& operator=(Intern &obj);
        ~Intern();
        AForm *makeForm(std::string nameForm, std::string target);
        AForm *createPresidentialPardonForm(std::string formName);
        AForm *createRobotomyRequestForm(std::string formName);
        AForm *createShrubberyCreationForm(std::string formName);
        class FormNotFound : public std::exception {
            const char *what(void) const throw();
        };
        

    private:
};
#endif