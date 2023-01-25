/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:45:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 14:51:18 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_point	*bullet_rcoll(void *game, void *pos)
{
	t_point			*b_axe;
	mlx_instance_t	*bullet;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	bullet = pos;
	b_axe = so->fly_eye->r_axe;
	b_axe->x = (bullet->x + 20) / of;
	i = 10;
	while (i < 32)
	{
		b_axe->y = (bullet->y + i) / of;
		if (so->map[b_axe->y][b_axe->x] == '1'
		|| (so->map[b_axe->y][b_axe->x] == 'M'
		&& so->fly_eye->idle[0]->instances[check_mob_pos(b_axe, so)].enabled))
			return (b_axe);
		i++;
	}
	return (NULL);
}

t_point	*bullet_lcoll(void *game, void *pos)
{
	t_point			*b_axe;
	mlx_instance_t	*bullet;
	t_game			*so;
	int				of;
	int				i;

	of = 64;
	so = game;
	bullet = pos;
	b_axe = so->fly_eye->l_axe;
	b_axe->x = (bullet->x + 20) / of;
	i = 10;
	while (i < 32)
	{
		b_axe->y = (bullet->y + i) / of;
		if (so->map[b_axe->y][b_axe->x] == '1'
		|| (so->map[b_axe->y][b_axe->x] == 'M'
		&& so->fly_eye->idle[0]->instances[check_mob_pos(b_axe, so)].enabled))
			return (b_axe);
		i++;
	}
	return (NULL);
}

static void	routine(mlx_instance_t *bullet, t_game *so, int j)
{
	int	i;

	i = 0;
	if (!bullet->enabled)
	{
		bullet->x = (so->player->idle[0]->instances[0].x) + 50;
		bullet->y = (so->player->idle[0]->instances[0].y) + 15;
		so->player->b_spawn[j] = bullet->x;
	}
	else
	{
		if (bullet_rcoll(so, bullet)
			|| bullet->x >= (so->player->b_spawn[j]) + 64 * 4)
		{
			i = check_mob_pos(bullet_rcoll(so, bullet), so);
			bullet->enabled = false;
			if (i >= 0)
				del_mob_instance(so->fly_eye->idle, i, so);
		}
		bullet->x += 6;
	}
}

static void	lroutine(mlx_instance_t *bullet, t_game *so, int j)
{
	int	i;

	i = 0;
	if (!bullet->enabled)
	{
		bullet->x = (so->player->idle[0]->instances[0].x) - 18;
		bullet->y = (so->player->idle[0]->instances[0].y) + 15;
		so->player->lb_spawn[j] = bullet->x;
	}
	else
	{
		if (bullet_lcoll(so, bullet)
			|| bullet->x <= (so->player->lb_spawn[j]) - (64 * 4))
		{
			bullet->enabled = false;
			i = check_mob_pos(bullet_lcoll(so, bullet), so);
			if (i >= 0)
				del_mob_instance(so->fly_eye->idle, i, so);
		}
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
