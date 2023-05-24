/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:37 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 19:06:29 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/ScalarConversion.hpp"

void ScalarConversion::printChar() const
{
    if (_isPseudoLiteral) {
        std::cout << "char: impossible" << std::endl;
    } else {
        int c = static_cast<int>(_doubleValue);
        if (_doubleValue == c && std::isprint(c)) {
            std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
}

void ScalarConversion::printInt() const
{
    if (_isPseudoLiteral) {
        std::cout << "int: impossible" << std::endl;
    } else {
        int i = static_cast<int>(_doubleValue);
        if (_doubleValue == i) {
            std::cout << "int: " << i << std::endl;
        } else {
            std::cout << "int: impossible" << std::endl;
        }
    }
}

void ScalarConversion::printFloat() const 
{
    if (_isPseudoLiteral) {
        std::cout << "float: " << _str << "f" << std::endl;
    } else {
        float f = static_cast<float>(_doubleValue);
        if (_doubleValue == f) {
            std::cout << "float: " << f;
            std::cout << (_doubleValue - static_cast<int>(_doubleValue) == 0 ? ".0" : "") << "f" << std::endl;
        } else {
            std::cout << "float: impossible" << std::endl;
        }
    }
}

void ScalarConversion::printDouble() const
{
    if (_isPseudoLiteral) {
        std::cout << "double: " << _str << std::endl;
    } else {
        std::cout << "double: " << _doubleValue;
        std::cout << (_doubleValue - static_cast<int>(_doubleValue) == 0 ? ".0" : "") << std::endl;
    }
}


ScalarConversion::ScalarConversion(const std::string &str) : _str(str)
{
    if (_str == "+inf" || _str == "+inff" || _str == "inf" || _str == "inff")
    {
        _doubleValue = std::numeric_limits<double>::infinity();
        _isPseudoLiteral = true;
    }
    else if (_str == "-inf" || _str == "-inff")
    {
        _doubleValue = -std::numeric_limits<double>::infinity();
        _isPseudoLiteral = true;
    }
    else if (_str == "nan" || _str == "nanf")
    {
        _doubleValue = 0.0 / 0.0;
        _isPseudoLiteral = true;
    }
    else
    {
        std::istringstream iss(_str);
        iss >> _doubleValue;
        if (iss.fail())
        {
            _isPseudoLiteral = true;
            _doubleValue = 0.0 / 0.0;
            }
            _isPseudoLiteral = false;
    }
}