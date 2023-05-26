/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:35:02 by guigui            #+#    #+#             */
/*   Updated: 2023/05/26 14:10:37 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/class/Base.hpp"

Base* generate()
{
    switch (rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        default:
            return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    identify(&p);
}

int main()
{
    srand(time(0));

    for (int i = 0; i < 10; ++i)
    {
        Base* ptr = generate();
        identify(*ptr);
        delete ptr;
    }

    return 0;
}
