/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:14:33 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 14:15:11 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/ScavTrap.hpp"
#include "../include/class/FragTrap.hpp"

int main(void)
{
	// Test default constructor
	ClapTrap ClapTrap1;
	FragTrap FragTrap1;

	// Test constructor with name
	FragTrap FragTrap2("Bob2");
	
	// Test copy constructor
	FragTrap FragTrap3(FragTrap2);
	
	// Test assignment operator
	FragTrap1 = FragTrap3;

	// Test getName()
	std::cout << "FragTrap1 name: " << FragTrap1.getName() << std::endl;
	
	// Test attack()
	FragTrap1.attack("enemy");
	std::cout << "FragTrap1 energy points: " << FragTrap1.getEnergyPoints() << std::endl;

	// Test takeDamage()
	FragTrap1.takeDamage(5);
	std::cout << "FragTrap1 hit points: " << FragTrap1.getHitPoints() << std::endl;

	// Test beRepaired()
	FragTrap1.beRepaired(3);
	std::cout << "FragTrap1 hit points: " << FragTrap1.getHitPoints() << std::endl;
	std::cout << "FragTrap1 energy points: " << FragTrap1.getEnergyPoints() << std::endl;

	// Test guardGate()
	FragTrap1.highFiveGuys();
	
	return 0;
}