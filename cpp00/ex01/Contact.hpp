/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoreira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:00:35 by dmoreira          #+#    #+#             */
/*   Updated: 2020/02/13 18:01:49 by dmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "includes.hpp"

class Contact{
    public:
        void set_first_name(std::string fn);
        std::string get_first_name(void);
        void set_last_name(std::string ln);
        std::string get_last_name(void);
        void set_nickname(std::string nn);
        std::string get_nickname(void);
        void set_phone_number(std::string pn);
        std::string get_phone_number(void);
        void set_darkest_secret(std::string ds);
        std::string get_darkest_secret(void);
        void show_contact(int index);
        Contact(void);
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
};

#endif
