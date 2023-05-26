/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:55:09 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 16:13:54 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PmergeMe.hpp
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <iostream>
# include <chrono>
# include <algorithm>
# include <iterator>
# include <string>
# include <sstream>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::list<int> lst;

        template <typename Container>
        void mergeSort(Container& container);
        template <typename Container>
        void printContainer(const Container& c);
        
    public:
        PmergeMe(int argc, char **args);
        void process();
};

#endif
