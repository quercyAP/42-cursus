/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:50:42 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/16 15:11:47 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

void	flood_fill(char **tab, t_point size, t_point cur, t_elem elem)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1')
		return ;
	tab[cur.y][cur.x] = '1';
	flood_fill(tab, size, (t_point){cur.x - 1, cur.y}, elem);
	flood_fill(tab, size, (t_point){cur.x + 1, cur.y}, elem);
	flood_fill(tab, size, (t_point){cur.x, cur.y - 1}, elem);
	flood_fill(tab, size, (t_point){cur.x, cur.y + 1}, elem);
}

void	axe_init(t_point *axe)
{
	axe->x = 0;
	axe->y = 0;
}

void	elem_init(t_elem *elem, char **map_array)
{
	t_point	*axe;

	axe = malloc(sizeof(t_point));
	axe_init(axe);
	elem->empty = '0';
	elem->wall = '1';
	elem->exit = 'E';
	elem->p_exit = find_elem(map_array, 'E', axe);
	axe_init(axe);
	elem->item = 'C';
	elem->lst_item = count_elem(map_array, 'C');
	elem->spawn = 'P';
	elem->p_spawn = find_elem(map_array, 'P', axe);
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
	while (map_array[axe->y][0])
	{
		axe->x = 0;
		while (map_array[axe->y][axe->x] != c && map_array[axe->y][axe->x])
			axe->x++;
		if (map_array[axe->y][axe->x] == c)
			return (axe);
		axe->y++;
	}
	return (axe);
}

t_list	*count_elem(char **map_array, char c)
{
	t_list	*lst_elem;
	t_list	*new_node;
	t_point	*axe;

	lst_elem = malloc(sizeof(t_list));
	lst_elem = NULL;
	axe = malloc(sizeof(t_point));
	axe_init(axe);
	while (map_array[axe->y][0])
	{
		axe = find_elem(map_array, c, axe);
		new_node = ft_lstnew(axe);
		ft_lstadd_front(&lst_elem, new_node);
		axe->y++;
	}
	return (lst_elem);
}
