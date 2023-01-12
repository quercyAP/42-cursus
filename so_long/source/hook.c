/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:56:20 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/12 15:09:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	set_anim(t_game *so, void (*anim)(t_game *))
{
	if (so->lplayer_idle_i[1] == so->lplayer_idle_i[2])
		printf("ok\n");
	anim(so);
}

void	player_anim(void *param)
{
	t_game	*so;

	so = param;
	if (so->dir == 0 && so->move_state == 0)
	{
		del_img(so->lplayer_run_i, so->p_len);
		del_img(so->player_run_i, so->p_len);
		del_img(so->player_idle_i, so->p_len);
		// lplayer_idle(so);
		set_anim(so, &lplayer_idle);
	}
	else if (so->dir == 1 && so->move_state == 0)
	{
		del_img(so->lplayer_run_i, so->p_len);
		del_img(so->player_run_i, so->p_len);
		del_img(so->lplayer_idle_i, so->p_len);
		player_idle(so);
	}
	if (so->dir == 0 && so->jump_state == 0 && so->move_state == 1)
	{
		del_img(so->lplayer_idle_i, so->p_len);
		del_img(so->player_idle_i, so->p_len);
		del_img(so->player_run_i, so->p_len);
		lplayer_run(so);
	}
	else if (so->dir == 1 && so->jump_state == 0 && so->move_state == 1)
	{
		del_img(so->lplayer_idle_i, so->p_len);
		del_img(so->player_idle_i, so->p_len);
		del_img(so->lplayer_run_i, so->p_len);
		player_run(so);
	}
	if (so->jump_state == 1)
		player_jet(so);
	else
		del_img(so->player_jet_i, so->j_len);
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
		so->jump_state = 1;
		player_jump(so);
	}
	if (mlx_is_key_down(so->mlx, MLX_KEY_LEFT) && player_lcoll(so))
	{
		so->move_state = 1;
		so->dir = 0;
		player_move(so, -5, 'x');
	}
	else if (mlx_is_key_down(so->mlx, MLX_KEY_RIGHT) && player_rcoll(so))
	{
		so->move_state = 1;
		so->dir = 1;
		player_move(so, 5, 'x');
	}
	else
		so->move_state = 0;
}
