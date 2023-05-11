/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:29:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 19:46:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	_name = "default";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const &src ) : ClapTrap( src ) 
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack( const std::string &target )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << _name << " is dead or has no energy!" << std::endl;
}

void FragTrap::highFiveGuys( void )
{
	if ( _hitPoints > 0)
		std::cout << "FragTrap " << _name << " wait for high five !" << std::endl;
	else
		std::cout << _name << " is dead" << std::endl;
}

FragTrap&	FragTrap::operator=( FragTrap const & copy )
{
	if (this != &copy)
	{
		_name = copy.getName();
		_hitPoints = copy.getHitPoints();
		_energyPoints = copy.getEnergyPoints();
		_attackDamage = copy.getAttackDamage();
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}
