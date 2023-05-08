/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/08 16:45:53 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/ClapTrap.hpp"

#pragma region Constructors & Destructors
ClapTrap::ClapTrap( void ) : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : name(src.name), hitPoints(src.hitPoints), energyPoints(src.energyPoints), attackDamage(src.attackDamage)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called" << std::endl;
}
#pragma endregion

#pragma region Getters & Setters
std::string	ClapTrap::getName( void ) const
{
	return (name);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (hitPoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (energyPoints);
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (attackDamage);
}
#pragma endregion

#pragma region Member Functions
void	ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is dead or has no energy!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is dead or has no energy!" << std::endl;
}

#pragma endregion


#pragma region Overload
ClapTrap&	ClapTrap::operator=( ClapTrap const & copy )
{
	if (this != &copy)
	{
		name = copy.getName();
		hitPoints = copy.getHitPoints();
		energyPoints = copy.getEnergyPoints();
		attackDamage = copy.getAttackDamage();
		std::cout << "ClapTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}
#pragma endregion