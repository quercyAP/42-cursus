/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:08:37 by guigui            #+#    #+#             */
/*   Updated: 2023/05/30 09:32:26 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/class/Array.hpp"

int main() {
    try {
        Array<int> a(5);
        std::cout << "Array size: " << a.size() << std::endl;

        for (unsigned int i = 0; i < a.size(); i++) {
            a[i] = i;
            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;
        Array<int> b(a);
        std::cout << "b[4] = " << b[4] << std::endl;

        std::cout << "Accessing element out of bounds: ";
        std::cout << a[10] << std::endl;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
