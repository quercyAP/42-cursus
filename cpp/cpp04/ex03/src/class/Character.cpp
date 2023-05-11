/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:06:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:14:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Character.hpp"

Character::Character( std::string const &name ) : _name(name) {}

Character::~Character( void )
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

std::string const &Character::getName( void ) const
{
	return (this->_name);
}

void Character::equip( AMateria *m )
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
	{
		if (_inventory[i] != NULL)
		{
			_inventory[i] = m->clone();
			return ;
		}
	}
}

void Character::unequip( int idx )
{
	if (idx >= 0 && idx < MAX_INVENTORY_SIZE && _inventory[idx])
	{
		delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

void Character::use( int idx, ICharacter &target ) const
{
	if (idx >= 0 && idx < MAX_INVENTORY_SIZE && _inventory[idx])
		_inventory[idx]->use(target);
}
