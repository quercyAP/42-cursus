/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:31:23 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/02 13:56:59 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_pair(int nb)
{
	if (nb % 2 == 0)
		return (1);
	return (0);
}

int	is_lower(int *stack, int j)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (j > stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_upper(int *stack, int j)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (j < stack[i])
			return (0);
		i++;
	}
	return (1);
}

int	f_lower(int *stack)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	j = INT_MAX;
	while (stack[i])
	{
		if (stack[i] <= j)
		{
			j = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	f_upper(int *stack)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	j = INT_MIN;
	while (stack[i])
	{
		if (stack[i] >= j)
		{
			j = stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}
