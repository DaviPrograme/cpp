/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name(std::string fn){
    this->first_name = fn;   
}

std::string Contact::get_first_name(void){
    return this->first_name;
}

void Contact::set_last_name(std::string ln){
    this->last_name = ln;  
}

std::string Contact::get_last_name(void){
    return this->last_name;
}

void Contact::set_nickname(std::string nn){
    this->nickname = nn; 
}

std::string Contact::get_nickname(void){
    return this->nickname;
}

 void Contact::set_phone_number(std::string pn){
     this->phone_number = pn;
 }

 std::string Contact::get_phone_number(void){
     return this->phone_number;
 }

 void Contact::set_darkest_secret(std::string dk){
     this->darkest_secret = dk;
 }

  std::string Contact::get_darkest_secret(void){
      return this->darkest_secret;
  }

  static void show_string(std::string str){
      int len;

      len = str.length();
      if (len > 10) {
            std::cout << str.substr(0, 9);
            std::cout << '.';
      }
      else 
        std::cout << std::setw(10) << str;
      std::cout << '|';
  }

  void Contact::show_contact(int index){
      std::cout << std::setw(10) << index << '|';
      show_string(this->get_first_name());
      show_string(this->get_last_name());
      show_string(this->get_nickname());
  }

 Contact::Contact(){
     this->set_first_name("");
     this->set_last_name("");
     this->set_nickname("");
     this->set_phone_number("");
     this->set_darkest_secret("");
 }