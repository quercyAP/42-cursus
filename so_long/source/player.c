/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:03:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/03 15:08:42 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_hook(void *param)
{
	t_game	*so;

	so = param;
	if (mlx_is_key_down(so->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(so->mlx);
	if (mlx_is_key_down(so->mlx, MLX_KEY_UP))
		so->player_idle_i[]
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
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
	static int			i;
	t_point				*axe;
	t_game				*t;

	delay = 0.15f;
	t = so_long;
	axe = t->elem->lst_spawn->content;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		printf("i = %i\n", i);
		t->player_idle_i[i]->enabled = true;
		if (i > 0)
			t->player_idle_i[i - 1]->enabled = false;
		else if (i == 0)
			t->player_idle_i[5]->enabled = false;
		t->player_idle_i[i]->instances[0].x += 5;
		i = (i + 1) % 6;
	}
}
