/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:03:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 12:06:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Bureaucrat.hpp"

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main() {
    printWithBorder("Form toto gradeToSign 151, gradeToExecute 0");
    try {
        Form toto("toto", 151, 0);
    } catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    
    printWithBorder("Form tata gradeToSign 0, gradeToExecute 151");
    try {
        Form tata("tata", 0, 151);
    } catch (std::exception &except) {
        std::cerr << except.what() << std::endl;
    }
    try {
        printWithBorder("Bureaucrat bob grade 75 sign Form tutu gradeToSign 100");    
        Bureaucrat bob("Bob", 75);
        Form tutu("tutu", 100, 50);
        std::cout << tutu << std::endl;
        bob.signForm(tutu);
        std::cout << tutu << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
