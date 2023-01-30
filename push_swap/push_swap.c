/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:45:44 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/30 15:23:11 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	*free_strs(char ***strs)
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
	return (strs);
}

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
	while (strs[i])
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
		i++;
	}
	return (strs);
}

static int	count_nbr(char ***strs)
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

static int	*set_stack(char ***strs)
{
	int	i;
	int	j;
	int	k;
	int	*stack_a;

	k = 0;
	stack_a = ft_calloc(sizeof(int), count_nbr(strs));
	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			stack_a[k] = ft_atoi(strs[i][j]);
			j++;
			k++;
		}
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
	}
}
