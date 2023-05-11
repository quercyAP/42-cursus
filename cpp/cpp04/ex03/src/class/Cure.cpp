/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:57:12 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:57:51 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {}

Cure::~Cure( void ) {}

AMateria *Cure::clone( void ) const
{
	return (new Cure(*this));
}

void Cure::use( ICharacter &target ) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}