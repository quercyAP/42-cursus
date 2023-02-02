/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:34:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/02 17:43:17 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_chunk(t_stack *stack)
{
	int	nb_chunk;

	if (stack_len(stack->stack_a) % 5 == 0)
		nb_chunk = stack_len(stack->stack_a) / 5;
	else
		nb_chunk = (stack_len(stack->stack_a) / 5) + 1;
	stack->chunk = ft_calloc(sizeof(int *), nb_chunk + 1);
}
