/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_anim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:04:30 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/25 15:13:14 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	fly_eye_anim(t_mob *mob)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.10f;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % mob->i_len;
	}
	del_img(mob->idle);
	mob->idle[i]->enabled = true;
}
