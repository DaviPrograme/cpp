/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

std::string defaultNameFormPresidential = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm() : 
AForm(defaultNameFormPresidential, 25, 5) {
    // std::cout << "[PresidentialPardonForm]Default constructor called\n";
    this->setTarget("NO-TARGET");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm(defaultNameFormPresidential, 25, 5){
    // std::cout << "[PresidentialPardonForm] called constructor with parameters\n";
    this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    // std::cout << "[PresidentialPardonForm]Destructor called.\n";
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &obj){
    this->setSigned(obj.getSigned()); 
    return (*this);
}

void PresidentialPardonForm::action(void) const{
    std::cout << this->getTarget() << " has been perdoned by Zafod Beeblebrox";
}

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm &obj){
    o << "__________DATA  PRESIDENTIALPARDONFORM__________\n" 
    << "Name: " << obj.getName() << "\n"
    << "Target: " << obj.getTarget() << "\n"
    << "Grade Signed: " << obj.getGradeSign() << "\n"
    << "Grade Execute: " << obj.getGradeExecute() << "\n"
    << "Is Valid: " << (obj.getValid() ? "True" : "False") << "\n"
    << "Is Signed: " << (obj.getSigned() ? "True" : "False") << "\n"
    << "______________________________\n";
    return o;
}
