/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 07:59:52 by guigui            #+#    #+#             */
/*   Updated: 2023/05/23 08:00:23 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/class/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 151);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat jane("Jane", 0);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
