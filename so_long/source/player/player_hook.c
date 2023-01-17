/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:56:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 15:45:22 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	player_anim(t_game *so)
{
	int		len;

	len = so->player->sprite_len;
	if (!so->player->dir && !so->player->move_state)
		set_anim(so->player, &lplayer_idle, so->player->sprite, len);
	else if (so->player->dir && !so->player->move_state)
		set_anim(so->player, &player_idle, so->player->sprite, len);
	if (!so->player->dir && so->player->move_state)
		set_anim(so->player, &lplayer_run, so->player->sprite, len);
	else if (so->player->dir && so->player->move_state)
		set_anim(so->player, &player_run, so->player->sprite, len);
	if (so->player->jump_state)
		player_jet(so->player);
	else if (!so->player->jump_state && player_dcoll(so, 5))
		player_jet1(so->player);
	if (so->player->shoot_state)
	{
		set_anim(so->player, &player_shoot, so->player->sprite, len);
		bullet_anim(so->player);
	}
}

static void	move_hook(t_game *so)
{
	gravity(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_SPACE))
		player_jump(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_LEFT) && player_lcoll(so))
	{
		so->player->dir = 0;
		player_move(so->player, -5, 'x');
	}
	else if (mlx_is_key_down(so->mlx, MLX_KEY_RIGHT) && player_rcoll(so))
	{
		so->player->dir = 1;
		player_move(so->player, 5, 'x');
	}
	else
		so->player->move_state = 0;
}

void	player_hook(void *param)
{
	t_game	*so;

	so = param;
	move_hook(so);
	player_anim(so);
	bullet_anim(so->player);
}
