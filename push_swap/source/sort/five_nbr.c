/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:13:06 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/02 14:02:04 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	action(int *stack_a, int *stack_b, int nb)
{
	if (nb == 1)
	{
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
	}
	else if (nb == 2)
	{
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
	}
}

static void	little_sort(int *stack_a, int *stack_b)
{
	if (cost(f_lower(stack_a), stack_a) < cost(f_upper(stack_a), stack_a))
	{
		loop_sort(stack_a, is_ra(f_lower(stack_a), stack_a),
			cost(f_lower(stack_a), stack_a));
		pb(stack_a, stack_b, 1);
		if (stack_len(stack_a) > 3)
		{
			loop_sort(stack_a, is_ra(f_upper(stack_a), stack_a),
				cost(f_upper(stack_a), stack_a));
			pb(stack_a, stack_b, 1);
		}
	}
	else
	{
		loop_sort(stack_a, is_ra(f_upper(stack_a), stack_a),
			cost(f_upper(stack_a), stack_a));
		pb(stack_a, stack_b, 1);
		if (stack_len(stack_a) > 3)
		{
			loop_sort(stack_a, is_ra(f_lower(stack_a), stack_a),
				cost(f_lower(stack_a), stack_a));
			pb(stack_a, stack_b, 1);
		}
	}
}

void	sort_five(int *stack_a, int *stack_b)
{
	little_sort(stack_a, stack_b);
	sort_three(stack_a);
	if (stack_len(stack_b) == 2)
	{
		if (stack_b[0] < stack_b[1])
			action(stack_a, stack_b, 1);
		else
			action(stack_a, stack_b, 2);
	}
	else
	{
		if (stack_b[0] < stack_a[1])
			pa(stack_a, stack_b, 1);
		else
		{
			pa(stack_a, stack_b, 1);
			ra(stack_a, 1);
		}
	}
}
