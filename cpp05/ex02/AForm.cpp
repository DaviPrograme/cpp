/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/31 02:04:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::string defaultNameForm = "Unnamed Form";
unsigned int defaultGradeSign = 75;
unsigned int defaultGradeExecute = 75;

AForm::AForm() : _name(defaultNameForm), _gradeSign(defaultGradeSign), _gradeExecute(defaultGradeExecute)
{
    // std::cout << "[AFORM]Default constructor called\n";
    this->_checkGrades();
    this->_isSigned = false;
    this->_target = "NO TARGET";
    this->_count = 0;
}

AForm::AForm(std::string name, int gradeSign, int gradeExecute) : _name(name), _gradeSign(gradeSign), 
_gradeExecute(gradeExecute)
{
    // std::cout << "[AFORM] called constructor with parameters\n";
    this->_checkGrades();
    this->_isSigned = false;
    this->_target = "NO TARGET";
    this->_count = 0;
}

std::string AForm::getName(void) const{
    return this->_name;
}

int AForm::getGradeSign(void) const{
    return this->_gradeSign; 
}

int AForm::getGradeExecute(void) const{
    return this->_gradeExecute;
}

void AForm::setSigned(bool status){
    this->_isSigned = status;
}

bool AForm::getSigned(void)const{
    return this->_isSigned;
}

unsigned int AForm::getCount(void) const{
   return this->_count;
}

void AForm::setCount(unsigned int count){
   this->_count = count;
}

AForm::AForm(AForm &obj) : _name(obj.getName()), _gradeSign(obj.getGradeSign()),
_gradeExecute(obj.getGradeExecute()){
    // std::cout << "[AFORM]Copy constructor called.\n";
    this->_checkGrades();
    this->_isSigned = obj.getSigned();
    this->_target = obj.getTarget();
    this->_count = obj.getCount();
}

AForm::~AForm(){
    // std::cout << "[AFORM]Destructor called.\n";
    return;
}

AForm& AForm::operator=(AForm &obj){
    this->setSigned(obj.getSigned());
    this->setTarget(obj.getTarget());
    return (*this);
}

const char *AForm::GradeTooHighException::what(void) const throw(){
    return ("ERROR: THE GRADE IS ABOVE THE ALLOWED! \n");
}

const char *AForm::GradeTooLowException::what(void) const throw(){
    return ("ERROR: THE GRADE IS BELOW THE ALLOWED! \n");
}

const char *AForm::TryRunFormWithoutSignature::what(void) const throw(){
    return ("ERROR: ATTEMPTED TO RUN AN UNSIGNED FORM! \n");
}

void AForm::beSigned(Bureaucrat& b){
    if (b.getGrade() > this->_gradeSign || !(this->getValid()))
        throw AForm::GradeTooLowException();
    else
        this->setSigned(true);    
}

void AForm::_checkGrades(void){
    try {
        if (this->_gradeExecute > 150 || this->_gradeSign > 150)
            throw AForm::GradeTooLowException();
        else if (this->_gradeExecute < 1 || this->_gradeSign < 1)
            throw AForm::GradeTooHighException();
        this->_isValid = true;
    } catch (const std::exception& e){
        this->_isValid = false;
        std::cout << e.what();
    }
}

void AForm::setValid(bool status){
        this->_isValid = status;
}

bool AForm::getValid(void) const{
    return this->_isValid;
}

void AForm::action(void) const{
    std::cout << "ACTION: NO ACTION";
}

void AForm::execute(Bureaucrat const & executor) const{
    if(!(this->getSigned()))
        throw AForm::TryRunFormWithoutSignature();
    else if(executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    else {
        this->action() ;
        std::cout << "\n";
    }
}

void AForm::setTarget(std::string target){
    this->_target = target;
}

std::string AForm::getTarget(void) const{
    return this->_target;
}

std::ostream& operator<<(std::ostream& o, const AForm &obj){
    o << "__________DATA  FORM__________\n" 
    << "Name: " << obj.getName() << "\n"
    << "Target: " << obj.getTarget() << "\n"
    << "Grade Signed: " << obj.getGradeSign() << "\n"
    << "Grade Execute: " << obj.getGradeExecute() << "\n"
    << "Is Valid: " << (obj.getValid() ? "True" : "False") << "\n"
    << "Is Signed: " << (obj.getSigned() ? "True" : "False") << "\n"
    << "______________________________\n";
    return o;
}
