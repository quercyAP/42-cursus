/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:26:04 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/06 16:46:09 by glamazer         ###   ########.fr       */
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
	while (stack->stack_a[i] && i >= 0)
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

static void	push_to_a(t_stack *stack)
{
	int	upper;

	while (stack_len(stack->stack_b))
	{
		upper = f_upper(stack->stack_b);
		loop_sort_b(stack->stack_b, is_ra(upper, stack->stack_b),
			cost(upper, stack->stack_b));
		pa(stack->stack_a, stack->stack_b, 1);
	}
}

static void	little_sort_b(t_stack *stack, int n_chunk)
{
	int	index;

	index = stack_len(stack->chunk[n_chunk]) / 2;
	if (stack->stack_b[0] <= stack->chunk[n_chunk][index])
	{
		if (!is_chunk(stack, n_chunk, stack->stack_a[0]))
			rr(stack->stack_a, stack->stack_b, 1);
		else
			rb(stack->stack_b, 1);
	}
}

void	chunk_sort(t_stack *stack)
{
	int	hold_up;
	int	hold_down;
	int	*a;
	int	i;
	int	len;

	a = stack->stack_a;
	i = -1;
	while (stack_len(stack->stack_a))
	{
		len = stack_len(stack->chunk[++i]);
		while (len > 0)
		{
			hold_up = find_hold(stack, i, 1);
			hold_down = find_hold(stack, i, 0);
			if (cost(hold_up, a) < cost(hold_down, a))
				loop_sort(a, is_ra(hold_up, a), cost(hold_up, a));
			else
				loop_sort(a, is_ra(hold_down, a), cost(hold_down, a));
			pb(a, stack->stack_b, 1);
			little_sort_b(stack, i);
			len--;
		}
	}
	push_to_a(stack);
}
