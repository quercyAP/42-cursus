/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:36:41 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 14:01:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form("RobotomyRequestForm", 72, 45), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy) {
        Form::operator=(copy);
        target = copy.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->getGradeExec())
        throw GradeTooLowException();
    else if (this->getIsSigned() == false)
        throw FormNotSignedException();
    else {
        std::cout << "<Drill sound>ShRinK !!!##4$4 DOM!!!<Drill sound>" << std::endl;
        if (rand() % 2 == 0)
            std::cout << this->target<< " has been robotomized successfully." << std::endl;
        else
            std::cout << this->target << " has failed to be robotomized." << std::endl;
    }
}