/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:50:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:54:27 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::~Ice( void ) {}

AMateria *Ice::clone( void ) const
{
	return (new Ice(*this));
}

void Ice::use( ICharacter &target ) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}