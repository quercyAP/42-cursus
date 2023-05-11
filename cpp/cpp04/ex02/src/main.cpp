/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:22:55 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/11 21:24:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Cat.hpp"
#include "../include/class/Dog.hpp"
#include <iostream>

int main()
{
    Animal *refuge[10];
    
    std::cout << BLUE << "---- Creating Cats ----" << RESET << std::endl;
    for (int i = 0; i < 5; i++)
        refuge[i] = new Cat();

    std::cout << BLUE << "---- Creating Dogs ----" << RESET << std::endl;
    for (int i = 5; i < 10; i++)
        refuge[i] = new Dog();

    std::cout << BLUE << "---- Deleting Animals ----" << RESET << std::endl;
    for (int i = 0; i < 10; i++)
        delete refuge[i];
    
    std::cout << GREEN << "---- Creating Original Dog ----" << RESET << std::endl;
    Dog original;
    original.getBrain()->addIdea("Hello");

    std::cout << GREEN << "---- Original Dog's Ideas ----" << RESET << std::endl;
    original.getBrain()->printIdeas();

    std::cout << YELLOW << "---- Creating Copy of Original Dog ----" << RESET << std::endl;
    Dog copy = original;

    std::cout << YELLOW << "---- Copy Dog's Ideas ----" << RESET << std::endl;
    copy.getBrain()->printIdeas();

    std::cout << RED << "---- Adding Idea to Copy Dog ----" << RESET << std::endl;
    copy.getBrain()->addIdea("toto");

    std::cout << RED << "---- Original Dog's Ideas After Copy Dog Added Idea ----" << RESET << std::endl;
    original.getBrain()->printIdeas();
    

    return 0;
}
