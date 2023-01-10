/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/10 15:26:04 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_dcoll(t_game *so_long)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.y = (so_long->player_idle_i[0]->instances->y + of) / of;
	i = of;
	if (mlx_is_key_down(so_long.mlx, ))
	while (i > 0)
	{
		p_axe.x = (so_long->player_idle_i[0]->instances->x + i) / of;
		printf("char = %c\n", so_long->map[p_axe.y][p_axe.x]);
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
	p_axe.x = so_long->player_idle_i[0]->instances->x / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe.y = (so_long->player_idle_i[0]->instances->y + i) / of;
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
	p_axe.x = (so_long->player_idle_i[0]->instances->x + of) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe.y = (so_long->player_idle_i[0]->instances->y + i) / of;
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
	p_axe.y = so_long->player_idle_i[0]->instances->y / of;
	i = 0;
	while (i < of)
	{
		p_axe.x = (so_long->player_idle_i[0]->instances->x + i) / of;
		if (so_long->map[p_axe.y][p_axe.x] == '1')
			return (0);
		i++;
	}
	return (1);
}
