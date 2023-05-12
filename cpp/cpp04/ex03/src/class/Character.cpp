/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 15:37:47 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_garbage[i] = NULL;
}

Character::Character( std::string const &name ) : _name(name)
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_garbage[i] = NULL;		
}

Character::Character( Character const &src )
{
	*this = src;
}

Character::~Character( void )
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		if (_inventory[i] != NULL)
			delete _inventory[i];
	for (int i = 0; i < 100; i++)
		if (_garbage[i] != NULL)
			delete _garbage[i];
}

std::string const &Character::getName( void ) const
{
	return (this->_name);
}

void Character::equip( AMateria *m )
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::add_to_garbage( AMateria *m )
{
	for (int i = 0; i < 100; i++)
	{
		if (_garbage[i] == NULL)
		{
			_garbage[i] = m;
			return ;
		}
	}
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < MAX_INVENTORY_SIZE && _inventory[idx])
	{
		add_to_garbage( _inventory[idx] );
		_inventory[idx] = NULL;
	}
}

void Character::use( int idx, ICharacter &target ) const
{
	if (idx >= 0 && idx < MAX_INVENTORY_SIZE && _inventory[idx])
		_inventory[idx]->use(target);
}

Character &Character::operator=( Character const &src)
{
	if (this != &src)
	{
		_name = src._name;
		for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
			_inventory[i] = src._inventory[i];
		for (int i = 0; i < 100; i++)
			_garbage[i] = src._garbage[i];
	}
	return *this;
}