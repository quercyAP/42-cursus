/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:44:36 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 14:06:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Bureaucrat.hpp"
#include "../include/class/ShrubberyCreationForm.hpp"
#include "../include/class/RobotomyRequestForm.hpp"
#include "../include/class/PresidentialPardonForm.hpp"

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main() {
    printWithBorder("START ERROR TEST");
    try {
        printWithBorder("Bureaucrat grade 150 try to sign and execute ShrubberyCreationForm");
        Bureaucrat bob("Bob", 150);
        std::cout << bob << std::endl;
        ShrubberyCreationForm olivier("Olivier");
        bob.signForm(olivier);
        bob.executeForm(olivier);
        printWithBorder("Bureaucrat grade 120 try to execute ShrubberyCreationForm not signed");
        Bureaucrat alice("Alice", 120);
        std::cout << alice << std::endl;
        alice.executeForm(olivier);
    }
    catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    printWithBorder("END ERROR TEST");
    
    
    
    try {
        printWithBorder("Bureaucrat grade 75 signed and execute ShrubberyCreationForm");    
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        ShrubberyCreationForm olivier("Olivier");
        bob.signForm(olivier);
        bob.executeForm(olivier);
        printWithBorder("Bureaucrat grade 30 signed and execute RobotomyRequestForm");
        Bureaucrat alice("Alice", 30);
        RobotomyRequestForm r2d2(bob.getName());
        std::cout << alice << std::endl;
        alice.signForm(r2d2);
        alice.executeForm(r2d2);
        printWithBorder("Bureaucrat grade 1 signed and execute PresidentialPardonForm");
        Bureaucrat jane("Jane", 1);
        std::cout << jane << std::endl;
        PresidentialPardonForm pardon(alice.getName());
        jane.signForm(pardon);
        jane.executeForm(pardon);
    }
    catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    
    return 0;
}
