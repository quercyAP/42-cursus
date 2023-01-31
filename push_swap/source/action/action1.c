/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:43:50 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/31 18:00:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rr(int *stack_a, int *stack_b, int display)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (display)
		ft_printf("rr\n");
}

void	rra(int *stack_a, int display)
{
	int	i;
	int	swap;

	i = stack_len(stack_a) - 1;
	while (i > 0)
	{
		swap = stack_a[i];
		stack_a[i] = stack_a[i - 1];
		stack_a[i - 1] = swap;
		i--;
	}
	if (display)
		ft_printf("rra\n");
}

void	rrb(int *stack_b, int display)
{
	rra(stack_b, 0);
	if (display)
		ft_printf("rra\n");
}

void	rrr(int	*stack_a, int *stack_b, int display)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (display)
		ft_printf("rrr\n");
}

void	pa(int *stack_a, int *stack_b, int display)
{
	if (stack_len(stack_b))
	{
		if (stack_a[0] != 0)
		{
			stack_a[stack_len(stack_a)] = stack_b[0];
			rra(stack_a, 0);
		}
		else
			stack_a[0] = stack_b[0];
		rb(stack_b, 0);
		stack_b[stack_len(stack_b) - 1] = 0;
		if (display)
			ft_printf("pa\n");
	}
}
