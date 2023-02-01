/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:57:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/01 10:06:53 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	action(int *stack_a, int nb)
{
	if (nb == 1)
		sa(stack_a, 1);
	else if (nb == 2)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (nb == 3)
		ra(stack_a, 1);
	else if (nb == 4)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (nb == 5)
		rra(stack_a, 1);
}

void	sort_three(int *stack_a)
{
	int	high;
	int	mid;
	int	low;

	high = stack_a[0];
	mid = stack_a[1];
	low = stack_a[2];
	if (high > mid && mid < low && low > high)
		action(stack_a, 1);
	else if (high > mid && mid > low && low < high)
		action(stack_a, 2);
	else if (high > mid && mid < low && low < high)
		action(stack_a, 3);
	else if (high < mid && mid > low && low > high)
		action(stack_a, 4);
	else if (high < mid && mid > low && low < high)
		action(stack_a, 5);
}
