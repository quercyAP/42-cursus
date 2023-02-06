/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:58:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/06 16:29:36 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	loop_sort(int *stack, int is_ra, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (is_ra)
			ra(stack, 1);
		else
			rra(stack, 1);
		i++;
	}
}

void	loop_sort_b(int *stack, int is_rb, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (is_rb)
			rb(stack, 1);
		else
			rrb(stack, 1);
		i++;
	}
}

int	is_ra(int index, int *stack)
{
	int	pair;

	pair = is_pair(stack_len(stack));
	if (pair)
	{
		if (index >= stack_len(stack) / 2)
			return (0);
	}
	else
	{
		if (index >= (stack_len(stack) / 2) + 1)
			return (0);
	}
	return (1);
}

int	cost(int index, int *stack)
{
	int	cost;

	cost = 0;
	if (is_ra(index, stack))
		cost = index;
	else
		cost = stack_len(stack) - index;
	return (cost);
}
