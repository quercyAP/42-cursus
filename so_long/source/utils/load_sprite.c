/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:31:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/16 15:10:53 by glamazer         ###   ########.fr       */
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

void	set_player_sprite(char *sprite_name, int nb_sprite, mlx_image_t **img,
t_game *so)
{
	int			i;
	char		*path;
	static int	j;

	i = 0;
	while (i < nb_sprite)
	{
		path = found_path(sprite_name, so->player->type, i);
		img[i] = mlx_texture_to_image(so->mlx, mlx_load_png(path));
		free(path);
		i++;
	}
	img[i] = NULL;
	so->player->sprite[j++] = img;
	so->player->sprite_len = j;
}

int	sprite_len(mlx_image_t **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}
