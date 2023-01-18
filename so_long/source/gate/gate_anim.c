/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:09:28 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 16:40:38 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	gate_anim(t_item *gate_anim)
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
		i = (i + 1) % gate_anim->i_len;
	}
	del_img(gate_anim->img);
	gate_anim->img[i]->enabled = true;
}
