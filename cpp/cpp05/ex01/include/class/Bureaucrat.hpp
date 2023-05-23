/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:58:42 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 11:22:19 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>
#include <iostream>
#include "Form.hpp"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;

    public:
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };


        Bureaucrat();
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        
        std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &form);
        
        Bureaucrat &operator=(const Bureaucrat &copy);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
