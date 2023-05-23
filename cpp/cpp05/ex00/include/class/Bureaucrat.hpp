/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:58:42 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 08:02:53 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat {
public:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    Bureaucrat(std::string name, int grade);
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

private:
    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
