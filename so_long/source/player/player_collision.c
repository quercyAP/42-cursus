/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 10:13:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	player_dcoll(t_game *so_long, int vof)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.y = (so_long->player->idle[0]->instances->y + of + vof) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe.x = (so_long->player->idle[0]->instances->x + i) / of;
		if (so_long->map[p_axe.y][p_axe.x] == '1')
			return (0);
		i--;
	}
	return (1);
}

int	player_lcoll(t_game *so_long)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.x = (so_long->player->idle[0]->instances->x - 5) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe.y = (so_long->player->idle[0]->instances->y + i) / of;
		if (so_long->map[p_axe.y][p_axe.x] == '1')
			return (0);
		i++;
	}
	return (1);
}

int	player_rcoll(t_game *so_long)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.x = (so_long->player->idle[0]->instances->x + of) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe.y = (so_long->player->idle[0]->instances->y + i) / of;
		if (so_long->map[p_axe.y][p_axe.x] == '1')
			return (0);
		i++;
	}
	return (1);
}

int	player_ucoll(t_game *so_long)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.y = (so_long->player->idle[0]->instances->y - 5) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe.x = (so_long->player->idle[0]->instances->x + i) / of;
		if (so_long->map[p_axe.y][p_axe.x] == '1')
			return (0);
		i--;
	}
	return (1);
}
