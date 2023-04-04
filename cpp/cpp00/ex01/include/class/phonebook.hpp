/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:42:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/04 11:57:50 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int	contact_count;

	public:
		PhoneBook();
		void add_contact(Contact &contact);
		void display_contact_list();
		void display_contact_info(int index);
};
