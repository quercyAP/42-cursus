/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:22:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/25 12:41:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include <../include/easyfind.h>

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main(void)
{
    printWithBorder("VALID TEST EASYFIND FUNCTION ");
    {
        std::vector<int> vec;

        for (int i = 0; i < 10; i++)
            vec.push_back(i);
        try {
            easyfind(vec, 1);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    printWithBorder("INVALID TEST EASYFIND FUNCTION ");
    {
        std::vector<int> vec;

        for (int i = 0; i < 10; i++)
            vec.push_back(i);
        try {
            easyfind(vec, 10);
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        
    }

    return 0;
}