/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/03/30 03:12:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "includes.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm& operator=(RobotomyRequestForm &obj);
        ~RobotomyRequestForm();
        void action(void) const;
    private:
        RobotomyRequestForm();
};

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm &obj);


#endif