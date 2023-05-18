/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:25:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 08:54:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Cat.hpp"

Cat::Cat( void ) : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat( Cat const &src ) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor constructor called" << std::endl;
}

Cat &Cat::operator=( Cat const &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}