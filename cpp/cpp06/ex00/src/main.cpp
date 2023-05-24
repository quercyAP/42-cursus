/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:19 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 19:00:14 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/ScalarConversion.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    ScalarConversion conversion(argv[1]);
    conversion.printChar();
    conversion.printInt();
    conversion.printFloat();
    conversion.printDouble();

    return 0;
}