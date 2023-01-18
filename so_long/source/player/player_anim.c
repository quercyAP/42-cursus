/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:46 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 10:09:43 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_idle(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.15f;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->idle[i]->enabled = true;
}

void	lplayer_idle(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.15f;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->lidle[i]->enabled = true;
}

void	player_run(t_player *player)
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
		i = (i + 1) % player->p_len;
	}
	player->run[i]->enabled = true;
}

void	lplayer_run(t_player *player)
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
		i = (i + 1) % player->p_len;
	}
	player->lrun[i]->enabled = true;
}

void	player_jet1(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.02f;
	current = mlx_get_time();
	i = player->jp;
	if (current - start >= delay && i < player->e_len - 1)
	{
		start = current;
		i++;
	}
	del_img(player->explo);
	player->explo[i]->enabled = true;
	if (i == player->e_len - 1)
		del_img(player->explo);
	player->jp = i;
}
