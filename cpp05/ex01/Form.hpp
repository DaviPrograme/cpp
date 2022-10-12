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

#ifndef FORM_HPP
# define FORM_HPP
# include "includes.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    public:
        Form();
        Form(std::string name, int gradeSign, int gradeExecute);
        Form(Form &obj);
        Form& operator=(Form &obj);
        ~Form();
        std::string getName(void) const;
        int getGradeSign(void) const;
        int getGradeExecute(void) const;
        void setSigned(bool status);
        bool getSigned(void) const;
        void setValid(bool status);
        bool getValid(void) const;
        void beSigned(Bureaucrat &b);
        class GradeTooHighException : public std::exception {
            const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what(void) const throw();
        };
    private:
        const std::string _name;
        const int _gradeSign;
        const int _gradeExecute;
        bool _isSigned;
        bool _isValid;
        void _checkGrades(void);
};

std::ostream& operator<<(std::ostream& o, const Form &obj);


#endif