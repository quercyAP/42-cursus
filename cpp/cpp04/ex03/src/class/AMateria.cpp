/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:39:27 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:49:26 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/AMateria.hpp"

AMateria::AMateria( std::string const &type ) : type(type) {}

AMateria::~AMateria( void ) {}

std::string const &AMateria::getType( void ) const
{
	return (this->type);
}