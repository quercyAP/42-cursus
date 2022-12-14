/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/05 12:56:28 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**map;
	int		fd;
	t_game	*so_long;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	map = parsing(fd);
	if (!check_error(map))
	{
		free_map(map);
		return (0);
	}
	so_long = malloc(sizeof(t_game));
	game_init(so_long, map);
	draw_map(so_long);
	draw_img(so_long);
	mlx_loop_hook(so_long->mlx, &player_idle, so_long);
	mlx_loop_hook(so_long->mlx, &key_hook, so_long);
	mlx_loop(so_long->mlx);
	t_game_clear(so_long);
	close(fd);
}
