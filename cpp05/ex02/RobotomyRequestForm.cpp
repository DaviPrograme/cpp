/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

std::string defaultNameFormRobotomy = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm() : 
AForm(defaultNameFormRobotomy, 72, 45) {
    // std::cout << "[RobotomyRequestForm]Default constructor called\n";
    this->setTarget("NO-TARGET");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm(defaultNameFormRobotomy, 72, 45){
    // std::cout << "[RobotomyRequestForm] called constructor with parameters\n";
    this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    // std::cout << "[RobotomyRequestForm]Destructor called.\n";
    return;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm &obj){
    this->setSigned(obj.getSigned()); 
    return (*this);
}

void RobotomyRequestForm::action(void) const{
    if (this->getCount() % 2)
        std::cout << "Rotobomization failure! :/ ";
    else
        std::cout << "beeep bzzzzzztrrr beeeeeeeeep! " << this->getTarget() << " has been robotomized successfully!!!";
}

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm &obj){
    o << "__________DATA  ROBOTOMYREQUESTFORM__________\n" 
    << "Name: " << obj.getName() << "\n"
    << "Target: " << obj.getTarget() << "\n"
    << "Grade Signed: " << obj.getGradeSign() << "\n"
    << "Grade Execute: " << obj.getGradeExecute() << "\n"
    << "Is Valid: " << (obj.getValid() ? "True" : "False") << "\n"
    << "Is Signed: " << (obj.getSigned() ? "True" : "False") << "\n"
    << "______________________________\n";
    return o;
}
