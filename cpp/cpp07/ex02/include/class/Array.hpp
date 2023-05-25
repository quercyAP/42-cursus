/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:10:00 by guigui            #+#    #+#             */
/*   Updated: 2023/05/25 08:11:12 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array<T>& src);
    ~Array();

    Array<T>& operator=(const Array<T>& rhs);
    T& operator[](unsigned int index);

    unsigned int size() const;
private:
    T* _array;
    unsigned int _size;
};

#include "../src/class/Array.tpp"

#endif
