/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include "includes.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    public:
        AForm();
        AForm(std::string name, int gradeSign, int gradeExecute);
        AForm(AForm &obj);
        AForm& operator=(AForm &obj);
        virtual ~AForm();
        std::string getName(void) const;
        int getGradeSign(void) const;
        int getGradeExecute(void) const;
        void setSigned(bool status);
        bool getSigned(void) const;
        void setValid(bool status);
        bool getValid(void) const;
        void beSigned(Bureaucrat &b);
        void execute(Bureaucrat const & executor) const;
        virtual void action(void) const = 0; 
        void setTarget(std::string target);
        std::string getTarget(void) const;
        void _checkGrades(void);
        void setCount(unsigned int count);
        unsigned int getCount(void) const;
        class GradeTooHighException : public std::exception {
            const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            const char *what(void) const throw();
        };
        class TryRunFormWithoutSignature : public std::exception {
            const char *what(void) const throw();
        };
    private:
        const std::string _name;
        const int _gradeSign;
        const int _gradeExecute;
        bool _isSigned;
        bool _isValid;
        unsigned int _count;
        std::string _target;
};

std::ostream& operator<<(std::ostream& o, const AForm &obj);


#endif