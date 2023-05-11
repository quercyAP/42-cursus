/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:28:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 14:30:13 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Cat.hpp"
#include "../include/class/Dog.hpp"

int main()
{
	Animal *refuge[10];
	
	for (int i = 0; i < 5; i++)
		refuge[i] = new Cat();
	for (int i = 5; i < 10; i++)
		refuge[i] = new Dog();
	
	refuge[9] = refuge[8];
	for (int i = 0; i < 10; i++)
		delete refuge[i];
	
	return 0;
}