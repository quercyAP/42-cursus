/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/09 11:02:52 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sort(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack->stack_a[i])
	{
		if (stack->stack_a[i - 1] > stack->stack_a[i])
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
		stack->nb_chunk = 20;
		set_chunk(stack);
		chunk_sort(stack);
	}
	else if (stack_len(stack->stack_a) > 100)
	{
		stack->nb_chunk = 46;
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
		if (!check_error(argv, argc, stack))
			return (free_all(stack, -1));
		set_index(stack);
		if (is_sort(stack))
			return (free_all(stack, 0));
		stack->stack_b = ft_calloc(sizeof(int), stack_len(stack->stack_a) + 1);
		set_sort(stack);
		if (stack_len(stack->stack_a) < 6)
			free_all(stack, 1);
		else
			free_all(stack, 2);
	}
	else
		free(stack);
}
