/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::insert_first_name(void){
    std::string first_name;

    std::cout << "First Name: ";
    std::getline(std::cin, first_name);
    this->contacts[this->numContactsUse].set_first_name(first_name);
}

void PhoneBook::insert_last_name(void){
    std::string last_name;
    std::cout << "Last Name: ";
    std::getline(std::cin, last_name);
    this->contacts[this->numContactsUse].set_last_name(last_name);
}

void PhoneBook::insert_nickname(void){
    std::string nickname;

    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    this->contacts[this->numContactsUse].set_nickname(nickname);
}

void PhoneBook::insert_phone(void){
    std::string phone;

    std::cout << "Phone Number: ";
    std::getline(std::cin, phone);
    this->contacts[this->numContactsUse].set_phone_number(phone);
}

void PhoneBook::insert_darkest_secret(void){
    std::string darkest_secret;

    std::cout << "Darkest Secret: ";
    std::getline(std::cin, darkest_secret);
    this->contacts[this->numContactsUse].set_darkest_secret(darkest_secret);
}

void PhoneBook::select_contact(void){
   std::string input;
   int select;

   std::cout << "\nInsert contact index: ";
   std::getline(std::cin, input);
   select = atoi(input.c_str());
   if (select <= 0 || select > this->numContactsUse){
      std::cout << "\nContact not found! \n";
   }
   else{
       std::cout << "\nFirst Name: " << this->contacts[select - 1].get_first_name() << "\n";
       std::cout << "Last Name: " << this->contacts[select - 1].get_last_name() << "\n";
       std::cout << "Nickname: " << this->contacts[select - 1].get_nickname() << "\n";
       std::cout << "Phone number: " << this->contacts[select - 1].get_phone_number() << "\n";
       std::cout << "Darkest secret: " << this->contacts[select - 1].get_darkest_secret() << "\n";
   }
}

void PhoneBook::search(void){
    int count;
    int limit;

    count = -1;
    limit = this->numContactsUse;
    if (this->is_full_contact)
        ++limit;
    std::cout << "\n     index|first name| last name|  nickname|\n";
    while (++count < limit){
        this->contacts[count].show_contact(count + 1);
        std::cout << "\n";
    }
    this->select_contact();
}

void PhoneBook::move_all_contacts(void){
    int count;

    count = -1;
    while (++count < 7){
        this->contacts[count].set_first_name(this->contacts[count + 1].get_first_name());
        this->contacts[count].set_last_name(this->contacts[count + 1].get_last_name());
        this->contacts[count].set_nickname(this->contacts[count + 1].get_nickname());
        this->contacts[count].set_phone_number(this->contacts[count + 1].get_phone_number());
        this->contacts[count].set_darkest_secret(this->contacts[count + 1].get_darkest_secret());
    }
}

void PhoneBook::add(void)
{
    if (this->is_full_contact)
        this->move_all_contacts();
    this->insert_first_name();
    this->insert_last_name();
    this->insert_nickname();
    this->insert_darkest_secret();
    this->insert_phone();
    if (this->numContactsUse == 7)
        this->is_full_contact = true;
    if (this->numContactsUse < 7)
        this->numContactsUse += 1;
    std::cout << "Registration Successfully Complete!!!!\n";
}

PhoneBook::PhoneBook(void){
    int count;

    count = -1;
    while(++count < 8)
        this->contacts[count] = *(new Contact());
    this->numContactsUse = 0;
    this->is_full_contact = false;
}