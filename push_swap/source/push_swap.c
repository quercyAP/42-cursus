/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/01 15:51:57 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sort(int *stack_a)
{
	int	i;

	i = 1;
	while (stack_a[i])
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*stack_a;
	int		*stack_b;

	if (argc > 1)
	{
		stack_a = check_error(argv, argc);
		if (stack_a == NULL || is_sort(stack_a))
			return (0);
		stack_b = ft_calloc(sizeof(int), stack_len(stack_a));
		if (stack_len(stack_a) == 2)
			sa(stack_a, 1);
		else if (stack_len(stack_a) == 3)
			sort_three(stack_a);
		else if (stack_len(stack_a) == 4 || stack_len(stack_a) == 5)
			sort_five(stack_a, stack_b);
		free(stack_a);
		free(stack_b);
	}
}
