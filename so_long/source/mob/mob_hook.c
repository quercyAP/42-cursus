/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:04:43 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/30 09:40:23 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	del_mob_instance(mlx_image_t **img, int inst, t_game *so)
{
	int	i;

	i = 0;
	while (i < so->fly_eye->i_len)
	{
		img[i]->instances[inst].enabled = false;
		i++;
	}
}

int	check_mob_pos(t_point *coll_pos, t_game *so)
{
	int	i;

	i = 0;
	if (coll_pos)
	{
		while (i < ft_lstsize(so->elem->lst_mob))
		{
			if (so->fly_eye->idle[0]->instances[i].x / 64 == coll_pos->x - 1
				&& so->fly_eye->idle[0]->instances[i].y / 64 == coll_pos->y - 1)
				return (i);
			i++;
		}
	}
	return (-1);
}

static void	player_dmg(t_game *so)
{
	t_point	**coll_pos;
	int		i;
	int		j;

	coll_pos = so->player->coll_pos;
	j = 0;
	i = 0;
	player_collison_pos(coll_pos, so);
	while (i < 4)
	{
		j = check_mob_pos(coll_pos[i], so);
		if (j >= 0 && so->fly_eye->idle[0]->instances[j].enabled)
		{
			end_msg(false, so);
			mlx_close_window(so->mlx);
		}
		i++;
	}
}

void	mob_hook(void *param)
{
	t_game	*so;

	so = param;
	player_dmg(so);
	fly_eye_anim(so->fly_eye);
}
