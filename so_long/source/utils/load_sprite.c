/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:31:11 by glamazer          #+#    #+#             */
/*   Updated: 2022/12/24 11:12:31 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	*found_path(char *sprite_name, char *type, int nb)
{
	char	*nbr;
	char	*str1;
	char	*str2;

	nbr = ft_itoa(nb);
	str1 = ft_strjoin("asset/", type);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, "/");
	free(str1);
	str1 = ft_strjoin(str2, sprite_name);
	free(str2);
	str2 = ft_strjoin(str1, nbr);
	free(str1);
	str1 = ft_strjoin(str2, ".png");
	free(str2);
	free(nbr);
	return (str1);
}

static void	set_texture_to_img(int i, char *path, char *type, t_game *so_long)
{
	if (!ft_strncmp("Player", type, 6))
	{
		so_long->player_idle_t[i] = mlx_load_png(path);
		so_long->player_idle_i[i] = mlx_texture_to_image(so_long->mlx, \
		so_long->player_idle_t[i]);
	}
}

void	set_sprite(char *sprite_name, int nb_sprite, char *type, \
t_game *so_long)
{
	int		i;
	char	*path;

	i = 1;
	while (i <= nb_sprite)
	{
		path = found_path(sprite_name, type, i);
		set_texture_to_img(i - 1, path, type, so_long);
		free(path);
		i++;
	}
}
