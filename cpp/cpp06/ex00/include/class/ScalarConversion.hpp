/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:44:26 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 16:46:23 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>
# include <limits>
# include <cstdlib>
# include <cfloat>
# include <cmath>
# include <stdexcept>

class ScalarConversion
{
private:
    std::string _str;
    double _doubleValue;
    bool _isPseudoLiteral;

public:
    ScalarConversion(const std::string &str);
    void printChar() const;
    void printInt() const;
    void printFloat() const;
    void printDouble() const;    
};

#endif