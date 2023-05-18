/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 15:56:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/08 16:48:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/ClapTrap.hpp"

int main(void)
{
	// Test default constructor
	ClapTrap clapTrap1;

	// Test constructor with name
	ClapTrap clapTrap2("Bob");

	// Test copy constructor
	ClapTrap clapTrap3(clapTrap2);

	// Test assignment operator
	clapTrap1 = clapTrap3;

	// Test getName()
	std::cout << "ClapTrap1 name: " << clapTrap1.getName() << std::endl;

	// Test attack()
	clapTrap1.attack("enemy");
	std::cout << "ClapTrap1 energy points: " << clapTrap1.getEnergyPoints() << std::endl;
	
	// Test takeDamage()
	clapTrap1.takeDamage(5);
	std::cout << "ClapTrap1 hit points: " << clapTrap1.getHitPoints() << std::endl;
	
	// Test beRepaired()
	clapTrap1.beRepaired(3);
	std::cout << "ClapTrap1 hit points: " << clapTrap1.getHitPoints() << std::endl;
	std::cout << "ClapTrap1 energy points: " << clapTrap1.getEnergyPoints() << std::endl;

	return 0;
}