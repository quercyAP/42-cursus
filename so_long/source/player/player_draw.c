/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamazer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:07:53 by glamazer          #+#    #+#             */
/*   Updated: 2023/01/17 14:10:23 by glamazer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	draw_bullet(t_game *so)
{
	int	i;

	i = 0;
	while (i < so->player->ammo)
	{
		draw_img(so, (t_point){50, 15}, so->player->bullet, so->player->b_len);
		i++;
	}
}

void	player_draw(t_game *so)
{
	draw_img(so, (t_point){0, 40}, so->player->explo, so->player->e_len);
	draw_img(so, (t_point){0, 0}, so->player->idle, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->lidle, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->lrun, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->run, so->player->p_len);
	draw_img(so, (t_point){0, 0}, so->player->shoot, so->player->s_len);
	draw_bullet(so);
}
