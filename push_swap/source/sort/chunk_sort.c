/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:04 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/04 12:21:32 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	is_chunk(t_stack *stack, int n_chunk, int nb)
{
	int	i;

	i = 0;
	while (stack->chunk[n_chunk][i])
	{
		if (nb == stack->chunk[n_chunk][i])
			return (1);
		i++;
	}
	return (0);
}

static int	find_hold(t_stack *stack, int n_chunk, int dir)
{
	int	i;

	if (dir)
		i = 0;
	else
		i = stack_len(stack->stack_a) - 1;
	while (stack->stack_a[i])
	{
		if (is_chunk(stack, n_chunk, stack->stack_a[i]))
			return (i);
		if (dir)
			i++;
		else
			i--;
	}
	return (-1);
}

int	**chunk_sort(t_stack *stack)
{
	int	hold_up;
	int	hold_down;
	int	*a;
	int	i;

	a = stack->stack_a;
	i = 0;
	ft_printf("len = %i\n", stack->chunk_len);
	while (i < stack->chunk_len)
	{
		while (stack_len(stack->stack_b) < 20 || stack_len(a) > 0)
		{
			hold_up = find_hold(stack, i, 1);
			hold_down = find_hold(stack, i, 0);
			if (cost(hold_up, a) < cost(hold_down, a))
				loop_sort(a, is_ra(hold_up, a), cost(hold_up, a));
			else
				loop_sort(a, is_ra(hold_down, a), cost(hold_down, a));
			pb(a, stack->stack_b, 1);
		}
		i++;
	}
	return (NULL);
}
