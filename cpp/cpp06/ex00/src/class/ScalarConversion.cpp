/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:37 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 16:47:24 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/ScalarConversion.hpp"



ScalarConversion::ScalarConversion(const std::string &str) : _str(str)
{
    // handle pseudo literals
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
        _doubleValue = std::nan("");
        _isPseudoLiteral = true;
    }
    else
    {
        try
        {
            _doubleValue = std::stod(_str);
            _isPseudoLiteral = false;
        }
        catch (std::exception &e)
        {
            _isPseudoLiteral = true; // if we can't convert the string to a number, consider it as a pseudo literal
        }
    }
}