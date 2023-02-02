/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/02 18:33:56 by glamazer         ###   ########.fr       */
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

static void	set_sort(t_stack *stack)
{
	if (stack_len(stack->stack_a) == 2)
		sa(stack->stack_a, 1);
	else if (stack_len(stack->stack_a) == 3)
		sort_three(stack->stack_a);
	else if (stack_len(stack->stack_a) == 4 || stack_len(stack->stack_a) == 5)
		sort_five(stack->stack_a, stack->stack_b);
	else if (stack_len(stack->stack_a) <= 100)
	{
		set_chunk(stack);
		chunk_sort(stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (argc > 1)
	{
		if (check_error(argv, argc, stack) || is_sort(stack->stack_a))
			return (free_all(stack));
		stack->stack_b = ft_calloc(sizeof(int), stack_len(stack->stack_a));
		set_sort(stack);
		free_all(stack);
	}
	free(stack);
}
