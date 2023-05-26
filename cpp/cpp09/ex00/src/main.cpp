/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 10:42:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 10:49:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc("data.csv");
    btc.evaluateFile(argv[1]);

    return 0;
}
