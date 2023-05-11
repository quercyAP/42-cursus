/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MetariaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 22:19:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 22:35:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/MateriaSource.hpp"

MateriaSource::MateriaSource( void ) 
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		this->learnedMateria[i] = NULL;
}

MateriaSource::~MateriaSource( void )
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
		if (this->learnedMateria[i] != NULL)
			delete this->learnedMateria[i];
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
	{
		if (this->learnedMateria[i] == NULL)
		{
			this->learnedMateria[i] = materia->clone();
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < MAX_INVENTORY_SIZE; i++)
	{
		if (learnedMateria[i] && learnedMateria[i]->getType == type)
			return (learnedMateria[i]->clone());
	}
	return (NULL);
}