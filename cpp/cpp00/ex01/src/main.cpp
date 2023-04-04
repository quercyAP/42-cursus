/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 09:35:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/04 15:56:51 by glamazer         ###   ########.fr       */
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
			if (std::cin.e())
				std::cin.ignore();
		} while (command.empty());
		if (command == "ADD")
		{
			Contact contact;
			std::string first_name, last_name, nickname, phone_number, darkest_secret;
			do
			{
				std::cout << "Enter First Name: ";
				std::getline(std::cin, first_name);
			} while (first_name.empty());
			do
			{
				std::cout << "Enter Last Name: ";
				std::getline(std::cin, last_name);
			} while (last_name.empty());
			do
			{
				std::cout << "Enter Nickname: ";
				std::getline(std::cin, nickname);
			} while (nickname.empty());
			do
			{
				std::cout << "Enter Phone Number: ";
				std::getline(std::cin, phone_number);
			} while (phone_number.empty());
			do
			{
				std::cout << "Enter Darkest Secret ";
				std::getline(std::cin, darkest_secret);	
			} while (darkest_secret.empty());
			contact.set_contact_info(first_name, last_name, nickname, phone_number, darkest_secret);
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.display_contact_list();
			std::string index;
			do
			{
				std::cout << "Enter the contact index: ";
				std::getline(std::cin, index);
			} while (index.empty());
			phonebook.display_contact_info(std::stoi(index));
		}
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}