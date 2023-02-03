/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:41:24 by glamazer          #+#    #+#             */
/*   Updated: 2023/02/03 11:49:22 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static char	***parse_arg(char **argv, int argc)
{
	int		i;
	char	***strs;

	strs = ft_calloc(sizeof(char **), argc);
	i = 1;
	while (i < argc)
	{
		strs[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	return (strs);
}

static char	***check_nbr(char **argv, int argc)
{
	char	***strs;
	int		i;
	int		j;
	int		k;

	strs = parse_arg(argv, argc);
	i = -1;
	while (strs[++i])
	{
		j = 0;
		while (strs[i][j])
		{
			k = 0;
			while (strs[i][j][k])
			{
				if (strs[i][j][k] == '-' && k == 0)
					k++;
				if (!ft_isdigit(strs[i][j][k]))
					return (free_strs(strs));
				k++;
			}
			j++;
		}
	}
	return (strs);
}

static int	check_doublon(int *stack_a)
{
	int	i;
	int	j;

	if (!stack_a)
		return (0);
	i = 0;
	while (stack_a[i])
	{
		j = i + 1;
		while (stack_a[j])
		{
			if (stack_a[i] == stack_a[j])
			{
				free(stack_a);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	*check_error(char **argv, int argc, t_stack *stack)
{
	char	***strs;

	strs = check_nbr(argv, argc);
	if (!strs)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	if (!set_stack(strs, stack))
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	free_strs(strs);
	if (!check_doublon(stack->stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (stack->stack_a);
}