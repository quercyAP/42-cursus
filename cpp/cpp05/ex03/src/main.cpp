/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:31:03 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 15:04:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Bureaucrat.hpp"
#include "../include/class/ShrubberyCreationForm.hpp"
#include "../include/class/RobotomyRequestForm.hpp"
#include "../include/class/PresidentialPardonForm.hpp"
#include "../include/class/Intern.hpp"

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main() {
    printWithBorder("Try to create an unknown form");
    Intern someRandomIntern;
    Form* rrf = someRandomIntern.makeForm("toto", "Bender");
    (void)rrf;
    
    try {
        printWithBorder("Try to create a ShrubberyCreationForm");
        Form* sf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        Bureaucrat bob("bob", 1);
        bob.signForm(*sf);
        bob.executeForm(*sf);
        delete sf;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }


    return 0;
}