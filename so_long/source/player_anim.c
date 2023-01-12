/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:46 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/12 14:38:34 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	del_img(mlx_image_t **img, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		img[i]->enabled = false;
		i++;
	}
}

void	player_idle(t_game *so_long)
{
	float			current;
	static float	start;
	float			delay;
	t_game			*t;

	delay = 0.15f;
	t = so_long;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		t->player_idle_i[t->ip]->enabled = true;
		t->ip = (t->ip + 1) % t->p_len;
	}
	else
	{
		del_img(t->player_idle_i, t->p_len);
		t->player_idle_i[t->ip]->enabled = true;
	}
}

void	lplayer_idle(t_game *so_long)
{
	float			current;
	static float	lstart;
	float			delay;
	t_game			*t;

	delay = 0.15f;
	t = so_long;
	current = mlx_get_time();
	if (current - lstart >= delay)
	{
		lstart = current;
		t->lplayer_idle_i[t->lip]->enabled = true;
		t->lip = (t->lip + 1) % t->p_len;
	}
	else
	{
		del_img(t->lplayer_idle_i, t->p_len);
		t->lplayer_idle_i[t->lip]->enabled = true;
	}
}

void	player_jet(t_game *so_long)
{
	float			current;
	static float	jet_start;
	float			delay;
	t_game			*t;

	delay = 0.02f;
	t = so_long;
	current = mlx_get_time();
	if (current - jet_start >= delay && mlx_is_key_down(t->mlx, MLX_KEY_SPACE))
	{
		jet_start = current;
		t->player_jet_i[t->jp]->enabled = true;
		t->jp = (t->jp + 1) % t->j_len;
	}
	else
	{
		t->jump_state = 0;
		del_img(t->player_jet_i, t->j_len);
		t->player_jet_i[t->jp]->enabled = true;
	}
}

void	player_run(t_game *so_long)
{
	float			current;
	static float	rstart;
	float			delay;
	t_game			*t;

	delay = 0.10f;
	t = so_long;
	current = mlx_get_time();
	if (current - rstart >= delay)
	{
		rstart = current;
		t->player_run_i[t->rip]->enabled = true;
		t->rip = (t->rip + 1) % t->p_len;
	}
	else
	{
		del_img(t->player_run_i, t->p_len);
		t->player_run_i[t->rip]->enabled = true;
	}
}

void	lplayer_run(t_game *so_long)
{
	float			current;
	static float	rlstart;
	float			delay;
	t_game			*t;

	delay = 0.10f;
	t = so_long;
	current = mlx_get_time();
	if (current - rlstart >= delay)
	{
		rlstart = current;
		t->lplayer_run_i[t->rlip]->enabled = true;
		t->rlip = (t->rlip + 1) % t->p_len;
	}
	else
	{
		del_img(t->lplayer_run_i, t->p_len);
		t->lplayer_run_i[t->rlip]->enabled = true;
	}
}