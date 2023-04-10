/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 11:05:13 by glamazer          #+#    #+#             */
/*   Updated: 2023/04/07 14:47:35 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Adresse de la string en mémoire: " << &str << std::endl;
    std::cout << "Adresse stockée dans stringPTR: " << stringPTR << std::endl;
    std::cout << "Adresse stockée dans stringREF: " << &stringREF << std::endl;

    std::cout << "Valeur de la string: " << str << std::endl;
    std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF: " << stringREF << std::endl;

    return 0;
}
