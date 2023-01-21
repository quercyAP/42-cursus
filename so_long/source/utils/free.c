/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:26:22 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/20 16:02:49 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*free_pos(t_point *pos)
{
	if (pos)
		free(pos);
	return (NULL);
}

void	free_coll_pos(t_point **coll_pos)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free_pos(coll_pos[i]);
		i++;
	}
}

void	free_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i][0])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array[i]);
	free(map_array);
}

void	lst_clear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}

void	elem_clear(t_elem *elem)
{
	lst_clear(&elem->lst_exit);
	lst_clear(&elem->lst_spawn);
	lst_clear(&elem->lst_item);
	free(elem);
}

static void	free_img(mlx_image_t **img, t_game *so)
{
	int	i;

	i = 0;
	while (i < sprite_len(img))
	{
		mlx_delete_image(so->mlx, img[i]);
		i++;
	}
}

static void	free_img_tab(mlx_image_t ***img, t_game *so)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		free_img(img[i], so);
		i++;
	}
}

void	t_game_clear(t_game *so)
{
	free_img_tab(so->player->sprite, so);
	free_img(so->player->bullet, so);
	free_img(so->player->lbullet, so);
	free_img(so->energy->img, so);
	free_img(so->gate_anim->img, so);
	mlx_delete_texture(so->void_t);
	mlx_delete_texture(so->gate_t);
	mlx_delete_texture(so->wall_t);
	mlx_delete_image(so->mlx, so->void_i);
	mlx_delete_image(so->mlx, so->gate_i);
	mlx_delete_image(so->mlx, so->wall_i);
	elem_clear(so->elem);
	free_map(so->map);
	free(so->player->coll_pos);
	free(so);
	printf("toto\n");
}
