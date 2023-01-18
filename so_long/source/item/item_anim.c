/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:49:45 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 11:55:10 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	energy_anim(t_item *energy)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.05f;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % energy->i_len;
	}
	del_img(energy->img);
	energy->img[i]->enabled = true;
}
