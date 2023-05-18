/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:35:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 20:58:19 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog( Dog const &src ) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor constructor called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=( Dog const &copy )
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

void Dog::makeSound() const
{
	std::cout << "Wouuufffff" << std::endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}

void Dog::setBrain( Brain *brain )
{
	this->brain = brain;
}
