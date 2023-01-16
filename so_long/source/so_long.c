/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/11 09:41:34 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**map;
	int		fd;
	t_game	*so;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	map = parsing(fd);
	if (!check_error(map))
	{
		free_map(map);
		return (0);
	}
	so = malloc(sizeof(t_game));
	game_init(so, map);
	draw_map(so);
	player_draw(so);
	mlx_loop_hook(so->mlx, &player_anim, so);
	mlx_loop_hook(so->mlx, &move_hook, so);
	mlx_loop(so->mlx);
	t_game_clear(so);
	close(fd);
}
