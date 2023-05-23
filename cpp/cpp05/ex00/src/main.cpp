/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:59:52 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 11:03:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/class/Bureaucrat.hpp"

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main() {
    printWithBorder("Bureaucrat grade 151");
    try {
        Bureaucrat john("John", 151);
    } catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    
    printWithBorder("Bureaucrat grade 0");
    try {
        Bureaucrat jane("Jane", 0);
    } catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    try {
        printWithBorder("Bureaucrat grade 75 and increment then decrement");    
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
        
        printWithBorder("Bureaucrat grade 1 and increment");    
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        alice.incrementGrade();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
