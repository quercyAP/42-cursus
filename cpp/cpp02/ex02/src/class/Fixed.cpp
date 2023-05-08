/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:12:42 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/07 18:53:36 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "../../include/class/Fixed.hpp"

const int Fixed::bits = 8;
// Constructeur / Destructeur
#pragma region
Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int nb)
{
	this->value = nb << bits;
}

Fixed::Fixed(const float nb)
{
	this->value = roundf(nb * (1 << bits));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed() {}
#pragma endregion

// Setter / Getter
#pragma region
int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(const int raw)
{
	this->value = raw;
}
#pragma endregion

// Methode
#pragma region
float Fixed::toFloat(void) const
{
	return (float)this->value / (1 << bits);
}

int Fixed::toInt(void) const
{
	return this->value >> bits;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

#pragma endregion

// Surcharge d'operateur
#pragma region
std::ostream &operator<<(std::ostream &out, const Fixed &nb)
{
	out << nb.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	if (this != &copy)
		this->value = copy.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &copy) const
{
	Fixed ret;
	ret.value = this->value + copy.value;
	return ret;
}

Fixed Fixed::operator-(const Fixed &copy) const
{
	Fixed ret;
	ret.value = this->value - copy.value;
	return ret;
}

Fixed Fixed::operator*(const Fixed &copy) const
{
	Fixed ret;
	long long tmp = (long long)this->value * (long long)copy.value;
	ret.value = (int)(tmp >> this->bits);
	return ret;
}

Fixed Fixed::operator/(const Fixed &copy) const
{
	if (copy.value == 0)
	{
		std::cerr << "Division par 0" << std::endl;
		return *this;
	}
	Fixed ret;
	long long tmp = ((long long)this->value << this->bits) / (long long)copy.value;
	ret.value = (int)(tmp);
	return ret;
}

Fixed Fixed::operator++(int)
{
	Fixed &copy(*this);
	this->value += 1;
	return copy;
}

Fixed &Fixed::operator++()
{
	this->value += 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed &copy(*this);
	this->value -= 1;
	return copy;
}

Fixed &Fixed::operator--()
{
	this->value -= 1;
	return *this;
}

bool Fixed::operator>(const Fixed &copy) const
{
	return this->value > copy.value;
}

bool Fixed::operator<(const Fixed &copy) const
{
	return this->value < copy.value;
}

bool Fixed::operator>=(const Fixed &copy) const
{
	return this->value >= copy.value;
}

bool Fixed::operator<=(const Fixed &copy) const
{
	return this->value <= copy.value;
}

bool Fixed::operator==(const Fixed &copy) const
{
	return this->value == copy.value;
}

bool Fixed::operator!=(const Fixed &copy) const
{
	return this->value != copy.value;
}

#pragma endregion
