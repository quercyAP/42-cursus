/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:31:13 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 15:39:21 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.h"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde = new Zombie[n];
	
	for (int i = 0; i < n; i++)
		horde[i].setName(name);
	return (horde);
}