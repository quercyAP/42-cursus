/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:43:02 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 11:39:02 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_point	*player_dcoll(void *game, void *player_pos)
{
	t_point			*p_axe;
	mlx_instance_t	*pos;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	pos = player_pos;
	p_axe = so->player->d_axe;
	p_axe->y = (pos->y + of + so->player->var) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe->x = (pos->x + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
			return (NULL);
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E'
			|| so->map[p_axe->y][p_axe->x] == 'M')
			return (p_axe);
		i--;
	}
	return (&(t_point){0, 0});
}

t_point	*player_lcoll(void *game, void *player_pos)
{
	t_point			*p_axe;
	mlx_instance_t	*pos;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	pos = player_pos;
	p_axe = so->player->l_axe;
	p_axe->x = (pos->x - 5) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe->y = (pos->y + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
			return (NULL);
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E'
			|| so->map[p_axe->y][p_axe->x] == 'M')
			return (p_axe);
		i++;
	}
	return (&(t_point){0, 0});
}

t_point	*player_rcoll(void *game, void *player_pos)
{
	t_point			*p_axe;
	mlx_instance_t	*pos;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	pos = player_pos;
	p_axe = so->player->r_axe;
	p_axe->x = (pos->x + of) / of;
	i = 0;
	while (i < of - 1)
	{
		p_axe->y = (pos->y + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
			return (NULL);
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E'
			|| so->map[p_axe->y][p_axe->x] == 'M')
			return (p_axe);
		i++;
	}
	return (&(t_point){0, 0});
}

t_point	*player_ucoll(void *game, void *player_pos)
{
	t_point			*p_axe;
	mlx_instance_t	*pos;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	pos = player_pos;
	p_axe = so->player->u_axe;
	p_axe->y = (pos->y - 5) / of;
	i = of - 5;
	while (i > 0)
	{
		p_axe->x = (pos->x + i) / of;
		if (so->map[p_axe->y][p_axe->x] == '1')
			return (NULL);
		else if (so->map[p_axe->y][p_axe->x] == 'C'
			|| so->map[p_axe->y][p_axe->x] == 'E'
			|| so->map[p_axe->y][p_axe->x] == 'M')
			return (p_axe);
		i--;
	}
	return (&(t_point){0, 0});
}
