/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/04 16:43:03 by glamazer         ###   ########.fr       */
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
	int		i;
	int		curr;
	int		y;
	int		max;
	t_game	*so;

	so = so_long;
	i = 0;
	curr = so->player_idle_i[i]->instances[0].y;
	max = curr - 128;
	y = curr;
	while (y > max)
	{
		so->jump_state = true;
		player_move(so, -1, 'y');
		y -= 1;
	}
}

void	key_hook(void *param)
{
	t_game	*so;
	int		i;

	so = param;
	i = so->ip;
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_SPACE) && !so->jump_state)
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
		mlx_image_to_window(so->mlx, so->player_idle_i[i], \
			axe->x * 64, axe->y * 64);
		i++;
	}
}

void	player_idle(void *so_long)
{
	float				current;
	static float		start;
	static float		delay;
	t_game				*t;

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
