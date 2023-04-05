/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:58:57 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/05 15:05:42 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.h"

int	main(void)
{
	Zombie *toto = newZombie("toto");
	toto->anounce();
	randomChump("tata");
	delete toto;
}