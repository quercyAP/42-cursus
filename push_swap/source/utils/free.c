/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:44:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/04 10:46:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	free_all(t_stack *stack, int mod)
{
	if (mod == 0)
		free(stack->stack_a);
	if (mod == 1)
	{
		free_chunk(stack);
		free(stack->stack_a);
		free(stack->stack_b);
	}
	free(stack);
	return (0);
}

void	*free_strs(char ***strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			free(strs[i][j]);
			j++;
		}
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

void	*set_stack_free(char *tmp, int *stack)
{
	free(tmp);
	free(stack);
	return (NULL);
}

void	*free_chunk(t_stack *stack)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(stack->stack_a);
	if (len % 20 == 0)
		len = len / 20;
	else
		len = (len / 20) + 1;
	while (i <= len)
	{
		free(stack->chunk[i]);
		i++;
	}
	free(stack->chunk);
	return (NULL);
}
