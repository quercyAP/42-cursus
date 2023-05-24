/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:05:50 by guillaume         #+#    #+#             */
/*   Updated: 2023/05/24 09:19:07 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.hpp"
#include <iostream>

int main() {
    Data myData;
    myData.a = 1;
    myData.b = 2.0;
    myData.c = '3';

    uintptr_t raw = serialize(&myData);
    Data* myDataPtr = deserialize(raw);

    std::cout << "myDataPtr.a = " << myDataPtr->a << std::endl;
    std::cout << "myData.a = " << myData.a << std::endl;
    std::cout << "myDataPtr.b = " << myDataPtr->b << std::endl;
    std::cout << "myData.b = " << myData.b << std::endl;
    std::cout << "myDataPtr.c = " << myDataPtr->c << std::endl;
    std::cout << "myData.c = " << myData.c << std::endl;

    return 0;
}
