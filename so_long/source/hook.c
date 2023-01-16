/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:56:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/16 16:39:27 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	del_img(mlx_image_t **img)
{
	int	i;
	int	len;

	len = sprite_len(img);
	i = 0;
	while (i < len)
	{
		img[i]->enabled = false;
		i++;
	}
}

void	set_anim(t_player *player, void (*anim)(t_player *),
mlx_image_t ***img)
{
	int	i;

	i = 0;
	while (i < player->sprite_len)
	{
		del_img(img[i]);
		i++;
	}
	anim(player);
}

void	player_anim(void *param)
{
	t_game	*so;

	so = param;
	if (!so->player->dir && !so->player->move_state)
		set_anim(so->player, &lplayer_idle, so->player->sprite);
	else if (so->player->dir && !so->player->move_state)
		set_anim(so->player, &player_idle, so->player->sprite);
	if (!so->player->dir && so->player->move_state)
		set_anim(so->player, &lplayer_run, so->player->sprite);
	else if (so->player->dir && so->player->move_state)
		set_anim(so->player, &player_run, so->player->sprite);
	if (so->player->jump_state)
		player_jet(so->player);
	else if (so->player->jump_state && !mlx_is_key_down(so->mlx, MLX_KEY_SPACE))
		player_jet1(so->player);
}

void	move_hook(void *param)
{
	t_game	*so;

	so = param;
	gravity(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_SPACE))
	{
		player_jump(so);
		so->player->jump_state = 1;
	}
	if (mlx_is_key_down(so->mlx, MLX_KEY_LEFT) && player_lcoll(so))
	{
		so->player->move_state = 1;
		so->player->dir = 0;
		player_move(so->player, -5, 'x');
	}
	else if (mlx_is_key_down(so->mlx, MLX_KEY_RIGHT) && player_rcoll(so))
	{
		so->player->move_state = 1;
		so->player->dir = 1;
		player_move(so->player, 5, 'x');
	}
	else
		so->player->move_state = 0;
}
