/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/31 01:30:03 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::string defaultNameFormShruberry = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm(defaultNameFormShruberry, 145, 137) {
    // std::cout << "[ShrubberyCreationForm]Default constructor called\n";
    this->setTarget("NO-TARGET");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm(defaultNameFormShruberry, 145, 137){
    // std::cout << "[ShrubberyCreationForm] called constructor with parameters\n";
    this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    // std::cout << "[ShrubberyCreationForm]Destructor called.\n";
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj){
    this->setSigned(obj.getSigned()); 
    return (*this);
}

std::string ShrubberyCreationForm::treeASCII(void) const{
	return("_________0________\n________000_______\n_______00000______\n______0000000_____\n_____000000000____\n________| |_______\n");
}

void ShrubberyCreationForm::_createFile(void) const{
    std::string nameFile = this->getTarget() + "_shrubbery";
    std::fstream file;
    file.open(nameFile.c_str(), std::fstream::out);
    if (file.is_open()){
        file << this->treeASCII() << this->treeASCII();
        file.close();
        std::cout << "File named " << nameFile << " has been created successfully!";
    }
    else{
        std::cout  << "Unable to create file named" << nameFile;
    }
}

void ShrubberyCreationForm::action(void) const{
    this->_createFile();
}

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm &obj){
    o << "__________DATA  SHRUBBERYCREATIONFORM__________\n" 
    << "Name: " << obj.getName() << "\n"
    << "Target: " << obj.getTarget() << "\n"
    << "Grade Signed: " << obj.getGradeSign() << "\n"
    << "Grade Execute: " << obj.getGradeExecute() << "\n"
    << "Is Valid: " << (obj.getValid() ? "True" : "False") << "\n"
    << "Is Signed: " << (obj.getSigned() ? "True" : "False") << "\n"
    << "______________________________\n";
    return o;
}
