/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string defaultNameForm = "Unnamed Form";
unsigned int defaultGradeSign = 75;
unsigned int defaultGradeExecute = 75;

Form::Form() : _name(defaultNameForm), _gradeSign(defaultGradeSign), _gradeExecute(defaultGradeExecute)
{
    std::cout << "[FORM]Default constructor called\n\n\n";
    this->_checkGrades();
    this->_isSigned = false;
}

Form::Form(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), 
_gradeExecute(gradeExecute)
{
    std::cout << "[FORM] called constructor with parameters\n\n\n";
    this->_checkGrades();
    this->_isSigned = false;
}

std::string Form::getName(void) const{
    return this->_name;
}

int Form::getGradeSign(void) const{
    return this->_gradeSign; 
}

int Form::getGradeExecute(void) const{
    return this->_gradeExecute;
}

void Form::setSigned(bool status){
    this->_isSigned = status;
}

bool Form::getSigned(void)const{
    return this->_isSigned;
}

Form::Form(Form &obj) : _name(obj.getName()), _gradeSign(obj.getGradeSign()),
_gradeExecute(obj.getGradeExecute()){
    std::cout << "[FORM]Copy constructor called.\n\n\n";
    this->_checkGrades();
    this->_isSigned = obj.getSigned();
}

Form::~Form(){
    std::cout << "[FORM]Destructor called.\n\n\n";
    return;
}

Form& Form::operator=(Form &obj){
    this->setSigned(obj.getSigned()); 
    return (*this);
}

const char *Form::GradeTooHighException::what(void) const throw(){
    return ("ERROR: THE GRADE IS ABOVE THE ALLOWED! \n\n");
}

const char *Form::GradeTooLowException::what(void) const throw(){
    return ("ERROR: THE GRADE IS BELOW THE ALLOWED! \n\n");
}

void Form::beSigned(Bureaucrat& b){
    if (b.getGrade() > this->_gradeSign || !(this->getValid()))
        throw Form::GradeTooLowException();
    else
        this->setSigned(true);    
}

void Form::_checkGrades(void){
    try {
        if (this->_gradeExecute > 150 || this->_gradeSign > 150)
            throw Form::GradeTooLowException();
        else if (this->_gradeExecute < 1 || this->_gradeSign < 1)
            throw Form::GradeTooHighException();
        this->_isValid = true;
    } catch (const std::exception& e){
        this->_isValid = false;
        std::cout << e.what();
    }
}

void Form::setValid(bool status){
        this->_isValid = status;
}

bool Form::getValid(void) const{
    return this->_isValid;
}

std::ostream& operator<<(std::ostream& o, const Form &obj){
    o << "__________DATA  FORM__________\n" 
    << "Name: " << obj.getName() << "\n"
    << "Grade Signed: " << obj.getGradeSign() << "\n"
    << "Grade Execute: " << obj.getGradeExecute() << "\n"
    << "Is Valid: " << (obj.getValid() ? "True" : "False") << "\n"
    << "Is Signed: " << (obj.getSigned() ? "True" : "False") << "\n"
    << "______________________________\n";
    return o;
}