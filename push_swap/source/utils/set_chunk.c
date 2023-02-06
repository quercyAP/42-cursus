/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:34:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/06 15:57:18 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	chunk_alloc(t_stack *stack)
{
	int	nb_chunk;
	int	len;
	int	i;

	len = stack_len(stack->stack_a);
	if (len % stack->nb_chunk == 0)
		nb_chunk = len / stack->nb_chunk;
	else
		nb_chunk = (len / stack->nb_chunk) + 1;
	stack->chunk = ft_calloc(sizeof(int *), nb_chunk + 1);
	i = 0;
	while (i < nb_chunk)
	{
		stack->chunk[i] = ft_calloc(sizeof(int), stack->nb_chunk + 1);
		i++;
	}
	if (len % stack->nb_chunk == 0)
		stack->chunk[i] = ft_calloc(sizeof(int), stack->nb_chunk + 1);
	else
		stack->chunk[i] = ft_calloc(sizeof(int), (len % stack->nb_chunk) + 1);
	return (nb_chunk);
}

static void	stock_chunk(t_stack *stack, int nb)
{
	int	i;
	int	j;
	int	rest;
	int	pivot;

	rest = stack->nb_chunk;
	pivot = INT_MIN;
	i = 0;
	while (i < nb)
	{
		if (i == nb - 1 && stack_len(stack->stack_a) % stack->nb_chunk != 0)
			rest = stack_len(stack->stack_a) % stack->nb_chunk;
		j = 0;
		while (j < rest)
		{
			stack->chunk[i][j] = is_lower_of(stack->stack_a, pivot);
			pivot = stack->chunk[i][j];
			j++;
		}
		i++;
	}
}

void	set_chunk(t_stack *stack)
{
	stack->chunk_len = chunk_alloc(stack);
	stock_chunk(stack, stack->chunk_len);
}
