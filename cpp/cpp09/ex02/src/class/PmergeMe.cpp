/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:05:16 by glamazer          #+#    #+#             */
/*   Updated: 2023/05/26 17:02:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) {
    if (argc < 2) {
        throw std::invalid_argument("Not enough arguments");
    }
    std::string args;
    for (int i = 1; i < argc; i++) {
        args += argv[i];
        if (i != argc - 1) {
            args += " ";
        }
    }
    std::istringstream iss(args);
    std::string token;
    while (iss >> token) {
        vec.push_back(std::stoi(token));
        lst.push_back(std::stoi(token));   
    }
}

template <typename Container>
void PmergeMe::mergeSort(Container& container) {
    if (container.size() > 1) {
        Container left_half;
        Container right_half;
        typename Container::iterator middle = container.begin();
        std::advance(middle, container.size() / 2);
        
        std::copy(container.begin(), middle, std::back_inserter(left_half));
        std::copy(middle, container.end(), std::back_inserter(right_half));
        
        mergeSort(left_half);
        mergeSort(right_half);
        
        std::merge(left_half.begin(), left_half.end(), right_half.begin(), right_half.end(), container.begin());
    }
}

void PmergeMe::process() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    printContainer(vec);
    mergeSort(vec);
    printContainer(vec);
    std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << duration.count() << " us\n";
    
    start = std::chrono::high_resolution_clock::now();
    mergeSort(lst);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time to process a range of " << lst.size() << " elements with std::list : " << duration.count() << " us\n";
}

template<typename Container>
void PmergeMe::printContainer(const Container& c) {
    typename Container::const_iterator it;
    for(it = c.begin(); it != c.end(); it++) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
}

