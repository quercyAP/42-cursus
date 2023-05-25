/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:05:05 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/25 16:45:33 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span() {}

Span &Span::operator=(Span const &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _numbers = copy._numbers;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _n)
        throw Span::outsideException();
    _numbers.push_back(n);
}
int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw Span::longerException();
    std::sort(_numbers.begin(), _numbers.end());
    int minSpan = INT_MAX;
    for (std::size_t i = 1; i < _numbers.size(); ++i)
        minSpan = std::min(minSpan, _numbers[i] - _numbers[i - 1]);
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw Span::longerException();
    int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
    int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());
    return maxNumber - minNumber;
}

const char *Span::longerException::what() const throw()
{
    return "Span::longer: no longer possible";
}

const char *Span::outsideException::what() const throw()
{
    return "Span::outside: out of range";
}

