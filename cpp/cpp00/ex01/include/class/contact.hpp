/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:41:57 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/04 11:43:36 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	
	public:
		Contact();
		void set_contact_info(std::string &first_name, std::string &last_name, std::string &nickname,
								std::string &phone_number, std::string &darkest_secret);
		std::string get_fisrt_name();
		std::string get_last_name();
		std::string get_nickname();
		void display_contact_info();
};