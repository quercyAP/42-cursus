/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 09:14:25 by guillaume         #+#    #+#             */
/*   Updated: 2023/05/24 09:14:59 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/data.hpp"

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
