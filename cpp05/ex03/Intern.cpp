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

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
    // std::cout << "[AFORM]Default constructor called\n";
}

Intern::Intern(Intern &obj) {
    *this = obj;
    // std::cout << "[AFORM]Copy constructor called.\n";
}

Intern::~Intern(){
    // std::cout << "[AFORM]Destructor called.\n";
    return;
}

Intern& Intern::operator=(Intern &obj){
    (void)obj;
    return (*this);
}

AForm *Intern::createPresidentialPardonForm(std::string formName){
    return new PresidentialPardonForm(formName);
}
AForm *Intern::createRobotomyRequestForm(std::string formName){
    return new RobotomyRequestForm(formName);
}
AForm *Intern::createShrubberyCreationForm(std::string formName){
    return new ShrubberyCreationForm(formName);
}

AForm *Intern::makeForm(std::string nameForm, std::string target){
    std::string optionsForm[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "not found"};
    int count = 0;
    while (count < 4 && optionsForm[count] != nameForm)
        ++count;
    if (count < 4 ){
        if (count == 0)
            return this->createShrubberyCreationForm(target);
        else if(count == 1)
            return this->createRobotomyRequestForm(target);
        else
            return this->createPresidentialPardonForm(target);
    }
    std::cout << "ERROR: FORM NOT FOUND!\n";
    return NULL;
}