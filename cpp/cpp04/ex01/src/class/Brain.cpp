/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:30:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/10 14:47:14 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Brain.hpp"

Brain::Brain() {}

Brain::Brain( Brain const &src)
{
	if (this != &src)
		*this = src;
}

Brain::~Brain( void ) {}

Brain &Brain::operator=( Brain const &copy )
{
	for (size_t i = 0; i < ideas->length(); i++)
		ideas[i] = copy.ideas[i];
	return *this;
}
