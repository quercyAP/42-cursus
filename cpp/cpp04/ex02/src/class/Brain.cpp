/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:30:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:03:46 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Brain.hpp"

Brain::Brain() : currentIdea(0) {}

Brain::Brain( Brain const &src)
{
	this->currentIdea = src.currentIdea;
	for (int i = 0; i < this->currentIdea; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::~Brain( void ) {}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy) 
	{
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return *this;
}

void Brain::addIdea( std::string idea )
{
	if (this->currentIdea < 100)
	{
		this->ideas[this->currentIdea] = idea;
		this->currentIdea++;
	}
}

void Brain::printIdeas( void ) const
{
	for (int i = 0; i < this->currentIdea; i++)
		std::cout << this->ideas[i] << std::endl;
}