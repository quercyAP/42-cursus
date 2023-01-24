/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gate_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:09:16 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/24 12:45:36 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	hide_anim(mlx_image_t **anim, bool set)
{
	int	i;

	i = 0;
	while (i < sprite_len(anim))
	{
		if (set)
			anim[i]->instances->enabled = false;
		else
			anim[i]->instances->enabled = true;
		i++;
	}
}

void	finish_game(t_game *so)
{
	int		k;
	t_point	**pos;
	t_point	*gate_pos;

	pos = so->player->coll_pos;
	gate_pos = so->elem->lst_exit->content;
	player_collison_pos(pos, so);
	k = 0;
	while (k < 4)
	{
		if (pos[k])
		{
			if (pos[k]->x * 64 == gate_pos->x * 64
				&& pos[k]->y * 64 == gate_pos->y * 64)
			{
				write(1, "Congratulation !!!\n", 19);
				write(1, "You won the game with ", 22);
				ft_putnbr_fd(so->player->step, 1);
				write(1, " steps\n", 7);
				mlx_close_window(so->mlx);
			}
		}
		k++;
	}
}

static void	launch_end(t_game *so)
{
	t_point	*gate_block;

	gate_block = so->elem->lst_exit->content;
	if (so->map[gate_block->y + 1][gate_block->x] != '1')
	{
		so->map[gate_block->y + 1][gate_block->x] = '1';
		mlx_image_to_window(so->mlx, so->wall_i, gate_block->x * 64,
			(gate_block->y + 1) * 64);
	}
	if (so->map[gate_block->y + 1][gate_block->x + 1] != '1')
	{
		so->map[gate_block->y + 1][gate_block->x + 1] = '1';
		mlx_image_to_window(so->mlx, so->wall_i, (gate_block->x + 1) * 64,
			(gate_block->y + 1) * 64);
	}
}

void	gate_hook(void *param)
{
	t_game	*so;

	so = param;
	if (so->finish)
	{
		hide_anim(so->gate_anim->img, false);
		so->gate_i->enabled = true;
		gate_anim(so->gate_anim);
		launch_end(so);
		finish_game(so);
	}
	else
		hide_anim(so->gate_anim->img, true);
}
