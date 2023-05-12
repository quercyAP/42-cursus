/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:39:27 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 15:24:49 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/AMateria.hpp"

AMateria::AMateria() : type("default") {}

AMateria::AMateria( AMateria const &src ) : type(src.type) {}

AMateria::AMateria( std::string const &type ) : type(type) {}

AMateria::~AMateria( void ) {}

std::string const &AMateria::getType( void ) const
{
	return (this->type);
}

AMateria &AMateria::operator=( AMateria const &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return *this;
}