/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:50:09 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/17 19:50:35 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

void	flood_fill(char **tab, t_point size, int x, int y)
{
	if (y < 0 || y >= size.y || x < 0 || x >= size.x
		|| tab[y][x] == '1')
		return ;
	tab[y][x] = '1';
	flood_fill(tab, size, x - 1, y);
	flood_fill(tab, size, x + 1, y);
	flood_fill(tab, size, x, y - 1);
	flood_fill(tab, size, x, y + 1);
}

char	**map_dup(char **map_array)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof(char *) * map_len(map_array) + 1);
	while (map_array[i][0])
	{
		tmp[i] = ft_strdup(map_array[i]);
		i++;
	}
	tmp[i] = ft_calloc(1, 1);
	return (tmp);
}

int	list_point_cmp(t_list *list, char **map_array)
{
	t_point	*tmp;

	while (list->next)
	{
		tmp = list->content;
		if (map_array[tmp->y][tmp->x] != '1')
			return (0);
		list = list->next;
	}
	return (1);
}

int	check_path(char **map_array)
{
	t_point	size;
	t_point	*cur;
	t_elem	*elem;
	char	**tmp;
	int		ret;

	ret = 1;
	tmp = map_dup(map_array);
	elem = malloc(sizeof(t_elem));
	elem_init(elem, tmp);
	size.x = ft_strlen(tmp[0]) - 1;
	size.y = map_len(tmp) - 1;
	cur = elem->lst_spawn->content;
	flood_fill(tmp, size, cur->x, cur->y);
	if (!list_point_cmp(elem->lst_exit, tmp)
		|| !list_point_cmp(elem->lst_item, tmp)
		|| !list_point_cmp(elem->lst_spawn, tmp))
		ret = 0;
	elem_clear(elem);
	free_map(tmp);
	return (ret);
}
