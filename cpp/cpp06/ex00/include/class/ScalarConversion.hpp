/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:44:26 by guigui            #+#    #+#             */
/*   Updated: 2023/05/24 08:53:38 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cstdlib>
# include <cfloat>
# include <cmath>

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