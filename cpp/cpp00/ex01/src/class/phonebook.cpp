/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:57:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/04 12:20:15 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

PhoneBook::PhoneBook() : contact_count(0) {}

void	PhoneBook::add_contact(Contact &contact)
{
	if (contact_count < 8)
	{
		contacts[contact_count] = contact;
		contact_count++;
	}
	else
	{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = contact;
	}
}

void	PhoneBook::display_contact_list()
{
	std::cout << std::setw(10) << "Index|" << std::setw(10) << "First Name|"
				<< std::setw(10) << "Last Name|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		std::cout << std::setw(10) << i << '|'
				<< std::setw(10) << contacts[i].get_fisrt_name().substr(0, 9) << '|'
				<< std::setw(10) << contacts[i].get_last_name().substr(0, 9) << '|'
				<< std::setw(10) << contacts[i].get_nickname().substr(0, 9) << std::endl;
	}
}

void	PhoneBook::display_contact_info(int index)
{
	if (index >= 0 && index < contact_count)
		contacts[index].display_contact_info();
	else
		std::cout << "Invalid contact index." << std::endl;
}
