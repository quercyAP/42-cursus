/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/26 08:45:51 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_move(t_player *player, float nb, char axe)
{
	int	i;
	int	j;
	int	jlen;

	i = 0;
	j = 0;
	while (i < player->sprite_len)
	{
		jlen = sprite_len(player->sprite[i]);
		j = 0;
		while (j < jlen)
		{
			if (axe == 'x')
				player->sprite[i][j]->instances[0].x += nb;
			else
				player->sprite[i][j]->instances[0].y += nb;
			j++;
		}
		i++;
	}
	player->move_state = 1;
}

void	player_jump(t_game *so)
{
	if (player_ucoll(so, so->player->idle[0]->instances))
	{
		so->player->jump_state = 1;
		so->player->step++;
		player_move(so->player, -5, 'y');
	}
}

void	gravity(t_game *so)
{
	static float	accel;
	float			var_max;

	var_max = 11.0f;
	if (player_dcoll(so, so->player->idle[0]->instances)
		&& !mlx_is_key_down(so->mlx, MLX_KEY_W))
	{
		so->player->var += accel;
		if (so->player->var > var_max)
			so->player->var = var_max;
		so->player->step++;
		player_move(so->player, so->player->var, 'y');
		so->player->jump_state = 0;
	}
	else
	{
		so->player->var = 0.0f;
		accel = 0.2f;
	}
}
