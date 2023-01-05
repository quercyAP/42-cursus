/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/05 15:20:06 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_coll(t_game *so_long)
{
	t_point	p_axe;
	t_point	w_axe;
	int		i;

	p_axe.x = so_long->player_idle_i[0]->instances->x;
	p_axe.y = so_long->player_idle_i[0]->instances->y;
	i = 0;
	if (p_axe.y == 64 || p_axe.y + 64 == (map_len(so_long->map) * 64) - 64
		|| p_axe.x == 64 || p_axe.x + 64 == (ft_strlen(so_long->map[0]) * 64) - 64)
		return (0);
	while (so_long->wall_i->instances[i])
	{
		w_axe.y = so_long->wall_i->instances[i].y;
		w_axe.x = so_long->wall_i->instances[i].x;
		if (w_axe.x == 0 || w_axe.x == )
		i++;
	}
	return (1);
}
