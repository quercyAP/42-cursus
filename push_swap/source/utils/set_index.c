/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:30:40 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/09 11:17:10 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	dup_stack(t_stack *stack, int *sort_tab)
{
	int	i;

	i = 0;
	while (i < stack->stack_len)
	{
		sort_tab[i] = stack->stack_a[i];
		i++;
	}
	sort_tab[i] = 0;
}

static void	sort(int *sort_tab, t_stack *stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack->stack_len)
	{
		j = i + 1;
		while (j < stack->stack_len)
		{
			if (sort_tab[i] > sort_tab[j])
			{
				tmp = sort_tab[i];
				sort_tab[i] = sort_tab[j];
				sort_tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	set_index(t_stack *stack)
{
	int	*sort_tab;
	int	i;
	int	j;

	sort_tab = malloc(sizeof(int) * stack->stack_len);
	dup_stack(stack, sort_tab);
	sort(sort_tab, stack);
	i = 0;
	while (i < stack->stack_len)
	{
		j = 0;
		while (j < stack->stack_len)
		{
			if (stack->stack_a[i] == sort_tab[j])
			{
				stack->stack_a[i] = j + 1;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sort_tab);
}
