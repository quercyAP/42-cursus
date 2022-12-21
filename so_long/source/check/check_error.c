/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:55:21 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/18 09:50:31 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

static int	is_rect(char **map_array)
{
	int	i;

	i = 1;
	if (map_len(map_array) < 3 || ft_strlen(map_array[0]) < 3)
		return (0);
	while (map_array[i][0])
	{
		if (ft_strlen(map_array[i]) != ft_strlen(map_array[i - 1]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_close(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[0][i])
	{
		if (map_array[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map_array[map_len(map_array) - 1][i])
	{
		if (map_array[map_len(map_array) - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map_array[i][0])
	{
		if (map_array[i][0] != '1'
			|| map_array[i][ft_strlen(map_array[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static	int	browse_map(char **map_array)
{
	t_point	index;

	index.y = 0;
	while (map_array[index.y][0])
	{
		index.x = 0;
		while (map_array[index.y][index.x])
		{
			if (map_array[index.y][index.x] == '0'
				|| map_array[index.y][index.x] == '1'
				|| map_array[index.y][index.x] == 'P'
				|| map_array[index.y][index.x] == 'C'
				|| map_array[index.y][index.x] == 'E')
				index.x++;
			else
				return (0);
		}
		index.y++;
	}
	return (1);
}

static	int	check_elem(char **map_array)
{
	t_elem	*c_elem;

	c_elem = malloc(sizeof(t_elem));
	elem_init(c_elem, map_array);
	if (ft_lstsize(c_elem->lst_exit) > 1
		|| ft_lstsize(c_elem->lst_spawn) > 1
		|| ft_lstsize(c_elem->lst_item) < 1)
	{
		elem_clear(c_elem);
		return (0);
	}
	elem_clear(c_elem);
	return (1);
}

int	check_error(char **map_array)
{
	if (!check_elem(map_array) || !browse_map(map_array))
	{
		ft_putstr_fd("Map Error\nelement list is wrong\n", 1);
		return (0);
	}
	if (!is_rect(map_array))
	{
		ft_putstr_fd("Map Error\nthe map is not rectangular.\n", 1);
		return (0);
	}
	if (!is_close(map_array))
	{
		ft_putstr_fd("Map Error\nthe map is not close\n", 1);
		return (0);
	}
	if (!check_path(map_array))
	{
		ft_putstr_fd("Map Error\nno valid path\n", 1);
		return (0);
	}
	return (1);
}
