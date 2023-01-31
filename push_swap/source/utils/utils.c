/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:46:50 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/31 16:19:55 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	display_stack(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		ft_printf("nbr %i = %i\n", i, stack[i]);
		i++;
	}
}

int	*set_stack(char ***strs)
{
	int		i;
	int		j;
	int		k;
	int		*stack_a;
	char	*tmp;

	k = -1;
	stack_a = ft_calloc(sizeof(int), count_nbr(strs));
	i = -1;
	while (strs[++i])
	{
		j = -1;
		while (strs[i][++j])
		{
			stack_a[++k] = ft_atoi(strs[i][j]);
			tmp = ft_itoa(stack_a[k]);
			if (ft_strncmp(tmp, strs[i][j], ft_strlen(strs[i][j])) != 0)
				return (set_stack_free(tmp, stack_a));
			free(tmp);
		}
	}
	return (stack_a);
}

int	stack_len(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

int	count_nbr(char ***strs)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	return (count);
}
