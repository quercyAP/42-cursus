/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/12 14:22:39 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_move(t_game *so, float nb, char axe)
{
	int	i;
	int	j;

	i = 0;
	while (i < so->p_len)
	{
		if (axe == 'x')
		{
			so->player_run_i[i]->instances[0].x += nb;
			so->lplayer_run_i[i]->instances[0].x += nb;
			so->player_idle_i[i]->instances[0].x += nb;
			so->lplayer_idle_i[i]->instances[0].x += nb;
		}
		else
		{
			so->player_run_i[i]->instances[0].y += nb;
			so->lplayer_run_i[i]->instances[0].y += nb;
			so->player_idle_i[i]->instances[0].y += nb;
			so->lplayer_idle_i[i]->instances[0].y += nb;
		}
		i++;
	}
	j = 0;
	while (j < so->j_len)
	{
		if (axe == 'x')
			so->player_jet_i[j]->instances[0].x += nb;
		else
			so->player_jet_i[j]->instances[0].y += nb;
		j++;
	}
}

void	player_jump(t_game *so_long)
{
	t_game	*so;

	so = so_long;
	if (player_ucoll(so_long))
		player_move(so, -5, 'y');
}

void	gravity(t_game *so_long)
{
	t_game			*so;
	static float	var;
	static float	accel;
	float			var_max;

	so = so_long;
	var_max = 11.0f;
	if (player_dcoll(so, var) && !mlx_is_key_down(so->mlx, MLX_KEY_SPACE))
	{
		var += accel;
		if (var > var_max)
			var = var_max;
		player_move(so, var, 'y');
	}
	else
	{
		var = 0.0f;
		accel = 0.2f;
	}
}
