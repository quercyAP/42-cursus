/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:31:53 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/23 15:06:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
    private:
        struct FormCreationMapEntry {
            const char* formName;
            Form* (*formCreationFunc)(const std::string&);
        };
        
    public:
        Intern(void);
        ~Intern(void);

        Form *makeForm(std::string name, std::string target);
};

#endif