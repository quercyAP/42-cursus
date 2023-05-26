/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:05:41 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 13:42:20 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/RPN.hpp"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " \"expression\"" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        std::cout << rpn.calculate(argv[1]) << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
