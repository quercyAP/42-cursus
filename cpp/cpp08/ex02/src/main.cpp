/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:02:34 by guigui            #+#    #+#             */
/*   Updated: 2023/05/26 09:36:16 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/MutantStack.hpp"
#include <iostream>
#include <list>

static void printWithBorder(const std::string& text) {
    std::string border(text.size(), '-');
    std::cout << RED << border << RESET << std::endl;
    std::cout << BLUE << text << RESET << std::endl;
    std::cout << RED << border << RESET << std::endl;
}

int main()
{
    printWithBorder("Test main with list container");
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        for (std::list<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
    }
    printWithBorder("Test main with MutantStack container");
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << std::endl;
        }
        std::stack<int> s(mstack);
    }
    return 0;
}
