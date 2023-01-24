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

static int	check_file_name(char *file)
{
	char	*cmp;

	cmp = file + (ft_strlen(file) - 4);
	if (ft_strncmp(cmp, ".ber", 5) != 0)
		return (0);
	return (1);
}

static void	loop(t_game *so)
{
	mlx_loop_hook(so->mlx, player_hook, so);
	mlx_loop_hook(so->mlx, item_hook, so);
	mlx_loop_hook(so->mlx, gate_hook, so);
	mlx_key_hook(so->mlx, bullet_shoot, so);
	mlx_loop_hook(so->mlx, mob_hook, so);
	mlx_loop(so->mlx);
}

int32_t	main(int argc, char **argv)
{
	char	**map;
	int		fd;
	t_game	*so;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || argc != 2 || !check_file_name(argv[1]))
	{
		ft_putstr_fd("Error\nBad argument\n", 1);
		return (0);
	}
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
	so->step_str = mlx_put_string(so->mlx, so->step, 0, 0);
	loop(so);
	close(fd);
	t_game_clear(so);
	system("leaks so_long");
}
