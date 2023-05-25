/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:57:18 by guigui            #+#    #+#             */
/*   Updated: 2023/05/25 11:44:07 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Iter.h"

template <typename T>
void printElement(T const & element) {
        std::cout << element << std::endl;
}

int main() {
    int intArray[5] = {0, 1, 2, 3, 4};
    iter(intArray, 5, printElement);

    std::string strArray[3] = {"toto", "est", "beau"};
    iter(strArray, 3, printElement);

    return 0;
}
