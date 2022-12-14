/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:36:35 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/03 12:13:59 by glamazer         ###   ########.fr       */
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
