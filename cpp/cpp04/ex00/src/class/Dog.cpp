/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:35:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/09 15:44:16 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Dog.hpp"

Dog::Dog( void ) : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog( Dog const &src ) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor constructor called" << std::endl;
}

Dog &Dog::operator=( Dog const &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Wouuufffff" << std::endl;
}