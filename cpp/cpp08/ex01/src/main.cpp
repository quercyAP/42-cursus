/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:04:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 09:55:05 by glamazer         ###   ########.fr       */
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
    try {
        printWithBorder("Span with size 5 { 6, 3, 17, 9, 11 }");
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

        printWithBorder("Span with size 10000 { [0 - 9999] }");
        Span spLarge = Span(10000);
        for (int i = 0; i < 10000; ++i)
            spLarge.addNumber(i);
        std::cout << "shortestSpan: " << spLarge.shortestSpan() << std::endl;
        std::cout << "longestSpan: " << spLarge.longestSpan() << std::endl;

        printWithBorder("Span with size 100 fill with std::vector { [(i + 1) * 2] }");
        Span spRange = Span(100);
        std::vector<int> numbers(100);
        for (int i = 0; i < 100; ++i)
            numbers[i] = i * 2;
        spRange.addNumber(numbers.begin(), numbers.end());
        std::cout << "shortestSpan" << spRange.shortestSpan() << std::endl;
        std::cout << "longestSpan" << spRange.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}