/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:49:46 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/16 16:43:41 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_idle(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.15f;
	current = mlx_get_time();
	i = player->ip;
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->idle[i]->enabled = true;
	player->ip = i;
}

void	lplayer_idle(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.15f;
	current = mlx_get_time();
	i = player->lip;
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->lidle[i]->enabled = true;
	player->lip = i;
}

void	player_jet(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.05f;
	current = mlx_get_time();
	i = player->jp;
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % 4;
	}
	del_img(player->explo);
	player->explo[i]->enabled = true;
	player->jp = i;
}

void	player_run(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.10f;
	i = player->rip;
	current = mlx_get_time();
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->run[i]->enabled = true;
	player->rip = i;
}

void	lplayer_run(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	int				i;

	delay = 0.10f;
	current = mlx_get_time();
	i = player->rlip;
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->p_len;
	}
	player->lrun[i]->enabled = true;
	player->rlip = i;
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
	if (current - start >= delay)
	{
		start = current;
		i = (i + 1) % player->e_len;
	}
	del_img(player->explo);
	player->explo[i]->enabled = true;
	player->jp = i;
}
