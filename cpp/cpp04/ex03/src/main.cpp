/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:26:46 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/12 16:11:43 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/IMateriaSource.hpp"
#include "../include/class/Character.hpp"
#include "../include/class/Ice.hpp"
#include "../include/class/Cure.hpp"
#include "../include/class/MateriaSource.hpp"


int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	me->unequip(3);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	
	AMateria *toto;
	AMateria *tata;
	
	toto = src->createMateria("Ice");
	tata = toto;
	
	me->equip(tata);
	me->use(3, *bob);
	
	delete bob;
	delete me;
	delete src;
	return 0;
}