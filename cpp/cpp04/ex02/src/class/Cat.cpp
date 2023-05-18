/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:25:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 20:58:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat( Cat const &src ) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor constructor called" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=( Cat const &copy )
{
	if (this != &copy)
	{
		this->type = copy.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*copy.brain);
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}

void Cat::setBrain( Brain *brain )
{
	this->brain = brain;
}
