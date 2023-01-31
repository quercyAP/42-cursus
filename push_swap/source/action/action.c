/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:04:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/31 18:03:30 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(int *stack_a, int display)
{
	int	swap;

	if (stack_len(stack_a) < 2)
	{
		swap = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = swap;
		if (display)
			ft_printf("sa\n");
	}
}

void	sb(int *stack_b, int display)
{
	if (stack_len(stack_b) < 2)
	{
		sa(stack_b, 0);
		if (display)
			ft_printf("sb\n");
	}
}

void	ss(int	*stack_a, int *stack_b, int display)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (display)
		ft_printf("ss\n");
}

void	ra(int	*stack_a, int display)
{
	int	i;
	int	swap;

	i = 0;
	while (stack_a[i + 1])
	{
		swap = stack_a[i];
		stack_a[i] = stack_a[i + 1];
		stack_a[i + 1] = swap;
		i++;
	}
	if (display)
		ft_printf("ra\n");
}

void	rb(int	*stack_b, int display)
{
	ra(stack_b, 0);
	if (display)
		ft_printf("rb\n");
}
