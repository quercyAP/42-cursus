/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:45:15 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 13:56:09 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/RPN.hpp"

bool RPN::is_operator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::apply_operator(const std::string& token, double operand1, double operand2) {
    if (token == "+") return operand1 + operand2;
    else if (token == "-") return operand1 - operand2;
    else if (token == "*") return operand1 * operand2;
    else if (token == "/") {
        if (operand2 == 0)
            throw std::invalid_argument("Error: Division by zero");
        return operand1 / operand2;
    }
    throw std::invalid_argument("Error: Unknown operator");
}

double RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;
    std::stack<double> values;
    
    while (iss >> token) {
        if (is_operator(token)) {
            if (values.size() < 2)
                throw std::invalid_argument("Error: Not enough operands");
            double operand2 = values.top(); values.pop();
            double operand1 = values.top(); values.pop();
            values.push(apply_operator(token, operand1, operand2));
        } else { 
            values.push(std::stod(token));
        }
    }
    
    if (values.size() != 1)
        throw std::invalid_argument("Error: More than one value in the stack");
        
    return values.top();
}
