/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:37:54 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/31 18:00:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb(int *stack_a, int *stack_b, int display)
{
	if (stack_len(stack_a))
	{
		if (stack_b[0] != 0)
		{
			stack_b[stack_len(stack_b)] = stack_a[0];
			rrb(stack_b, 0);
		}
		else
			stack_b[0] = stack_a[0];
		ra(stack_a, 0);
		stack_a[stack_len(stack_a) - 1] = 0;
		if (display)
			ft_printf("pb\n");
	}
}
