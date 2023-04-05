/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:01:12 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 14:47:20 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.h"

Zombie	*newZombie(std::string name)
{
	Zombie *newZombie = new Zombie;
	
	newZombie->setName(name);
	return (newZombie);
}