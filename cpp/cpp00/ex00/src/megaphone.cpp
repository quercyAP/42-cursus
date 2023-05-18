/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:27:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/04 09:09:29by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cerr << "ERROR: Bad arguments" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
			{
				char c = std::toupper(str[j]);
				std::cout << c;
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}