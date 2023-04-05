/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:01:23 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 15:00:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Zombie.h"

Zombie::Zombie()
{
	std::cout << "zombie was created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "zombie " + this->name + " delete" << std::endl;
}

void	Zombie::anounce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ.." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}

std::string	Zombie::getName()
{
	return this->name;
}
