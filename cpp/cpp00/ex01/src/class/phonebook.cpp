/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:57:59 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/04 10:16:08 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/includes.h"

PhoneBook::PhoneBook() : contact_count(0)
{
	this->speech[0] = "Enter First Name: ";
	this->speech[1] = "Enter Last Name: ";
	this->speech[2] = "Enter Nickname: ";
	this->speech[3] = "Enter Phone Number: ";
	this->speech[4] = "Enter Darkest Secret: ";
	this->speech[5] = "Enter the contact index: ";
} 

std::string check_length(const std::string& text, size_t max_length) {
    if (text.length() <= max_length)
        return text;
    return text.substr(0, max_length - 1) + ".";
}

static bool	is_num(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (false);
	}
	return (true);
}

static bool max_range(std::string &str)
{
	if (!str.empty())
	{
		long long num = std::stoll(str);
		if (num > INT_MAX)
			return (false);
	}
	return (true);
}

std::string	user_loop(std::string &speech)
{
	std::string data;
	bool input;

	do
	{
		input = true;
		std::cout << speech;
		std::getline(std::cin, data);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (speech == "Enter Phone Number: " && !is_num(data))
		{
			std::cout << "Only number." << std::endl;
			input = false;
		}
		else if (speech == "Enter the contact index: " && (!is_num(data) || !max_range(data)))
		{
			std::cout << "Only number in range of [0-7]." << std::endl;
			input = false;
		}
	} while (data.empty() || !input);

	return (data);
}

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

void PhoneBook::display_contact_list()
{
    std::cout << " ___________________________________________" << std::endl;
    std::cout << "|     Index|" << std::setw(10) << "First Name|"
              << std::setw(10) << " Last Name|" << std::setw(10) << "  Nickname|" << std::endl;
    for (int i = 0; i < contact_count; i++)
	{
        std::cout << "|" << std::setw(10) << i << "|"
                  << std::setw(10) << check_length(contacts[i].get_fisrt_name(), 10) << "|"
                  << std::setw(10) << check_length(contacts[i].get_last_name(), 10) << "|"
                  << std::setw(10) << check_length(contacts[i].get_nickname(), 10) << "|" << std::endl;
    }
}

void	PhoneBook::display_contact_info(int index)
{
	if (index >= 0 && index < contact_count)
		contacts[index].display_contact_info();
	else
		std::cout << "Invalid contact index." << std::endl;
}

std::string	*PhoneBook::add_routine()
{
	for (int i = 0; i < 5; i++)
		this->data[i] = user_loop(this->speech[i]);
	return (data);
}

int	PhoneBook::search_routine()
{
	return std::stoi(user_loop(this->speech[5]));
}