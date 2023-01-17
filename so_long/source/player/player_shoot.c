/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:45:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 21:45:00 by glamazer         ###   ########.fr       */
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

static void	routine(mlx_instance_t *bullet, t_game *so, int j)
{
	if (!bullet->enabled)
	{
		so->player->b_spawn[j] = bullet->x;
		bullet->x = (so->player->idle[0]->instances[0].x) + 50;
		bullet->y = (so->player->idle[0]->instances[0].y) + 15;
	}
	else
	{
		if (!bullet_rcoll(so->map, *bullet)
			|| bullet->x >= (so->player->b_spawn[j]) + 64 * 4)
			bullet->enabled = false;
		bullet->x += 6;
	}
}

void	bullet_routine(void *param)
{
	t_game	*so;
	int		i;
	int		j;

	so = param;
	i = 0;
	if (!mlx_is_key_down(so->mlx, MLX_KEY_D))
		so->player->shoot_state = 0;
	while (i < so->player->b_len)
	{
		j = 0;
		while (j < so->player->ammo)
		{
			routine(&so->player->bullet[i]->instances[j], so, j);
			j++;
		}
		i++;
	}
}

static void	fire(t_game *so, mlx_image_t **bullet)
{
	int			i;
	static int	j;

	i = 0;
	while (i < so->player->b_len)
	{
		bullet[i]->instances[j].enabled = true;
		i++;
	}
	j = (j + 1) % so->player->ammo;
}

void	bullet_shoot(mlx_key_data_t data, void *param)
{
	t_game	*so;

	so = param;
	if (data.key == MLX_KEY_D)
	{
		so->player->shoot_state = 1;
		fire(so, so->player->bullet);
	}
	if (data.key == MLX_KEY_Q)
	{
		so->player->shoot_state = 1;
		fire(so, so->player->lbullet);
	}
}
