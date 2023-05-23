/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:31:42 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 15:06:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Form* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

Form* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

Form* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string name, std::string target) {
    const FormCreationMapEntry formCreationMap[] = {
            {"shrubbery creation", &createShrubberyCreationForm},
            {"robotomy request", &createRobotomyRequestForm},
            {"presidential pardon", &createPresidentialPardonForm}
    };
    for (int i = 0; i < 3; i++) {
        if (name == formCreationMap[i].formName) {
            return formCreationMap[i].formCreationFunc(target);
        }
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}