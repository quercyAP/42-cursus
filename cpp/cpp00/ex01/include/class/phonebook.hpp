/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:42:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 12:13:25 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	contact_count;
		std::string speech[6];

	public:
		PhoneBook();
		void add_contact(Contact &contact);
		void display_contact_list();
		void display_contact_info(int index);
		std::string *add_routine();
		int search_routine();
};
