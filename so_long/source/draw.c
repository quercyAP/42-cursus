/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:36:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/16 16:40:44 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	browse_map(t_game *so_long, char c, mlx_image_t *img, int ratio)
{
	int	x;
	int	y;

	y = 0;
	while (so_long->map[y][0])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == c || (c == '0' && c != '1'))
				mlx_image_to_window(so_long->mlx, img, x * 64, y * 64 - ratio);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *so_long)
{
	browse_map(so_long, so_long->elem->empty, so_long->void_i, 0);
	browse_map(so_long, so_long->elem->wall, so_long->wall_i, 0);
	browse_map(so_long, so_long->elem->exit, so_long->gate_i, 64);
}

void	player_draw(t_game *so)
{
	// draw_img(so, (t_point){15, 32}, so->player->jet, so->player->j_len);
	draw_img(so, (t_point){0, 40}, so->player->explo, so->player->e_len);
	draw_img(so, (t_point){0, 0}, so->player->idle, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->run, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->lrun, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->lidle, so->player->p_len);
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
