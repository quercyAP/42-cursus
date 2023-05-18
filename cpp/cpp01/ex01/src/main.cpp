/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:19:10 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 15:42:36 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.h"

int	main(void)
{
	Zombie *horde = zombieHorde(5, "toto");
	
	for (int i = 0; i < 5; i++)
		horde[i].anounce();

	delete[] horde;
}