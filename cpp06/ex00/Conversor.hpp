/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/06 00:53:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "includes.hpp"
class Conversor {
    public:
		Conversor();
      	Conversor(Conversor &obj);
        Conversor& operator=(Conversor &obj);
        ~Conversor();
		bool getIsNumber(void);
		bool getIsLiteral(void);
		void convertToTypes(std::string str);
		std::string convertToInt(std::string str);
		std::string convertToDouble(std::string str);
		std::string convertToChar(std::string str);
		std::string convertToFloat(std::string str);
		bool checkIsLiteral(std::string str);
		bool checkIsNumber(std::string str);
		std::string convertLiteralToDouble(std::string str);
		std::string convertLiteralToFloat(std::string str);
    private:
		bool isNumber;
		bool isLiteral;
};
#endif