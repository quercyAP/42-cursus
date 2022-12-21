/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:50:42 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/20 13:48:15 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

void	elem_init(t_elem *elem, char **map_array)
{
	elem->empty = '0';
	elem->wall = '1';
	elem->exit = 'E';
	elem->lst_exit = count_elem(map_array, 'E');
	elem->item = 'C';
	elem->lst_item = count_elem(map_array, 'C');
	elem->spawn = 'P';
	elem->lst_spawn = count_elem(map_array, 'P');
}

int	map_len(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i][0])
		i++;
	return (i);
}

t_point	*find_elem(char **map_array, char c, t_point *axe)
{
	t_point	*ret;
	int		len;

	len = map_len(map_array);
	while (axe->y < len)
	{
		ret = malloc(sizeof(t_point));
		while (map_array[axe->y][axe->x] != c && map_array[axe->y][axe->x])
			axe->x++;
		if (map_array[axe->y][axe->x] == c)
		{
			ret->x = axe->x;
			ret->y = axe->y;
			axe->x++;
			return (ret);
		}
		else
			free(ret);
		axe->y++;
		axe->x = 0;
	}
	return (NULL);
}

t_list	*count_elem(char **map_array, char c)
{
	t_list	*lst_elem;
	t_list	*new_node;
	t_point	*index;
	t_point	*point;

	lst_elem = NULL;
	index = malloc(sizeof(t_point));
	index->y = 0;
	index->x = 0;
	while (index->y < map_len(map_array))
	{
		while (index->x < (int)ft_strlen(map_array[index->y]))
		{
			point = find_elem(map_array, c, index);
			if (point)
			{
				new_node = ft_lstnew(point);
				ft_lstadd_back(&lst_elem, new_node);
			}
		}
		index->y++;
	}
	free(index);
	return (lst_elem);
}
