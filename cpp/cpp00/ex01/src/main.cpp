/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:35:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 11:19:21 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		do
		{
			std::cout << "Enter a command (ADD, SEARCH, or EXIT): ";
			std::getline(std::cin, command);
			if (std::cin.eof())
			{
				std::cin.clear();
				std::clearerr(stdin);
				std::cout << std::endl;
			}
		}
		while (command.empty());
		if (command == "ADD")
		{
			Contact contact;
			
			contact.set_contact_info(phonebook.add_routine());
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.display_contact_list();
			phonebook.display_contact_info(phonebook.search_routine());
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}