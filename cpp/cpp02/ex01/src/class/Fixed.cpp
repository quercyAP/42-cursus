/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:12:42 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/05 14:06:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../../include/class/Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nb)
{
	this->value = nb << bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nb)
{
	this->value = roundf(nb * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &nb)
{
	out << nb.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		this->value = copy.getRawBits();
	}
	return *this;
}
