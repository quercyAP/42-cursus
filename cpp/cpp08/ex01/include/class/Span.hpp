/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:05:14 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/31 09:52:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

# include <iostream>
# include <exception>
# include <climits>
# include <vector>
# include <algorithm>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _numbers;

    public:
        class longerException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        Span(unsigned int n);
        Span(Span const &src);
        ~Span();
        Span &operator=(Span const &copy);
        void addNumber(int n);
        template<typename It>
        void addNumber(It begin, It end)
        {
            if (std::distance(begin, end) + _numbers.size() > _n)
                 throw std::out_of_range("Span::addNumber");
            _numbers.insert(_numbers.end(), begin, end);            
        }
        int shortestSpan();
        int longestSpan();
};

#endif