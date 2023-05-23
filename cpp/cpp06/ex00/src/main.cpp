/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:43:19 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 16:47:13 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/ScalarConversion.hpp"
// Implementations for printChar, printInt, printFloat, and printDouble would follow...

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