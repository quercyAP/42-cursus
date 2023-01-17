/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:59:57 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 10:04:03 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	del_img(mlx_image_t **img)
{
	int	i;
	int	len;

	len = sprite_len(img);
	i = 0;
	while (i < len)
	{
		img[i]->enabled = false;
		i++;
	}
}

void	set_anim(t_player *player, void (*anim)(t_player *),
mlx_image_t ***img, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		del_img(img[i]);
		i++;
	}
	anim(player);
}
