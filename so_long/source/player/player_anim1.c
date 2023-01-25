/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:45:21 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/18 10:23:37 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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

void	player_shoot(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.05f;
	current = mlx_get_time();
	if (current - start >= delay && i < player->s_len - 1)
	{
		start = current;
		i++;
	}
	if (i == player->s_len)
		i--;
	player->shoot[i]->enabled = true;
}

void	lplayer_shoot(t_player *player)
{
	float			current;
	static float	start;
	float			delay;
	static int		i;

	delay = 0.05f;
	current = mlx_get_time();
	if (current - start >= delay && i < player->s_len - 1)
	{
		start = current;
		i++;
	}
	if (i == player->s_len)
		i--;
	player->lshoot[i]->enabled = true;
}

void	bullet_anim(t_player *player)
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
		i = (i + 1) % player->b_len;
	}
	player->bullet[i]->enabled = true;
}

void	lbullet_anim(t_player *player)
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
		i = (i + 1) % player->b_len;
	}
	player->lbullet[i]->enabled = true;
}