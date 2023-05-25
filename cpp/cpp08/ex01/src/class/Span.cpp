/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:05:05 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/25 14:27:11 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Span.hpp"

Span::Span(unsigned int n) : _n(n), _size(0), _array(new int[n]) {}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span()
{
    delete[] _array;
}

Span &Span::operator=(Span const &copy)
{
    if (this != &copy)
    {
        _n = copy._n;
        _size = copy._size;
        _array = new int[_n];
        for (unsigned int i = 0; i < _n; i++)
            _array[i] = copy._array[i];
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_size < _n)
    {
        _array[_size++] = n;
    }
    else
        throw Span::outsideException();
}

int Span::shortestSpan()
{
    if (_size < 2)
        throw Span::longerException();
    int shortest = INT_MAX;
    for (unsigned int i = 0; i < _size - 1; i++)
    {
        for (unsigned int j = i + 1; j < _size; j++)
        {
            if (_array[j] - _array[i] < shortest)
                shortest = _array[j] - _array[i];
        }
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_size < 2)
        throw Span::longerException();
    int longest = 0;
    for (unsigned int i = 0; i < _size - 1; i++)
    {
        for (unsigned int j = i + 1; j < _size; j++)
        {   
            if (_array[j] - _array[i] > longest)
                longest = _array[j] + _array[i];
        }
    }
    return longest;
}

const char *Span::longerException::what() const throw()
{
    return "Span::longer: no longer possible";
}

const char *Span::outsideException::what() const throw()
{
    return "Span::outside: out of range";
}

