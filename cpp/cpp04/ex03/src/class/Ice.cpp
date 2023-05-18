/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:50:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 15:52:53 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Ice.hpp"

Ice::~Ice( void ) {}

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice( Ice const &src)
{
	*this = src;
}

AMateria *Ice::clone( void ) const
{
	return (new Ice(*this));
}

void Ice::use( ICharacter &target ) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=( Ice const &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}