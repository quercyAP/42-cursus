/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:04:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/25 16:48:22 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Span.hpp"

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main()
{
    printWithBorder("TEST");
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl; // Doit afficher 2
        std::cout << sp.longestSpan() << std::endl;  // Doit afficher 14

        Span spLarge = Span(10000);
        for (int i = 0; i < 10000; ++i)
            spLarge.addNumber(i);
        std::cout << spLarge.shortestSpan() << std::endl; // Doit afficher 1
        std::cout << spLarge.longestSpan() << std::endl;  // Doit afficher 9999

        Span spRange = Span(100);
        std::vector<int> numbers(100);
        for (int i = 0; i < 100; ++i)
            numbers[i] = i * 2;
        spRange.addNumber(numbers.begin(), numbers.end());
        std::cout << spRange.shortestSpan() << std::endl; // Doit afficher 2
        std::cout << spRange.longestSpan() << std::endl;  // Doit afficher 198
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}