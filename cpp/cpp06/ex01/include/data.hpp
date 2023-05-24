/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:13:28 by guillaume         #+#    #+#             */
/*   Updated: 2023/05/24 09:13:45 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

struct Data {
    int a;
    float b;
    char c;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
