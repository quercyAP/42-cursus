/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:31:11 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/20 14:28:46 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*found_path(char *sprite_name, char *type, int nb)
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
	int				i;
	char			*path;
	mlx_texture_t	*tmp;

	i = 0;
	while (i < nb_sprite)
	{
		path = found_path(sprite_name, so->player->type, i);
		tmp = mlx_load_png(path);
		img[i] = mlx_texture_to_image(so->mlx, tmp);
		mlx_delete_texture(tmp);
		free(path);
		i++;
	}
	img[i] = NULL;
	if (so->player->sprite_len < 7)
		so->player->sprite[so->player->sprite_len++] = img;
}

void	set_item_sprite(char *sprite_name, int nb_sprite, mlx_image_t **img,
t_game *so)
{
	int				i;
	char			*path;
	mlx_texture_t	*tmp;

	i = 0;
	while (i < nb_sprite)
	{
		path = found_path(sprite_name, so->energy->type, i);
		tmp = mlx_load_png(path);
		img[i] = mlx_texture_to_image(so->mlx, tmp);
		mlx_delete_texture(tmp);
		free(path);
		i++;
	}
	img[i] = NULL;
}

int	sprite_len(mlx_image_t **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
