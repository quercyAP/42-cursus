/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:15:19 by guillaume         #+#    #+#             */
/*   Updated: 2023/05/24 09:15:31 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.hpp"

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
