/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2022/04/10 19:27:32 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversor.hpp"

Conversor::Conversor() {
	this->isNumber = false;
	this->isLiteral = false;
}


Conversor::Conversor(Conversor &obj){
	*this = obj;
}

Conversor::~Conversor(){
    return;
}

Conversor& Conversor::operator=(Conversor &obj){
    this->isNumber = obj.getIsNumber();
	this->isLiteral = obj.getIsLiteral();
	return (*this);
}

bool Conversor::getIsNumber(void){
	return this->isNumber;
}

bool Conversor::getIsLiteral(void){
	return this->isLiteral;
}

std::string Conversor::convertToInt(std::string str){
	std::stringstream output;
	
	if (!(this->isNumber) && str.length() > 1)
		return "impossible";
	if (!(this->isNumber) && str.length() == 1){
		output << static_cast<int>(str[0]);
		return output.str();
	}
	long int number = atol(str.c_str());
	if (number < INT_MIN || number > INT_MAX)
		return (number < INT_MIN ? "underflow" : "overflow");
	output << number;
	return output.str();
}

std::string Conversor::convertToDouble(std::string str){
	std::stringstream output;
	
	if (this->isLiteral)
		return this->convertLiteralToDouble(str);
	if (!(this->isNumber) && str.length() > 1)
		return "impossible";
	if (!(this->isNumber) && str.length() == 1){
		output << std::fixed << std::setprecision(1) << static_cast<double>(str[0]);
		return (output.str());
	}
	double number = atof(str.c_str());
	if (number > DBL_MAX || number < -DBL_MAX)
		return (static_cast<char>(str[0]) == '-' ? "underflow" : "overflow");
	output << std::fixed << std::setprecision(1) << number;
	return (output.str());
}

std::string Conversor::convertToFloat(std::string str){
	std::stringstream output;
	
	if (this->isLiteral)
		return this->convertLiteralToFloat(str);
	if (!(this->isNumber) && str.length() > 1)
		return "impossible";
	if (!(this->isNumber) && str.length() == 1){
		output << std::fixed << std::setprecision(1) << static_cast<float>(str[0]);
		return (output.str() + "f");
	}
	float number = static_cast<float>(atof(str.c_str()));
	if (number > FLT_MAX || number < -FLT_MAX)
		return (static_cast<char>(str[0]) == '-' ? "underflow" : "overflow");
	output << std::fixed << std::setprecision(1) << number;
	return (output.str() + "f");
}

std::string Conversor::convertToChar(std::string str){
	std::string ret;
	if (!(this->isNumber) && str.length() > 1)
		return "impossible";
	if (!(this->isNumber) && str.length() == 1)
		return '\'' + str + '\'';
	long int number = atol(str.c_str());
	if (number >= 32 && number <= 126){
		ret.append(1, static_cast<char>(number));
		return '\'' + ret + '\'';
	}
	return "Non displayable";
}

void Conversor::convertToTypes(std::string str){
	this->isNumber = this->checkIsNumber(str);
	this->isLiteral = this->checkIsLiteral(str);
	std::cout << "char: " << this->convertToChar(str) << "\n";
	std::cout << "int: " << this->convertToInt(str) << "\n";
	std::cout << "float: " << this->convertToFloat(str) << "\n";
	std::cout << "double: " << this->convertToDouble(str) << "\n";
}

bool Conversor::checkIsNumber(std::string str){
	int index = -1;
	bool isPoint = false;
	std::string charPoint = ".";
	std::string charTrace = "-";
	std::string floatIdentifier = "f";
	
	while(str[++index]){
		if (!index && str[index] == charTrace[0] && str.length() > 1)
			continue;
		if (isdigit(static_cast<char>(str[index])))
			continue;
		if (str[index] == charPoint[0] && !isPoint && str.length() > 1){
			isPoint = true;
			continue;
		}
		if(index == static_cast<int>(str.length()) - 1 && str[index] == floatIdentifier[0] && isPoint)
			continue;
		return false;
	} 
	return true;
}

bool Conversor::checkIsLiteral(std::string str){
	if(!(str.compare("+inf")))
		return true;
	else if(!(str.compare("+inff")))
		return true;
	else if(!(str.compare("-inf")))
		return true;
	else if(!(str.compare("-inff")))
		return true;
	else if(!(str.compare("nan")))
		return true;
	else if(!(str.compare("nanf")))
		return true;
	return false;
}

std::string Conversor::convertLiteralToDouble(std::string str){
	if(!(str.compare("+inf")) || !(str.compare("+inff")))
		return "+inf";
	else if(!(str.compare("-inf")) || !(str.compare("-inff")))
		return "-inf";
	return "nan";
}

std::string Conversor::convertLiteralToFloat(std::string str){
	if(!(str.compare("+inf")) || !(str.compare("+inff")))
		return "+inff";
	else if(!(str.compare("-inf")) || !(str.compare("-inff")))
		return "-inff";
	return "nanf";
}