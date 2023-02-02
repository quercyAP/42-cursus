/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:44:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/02 18:30:58 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	free_all(t_stack *stack)
{
	free(stack->stack_a);
	free(stack->stack_b);
	if (stack->chunk)
		free_chunk(stack->chunk);
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

void	*free_chunk(int **chunk)
{
	int	len;
	int	i;

	i = 0;
	len = stack_len(chunk[0]);
	while (i < len)
	{
		free(chunk[i]);
		i++;
	}
	free(chunk);
	return (NULL);
}
