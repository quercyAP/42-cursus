/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <glamazer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:11:13 by guigui            #+#    #+#             */
/*   Updated: 2023/05/25 13:19:54 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/class/Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template<typename T>
Array<T>::Array(const Array<T>& src) : _array(new T[src._size]), _size(src._size) {
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = src._array[i];
}

template<typename T>
Array<T>::~Array() {
    delete[] _array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this != &rhs) {
        delete[] _array;
        _array = new T[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = rhs._array[i];
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Array index out of range");
    return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
    return _size;
}
