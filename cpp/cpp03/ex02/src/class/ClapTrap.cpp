/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:02:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 10:02:45 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/ClapTrap.hpp"

#pragma region Constructors & Destructors
ClapTrap::ClapTrap( void ) : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &src ) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
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
	return (_name);
}

int	ClapTrap::getHitPoints( void ) const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints( void ) const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage( void ) const
{
	return (_attackDamage);
}
#pragma endregion

#pragma region Member Functions
void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is dead or has no energy!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
	}
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is dead or has no energy!" << std::endl;
}

#pragma endregion


#pragma region Overload
ClapTrap&	ClapTrap::operator=( ClapTrap const & copy )
{
	if (this != &copy)
	{
		_name = copy.getName();
		_hitPoints = copy.getHitPoints();
		_energyPoints = copy.getEnergyPoints();
		_attackDamage = copy.getAttackDamage();
		std::cout << "ClapTrap copy assignment operator called" << std::endl;
	}
	return (*this);
}
#pragma endregion