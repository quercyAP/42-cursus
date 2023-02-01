/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:13:06 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/01 16:40:40 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	action(int *stack_a, int *stack_b, int nb)
{
	if (nb == 1)
	{
		rra(stack_a, 1);
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (nb == 2)
	{
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
	}
	else if (nb == 3)
	{
		ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
}

static void	check_case_high(int *stack_a, int *stack_b)
{
	int	b_high;

	b_high = stack_b[0];
	if (b_high < stack_a[2] && b_high > stack_a[1])
		action(stack_a, stack_b, 1);
	else if (b_high > stack_a[2])
		action(stack_a, stack_b, 2);
	else if (b_high > stack_a[0] && b_high < stack_a[1])
	{
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
	}
	else
		pa(stack_a, stack_b, 1);
}

static void	check_case_low(int *stack_a, int *stack_b)
{
	int	b;

	b = stack_b[0];
	if (b > stack_a[3])
	{
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
	}
	else if (b < stack_a[3] && b > stack_a[2])
		action(stack_a, stack_b, 1);
	else if (b > stack_a[1] && b < stack_a[2])
		action(stack_a, stack_b, 3);
	else if (b > stack_a[0] && b < stack_a[1])
	{
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
	}
	else
		pa(stack_a, stack_b, 1);
}

void	sort_five(int *stack_a, int *stack_b)
{
	if (stack_len(stack_a) == 5)
		pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	check_case_high(stack_a, stack_b);
	if (stack_len(stack_b))
		check_case_low(stack_a, stack_b);
}
