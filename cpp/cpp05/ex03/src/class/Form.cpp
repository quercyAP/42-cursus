/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:35:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 13:30:45 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Form.hpp"

#pragma region Constructors & Destructors
Form::Form() : _name("Default"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec) {}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1) {
        throw GradeTooHighException();
    }
    if (gradeSign > 150 || gradeExec > 150) {
        throw GradeTooLowException();
    }
}

Form::~Form() {}
#pragma enregion

#pragma region Getters & Setters
std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}
#pragma endregion

#pragma region Exception
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

const char* Form::FormNotSignedException::what() const throw() {
    return "Form not signed!";
}

#pragma endregion

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeSign) {
        throw GradeTooLowException();
    }
    else {
        this->_isSigned = true;
    }
}

Form& Form::operator=(const Form& copy) {
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << form.getName() << ", Form grade to sign " << form.getGradeSign() << \
    ", grade to execute " << form.getGradeExec() << ", is " << \
    (form.getIsSigned() ? "" : "not ") << "signed";
    return os;
}