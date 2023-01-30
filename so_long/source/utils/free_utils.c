/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 08:45:37 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/30 09:40:06 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
	{
		free(map_array[i]);
		i++;
	}
	free(map_array[i]);
	free(map_array);
}

void	free_img_tab(mlx_image_t ***img, t_game *so)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		free_img(img[i], so);
		i++;
	}
}

void	free_img(mlx_image_t **img, t_game *so)
{
	int	i;

	i = 0;
	while (i < sprite_len(img))
	{
		mlx_delete_image(so->mlx, img[i]);
		i++;
	}
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
	lst_clear(&elem->lst_mob);
	free(elem);
}
