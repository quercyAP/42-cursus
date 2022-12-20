/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/20 17:14:00 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**test_map;
	int		fd;
	mlx_t	*mlx;
	mlx_im	*img;
	char	*path = "asset/Characters/Player/Player-idle/player-idle.png";
	int		width;
	int		height;
	mlx_image_t 

	(void)argc;
	mlx = mlx_init(800, 600, "test", true);
	mlx_loop(mlx);
	width = 16;
	height = 16;
	mlx_png_file_to_image(mlx, path, &width, &height);
	mlx_image_to_window(mlx, );
	fd = open(argv[1], O_RDONLY);
	test_map = parsing(fd);
	if (!check_error(test_map))
	{
		free_map(test_map);
		return (0);
	}
	free_map(test_map);
	mlx_terminate(mlx);
	close(fd);
}
