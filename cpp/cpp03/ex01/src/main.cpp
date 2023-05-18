/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:23:48 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 11:13:07 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/ScavTrap.hpp"

int main(void)
{
	// Test default constructor
	ClapTrap ClapTrap1;
	ScavTrap ScavTrap1;

	// Test constructor with name
	ScavTrap ScavTrap2("Bob2");
	
	// Test copy constructor
	ScavTrap ScavTrap3(ScavTrap2);
	
	// Test assignment operator
	ScavTrap1 = ScavTrap3;

	// Test getName()
	std::cout << "ScavTrap1 name: " << ScavTrap1.getName() << std::endl;
	
	// Test attack()
	ScavTrap1.attack("enemy");
	std::cout << "ScavTrap1 energy points: " << ScavTrap1.getEnergyPoints() << std::endl;

	// Test takeDamage()
	ScavTrap1.takeDamage(5);
	std::cout << "ClapTrap1 hit points: " << ScavTrap1.getHitPoints() << std::endl;

	// Test beRepaired()
	ScavTrap1.beRepaired(3);
	std::cout << "ScavTrap1 hit points: " << ScavTrap1.getHitPoints() << std::endl;
	std::cout << "ScavTrap1 energy points: " << ScavTrap1.getEnergyPoints() << std::endl;

	// Test guardGate()
	ScavTrap1.guardGate();
	
	return 0;
}