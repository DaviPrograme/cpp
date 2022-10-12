/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/31 02:02:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void){
    std::cout << "1) test with ShrubberyCreationForm: \n\n";
    Bureaucrat bureaucrat(146);
    ShrubberyCreationForm form1("file1");
    std::cout << "\n   1.1) Attempt to sign the form without having the required grade: \n\n\n";
    std::cout << bureaucrat;
    bureaucrat.signForm(form1);
    std::cout << form1;
    std::cout << "\n   1.2) Attempt to sign the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(145);
    std::cout << bureaucrat;
    bureaucrat.signForm(form1);
    std::cout << form1;
    std::cout << "\n   1.3) Attempt to run the form without signing: \n\n\n";
    bureaucrat.setGrade(137);
    form1.setSigned(false);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form1);
    std::cout << form1;
    std::cout << "\n   1.4) Attempt to run the form without having the required grade: \n\n\n";
    bureaucrat.setGrade(138);
    form1.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form1);
    std::cout << form1;
    std::cout << "\n   1.5) attempt to run the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(137);
    form1.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form1);
    std::cout << form1;


    std::cout << "\n\n\n\n2) test with RobotomyRequestForm: \n\n";
    RobotomyRequestForm form2("file2");
    std::cout << "\n   2.1) Attempt to sign the form without having the required grade: \n\n\n";
    bureaucrat.setGrade(73);
    std::cout << bureaucrat;
    bureaucrat.signForm(form2);
    std::cout << form2;
    std::cout << "\n   2.2) attempt to sign the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(72);
    std::cout << bureaucrat;
    bureaucrat.signForm(form2);
    std::cout << form2;
    std::cout << "\n   2.3) Attempt to run the form without signing: \n\n\n";
    bureaucrat.setGrade(45);
    form2.setSigned(false);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form2);
    std::cout << form2;
    std::cout << "\n   2.4) attempt to run the form without having the required grade: \n\n\n";
    bureaucrat.setGrade(46);
    form2.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form2);
    std::cout << form2;
    std::cout << "\n   2.5) attempt to run the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(45);
    form2.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form2);
    std::cout << form2;
    std::cout << "\n   2.6) check behavior with multiple executions: \n\n\n";
    std::cout << bureaucrat;
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
    bureaucrat.executeForm(form2);
    std::cout << form2;


    std::cout << "\n\n\n\n3) test with PresidentialPardonForm: \n\n";
    PresidentialPardonForm form3("file3");
    std::cout << "\n   3.1) Attempt to sign the form without having the required grade: \n\n\n";
    bureaucrat.setGrade(26);
    std::cout << bureaucrat;
    bureaucrat.signForm(form3);
    std::cout << form3;
    std::cout << "\n   3.2) attempt to sign the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(25);
    std::cout << bureaucrat;
    bureaucrat.signForm(form3);
    std::cout << form3;
    std::cout << "\n   3.3) Attempt to run the form without signing: \n\n\n";
    bureaucrat.setGrade(5);
    form3.setSigned(false);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form3);
    std::cout << form3;
    std::cout << "\n   3.4) attempt to run the form without having the required grade: \n\n\n";
    bureaucrat.setGrade(6);
    form3.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form3);
    std::cout << form3;
    std::cout << "\n   3.5) attempt to run the form with the minimum required grade: \n\n\n";
    bureaucrat.setGrade(5);
    form3.setSigned(true);
    std::cout << bureaucrat;
    bureaucrat.executeForm(form3);
    std::cout << form3;

    return 0;
}