/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_shoot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:45:26 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 15:53:44 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	bullet_rcoll(char **map, mlx_instance_t bullet)
{
	t_point	p_axe;
	int		of;
	int		i;

	of = 64;
	p_axe.x = (bullet.x + of) / of;
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

void	bullet_routine(void *param)
{
	int		i;
	int		j;
	t_game	*so;

	so = param;
	i = 0;
	while (i < so->player->b_len)
	{
		j = 0;
		while (j <= so->player->curr_bull)
		{
			if (bullet_rcoll(so->map, so->player->bullet[i]->instances[j])
				&& so->player->bullet[i]->instances[j].enabled)
				so->player->bullet[i]->instances[j].x += 10;
			else
			{
				so->player->bullet[i]->instances[j].enabled = false;
				so->player->bullet[i]->instances[j].x = (so->player->idle[0]->instances[0].x) + 50;
				so->player->bullet[i]->instances[j].y = (so->player->idle[0]->instances[0].y) + 15;
			}
			j++;
		}
		i++;
	}
}

static void	fire(t_game *so)
{
	int			i;
	static int	j;

	i = 0;
	while (i < so->player->b_len)
	{
		so->player->bullet[i]->instances[j].enabled = true;
		i++;
	}
	j = (j + 1) % so->player->ammo;
	so->player->curr_bull = j;
}

void	bullet_shoot(mlx_key_data_t data, void *param)
{
	t_game	*so;

	so = param;
	if (data.key == MLX_KEY_F && data.action)
	{
		fire(so);
	}
}
