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

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "includes.hpp"
# include "AForm.hpp"

class AForm;

class Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(int grade);
        Bureaucrat(std::string name, int grade);
        Bureaucrat(int grade, std::string name);
        Bureaucrat(Bureaucrat &obj);
        Bureaucrat& operator=(Bureaucrat &obj);
        ~Bureaucrat();
        std::string getName(void) const;
        void setGrade(int grade);
        int getGrade(void) const;
        void upGrade(void);
        void downGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm &form);
        class GradeTooHighException : public std::exception {
            const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what(void) const throw();
        };
    private:
        const std::string _name;
        int _grade;
        void _checkHighGrade(void);
        void _checkLowGrade(void);

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat &obj);


#endif