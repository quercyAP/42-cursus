/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:26:22 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/24 10:22:50 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void	free_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i][0])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array[i]);
	free(map_array);
}

void	lst_clear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	elem_clear(t_elem *elem)
{
	lst_clear(&elem->lst_exit);
	lst_clear(&elem->lst_spawn);
	lst_clear(&elem->lst_item);
	free(elem);
}

void	t_game_clear(t_game *so_long)
{
	elem_clear(so_long->elem);
	free_map(so_long->map);
	mlx_terminate(so_long->mlx);
	free(so_long);
}
