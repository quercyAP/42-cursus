/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:48:28 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/24 10:46:38 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

typedef	t_point *(f_coll)(void *);

void	player_collison_pos(t_point **coll_pos, t_game *so)
{
	f_coll	*coll_func[4];
	int		i;

	coll_func[0] = &player_dcoll;
	coll_func[1] = &player_ucoll;
	coll_func[2] = &player_lcoll;
	coll_func[3] = &player_rcoll;
	i = 0;
	while (i < 4)
	{
		coll_pos[i] = coll_func[i](so);
		i++;
	}
}

static void	del_instance(mlx_image_t **img, int inst, t_game *so)
{
	int	i;

	i = 0;
	so->nb_pick++;
	while (i < so->energy->i_len)
	{
		img[i]->instances[inst].enabled = false;
		i++;
	}
	if (so->nb_pick == ft_lstsize(so->elem->lst_item))
		so->finish = true;
}

static void	pick_up(t_game *so)
{
	int			j;
	int			k;
	t_point		**pos;

	pos = so->player->coll_pos;
	player_collison_pos(pos, so);
	j = 0;
	while (j < ft_lstsize(so->elem->lst_item))
	{
		k = 0;
		while (k < 4)
		{
			if (pos[k])
			{
				if (pos[k]->x == so->energy->img[0]->instances[j].x / 64
					&& pos[k]->y == so->energy->img[0]->instances[j].y / 64
					&& so->energy->img[0]->instances[j].enabled)
					del_instance(so->energy->img, j, so);
			}
			k++;
		}
		j++;
	}
}

void	item_hook(void *param)
{
	t_game	*so;

	so = param;
	pick_up(so);
	energy_anim(so->energy);
}
