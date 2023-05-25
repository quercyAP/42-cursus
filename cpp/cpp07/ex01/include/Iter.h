/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigui <guigui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 07:58:28 by guigui            #+#    #+#             */
/*   Updated: 2023/05/25 08:01:08 by guigui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

# include <iostream>

template<typename T>
void iter(T* array, size_t size, void (*f)(T const &))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

#endif