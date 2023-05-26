/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:45:12 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 13:42:26 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <iostream>

class RPN {
    public:
        double calculate(const std::string& expression);
    private:
        bool is_operator(const std::string& token);
        double apply_operator(const std::string& token, double operand1, double operand2);
};

#endif
