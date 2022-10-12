/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::string defaultName = "Rufus Lenhador";
unsigned int defaultGrade = 75;

Bureaucrat::Bureaucrat() : _name(defaultName), _grade(defaultGrade){
    // std::cout << "[BUREAUCRAT]Default constructor called\n";
    this->_checkHighGrade();
    this->_checkLowGrade();
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(defaultGrade){
    // std::cout << "[BUREAUCRAT] called constructor getting name\n";
    this->_checkHighGrade();
    this->_checkLowGrade();
}

Bureaucrat::Bureaucrat(int grade) : _name(defaultName), _grade(grade){
    // std::cout << "[BUREAUCRAT] called constructor getting grade\n";
    this->_checkHighGrade();
    this->_checkLowGrade();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    // std::cout << "[BUREAUCRAT] called constructor getting name and grade\n";
    this->_checkHighGrade();
    this->_checkLowGrade();
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name), _grade(grade){
    // std::cout << "[BUREAUCRAT] called constructor getting grade and name\n";
    this->_checkHighGrade();
    this->_checkLowGrade();
}

Bureaucrat::Bureaucrat(Bureaucrat &obj){
    this->_grade = obj.getGrade();
    // std::cout << "[BUREAUCRAT]Copy constructor called.\n";
}

Bureaucrat::~Bureaucrat(){
    // std::cout << "[BUREAUCRAT]Destructor called.\n";
    return;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &obj){
    this->setGrade(obj.getGrade()); 
    return (*this);
}

std::string Bureaucrat::getName(void) const{
    return this->_name;
}

void Bureaucrat::setGrade(int grade){
    this->_grade = grade;
    this->_checkHighGrade();
    this->_checkLowGrade();
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void  Bureaucrat::upGrade(void){
    this->_grade -= 1;
    this->_checkHighGrade();
}

void  Bureaucrat::downGrade(void){
    this->_grade += 1;
    this->_checkLowGrade();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw(){
    return ("ERROR: INVALID GRADE! THE HIGHEST GRADE PERMITTED IS 1! \n");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw(){
    return ("ERROR: INVALID GRADE! THE LOWEST GRADE PERMITTED IS 150! \n");
}

void Bureaucrat::_checkHighGrade(void){
    try {
        if (this->_grade < 1)
            throw Bureaucrat::GradeTooHighException(); 
    } catch (const std::exception& e){
        this->_grade = 1;
        std::cout << e.what();
    }
}

void Bureaucrat::_checkLowGrade(void){
    try {
        if (this->_grade > 150)
            throw Bureaucrat::GradeTooLowException(); 
    } catch (const std::exception& e){
        this->_grade = 150;
        std::cout << e.what();
    }
}

void Bureaucrat::signForm(AForm &form){
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << "\n";
    }catch(const std::exception &e){
        std::cout << this->getName() << " coudn't sign " << form.getName() << " because" 
        << (form.getValid() ? " bureaucrat has a lower grade than required to sign the form" 
        : " invalid form") << "\n";
    }
}

void Bureaucrat::executeForm(AForm &form){
    try{
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << "\n";
    }catch(std::exception &e){
        std::cout << e.what();
    }
    form.setCount(form.getCount() + 1);
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat &obj){
    o << "[BUREAUCRAT]" << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "\n\n";
    return o;
}