/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:45:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/24 14:18:05 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	bullet_rcoll(char **map, mlx_instance_t bullet)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.x = (bullet.x + 45) / of;
	i = 10;
	while (i < 32)
	{
		p_axe.y = (bullet.y + i) / of;
		if (map[p_axe.y][p_axe.x] == '1')
			return (0);
		i++;
	}
	return (1);
}

static int	bullet_lcoll(char **map, mlx_instance_t bullet)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.x = bullet.x / of;
	i = 10;
	while (i < 32)
	{
		p_axe.y = (bullet.y + i) / of;
		if (map[p_axe.y][p_axe.x] == '1')
			return (0);
		i++;
	}
	return (1);
}

static void	routine(mlx_instance_t *bullet, t_game *so, int j)
{
	if (!bullet->enabled)
	{
		bullet->x = (so->player->idle[0]->instances[0].x) + 50;
		bullet->y = (so->player->idle[0]->instances[0].y) + 15;
		so->player->b_spawn[j] = bullet->x;
	}
	else
	{
		if (!bullet_rcoll(so->map, *bullet)
			|| bullet->x >= (so->player->b_spawn[j]) + 64 * 4)
			bullet->enabled = false;
		bullet->x += 6;
	}
}

static void	lroutine(mlx_instance_t *bullet, t_game *so, int j)
{
	if (!bullet->enabled)
	{
		bullet->x = (so->player->idle[0]->instances[0].x) - 18;
		bullet->y = (so->player->idle[0]->instances[0].y) + 15;
		so->player->lb_spawn[j] = bullet->x;
	}
	else
	{
		if (!bullet_lcoll(so->map, *bullet)
			|| bullet->x <= (so->player->lb_spawn[j]) - (64 * 4))
			bullet->enabled = false;
		bullet->x -= 6;
	}
}

void	bullet_routine(void *param)
{
	t_game	*so;
	int		i;
	int		j;

	so = param;
	i = 0;
	while (i < so->player->b_len)
	{
		j = 0;
		while (j < so->player->ammo)
		{
			routine(&so->player->bullet[i]->instances[j], so, j);
			lroutine(&so->player->lbullet[i]->instances[j], so, j);
			j++;
		}
		i++;
	}
}
