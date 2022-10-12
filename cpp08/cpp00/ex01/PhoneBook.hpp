/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "includes.hpp"
# include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook(void);
        void add(void);
        void search(void);
    private:
        Contact contacts[8];
        int numContactsUse;
        bool is_full_contact;
        void insert_first_name(void);
        void insert_last_name(void);
        void insert_nickname(void);
        void insert_phone(void);
        void insert_darkest_secret(void);
        void move_all_contacts(void);
        void select_contact(void);
};

#endif