/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chunk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:34:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/03 15:41:45 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	chunk_alloc(t_stack *stack)
{
	int	nb_chunk;
	int	len;
	int	i;

	len = stack_len(stack->stack_a);
	if (len % 20 == 0)
		nb_chunk = len / 20;
	else
		nb_chunk = (len / 20) + 1;
	stack->chunk = ft_calloc(sizeof(int *), nb_chunk + 1);
	i = 0;
	while (i < nb_chunk)
	{
		stack->chunk[i] = ft_calloc(sizeof(int), 20);
		i++;
	}
	if (len % 20 == 0)
		stack->chunk[i] = ft_calloc(sizeof(int), 20);
	else
		stack->chunk[i] = ft_calloc(sizeof(int), len % 20);
	return (nb_chunk);
}

static void	stock_chunk(t_stack *stack, int nb)
{
	int	i;
	int	j;
	int	rest;
	int	pivot;

	rest = 20;
	pivot = f_lower(stack->stack_a);
	i = 0;
	while (i < nb)
	{
		if (i == nb - 1 && stack_len(stack->stack_a) % 20 != 0)
			rest = stack_len(stack->stack_a) % 20;
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
	int	len;
	int	i;

	len = chunk_alloc(stack);
	stock_chunk(stack, len);
	i = 0;
	while (i < len)
	{
		display_stack(stack->chunk[i]);
		i++;
	}
}
