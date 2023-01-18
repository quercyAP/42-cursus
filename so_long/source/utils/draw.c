/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:36:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 16:49:54 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	browse_map(t_game *so_long, char c, mlx_image_t *img, t_point ratio)
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
				mlx_image_to_window(so_long->mlx,
					img, x * 64 + ratio.x, y * 64 + ratio.y);
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *so)
{
	int	i;

	browse_map(so, so->elem->empty, so->void_i, (t_point){0, 0});
	browse_map(so, so->elem->wall, so->wall_i, (t_point){0, 0});
	i = -1;
	while (++i < so->energy->i_len)
	{
		browse_map(so, so->elem->item, so->energy->img[i], (t_point){16, 16});
		browse_map(so, so->elem->exit, so->gate_anim->img[i],
			(t_point){25, -32});
	}
	browse_map(so, so->elem->exit, so->gate_i, (t_point){0, -64});
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
