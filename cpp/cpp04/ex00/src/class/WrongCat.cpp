/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:16:34 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 09:17:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( WrongCat const &src ) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor constructor called" << std::endl;
}

WrongCat &WrongCat::operator=( WrongCat const &copy)
{
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaouuuuu" << std::endl;
}