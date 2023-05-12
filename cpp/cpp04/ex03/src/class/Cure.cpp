/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:57:12 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 15:53:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Cure.hpp"

Cure::~Cure( void ) {}

Cure::Cure( void ) : AMateria("cure") {}

Cure::Cure( Cure const &src )
{
	*this = src;
}

AMateria *Cure::clone( void ) const
{
	return (new Cure(*this));
}

void Cure::use( ICharacter &target ) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure &Cure::operator=( Cure const &src)
{
	if (this != &src)
		this->type = src.type;
	return *this;
}