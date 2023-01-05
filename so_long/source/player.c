/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/05 14:06:49 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	player_move(t_game *so, int nb, char axe)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (axe == 'x')
			so->player_idle_i[i]->instances[0].x += nb;
		else
			so->player_idle_i[i]->instances[0].y += nb;
		i++;
	}
}

static void	player_jump(void *so_long)
{
	t_game	*so;

	so = so_long;
	if (so->h_max <= 130)
	{
		player_move(so, -10, 'y');
		so->h_max += 10;
	}
}

static void	gravity(void *so_long)
{
	t_game	*so;

	so = so_long;
	if (so->h_max > 0)
	{
		player_move(so, 5, 'y');
		so->h_max -= 5;
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
	if (mlx_is_key_down(so->mlx, MLX_KEY_LEFT))
		player_move(so, -5, 'x');
	if (mlx_is_key_down(so->mlx, MLX_KEY_RIGHT))
		player_move(so, 5, 'x');
}

void	draw_img(t_game *so)
{
	int		i;
	t_point	*axe;

	i = 0;
	axe = so->elem->lst_spawn->content;
	while (i < 6)
	{
		so->player_idle_i[i]->enabled = false;
		mlx_image_to_window(so->mlx, so->player_idle_i[i], axe->x * 64, axe->y
			* 64);
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
		if (t->ip > 0)
			t->player_idle_i[t->ip - 1]->enabled = false;
		else if (t->ip == 0)
			t->player_idle_i[5]->enabled = false;
		t->ip = (t->ip + 1) % 6;
	}
}
