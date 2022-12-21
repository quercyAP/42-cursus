/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:10:06 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/21 13:04:56 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../includes/so_long.h"

mlx_image_t		*img;

static void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

static void	init(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*t_img;

	mlx = mlx_init(1360, 768, "test", true);
	t_img = mlx_load_png("asset/Environment/Wall1.png");
	img = mlx_texture_to_image(mlx, t_img);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int32_t	main(int argc, char **argv)
{
	char	**test_map;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	init();
	test_map = parsing(fd);
	if (!check_error(test_map))
	{
		free_map(test_map);
		return (0);
	}
	free_map(test_map);
	close(fd);
}
