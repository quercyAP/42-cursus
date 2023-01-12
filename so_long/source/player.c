/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/11 11:32:19 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_move(t_game *so, float nb, char axe)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		if (axe == 'x')
			so->player_idle_i[i]->instances[0].x += nb;
		else
			so->player_idle_i[i]->instances[0].y += nb;
		i++;
	}
	j = 0;
	while (j < 4)
	{
		if (axe == 'x')
			so->player_jet_i[j]->instances[0].x += nb;
		else
			so->player_jet_i[j]->instances[0].y += nb;
		j++;
	}
}

static void	player_jump(void *so_long)
{
	t_game	*so;

	so = so_long;
	if (player_ucoll(so_long))
		player_move(so, -5, 'y');
}

static void	gravity(void *so_long)
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

void	key_hook(void *param)
{
	t_game	*so;

	so = param;
	gravity(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_SPACE))
		player_jump(so);
	if (mlx_is_key_down(so->mlx, MLX_KEY_LEFT) && player_lcoll(so))
		player_move(so, -5, 'x');
	if (mlx_is_key_down(so->mlx, MLX_KEY_RIGHT) && player_rcoll(so))
		player_move(so, 5, 'x');
}

void	draw_img(t_game *so, t_point of, mlx_image_t **img, int len)
{
	int		i;
	t_point	*pos;

	pos = so->elem->lst_spawn->content;
	i = 0;
	while (i < len)
	{
		img[i]->enabled = false;
		mlx_image_to_window(so->mlx, img[i], pos->x * 64 + of.x, pos->y
			* 64 + of.y);
		i++;
	}
}

static void	del_img(mlx_image_t **img, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		img[i]->enabled = false;
		i++;
	}
}

void	player_idle(void *so_long)
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
		t->ip = (t->ip + 1) % 6;
	}
	else
	{
		del_img(t->player_idle_i, 6);
		t->player_idle_i[t->ip]->enabled = true;
	}
}

void	player_jet(void *so_long)
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
		t->jp = (t->jp + 1) % 4;
	}
	else
	{
		del_img(t->player_jet_i, 4);
		t->player_idle_i[t->jp]->enabled = true;
	}
}
